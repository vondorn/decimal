#include <stdio.h>

#include "s21_decimal.h"

int main(){
  s21_decimal value_1, value_2;
  value_1.bits[0] = 0b10011100010000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  value_2.bits[0] = 0b10001;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_long_decimal value_1long, value_2long;
  convert_to_long(value_1, &value_1long);
  convert_to_long(value_2, &value_2long);
  s21_long_decimal to_use = value_2long;
  int k = 1, i = -1, j = 0, result = 0;
  while(!s21_is_zero_long(value_2long)){
    i = -1, j = 0;
    copy_long_decimal(&to_use, value_2long);

    if (s21_is_zero_long(value_1long) || s21_is_less_long(value_1long, value_2long)){
      break;
    }
    while(!s21_is_less_long(value_1long, to_use)){
      mult_by_num_long(to_use, &to_use, 10);
      i++;
    }
    if (i >= 0) div_by_num_long(&to_use, 10);
    s21_long_decimal temp_to_use = to_use;
    while(!s21_is_less_long(value_1long, to_use)){
      real_add_long(to_use, temp_to_use, &to_use);
      j++;
    }
    real_sub_long(to_use, temp_to_use, &to_use);
    real_sub_long(value_1long, to_use, &value_1long);
    i = pow(10, i);
    j = j * i;
    printf("i: %d\n", i);
    printf("j: %d\n", j);
    result += j;
  }
  printf("result: %d", result);
}