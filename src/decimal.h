#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define NEGATIVE 0x80000000
#define SCALE 0xff
#define POSSIBLE 0x80ff0000

typedef struct {
  unsigned bits[4];
} s21_decimal;

bool get_sign(s21_decimal decimal);
void set_sign(s21_decimal* decimal);
int get_scale(s21_decimal decimal);
void set_scale(s21_decimal* decimal, int scale);
void decimal_normalization(s21_decimal* value_1, s21_decimal* value_2);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int real_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
void print_decimal(s21_decimal decimal);

int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);

int s21_negate(s21_decimal value, s21_decimal *result);

void mult_by_num(s21_decimal* decimal, int num);
bool mult_by_10(s21_decimal* decimal, int scale_big, int* scale_little);
void div_by_num(s21_decimal* decimal, int num);
bool div_by_10(s21_decimal* decimal, int* scale_big, int scale_little);

void to_binary(unsigned n);
void copy_decimal(s21_decimal *dest, const s21_decimal src);
bool correct_decimal(s21_decimal value);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);






















// 1.4855280472607053437301170471
// 0002963757959488.7909114781715
// 2963757959490.2764395254322053

// https://findhow.org/5372-kalkulyator-bolshih-chisel.html