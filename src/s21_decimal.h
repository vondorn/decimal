#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NEGATIVE 0x80000000
#define SCALE 0xff
#define POSSIBLE 0x80ff0000
#define MAX 0xffffffff

typedef struct {
  unsigned bits[4];
} s21_decimal;

typedef struct {
  unsigned bits[8];
} s21_long_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_abs(s21_decimal value_1, s21_decimal value_2);
int s21_is_zero(s21_decimal value);

int s21_from_int_to_decimal(int src, s21_decimal* dst);
int s21_from_float_to_decimal(float src, s21_decimal* dst);
int s21_from_decimal_to_int(s21_decimal src, int* dst);
int s21_from_decimal_to_float(s21_decimal src, float* dst);

bool get_sign(s21_decimal decimal);
void set_sign(s21_decimal* decimal);
int get_scale(s21_decimal decimal);
void set_scale(s21_decimal* decimal, int scale);
void decimal_normalization(s21_decimal* value_1, s21_decimal* value_2);
void set_zero(s21_decimal* decimal);
void cut_zero(s21_decimal* decimal);

int s21_floor(s21_decimal value, s21_decimal* result);
int s21_round(s21_decimal value, s21_decimal* result);
int s21_truncate(s21_decimal value, s21_decimal* result);
int s21_negate(s21_decimal value, s21_decimal* result);

int real_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int real_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int real_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int real_round(s21_decimal* value, int* overcut, int overcut_size);

void print_decimal(s21_decimal decimal);
void copy_decimal(s21_decimal* dest, const s21_decimal src);
void swap_decimal(s21_decimal* value_1, s21_decimal* value_2);

void mult_by_num(s21_decimal decimal, s21_decimal* result, int num);
bool mult_by_10(s21_decimal* decimal, int scale_big, int* scale_little);
void div_by_num(s21_decimal* decimal, int num);
bool div_by_10(s21_decimal* decimal, int* scale_big, int scale_little);
int mod_by_num(s21_decimal value, int integer);

void to_binary(unsigned n);
bool correct_decimal(s21_decimal value);
10000000000000000000000000000
void convert_to_long(s21_decimal decimal, s21_long_decimal* long_decimal);
int convert_from_long(s21_decimal* decimal, s21_long_decimal long_decimal);
void print_long_decimal(s21_long_decimal decimal);
int get_scale_long(s21_long_decimal decimal);
void div_by_num_long(s21_long_decimal* decimal, int num);
bool div_by_10_long(s21_long_decimal* decimal, int* scale_big,
                    int scale_little);
int mod_by_num_long(s21_long_decimal value, int integer);
void set_scale_long(s21_long_decimal* decimal, int scale);
int count_digits_long(s21_long_decimal decimal);
int s21_is_zero_long(s21_long_decimal value);
int s21_is_less_long(s21_long_decimal value_1, s21_long_decimal value_2);
void real_add_long(s21_long_decimal value_1, s21_long_decimal value_2,
                  s21_long_decimal* result);
void mult_by_num_long(s21_long_decimal decimal, s21_long_decimal* result,
                      int num);
int real_round_long(s21_long_decimal* value, int* overcut, int overcut_size);
int real_sub_long(s21_long_decimal value_1, s21_long_decimal value_2, s21_long_decimal* result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
void real_div(s21_long_decimal value_1, s21_long_decimal value_2, s21_long_decimal* result);
void copy_long_decimal(s21_long_decimal* dest, const s21_long_decimal src);
void decimal_normalization_long(s21_long_decimal* value_1, s21_long_decimal* value_2);
int s21_is_greater_long(s21_long_decimal value_1, s21_long_decimal value_2);
/*
10000000000000000000000000000
00000000000000000000000000001

+ & +
- & +
+ & -
- & - ok

*/

// 1.4855280472607053437301170471
// 0002963757959488.7909114781715
// 2963757959490.2764395254322053

// https://findhow.org/5372-kalkulyator-bolshih-chisel.html