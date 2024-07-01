#include "decimal.h"

int main() {
  s21_decimal src1, src2;
  
  src1.bits[0] = 0b110010;
  src1.bits[1] = 0b11111110;
  src1.bits[2] = 0;
  src1.bits[3] = 0b1100000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;

  // print_decimal(src1);
  // print_decimal(src2);
  // printf("%d - %d\n", get_scale(src1), get_scale(src2));
  // s21_add(src1, src2, &result);
  // print_decimal(result);
  // printf("%d\n", get_scale(result));
  // s21_floor(src1, &src2);
  // s21_truncate(src1, &src2);
  // s21_round(src1, &src2);
  print_decimal(src1);
  print_decimal(src2);
  return 0;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int flag = 0;
  int sign_1 = get_sign(value_1);
  int sign_2 = get_sign(value_2);
  if (sign_1 && sign_2) {
    set_sign(result);
    flag = real_add(value_1, value_2, result);
  } else if (!sign_1 && sign_2) {
    flag = s21_sub(value_2, value_1, result);
  } else if (sign_1 && !sign_2) {
    flag = s21_sub(value_1, value_2, result);    
  }
  return flag;
}

int real_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  decimal_normalization(&value_1, &value_2);
  unsigned long long temp = 0;
  for (int i = 0; i < 3; i++) {
    temp += (unsigned long long)value_1.bits[i] + (unsigned long long)value_2.bits[i];
    result->bits[i] = (unsigned)temp;
    temp >>= 32;
  }
  set_scale(result, get_scale(value_1));
  return (int)temp;
} 

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)   {
  int flag = 0;
  // if (get_sign(value_1) && get_sign(value_2)) {
  //   
  // }
  decimal_normalization(&value_1, &value_2);
  unsigned long long temp = 0;
  for (int i = 2; i >= 0; i--) {
    temp += (unsigned long long)value_1.bits[i] - (unsigned long long)value_2.bits[i];
    result->bits[i] = (unsigned)temp;
    temp <<= 32;
  }
  set_scale(result, get_scale(value_1));
  if (temp) flag = 1;

  return flag;
}

void decimal_normalization(s21_decimal* value_1, s21_decimal* value_2) {
  int flag_overflow = 0;
  int scale_1 = get_scale(*value_1);
  int scale_2 = get_scale(*value_2);
  while (scale_1 != scale_2) {
    if (scale_1 > scale_2 && !flag_overflow) {
      flag_overflow = mult_by_10(value_2, scale_1, &scale_2);
    } else if (scale_1 > scale_2 && flag_overflow) {
      div_by_10(value_1, &scale_1, scale_2);
    }
    if (scale_2 > scale_1 && !flag_overflow) {
      flag_overflow = mult_by_10(value_1, scale_2, &scale_1);
    } else if (scale_2 > scale_1 && flag_overflow) {
      div_by_10(value_2, &scale_2, scale_1);
    }
  }
  set_scale(value_2, scale_2);
  set_scale(value_1, scale_1);
}


bool mult_by_10(s21_decimal* decimal, int scale_big, int* scale_little) {
  bool flag = 0;
  s21_decimal top_decimal;
  top_decimal.bits[0] = 0b10011001100110011001100110011001;
  top_decimal.bits[1] = 0b10011001100110011001100110011001;
  top_decimal.bits[2] = 0b00011001100110011001100110011001;
  top_decimal.bits[3] = decimal->bits[3];
  for (;scale_big > *scale_little; (*scale_little)++) {
    if (s21_is_less_or_equal(*decimal, top_decimal)) {
      mult_by_num(decimal, 10);
    } else {
      flag = 1;
      break;
    }
  }
  return flag;
}

void mult_by_num(s21_decimal* decimal, int num) {
  unsigned long long temp = 0;
  for (int i = 0; i < 3; i++) { 
    temp += (unsigned long long)decimal->bits[i] * (unsigned long long)num;
    decimal->bits[i] = (unsigned)temp;
    temp >>= 32;
  }
}

bool div_by_10(s21_decimal* decimal, int* scale_big, int scale_little) {
  bool flag = 0;
  for (;*scale_big > scale_little; (*scale_big)--) {
    div_by_num(decimal, 10);
  }
  return flag;
}

void div_by_num(s21_decimal* decimal, int num) {
  unsigned long long ost = 0;
  unsigned long long temp = 0;
  for (int i = 2; i >= 0; i--) {
    ost = (temp + decimal->bits[i]) % (unsigned long long)num;
    temp = (temp + decimal->bits[i]) / (unsigned long long)num;
    decimal->bits[i] = (unsigned)temp;
    temp = (ost << 32);
  }
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  s21_decimal bottom_decimal = {0};
  bottom_decimal.bits[2] = 4294967295;
  int return_value;
  if (!correct_decimal(value)){
    decimal_normalization(&value, &bottom_decimal);
    copy_decimal(result, value);
    return_value = 0;
  }
  else {
    return_value = 1;
  }
  return return_value;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  if (!correct_decimal(value) && get_scale(value) > 0 && get_sign(value) == 1){
    s21_decimal plusone = {0};
    plusone.bits[0] = 1;
    s21_add(value, plusone, result);
  }
  return s21_truncate(*result, result);
}

// int s21_round(s21_decimal value, s21_decimal *result) {
//   int scale = get_scale(value);
//   if (!correct_decimal(value) && scale > 0){
//     if (get_sign(value) == 0){
//       s21_decimal half = {0};
//       s21_decimal temp = {0};
//       s21_decimal afterpoint = {0};
//       half.bits[0] = 0b110010;
//       half.bits[3] = 0b100000000000000000; //0.5
//       s21_truncate(value, &temp);
//       s21_sub(value, temp, &afterpoint);
//       div_by_num(&afterpoint, scale - 1);
//       print_decimal(afterpoint);
//       if (s21_is_greater(afterpoint, half)){
//         // result = value + 1
//         s21_decimal plusone = {0};
//         plusone.bits[0] = 1;
//         s21_add(value, plusone, result);
//         s21_truncate(*result, result);
//       }
//       else if (s21_is_less(temp, half)){

//       }
//       else {
    
//       }
//       // print_decimal(temp);
//       // s21_truncate(temp, &temp);
//       // print_decimal(temp);
//     }
//   }

//   return s21_truncate(*result, result);
// }

void copy_decimal(s21_decimal *dest, const s21_decimal src) {
  for(int i = 0; i <= 3; i++){
    dest->bits[i] = src.bits[i];
  }
}

bool correct_decimal(s21_decimal value) {
  bool return_value = 1;
  int scale = get_scale(value);
  if (scale >= 0 && scale <= 28)
    return_value = (value.bits[3] | POSSIBLE) & (~POSSIBLE);
  return return_value;
}