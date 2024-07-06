#include <stdio.h>

#include "s21_decimal.h"

int main() {
  s21_decimal value_1, value_2;
  value_1.bits[0] = 0b11000000111001;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  value_2.bits[0] = 0b1001110;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;

  s21_decimal result = {0};
  s21_div(value_1, value_2, &result);
  print_decimal(result);
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_long_decimal value_1long, value_2long;
  convert_to_long(value_1, &value_1long);
  convert_to_long(value_2, &value_2long);
  s21_long_decimal to_use1 = value_1long;
  s21_long_decimal to_use2 = value_2long;
  s21_decimal temp_result = {0};
  int i = -1, j = 0, aaa = 1, k = 0;
  while (!s21_is_zero_long(value_2long)) {
    int zero = 0;
    i = -1, j = 0;
    copy_long_decimal(&to_use2, value_2long);
    copy_long_decimal(&to_use1, value_1long);
    if (!s21_is_zero_long(value_1long) &&
        !s21_is_less_long(value_1long, value_2long) && k < 2) {
      while (!s21_is_less_long(value_1long, to_use2)) {
        mult_by_num_long(to_use2, &to_use2, 10);
        i++;
      }
      if (i >= 0) div_by_num_long(&to_use2, 10);
      s21_long_decimal temp_to_use2 = to_use2;
      while (!s21_is_less_long(value_1long, to_use2)) {
        real_add_long(to_use2, temp_to_use2, &to_use2);
        j++;
      }
      if (j > 0) real_sub_long(to_use2, temp_to_use2, &to_use2);
      real_sub_long(value_1long, to_use2, &value_1long);
      s21_from_int_to_decimal(j, &temp_result);
      mult_by_10(&temp_result, i, &zero);
      real_add(*result, temp_result, result);
    } else if (((!s21_is_zero_long(value_1long) &&
                 s21_is_less_long(value_1long, value_2long)) ||
                k >= 2) &&
               aaa < 25) {
      k = 0;
      while (s21_is_less_long(to_use1, value_2long)) {
        mult_by_num_long(to_use1, &to_use1, 10);
        k++;
      }
      if (k < 2) {
        while (!s21_is_less_long(to_use1, to_use2)) {
          mult_by_num_long(to_use2, &to_use2, 10);
          i++;
        }
        if (i <= 0) div_by_num_long(&to_use2, 10);
        s21_long_decimal temp_to_use2 = to_use2;
        while (!s21_is_less_long(to_use1, to_use2)) {
          real_add_long(to_use2, temp_to_use2, &to_use2);
          j++;
        }
        if (j > 0) real_sub_long(to_use2, temp_to_use2, &to_use2);
        real_sub_long(to_use1, to_use2, &to_use1);
        if (i == 0) i = 1;
        copy_long_decimal(&value_1long, to_use1);
        s21_from_int_to_decimal(j, &temp_result);
        set_scale(&temp_result, aaa);
        real_add(*result, temp_result, result);
      } else
        copy_long_decimal(&value_1long, to_use1);
      aaa++;
    } else
      break;
  }
  return 0;
}