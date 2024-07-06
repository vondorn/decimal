#include "s21_decimal.h"

int main() {
  s21_decimal result, src1, src2;
  // origin.bits[0] = 0b10010010000001100111100010100101;
  // origin.bits[1] = 0b10001011011010100100100011011111;
  // origin.bits[2] = 0b00011100010100011001001100010001;
  // origin.bits[3] = 0b00000000000100010000000000000000;
  src1.bits[0] = 0b100010001110000;
  src1.bits[1] = 0b000000000000000000000000000000000;
  src1.bits[2] = 0b000000000000000000000000000000000;
  src1.bits[3] = 0b000000000000000000000000000000000;
  src2.bits[0] = 0b10101;
  src2.bits[1] = 0b000000000000000000000000000000000;
  src2.bits[2] = 0b000000000000000000000000000000000;
  src2.bits[3] = 0b000000000000000000000000000000000;
  // s21_long_decimal example;
  // example.bits[0] = 0b10000010111000100101101011101101;
  // example.bits[1] = 0b11111001111010000010010110101101;987879878910
  // example.bits[2] = 0b10110000001111101111000010010100;
  // example.bits[3] = 0b10000010000011110000010010100000;
  // example.bits[4] = 0b10000010111000100101101011101101;
  // example.bits[5] = 0b11111001111010000010010110101101;
  // example.bits[6] = 0b00000000000000000000000000000000;
  // example.bits[7] = 0b00000000001010000000000000000000;
  print_decimal(src1);
  print_decimal(src2);
  printf("\n\n");
  // decimal_normalization(&src1, &src2);
  // print_decimal(src1);
  // print_decimal(src2);

  s21_div(src1, src2, &result);
  // s21_sub(src1, src2, &result);
  printf("\n\n");
  print_decimal(result);
  // convert_to_long(origin, &example);
  // convert_from_long(&src, example);
  // print_long_decimal(example);
  // print_decimal(src);
  // printf("%d\n", get_scale(result));
  return 0;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int flag = 0;
  if (s21_is_zero(value_2)) {
    flag = 3;
  } else if (!s21_is_zero(value_1)) {
    s21_long_decimal long_val_1, long_val_2, result_long = {0};
    convert_to_long(value_1, &long_val_1);
    convert_to_long(value_2, &long_val_2);
    real_div(long_val_1, long_val_2, &result_long);
    flag = convert_from_long(result, result_long);
  }
  return flag;
}

