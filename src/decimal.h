#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define NEGATIVE 0x80000000
#define SCALE 0xff

typedef struct {
  unsigned bits[4];
} s21_decimal;
bool get_sign(s21_decimal decimal);
int get_scale(s21_decimal decimal);
void s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void print_decimal(s21_decimal decimal);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);