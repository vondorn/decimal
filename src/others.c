#include "decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  if (!correct_decimal(value) && get_scale(value) > 0 && get_sign(value) && !s21_is_zero(value) && result != NULL){
    s21_decimal plusone = {0};
    plusone.bits[0] = 1;
    plusone.bits[3] = NEGATIVE;
    s21_add(value, plusone, &value);
  }
  return s21_truncate(value, result);
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int return_value = 0;
  if(!correct_decimal(value) && result != NULL){
    int scale = get_scale(value);
    if (scale > 0){
      div_by_10(&value, &scale, 0);
      set_scale(&value, 0);
    }
    copy_decimal(result, value);
  } else return_value = 1;
  return return_value;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int return_value;
  if (!correct_decimal(value) && result != NULL){
    int scale = get_scale(value);
    if (scale > 0){
      for (int i = 0; scale > 0; scale--, i++) {
        div_by_num(&value, 10);
      }
      set_scale(&value, 0);
    }
    copy_decimal(result, value);
    return_value = 0;
  } else return_value = 1;
  return return_value;
}

int s21_negate(s21_decimal value, s21_decimal* result) {
  for (int i = 0; i < 3; i++) {
    result->bits[i] = value.bits[i];
  }
  result->bits[3] = (value.bits[3] ^ NEGATIVE);
  return 0;
}