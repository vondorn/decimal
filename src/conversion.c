#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  dst->bits[0] = abs(src);
  for (int i = 1; i < 4; i++) {
    dst->bits[i] = 0;
  }
  dst->bits[3] = src & NEGATIVE;
  return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int return_value = 0;
  if (dst != NULL && src < MAXFLOAT && src != INFINITY) {
    long int beforepoint = (long int)src;
    if (src < 0) beforepoint *= -1;
    long int afterpoint = 0;
    bool flag = 0;
    char temp[75];
    sprintf(temp, "%7f", src);
    int j = 5;
    for (int i = 0; j >= 0; i++) {
      if (flag == 1) {
        afterpoint += (temp[i] - '0') * pow(10, j);
        j--;
      } else if (temp[i] == '.') {
        flag = 1;
      }
    }
    unsigned long int total = (beforepoint * 1000000) + afterpoint;
    for (int i = 1; i < 4; i++) {
      dst->bits[i] = 0;
    }
    dst->bits[0] = total;
    dst->bits[3] = (6 << 16);
    if (src < 0) set_sign(dst);
  } else if (dst != NULL) {
    set_zero(dst);
    return_value = 1;
  } else
    return_value = 1;
  return return_value;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int return_value = 0;
  bool flag = s21_truncate(src, &src);
  if (dst != NULL && flag == 0 &&
      (src.bits[1] == 0 && src.bits[2] == 0 && src.bits[0] < 2147483648)) {
    *dst = src.bits[0];
    if (get_sign(src)) *dst *= -1;
  } else
    return_value = 1;
  return return_value;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int return_value = 0;
  if (dst != NULL && !correct_decimal(src)) {
    int scale = get_scale(src);
    int temp = 0;
    *dst = 0;
    for (int i = scale; i > 0; i--) {
      temp = mod_by_num(src, 10);
      div_by_num(&src, 10);
      *dst += temp * pow(10, -i);
    }
    for (int i = 0; i < 29; i++) {
      temp = mod_by_num(src, 10);
      div_by_num(&src, 10);
      *dst += i == 0 ? temp : temp * pow(10, i);
    }
    *dst += temp;
    if (get_sign(src)) *dst *= -1;
  } else
    return_value = 1;
  return return_value;
}