void real_div(s21_long_decimal value_1, s21_long_decimal value_2, s21_long_decimal* result) {
  s21_long_decimal digit = {0};
  int count = 0, result_scale = 0;
  s21_long_decimal temp, temp_2;
  while (!s21_is_zero_long(value_1) && count < 40) {
    copy_long_decimal(&temp, value_2);
    int re = 0, we = 1, qe = 0;
    while(s21_is_less_long(temp, value_1)) {
      mult_by_num_long(temp, &temp, 10);
      re++;
    }
    if (re) {
      div_by_num_long(&temp, 10);
      re--;
    }
    copy_long_decimal(&temp_2, temp);
    while (s21_is_less_long(temp, value_1)) {
      real_add_long(temp_2, temp, &temp);
      we++;
    }
    if (we > 1) {
      real_sub_long(temp, temp_2, &temp);
      we--;
    }
    real_sub_long(value_1, temp, &value_1);
    digit.bits[0] = we;
    mult_by_num_long(*result, result, 10);
    real_add_long(digit, *result, result);
    count++;
    if (!result_scale && s21_is_less_long(value_1, value_2))
      result_scale = count;
    while (s21_is_less_long(value_1, value_2)) {
       mult_by_num_long(value_1, &value_1, 10);
       qe++;
       if (qe > 1) {
        count++;
        mult_by_num_long(*result, result, 10);
       }
    }
  }
  set_scale_long(result, count-result_scale);
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int flag = 0, sign_flag = 0;
  int sign_1 = get_sign(value_1);
  int sign_2 = get_sign(value_2);
  s21_long_decimal long_val_1, long_val_2, result_long = {0};
  convert_to_long(value_1, &long_val_1);
  convert_to_long(value_2, &long_val_2);
  decimal_normalization_long(&long_val_1, &long_val_2);
  if (sign_1 && sign_2) {
    sign_flag = 1;
    flag = real_add_long(long_val_1, long_val_2, &result_long);
  } else if (!sign_1 && !sign_2) {
    flag = real_add_long(long_val_1, long_val_2, &result_long);
  } else {
    if (s21_is_less_long(long_val_1, long_val_2)) {
      if (!sign_1 && sign_2) sign_flag = 1;
      flag = real_sub_long(long_val_2, long_val_1, &result_long);
    } else {
      if (sign_1 && !sign_2) sign_flag = 1;
      flag = real_sub_long(long_val_1, long_val_2, &result_long);
    }
  }
  convert_from_long(result, result_long);
  if (sign_flag) set_sign(result);
  if (flag && sign_flag) flag = 2;
  if (flag) set_zero(result);
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
  return temp ? 1 : 0;
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
      result->bits[i + 1]--;
    }
    result->bits[i] = (unsigned)temp;
    temp <<= 32;
  }
  set_scale(result, get_scale(value_1));
  return (int)temp;
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
  int overcut[30] = {0};
  int i = 0;
  for (; *scale_big > scale_little; (*scale_big)--, i++) {
    overcut[i] = mod_by_num(*decimal, 10);
    div_by_num(decimal, 10);
  }
  real_round(decimal, overcut, i);
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
  cut_zero(&value_1);
  cut_zero(&value_2);
  set_zero(result);
  if (s21_is_zero(value_2) || s21_is_zero(value_1)) return flag;
  if (s21_is_less_abs(value_1, value_2)) swap_decimal(&value_1, &value_2);
  flag = real_mul(value_1, value_2, result);
  if ((get_sign(value_1) + get_sign(value_2) == 1) && !flag) set_sign(result);

  return flag;
}

int real_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_long_decimal long_val_1, long_val_2, result_long = {0};
  convert_to_long(value_1, &long_val_1);
  convert_to_long(value_2, &long_val_2);
  s21_long_decimal temp;
  int flag = 0;
  int count = 0;
  while (!s21_is_zero_long(long_val_2)) {
    int mul = mod_by_num_long(long_val_2, 10);
    mult_by_num_long(long_val_1, &temp, mul);
    for (int i = 0; i < count; i++) {
      mult_by_num_long(temp, &temp, 10);
    } 
    real_add_long(temp, result_long, &result_long);
    div_by_num_long(&long_val_2, 10);
    count++;
  }
  // if (flag) set_zero(result);
  set_scale_long(&result_long,
                 get_scale_long(long_val_1) + get_scale_long(long_val_2));
  convert_from_long(result, result_long);
  return flag;
}

void convert_to_long(s21_decimal decimal, s21_long_decimal* long_decimal) {
  for (int i = 0; i < 8; i++) {
    long_decimal->bits[i] = 0;
  }
  for (int i = 0; i < 3; i++) {
    long_decimal->bits[i] = decimal.bits[i];
  }
  long_decimal->bits[7] = decimal.bits[3];
}

int convert_from_long(s21_decimal* decimal, s21_long_decimal long_decimal) {
  int flag = 0;
  int scale_long = get_scale_long(long_decimal);
  s21_long_decimal top = {{MAX, MAX, MAX, 0, 0, 0, 0, 0}};
  int overcut[60] = {0};
  int i = 0;
  while (s21_is_less_long(top, long_decimal) || scale_long > 28) {
    overcut[i++] = mod_by_num_long(long_decimal, 10);
    div_by_num_long(&long_decimal, 10);
    set_scale_long(&long_decimal, --scale_long);
    if (scale_long < 0) flag = 1;
  }
  if (i) real_round_long(&long_decimal, overcut, --i);
  for (int i = 0; i < 3; i++) {
    decimal->bits[i] = long_decimal.bits[i];
  }
  decimal->bits[3] = scale_long << 16;
  return flag;
}

