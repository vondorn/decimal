#include "decimal.h"

// int main() {
//   s21_decimal src1;
//   float result = 0;
//   float src2 = -364748;
//   src1.bits[0] = 0b00000000000000000000000010101111;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000000100000000000000000;
//   s21_from_decimal_to_float(src1, &result);
//   print_decimal(src1);
//   if (result >= 0){
//     printf(" ");
//   }
//   printf("   %f\n", result);
//   if (src2 >= 0){
//     printf(" ");
//   }
//   // printf("   %f\n", src2);
//   // int abc = *(int *)(void *)&result;
//   // printf("aboba: %d\n", abc);
//   // int aboba = -2147483648;
//   // printf("0: %u\n", (unsigned)aboba);

//   // s21_sub(src1, src2, &result);

//   // printf("%d\n", get_scale(result));
//   return 0;
// }

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int flag = 0;
  int sign_1 = get_sign(value_1);
  int sign_2 = get_sign(value_2);
  if (sign_1 && sign_2) {
    set_sign(result);
    flag = real_add(value_1, value_2, result);
  } else if (!sign_1 && !sign_2) {
    flag = real_add(value_1, value_2, result);
  } else {
    if (s21_is_less_abs(value_1, value_2)) {
      if (!sign_1 && sign_2) set_sign(result);
      flag = real_sub(value_2, value_1, result);
    } else {
      if (sign_1 && !sign_2) set_sign(result);
      flag = real_sub(value_1, value_2, result);
    }
  }
  return flag;
}

int real_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  decimal_normalization(&value_1, &value_2);
  unsigned long long temp = 0;
  for (int i = 0; i < 3; i++) {
    temp += (unsigned long long)value_1.bits[i] +
            (unsigned long long)value_2.bits[i];
    result->bits[i] = (unsigned)temp;
    temp >>= 32;
  }

  set_scale(result, get_scale(value_1));
  return (int)temp;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_negate(value_2, &value_2);
  return s21_add(value_1, value_2, result);
}

int real_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  decimal_normalization(&value_1, &value_2);
  unsigned long long temp = 0;
  for (int i = 2; i >= 0; i--) {
    temp = temp + (unsigned long long)value_1.bits[i] -
            (unsigned long long)value_2.bits[i];
    if (value_1.bits[i] < value_2.bits[i]) {
      result->bits[i+1]--;
    }
    result->bits[i] = (unsigned)temp;
    temp <<= 32;
  }
  set_scale(result, get_scale(value_1));
  return (int)temp;
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
  for (; scale_big > *scale_little; (*scale_little)++) {
    if (s21_is_less_abs(*decimal, top_decimal) ||
        s21_is_equal(*decimal, top_decimal)) {
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
  int overcut[30] = {0};
  int i = 0;
  for (; *scale_big > scale_little; (*scale_big)--, i++) {
    overcut[i] = mod_by_num(*decimal, 10);
    div_by_num(decimal, 10);
  }
  real_round(decimal, overcut, i);
  return flag;
}

int real_round(s21_decimal *value, int *overcut, int overcut_size) {
  int flag_bank = 0;
  if (overcut[--overcut_size] == 5) {
    for (; overcut_size >= 0; --overcut_size) {
      if (overcut[overcut_size]) {
        flag_bank = 2;
        break;
      }
    }
    if (flag_bank != 2) flag_bank = 1;
  } else if (overcut[overcut_size] > 5) {
    flag_bank = 2;
  }
  if ((flag_bank == 1 && !mod_by_num(*value, 2)) || flag_bank == 2) {
    s21_decimal plusone = {{1, 0, 0, value->bits[3]}};
    s21_add(*value, plusone, value);
  }
  return flag_bank;
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

int s21_floor(s21_decimal value, s21_decimal *result) {
  if (!correct_decimal(value) && get_scale(value) > 0 && get_sign(value) && !s21_is_zero(value) && result != NULL){
    s21_decimal plusone = {0};
    plusone.bits[0] = 1;
    plusone.bits[3] = 0b10000000000000000000000000000000;
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

int s21_from_float_to_decimal(float src, s21_decimal *dst){
  int return_value = 0;
  if (dst != NULL && src < MAXFLOAT && src != INFINITY){
    long int beforepoint = (long int)src;
    if (src < 0) beforepoint *= -1;
    // printf("%ld\n", beforepoint);
    long int afterpoint = 0;
    bool flag = 0;
    char temp[75];
    sprintf(temp, "%7f", src);
    int j = 5;
    for(int i = 0; j >= 0; i++){
      if(flag == 1){
        afterpoint += (temp[i] - '0') * pow(10, j);
        j--;
      }
      else if(temp[i] == '.'){
        flag = 1;
      }
    }
    unsigned long int total = (beforepoint * 1000000) + afterpoint;
    for (int i = 1; i < 4; i++) {
      dst->bits[i] = 0;
    }
    dst->bits[0] = total;
    dst->bits[3] = (6 << 16);
    if (src < 0) set_sign(dst);
  }
  else if (dst != NULL) {
    s21_decimal zero = {0};
    copy_decimal(dst, zero);
    return_value = 1;
  } else
    return_value = 1;
  return return_value;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst){
  int return_value = 0;
  bool flag = s21_truncate(src, &src);
  if(dst != NULL && flag == 0 && (src.bits[1] == 0 && src.bits[2] == 0 && src.bits[0] < 2147483648)) {
    *dst = src.bits[0];
    if(get_sign(src)) *dst *= -1;
  }
  else
    return_value = 1;
  return return_value;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst){
  int return_value = 0;
  if(dst != NULL && !correct_decimal(src) && !s21_is_zero(src)){
    int scale = get_scale(src);
    int temp = 0;
    for (int i = scale; i > 0; i--) {
      temp = mod_by_num(src, 10);
      div_by_num(&src, 10);
      *dst += temp * pow(10, -i);
    } 
    for (int i = 0; i < 29; i++) {
      temp = mod_by_num(src, 10);
      div_by_num(&src, 10);
      *dst += i == 0 ? temp : temp * pow(10, i);
    } 
    *dst += temp;
    if(get_sign(src)) *dst *= -1;
  } else if (dst != NULL && !correct_decimal(src) && s21_is_zero(src)){
    *dst = -0;
  } else return_value = 1;
  return return_value;
}

int mod_by_num(s21_decimal value, int integer) {
  unsigned long long buf = 0;
  unsigned long long mod = 0;
  for (int i = 2; i >= 0; i--) {
    mod = (buf + value.bits[i]) % integer;
    buf = mod << 32;
  }
  return mod;
}

void decimal_inversion(s21_decimal decimal, s21_decimal* result) {
  for (int i = 0; i < 3; i++) result->bits[i] = ~decimal.bits[i];
  unsigned long long buf = 1ull;
  for (int i = 0; i < 3; i++) {
    buf += (unsigned long long)result->bits[i];
    result->bits[i] = (unsigned)buf;
    buf >>= 32;
  }
}
