#include "decimal.h"


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

void print_decimal(s21_decimal decimal) {
  if (get_sign(decimal)) printf("-");
  for (int i = 2; i >= 0; i--) {
    to_binary(decimal.bits[i]);
    if (!i) printf("\n");
  }
}

// int s21_from_decimal_to_int(s21_decimal src, int *dst) {
//   for (int i = 2; i >= 0; i--) {
//     *dst += src.bits[i];

//   }
// }