int get_scale_long(s21_long_decimal decimal) {
  return (decimal.bits[7] >> 16) & SCALE;
}

void div_by_num_long(s21_long_decimal* decimal, int num) {
  unsigned long long ost = 0;
  unsigned long long temp = 0;
  for (int i = 6; i >= 0; i--) {
    ost = (temp + decimal->bits[i]) % (unsigned long long)num;
    temp = (temp + decimal->bits[i]) / (unsigned long long)num;
    decimal->bits[i] = (unsigned)temp;
    temp = (ost << 32);
  }
}

int mod_by_num_long(s21_long_decimal value, int integer) {
  unsigned long long buf = 0;
  unsigned long long mod = 0;
  for (int i = 6; i >= 0; i--) {
    mod = (buf + value.bits[i]) % integer;
    buf = mod << 32;
  }
  return mod;
}

void set_scale_long(s21_long_decimal* decimal, int scale) {
  decimal->bits[7] = scale << 16;
}

int count_digits_long(s21_long_decimal decimal) {
  int i = 0;
  while (!s21_is_zero_long(decimal)) {
    i++;
    div_by_num_long(&decimal, 10);
  }
  return i;
}

int s21_is_zero_long(s21_long_decimal value) {
  int res = 1;
  for (int i = 6; i >= 0; i--) {
    if (value.bits[i]) {
      res = 0;
    }
  }
  return res;
}

int s21_is_less_long(s21_long_decimal value_1, s21_long_decimal value_2) {
  int res = 0;
  for (int i = 6; i >= 0; i--) {
    if (value_1.bits[i] < value_2.bits[i]) {
      res = 1;
    } else if (value_1.bits[i] > value_2.bits[i])
      break;
  }
  return res;
}

int real_add_long(s21_long_decimal value_1, s21_long_decimal value_2,
                  s21_long_decimal* result) {
  // decimal_normalization(&value_1, &value_2);
  unsigned long long temp = 0;
  for (int i = 0; i < 7; i++) {
    temp += (unsigned long long)value_1.bits[i] +
            (unsigned long long)value_2.bits[i];
    result->bits[i] = (unsigned)temp;
    temp >>= 32;
  }
  set_scale_long(result, get_scale_long(value_1));
  return temp ? 1 : 0;
}

void mult_by_num_long(s21_long_decimal decimal, s21_long_decimal* result,
                      int num) {
  unsigned long long temp = 0;
  for (int i = 0; i < 7; i++) {
    temp += (unsigned long long)decimal.bits[i] * (unsigned long long)num;
    result->bits[i] = (unsigned)temp;
    temp >>= 32;
  }
}

int real_round_long(s21_long_decimal* value, int* overcut, int overcut_size) {
  int flag_bank = 0;
  if (overcut[overcut_size] == 5) {
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
  if ((flag_bank == 1 && !mod_by_num_long(*value, 2)) || flag_bank == 2) {
    s21_long_decimal plusone = {{1, 0, 0, value->bits[3]}};
    real_add_long(*value, plusone, value);
  }
  return flag_bank;
}

int real_sub_long(s21_long_decimal value_1, s21_long_decimal value_2, s21_long_decimal* result) {
  unsigned long long temp = 0;
  for (int i = 6; i >= 0; i--) {
    temp = temp + (unsigned long long)value_1.bits[i] -
           (unsigned long long)value_2.bits[i];
    if (value_1.bits[i] < value_2.bits[i]) {
      result->bits[i + 1]--;
    }
    result->bits[i] = (unsigned)temp;
    temp <<= 32;
  }
  set_scale_long(result, get_scale_long(value_1));
  return (int)temp;
}

void copy_long_decimal(s21_long_decimal* dest, const s21_long_decimal src) {
  for (int i = 0; i < 7; i++) {
    dest->bits[i] = src.bits[i];
  }
}
