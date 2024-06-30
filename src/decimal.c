#include "decimal.h"


int main() {
  s21_decimal src1, src2;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b00000000000000000010000000010011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b10000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal_normalization(&src1, &src2);
  print_decimal(src1);
  print_decimal(src2);
  // s21_is_less(src1, src2) ? printf("YES\n") : printf("NO\n");
  printf("%d - %d\n", get_scale(src1), get_scale(src2));
  return 0;
}

bool get_sign(s21_decimal decimal) {
  return decimal.bits[3] & NEGATIVE ? 1 : 0;
}

void set_sign(s21_decimal* decimal) {
  decimal->bits[3] |= NEGATIVE;
}

int get_scale(s21_decimal decimal) { 
  return (decimal.bits[3] >> 16) & SCALE;
}

void set_scale(s21_decimal* decimal, int scale) {
  bool sign = get_sign(*decimal);
  decimal->bits[3] = scale << 16;
  if (sign) set_sign(decimal);
}

void s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  if (get_sign(value_1) && get_sign(value_2)) {
    set_sign(result);
  }
  // decimal_normalization(&value_1, &value_2);
  unsigned long long temp = 0;
  for (int i = 0; i < 3; i++) {
    temp += (unsigned long long)value_1.bits[i] + (unsigned long long)value_2.bits[i];
    result->bits[i] = (unsigned)temp;
    temp >>= 32;
  }
}

void print_decimal(s21_decimal decimal) {
  if (get_sign(decimal)) printf("-");
  for (int i = 2; i >= 0; i--) {
    to_binary(decimal.bits[i]);
    if (!i) printf("\n");
  }
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int res = 1;
  for (int i = 0; i < 3; i++) {
    if (value_1.bits[i] != value_2.bits[i])
      res = 0;
  }
  return res;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;
  for (int i = 0; i < 3; i++) {
    if (value_1.bits[i] != value_2.bits[i])
      res = 1;
  }
  return res;
}

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;
  if (s21_is_equal(value_1, value_2)) return res;
  if (!get_sign(value_1) && get_sign(value_2)) {
    res = 1;
  } else if (get_scale(value_1) > get_scale(value_2)) {
    res = 1;
  } else {
    for (int i = 2; i >= 0; i--) {
      if (value_1.bits[i] < value_2.bits[i]) {
        res = 1;
      } else if (value_1.bits[i] > value_2.bits[i])
        break;
    }
  }
  return res;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return (s21_is_less(value_1, value_2) || s21_is_equal(value_1, value_2));
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  return !(s21_is_less_or_equal(value_1, value_2));
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return !(s21_is_less(value_1, value_2));
}

// int s21_from_decimal_to_int(s21_decimal src, int *dst) {
//   for (int i = 2; i >= 0; i--) {
//     *dst += src.bits[i];

//   }
// }

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  dst->bits[0] = abs(src);
  for (int i = 1; i < 4; i++) {
    dst->bits[i] = 0;
  }
  dst->bits[3] = src & NEGATIVE;
  return 0;
}

int s21_negate(s21_decimal value, s21_decimal* result) {
  for (int i = 0; i < 3; i++) {
    result->bits[i] = value.bits[i];
  }
  result->bits[3] = (value.bits[3] ^ NEGATIVE);
  return 0;
}

void decimal_normalization(s21_decimal* value_1, s21_decimal* value_2) {
  bool flag_overflow = 0;
  int scale_1 = get_scale(*value_1);
  int scale_2 = get_scale(*value_2);
  while (scale_1 != scale_2) {
    if (scale_1 > scale_2 && !flag_overflow) {
      flag_overflow = mult_by_10(value_2, scale_1, &scale_2);
    } else
      break;
  }
  set_scale(value_2, scale_2);
}

bool mult_by_10(s21_decimal* decimal, int scale_big, int* scale_little) {
  bool flag = 0;
  s21_decimal top_decimal;
  top_decimal.bits[0] = 0b10011001100110011001100110011001;
  top_decimal.bits[1] = 0b10011001100110011001100110011001;
  top_decimal.bits[2] = 0b00011001100110011001100110011001;
  top_decimal.bits[3] = decimal->bits[3];
  for (;scale_big > *scale_little; (*scale_little)++) {
    if (s21_is_less_or_equal(*decimal, top_decimal)) {
      mult_by_num(decimal, 10);
    } else {
      flag = 1;
      break;
    }
  }
  return flag;
}

void mult_by_num(s21_decimal* decimal, int num) {
   unsigned long long temp = 0;
  for (int i = 0; i < 3; i++) { 
    temp += (unsigned long long)decimal->bits[i] * (unsigned long long)num;
    decimal->bits[i] = (unsigned)temp;
    temp >>= 32;
  }
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
      if (buf[k] == ' ')
        buf[k] = '0';
    }
    printf("%s", buf);
}