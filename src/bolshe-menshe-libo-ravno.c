#include "decimal.h"

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