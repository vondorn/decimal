#include "decimal.h"

int main() {
  s21_decimal src1, src2;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b01000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  printf("%d\n", s21_is_less(src1, src2));
  printf("%d\n", s21_is_greater(src1, src2));
  // s21_add(src1, src2, &result);
  // print_decimal(result);
  return 0;
}

bool get_sign(s21_decimal decimal) {
  return decimal.bits[3] & NEGATIVE ? 1 : 0;
}

void set_sign(s21_decimal* decimal) {
  decimal->bits[3] |= NEGATIVE;
}

int get_scale(s21_decimal decimal) { return (decimal.bits[3] >> 16) & SCALE; }

void s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  if (get_sign(value_1) && get_sign(value_2)) {
    set_sign(result);
  }
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
    printf("%u", decimal.bits[i]);
    if (!i) printf("\n");
    else printf(".");
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
  if (!get_sign(value_1) && get_sign(value_2)) {
    res = 1;
  } else if (get_scale(value_1) > get_scale(value_2)) {
    res = 1;
  } else {
    for (int i = 0; i < 2; i++) {
      if (value_1.bits[i] < value_2.bits[i])
        res = 1;
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

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  
}