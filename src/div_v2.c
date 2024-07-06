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
  s21_long_decimal to_use1 = value_1long;
  s21_long_decimal to_use2 = value_2long;
  double k = 1, i = -1, j = 0;
   double result = 0;
   int aaa = 1;
  while(!s21_is_zero_long(value_2long)){
    i = -1, j = 0;
    copy_long_decimal(&to_use2, value_2long);
    copy_long_decimal(&to_use1, value_1long);
    if (!s21_is_zero_long(value_1long) && !s21_is_less_long(value_1long, value_2long)){
      while(!s21_is_less_long(value_1long, to_use2)){
        mult_by_num_long(to_use2, &to_use2, 10);
        i++;
      }
      if (i >= 0) div_by_num_long(&to_use2, 10);
      s21_long_decimal temp_to_use2 = to_use2;
      while(!s21_is_less_long(value_1long, to_use2)){
        real_add_long(to_use2, temp_to_use2, &to_use2);
        j++;
      }
      if (j > 0) real_sub_long(to_use2, temp_to_use2, &to_use2);
      real_sub_long(value_1long, to_use2, &value_1long);
      i = pow(10, i);
      j = j * i;
      printf("i: %lf\n", i);
      printf("j: %lf\n", j);
      result += j;
    } else if (!s21_is_zero_long(value_1long) && s21_is_less_long(value_1long, value_2long) && aaa < 10){
      while(s21_is_less_long(to_use1, value_2long)){
        mult_by_num_long(to_use1, &to_use1, 10);
        // i++;
      }
      while(!s21_is_less_long(to_use1, to_use2)){
        mult_by_num_long(to_use2, &to_use2, 10);
        i--;
      }
      print_long_decimal(to_use2);
      if (i <= 0) div_by_num_long(&to_use2, 10);
      print_long_decimal(to_use1);
      s21_long_decimal temp_to_use2 = to_use2;
      while(!s21_is_less_long(to_use1, to_use2)){
        real_add_long(to_use2, temp_to_use2, &to_use2);
        j++;
      }
      if (j > 0) real_sub_long(to_use2, temp_to_use2, &to_use2);
      real_sub_long(to_use1, to_use2, &to_use1);
      if (i == 0) i *= 0.1;
      copy_long_decimal(&value_1long, to_use1);
      i = pow(10, -aaa);
      printf("-i: %lf\n", i);
      j = j * i;
      result += j;
      printf("-j: %lf\n", j);
      aaa++;
    } else break;
  }
  printf("result: %lf", result);
}