#include "decimal.h"

int main() {
  s21_decimal src1, src2, result;
  // origin.bits[0] = 0b00101100010111011001101101001111;
  // origin.bits[1] = 0b11111000000111110000000110111111;
  // origin.bits[2] = 0b10111011010111111101000100011001;
  // origin.bits[3] = 0b00000000000010110000000000000000;
  src1.bits[0] = 0b11101111010100000000000000000000;
  src1.bits[1] = 0b00011010111001001101011011100010;
  src1.bits[2] = 0b00000000000000000000000000011011;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b10000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;

  print_decimal(src1);
  print_decimal(src2);
  // decimal_normalization(&src1, &src2);
  // print_decimal(src1);
  // print_decimal(src2);

  s21_mul(src1, src2, &result);
  // s21_sub(src1, src2, &result);
  print_decimal(result);
  // printf("%d\n", get_scale(result));
  return 0;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int flag = 0;
  int sign_1 = get_sign(value_1);
  int sign_2 = get_sign(value_2);
  if (sign_1 && sign_2) {
    set_sign(result);
    flag = real_add(value_1, value_2, result);
  } else if (!sign_1 && !sign_2) {
    flag = real_add(value_1, value_2, result);
  } else {
    if (s21_is_less_abs(value_1, value_2)) {
      if (!sign_1 && sign_2) set_sign(result);
      flag = real_sub(value_2, value_1, result);
    } else {
      if (sign_1 && !sign_2) set_sign(result);
      flag = real_sub(value_1, value_2, result);
    }
  }
  return flag;
}

int real_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  decimal_normalization(&value_1, &value_2);
  unsigned long long temp = 0;
  for (int i = 0; i < 3; i++) {
    temp += (unsigned long long)value_1.bits[i] +
            (unsigned long long)value_2.bits[i];
    result->bits[i] = (unsigned)temp;
    temp >>= 32;
  }

  set_scale(result, get_scale(value_1));
  return (int)temp;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_negate(value_2, &value_2);
  return s21_add(value_1, value_2, result);
}

int real_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  decimal_normalization(&value_1, &value_2);
  unsigned long long temp = 0;
  for (int i = 2; i >= 0; i--) {
    temp = temp + (unsigned long long)value_1.bits[i] -
            (unsigned long long)value_2.bits[i];
    if (value_1.bits[i] < value_2.bits[i]) {
      result->bits[i+1]--;
    }
    result->bits[i] = (unsigned)temp;
    temp <<= 32;
  }
  set_scale(result, get_scale(value_1));
  return (int)temp;
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

bool mult_by_10(s21_decimal* decimal, int scale_big, int* scale_little) {
  bool flag = 0;
  s21_decimal top_decimal;
  top_decimal.bits[0] = 0b10011001100110011001100110011001;
  top_decimal.bits[1] = 0b10011001100110011001100110011001;
  top_decimal.bits[2] = 0b00011001100110011001100110011001;
  top_decimal.bits[3] = decimal->bits[3];
  for (; scale_big > *scale_little; (*scale_little)++) {
    if (s21_is_less_abs(*decimal, top_decimal) ||
        s21_is_equal(*decimal, top_decimal)) {
      mult_by_num(*decimal, decimal, 10);
    } else {
      flag = 1;
      break;
    }
  }
  return flag;
}

void mult_by_num(s21_decimal decimal, s21_decimal* result, int num) {
  unsigned long long temp = 0;
  for (int i = 0; i < 3; i++) {
    temp += (unsigned long long)decimal.bits[i] * (unsigned long long)num;
    result->bits[i] = (unsigned)temp;
    temp >>= 32;
  }
}

bool div_by_10(s21_decimal* decimal, int* scale_big, int scale_little) {
  bool flag = 0;
  int flag_bank = 0;
  int overcut[30] = {0};
  int i = 0;
  for (; *scale_big > scale_little; (*scale_big)--, i++) {
    overcut[i] = mod_by_num(*decimal, 10);
    div_by_num(decimal, 10);
  }
  if (overcut[--i] == 5) {
    for (; i >= 0; --i) {
      if (overcut[i]) {
        flag_bank = 2;
        break;
      }
    }
    if (flag_bank != 2) flag_bank = 1;
  } else if (overcut[i] > 5) {
    flag_bank = 2;
  }
  if ((flag_bank == 1 && !mod_by_num(*decimal, 2)) || flag_bank == 2) {
    s21_decimal plusone = {{1, 0, 0, decimal->bits[3]}};
    s21_add(*decimal, plusone, decimal);
  }
  return flag;
}

void div_by_num(s21_decimal* decimal, int num) {
  unsigned long long ost = 0;
  unsigned long long temp = 0;
  for (int i = 2; i >= 0; i--) {
    ost = (temp + decimal->bits[i]) % (unsigned long long)num;
    temp = (temp + decimal->bits[i]) / (unsigned long long)num;
    decimal->bits[i] = (unsigned)temp;
    temp = (ost << 32);
  }
}

int mod_by_num(s21_decimal value, int integer) {
  unsigned long long buf = 0;
  unsigned long long mod = 0;
  for (int i = 2; i >= 0; i--) {
    mod = (buf + value.bits[i]) % integer;
    buf = mod << 32;
  }
  return mod;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int flag = 0;
  if (s21_is_zero(value_2) || s21_is_zero(value_1))
    return flag;
  set_zero(result);
  if (s21_is_less_abs(value_1, value_2))
    swap_decimal(&value_1, &value_2);
  real_mul(value_1, value_2, result);
  // s21_decimal minusone = {{1, 0, 0, 0}};
  
  return flag;
}

int real_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_decimal temp;
  int flag = 0;
  while (!s21_is_zero(value_2)) {
    int mul = mod_by_num(value_2, 10);
    


    div_by_10(&value_2, 1, 0);
  }
  return flag;
}

void copy_decimal(s21_decimal *dest, const s21_decimal src) {
  for(int i = 0; i <= 3; i++){
    dest->bits[i] = src.bits[i];
  }
}

void set_zero(s21_decimal* decimal) {
  for(int i = 0; i <= 3; i++){
    decimal->bits[i] = 0;
  }
}

void swap_decimal(s21_decimal* value_1, s21_decimal* value_2) {
  s21_decimal temp;
  copy_decimal(&temp, *value_1);
  copy_decimal(value_1, *value_2);
  copy_decimal(value_2, temp);
}