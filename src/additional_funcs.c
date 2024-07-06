#include "s21_decimal.h"

bool get_sign(s21_decimal decimal) {
  return decimal.bits[3] & NEGATIVE ? 1 : 0;
}

void set_sign(s21_decimal* decimal) { decimal->bits[3] |= NEGATIVE; }

int get_scale(s21_decimal decimal) { return (decimal.bits[3] >> 16) & SCALE; }

void set_scale(s21_decimal* decimal, int scale) {
  bool sign = get_sign(*decimal);
  decimal->bits[3] = scale << 16;
  if (sign) set_sign(decimal);
}

void decimal_normalization(s21_decimal* value_1, s21_decimal* value_2) {
  int flag_overflow = 0;
  int scale_1 = get_scale(*value_1);
  int scale_2 = get_scale(*value_2);
  while (scale_1 != scale_2) {
    if (scale_1 > scale_2 && !flag_overflow) {
      flag_overflow = mult_by_10(value_2, scale_1, &scale_2);
    } else if (scale_1 > scale_2 && flag_overflow) {
      div_by_10(value_1, &scale_1, scale_2);
    }
    if (scale_2 > scale_1 && !flag_overflow) {
      flag_overflow = mult_by_10(value_1, scale_2, &scale_1);
    } else if (scale_2 > scale_1 && flag_overflow) {
      div_by_10(value_2, &scale_2, scale_1);
    }
  }
  set_scale(value_2, scale_2);
  set_scale(value_1, scale_1);
}

void to_binary(unsigned n) {
  int binaryNum[32] = {0};
  int i = 0;
  char binaryStr[32] = "";

  while (n > 0) {
    binaryNum[i] = n % 2;
    n = n / 2;
    i++;
  }

  for (int j = 31; j >= 0; j--) {
    binaryStr[i - 1 - j] = binaryNum[j] + '0';
  }
  char buf[40];
  sprintf(buf, "%32s", binaryStr);
  for (int k = 0; k < 32; k++) {
    if (buf[k] == ' ') buf[k] = '0';
  }
  printf("%s", buf);
}

void print_decimal(s21_decimal decimal) {
  printf("%d: ", get_scale(decimal));
  if (get_sign(decimal))
    printf("-");
  else
    printf(" ");
  for (int i = 2; i >= 0; i--) {
    to_binary(decimal.bits[i]);
    if (!i) printf("\n");
  }
}

void cut_zero(s21_decimal* decimal) {
  int scale = get_scale(*decimal);
  while (scale && !mod_by_num(*decimal, 10)) {
    div_by_num(decimal, 10);
    scale--;
  }
  set_scale(decimal, scale);
}

void set_zero(s21_decimal* decimal) {
  for (int i = 0; i <= 3; i++) {
    decimal->bits[i] = 0;
  }
}

void swap_decimal(s21_decimal* value_1, s21_decimal* value_2) {
  s21_decimal* temp;
  temp = value_1;
  value_1 = value_2;
  value_2 = temp;
}

// int count_digits(s21_decimal decimal) {
//   int array_digits[30] = {0};
//   int i = 0;
//   while (!s21_is_zero(decimal)) {
//     array_digits[i++] = mod_by_num(decimal, 10);
//     div_by_num(&decimal, 10);
//   }
//   return i;
// }

void copy_decimal(s21_decimal* dest, const s21_decimal src) {
  for (int i = 0; i <= 3; i++) {
    dest->bits[i] = src.bits[i];
  }
}

bool correct_decimal(s21_decimal value) {
  bool return_value = 1;
  int scale = get_scale(value);
  if (scale >= 0 && scale <= 28)
    return_value = (value.bits[3] | POSSIBLE) & (~POSSIBLE);
  return return_value;
}

int real_round(s21_decimal* value, int* overcut, int overcut_size) {
  int flag_bank = 0;
  if (overcut[--overcut_size] == 5) {
    for (; overcut_size >= 0; --overcut_size) {
      if (overcut[overcut_size]) {
        flag_bank = 2;
        break;
      }
    }
    if (flag_bank != 2) flag_bank = 1;
  } else if (overcut[overcut_size] > 5) {
    flag_bank = 2;
  }
  if ((flag_bank == 1 && !mod_by_num(*value, 2)) || flag_bank == 2) {
    s21_decimal plusone = {{1, 0, 0, value->bits[3]}};
    s21_add(*value, plusone, value);
  }
  return flag_bank;
}

void print_long_decimal(s21_long_decimal decimal) {
  printf("%d: ", get_scale_long(decimal));
  for (int i = 6; i >= 0; i--) {
    to_binary(decimal.bits[i]);
    if (!i) printf("\n");
  }
}

void decimal_normalization_long(s21_long_decimal* value_1, s21_long_decimal* value_2) {

  int scale_1 = get_scale_long(*value_1);
  int scale_2 = get_scale_long(*value_2);
  while (scale_1 != scale_2) {
    if (scale_2 > scale_1) {
      mult_by_num_long(*value_1, value_1, 10);
      scale_1++;
    } else {
      mult_by_num_long(*value_2, value_2, 10);
      scale_2++;
    }
  }
  set_scale_long(value_2, scale_2);
  set_scale_long(value_1, scale_1);
}