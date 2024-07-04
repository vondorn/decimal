#include <check.h>

#include "s21_decimal.h"

// START_TEST(){

// } END_TEST

START_TEST(s21_add1) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = 96714065591710322362983.04
  // src2 = 2251937252639360
  src1.bits[0] = 0b00000000000110100001000001000000;
  src1.bits[1] = 0b00000000000010000000001000000000;
  src1.bits[2] = 0b00000000000010000000000000000000;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 0b00000000000000000000001010000000;
  src2.bits[1] = 0b00000000000010000000000000100000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_add(src1, src2, &result);
  origin_return_value = 0;
  // origin = 96714067843647575002343.04
  origin.bits[0] = 0b00000000000110110000101001000000;
  origin.bits[1] = 0b00000011001010000000111010000000;
  origin.bits[2] = 0b00000000000010000000000000000000;
  origin.bits[3] = 0b00000000000000100000000000000000;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_add2) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = -96714065591710322362983.04
  // src2 = -38685626229920070843236992
  src1.bits[0] = 0b00000000000110100001000001000000;
  src1.bits[1] = 0b00000000000010000000001000000000;
  src1.bits[2] = 0b00000000000010000000000000000000;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 0b00000000000000000000001010000000;
  src2.bits[1] = 0b00000000000010000000000000100000;
  src2.bits[2] = 0b00000000001000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_add(src1, src2, &result);
  origin_return_value = 0;
  // origin = -38782340295511781165599975.04
  origin.bits[0] = 0b00000000000110110000101001000000;
  origin.bits[1] = 0b00000011001010000000111010000000;
  origin.bits[2] = 0b00001100100010000000000000000000;
  origin.bits[3] = 0b10000000000000100000000000000000;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_add3) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = -96714065591710322362983.04
  // src2 = 2251937252639360
  src1.bits[0] = 0b00000000000110100001000001000000;
  src1.bits[1] = 0b00000000000010000000001000000000;
  src1.bits[2] = 0b00000000000010000000000000000000;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 0b00000000000000000000001010000000;
  src2.bits[1] = 0b00000000000010000000000000100000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_add(src1, src2, &result);
  origin_return_value = 0;
  // origin = -96714063339773069723623.04
  origin.bits[0] = 0b00000000000110010001011001000000;
  origin.bits[1] = 0b11111100111001111111010110000000;
  origin.bits[2] = 0b00000000000001111111111111111111;
  origin.bits[3] = 0b10000000000000100000000000000000;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_add4) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = 96714065591710322362983.04
  // src2 = -38685626229920070843236992
  src1.bits[0] = 0b00000000000110100001000001000000;
  src1.bits[1] = 0b00000000000010000000001000000000;
  src1.bits[2] = 0b00000000000010000000000000000000;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 0b00000000000000000000001010000000;
  src2.bits[1] = 0b00000000000010000000000000100000;
  src2.bits[2] = 0b00000000001000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_add(src1, src2, &result);
  origin_return_value = 0;
  // origin = -38588912164328360520874008.96
  origin.bits[0] = 0b11111111111001101110100111000000;
  origin.bits[1] = 0b00000011000110000000101001111111;
  origin.bits[2] = 0b00001100011110000000000000000000;
  origin.bits[3] = 0b10000000000000100000000000000000;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_add5) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = 396237526636913398311557571.20
  // src2 = 39614081257134420736172098176
  src1.bits[0] = 0b10000000000110100001000001000000;
  src1.bits[1] = 0b00000000000010000000001000000000;
  src1.bits[2] = 0b10000000000010000000000000000000;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 0b10000000000000000000001010000000;
  src2.bits[1] = 0b00000000000010000000000000100000;
  src2.bits[2] = 0b10000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_add(src1, src2, &result);
  origin_return_value = 0;
  // origin = 40010318783771334134483655747
  origin.bits[0] = 0b00010000101001000001110001000011;
  origin.bits[1] = 0b01011100001100010000101001100011;
  origin.bits[2] = 0b10000001010001111100001010001111;
  origin.bits[3] = 0;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_add6) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = 39623752663691339831155757120
  // src2 = 39614081257134420736172098176
  src1.bits[0] = 0b10000000000110100001000001000000;
  src1.bits[1] = 0b00000000000010000000001000000000;
  src1.bits[2] = 0b10000000000010000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b10000000000000000000001010000000;
  src2.bits[1] = 0b00000000000010000000000000100000;
  src2.bits[2] = 0b10000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_add(src1, src2, &result);
  origin_return_value = 1;
  // origin = 0
  origin.bits[0] = 0;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_add7) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = -39623752663691339831155757120
  // src2 = -39614081257134420736172098176
  src1.bits[0] = 0b10000000000110100001000001000000;
  src1.bits[1] = 0b00000000000010000000001000000000;
  src1.bits[2] = 0b10000000000010000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b10000000000000000000001010000000;
  src2.bits[1] = 0b00000000000010000000000000100000;
  src2.bits[2] = 0b10000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_add(src1, src2, &result);
  origin_return_value = 2;
  // origin = 0
  origin.bits[0] = 0;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_sub1) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = 96714065591710322362983.04
  // src2 = 2251937252639360
  src1.bits[0] = 0b00000000000110100001000001000000;
  src1.bits[1] = 0b00000000000010000000001000000000;
  src1.bits[2] = 0b00000000000010000000000000000000;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 0b00000000000000000000001010000000;
  src2.bits[1] = 0b00000000000010000000000000100000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_sub(src1, src2, &result);
  origin_return_value = 0;
  // origin = 96714063339773069723623.04
  origin.bits[0] = 0b00000000000110010001011001000000;
  origin.bits[1] = 0b11111100111001111111010110000000;
  origin.bits[2] = 0b00000000000001111111111111111111;
  origin.bits[3] = 0b00000000000000100000000000000000;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_sub2) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = -96714065591710322362983.04
  // src2 = -38685626229920070843236992
  src1.bits[0] = 0b00000000000110100001000001000000;
  src1.bits[1] = 0b00000000000010000000001000000000;
  src1.bits[2] = 0b00000000000010000000000000000000;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 0b00000000000000000000001010000000;
  src2.bits[1] = 0b00000000000010000000000000100000;
  src2.bits[2] = 0b00000000001000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_sub(src1, src2, &result);
  origin_return_value = 0;
  // origin = 38588912164328360520874008.96
  origin.bits[0] = 0b11111111111001101110100111000000;
  origin.bits[1] = 0b00000011000110000000101001111111;
  origin.bits[2] = 0b00001100011110000000000000000000;
  origin.bits[3] = 0b00000000000000100000000000000000;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_sub3) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = -96714065591710322362983.04
  // src2 = 2251937252639360
  src1.bits[0] = 0b00000000000110100001000001000000;
  src1.bits[1] = 0b00000000000010000000001000000000;
  src1.bits[2] = 0b00000000000010000000000000000000;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 0b00000000000000000000001010000000;
  src2.bits[1] = 0b00000000000010000000000000100000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_sub(src1, src2, &result);
  origin_return_value = 0;
  // origin = -96714067843647575002343.04
  origin.bits[0] = 0b00000000000110110000101001000000;
  origin.bits[1] = 0b00000011001010000000111010000000;
  origin.bits[2] = 0b00000000000010000000000000000000;
  origin.bits[3] = 0b10000000000000100000000000000000;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_sub4) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = 96714065591710322362983.04
  // src2 = -38685626229920070843236992
  src1.bits[0] = 0b00000000000110100001000001000000;
  src1.bits[1] = 0b00000000000010000000001000000000;
  src1.bits[2] = 0b00000000000010000000000000000000;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 0b00000000000000000000001010000000;
  src2.bits[1] = 0b00000000000010000000000000100000;
  src2.bits[2] = 0b00000000001000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_sub(src1, src2, &result);
  origin_return_value = 0;
  // origin = -38588912164328360520874008.96
  origin.bits[0] = 0b00000000000110110000101001000000;
  origin.bits[1] = 0b00000011001010000000111010000000;
  origin.bits[2] = 0b00001100100010000000000000000000;
  origin.bits[3] = 0b00000000000000100000000000000000;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_sub5) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = 396237526636913398311557571.20
  // src2 = 39614081257134420736172098176
  src1.bits[0] = 0b10000000000110100001000001000000;
  src1.bits[1] = 0b00000000000010000000001000000000;
  src1.bits[2] = 0b10000000000010000000000000000000;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 0b10000000000000000000001010000000;
  src2.bits[1] = 0b00000000000010000000000000100000;
  src2.bits[2] = 0b10000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_sub(src1, src2, &result);
  origin_return_value = 0;
  // origin = 40010318783771334134483655747.2
  origin.bits[0] = 0b11101111010110111110100010111101;
  origin.bits[1] = 0b10100011110111101111010111011101;
  origin.bits[2] = 0b01111110101110000011110101110000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_sub6) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = 39623752663691339831155757120
  // src2 = 39614081257134420736172098176
  src1.bits[0] = 0b10000000000110100001000001000000;
  src1.bits[1] = 0b00000000000010000000001000000000;
  src1.bits[2] = 0b10000000000010000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b10000000000000000000001010000000;
  src2.bits[1] = 0b00000000000010000000000000100000;
  src2.bits[2] = 0b10000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_sub(src1, src2, &result);
  origin_return_value = 0;
  // origin = 9671406556919094983658944
  origin.bits[0] = 0b00000000000110100000110111000000;
  origin.bits[1] = 0b00000000000000000000000111100000;
  origin.bits[2] = 0b00000000000010000000000000000000;
  origin.bits[3] = 0;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_sub7) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = -39623752663691339831155757120
  // src2 = -39614081257134420736172098176
  src1.bits[0] = 0b10000000000110100001000001000000;
  src1.bits[1] = 0b00000000000010000000001000000000;
  src1.bits[2] = 0b10000000000010000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b10000000000000000000001010000000;
  src2.bits[1] = 0b00000000000010000000000000100000;
  src2.bits[2] = 0b10000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_sub(src1, src2, &result);
  origin_return_value = 0;
  // origin = -9671406556919094983658944
  origin.bits[0] = 0b00000000000110100000110111000000;
  origin.bits[1] = 0b00000000000000000000000111100000;
  origin.bits[2] = 0b00000000000010000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_sub8) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = -39623752663691339831155757120
  // src2 = 39614081257134420736172098176
  src1.bits[0] = 0b10000000000110100001000001000000;
  src1.bits[1] = 0b00000000000010000000001000000000;
  src1.bits[2] = 0b10000000000010000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b10000000000000000000001010000000;
  src2.bits[1] = 0b00000000000010000000000000100000;
  src2.bits[2] = 0b10000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_sub(src1, src2, &result);
  origin_return_value = 2;
  // origin = -9671406556919094983658944
  origin.bits[0] = 0;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_mul1) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul2) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul3) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul4) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11000110011101000101101010011110;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00111001100010111010010101100001;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul6) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000001010010011001000011101110;
  origin.bits[1] = 0b10101010100001010100111110001111;
  origin.bits[2] = 0b00100010111101110101101000011010;
  origin.bits[3] = 0b10000000000010100000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul7) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000001010010011001000011101110;
  origin.bits[1] = 0b10101010100001010100111110001111;
  origin.bits[2] = 0b00100010111101110101101000011010;
  origin.bits[3] = 0b00000000000010100000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul8) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -0.77545545454546589781;
  // src2 = 87894515154546456456;
  src1.bits[0] = 0b10101100001010000001100001010101;
  src1.bits[1] = 0b00110100001010010001111010111100;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000101000000000000000000;
  src2.bits[0] = 0b00010011111011011111011110001000;
  src2.bits[1] = 0b11000011110010000000101111011001;
  src2.bits[2] = 0b00000000000000000000000000000100;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00101100010001000110001011111110;
  origin.bits[1] = 0b10001111111010010000010001010010;
  origin.bits[2] = 0b11011100001110110011010101110011;
  origin.bits[3] = 0b10000000000010010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_equal_1) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_equal(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_equal_2) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = -0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_equal(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_equal_3) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 0;
  // src2 = 1;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_equal(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_equal_4) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 1;
  // src2 = 1;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_equal(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_equal_5) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 5.0000000000000;
  // src2 = 5;
  src1.bits[0] = 0b10001000001111010010000000000000;
  src1.bits[1] = 0b00000000000000000010110101111001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_equal(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_equal_6) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 5.0000000000000;
  // src2 = 5.0;
  src1.bits[0] = 0b10001000001111010010000000000000;
  src1.bits[1] = 0b00000000000000000010110101111001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b00000000000000000000000000110010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  return_value = s21_is_equal(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_equal_7) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = -12345678901234567890123456789;
  // src2 = -12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010101;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_is_equal(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_equal_8) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = -12345678901234567890123456789;
  // src2 = 12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010101;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_equal(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_not_equal_1) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_not_equal(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_not_equal_2) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = -0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_not_equal(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_not_equal_3) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 0;
  // src2 = 1;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_not_equal(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_not_equal_4) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 1;
  // src2 = 1;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_not_equal(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_not_equal_5) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 5.0000000000000;
  // src2 = 5;
  src1.bits[0] = 0b10001000001111010010000000000000;
  src1.bits[1] = 0b00000000000000000010110101111001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_not_equal(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_not_equal_6) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 5.0000000000000;
  // src2 = 5.0;
  src1.bits[0] = 0b10001000001111010010000000000000;
  src1.bits[1] = 0b00000000000000000010110101111001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b00000000000000000000000000110010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  return_value = s21_is_not_equal(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_not_equal_7) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = -12345678901234567890123456789;
  // src2 = -12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010101;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_is_not_equal(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_not_equal_8) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = -12345678901234567890123456789;
  // src2 = 12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010101;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_not_equal(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_less_1) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 0;
  // src2 = 1;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_less(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_less_2) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 1;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_less(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_less_3) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 0;
  // src2 = -1;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_is_less(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_less_4) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = -12345678901234567890123456789;
  // src2 = 0;
  src1.bits[0] = 0b01101110001110011000000100010101;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000001;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_less(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_less_5) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 12345678901234567890123456789;
  // src2 = 0;
  src1.bits[0] = 0b01101110001110011000000100010101;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_less(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_less_6) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 12345678901234567890123456788;
  // src2 = 12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010100;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b00000000000000110000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b00000000000000110000000000000000;
  return_value = s21_is_less(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_less_7) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = -12345678901234567890123456788;
  // src2 = -12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010100;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_is_less(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_less_8) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 12345678901234567890123456.788;
  // src2 = 12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010100;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b00000000000000110000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_less(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_greater_1) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 0;
  // src2 = 1;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_greater(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_greater_2) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 1;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_greater(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_greater_3) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 0;
  // src2 = -1;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_is_greater(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_greater_4) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = -12345678901234567890123456789;
  // src2 = 0;
  src1.bits[0] = 0b01101110001110011000000100010101;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000001;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_greater(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_greater_5) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 12345678901234567890123456789;
  // src2 = 0;
  src1.bits[0] = 0b01101110001110011000000100010101;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_greater(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_greater_6) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 12345678901234567890123456788;
  // src2 = 12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010100;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b00000000000000110000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b00000000000000110000000000000000;
  return_value = s21_is_greater(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_greater_7) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = -12345678901234567890123456788;
  // src2 = -12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010100;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_is_greater(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_greater_8) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 12345678901234567890123456.788;
  // src2 = 12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010100;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b00000000000000110000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_greater(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_less_or_equal_1) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = -12345678901234567890123456789;
  // src2 = -12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010101;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_is_less_or_equal(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_less_or_equal_2) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = -12345678901234567890123456788;
  // src2 = -12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010100;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_is_less_or_equal(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_less_or_equal_3) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 12345678901234567890123456788;
  // src2 = 12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010100;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_less_or_equal(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_less_or_equal_4) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = -12345678901234567890123456789;
  // src2 = 12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010101;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_less_or_equal(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_greater_or_equal_1) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = -12345678901234567890123456789;
  // src2 = -12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010101;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_is_greater_or_equal(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_greater_or_equal_2) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = -12345678901234567890123456788;
  // src2 = -12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010100;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_is_greater_or_equal(src1, src2);
  origin_return_value = 1;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_greater_or_equal_3) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = 12345678901234567890123456788;
  // src2 = 12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010100;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_greater_or_equal(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_greater_or_equal_4) {
  s21_decimal src1, src2;
  int return_value, origin_return_value;
  // src1 = -12345678901234567890123456789;
  // src2 = 12345678901234567890123456789;
  src1.bits[0] = 0b01101110001110011000000100010101;
  src1.bits[1] = 0b01000110101111101100100110110001;
  src1.bits[2] = 0b00100111111001000001101100110010;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b01101110001110011000000100010101;
  src2.bits[1] = 0b01000110101111101100100110110001;
  src2.bits[2] = 0b00100111111001000001101100110010;
  src2.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_is_greater_or_equal(src1, src2);
  origin_return_value = 0;
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_negate_1) {
  s21_decimal src, origin, result;
  int return_value, origin_return_value;
  // src = -12345678901234567890123456789;
  src.bits[0] = 0b01101110001110011000000100010101;
  src.bits[1] = 0b01000110101111101100100110110001;
  src.bits[2] = 0b00100111111001000001101100110010;
  src.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_negate(src, &result);
  origin_return_value = 0;
  origin.bits[0] = 0b01101110001110011000000100010101;
  origin.bits[1] = 0b01000110101111101100100110110001;
  origin.bits[2] = 0b00100111111001000001101100110010;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_negate_2) {
  s21_decimal src, origin, result;
  int return_value, origin_return_value;
  // src = -12345678901234567890123456789;
  src.bits[0] = 0b01101110001110011000000100010101;
  src.bits[1] = 0b01000110101111101100100110110001;
  src.bits[2] = 0b00100111111001000001101100110010;
  src.bits[3] = 0b00000000000000000000000000000000;
  return_value = s21_negate(src, &result);
  origin_return_value = 0;
  origin.bits[0] = 0b01101110001110011000000100010101;
  origin.bits[1] = 0b01000110101111101100100110110001;
  origin.bits[2] = 0b00100111111001000001101100110010;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_truncate_1) {
  s21_decimal src1, origin, result;
  // src1 = 2.1234;
  src1.bits[0] = 0b00000000000000000101001011110010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001000000000000000000;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal src1, origin, result;
  // src1 = -457.000001;
  src1.bits[0] = 0b00011011001111010100010001000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001100000000000000000;
  // origin = -457;
  origin.bits[0] = 0b00000000000000000000000111001001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_3) {
  s21_decimal src1, origin, result;
  // src1 = 2.000;
  src1.bits[0] = 0b00000000000000000000011111010000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000110000000000000000;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_4) {
  s21_decimal src1, origin, result;
  // src1 = 0.000000000000000000000000000;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_5) {
  s21_decimal src1, origin, result;
  // src1 = -3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  // origin = -3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_6) {
  s21_decimal src1, origin, result;
  // src1 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_7) {
  s21_decimal src1, origin, result;
  // src1 = 2.22221200000001000;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_8) {
  s21_decimal src1, origin, result;
  // src1 = -3.745754741;
  src1.bits[0] = 0b11011111010000111010111001110101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000010010000000000000000;
  // origin = -3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_1) {
  s21_decimal src, origin, result;
  // src = 5.0;
  src.bits[0] = 0b00000000000000000000000000110010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 5;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_2) {
  s21_decimal src, origin, result;
  // src = 3.4;
  src.bits[0] = 0b00000000000000000000000000100010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal src, origin, result;
  // src = 0.0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_4) {
  s21_decimal src, origin, result;
  // src = -2.4363463;
  src.bits[0] = 0b00000001011100111100000111000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = -2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_5) {
  s21_decimal src, origin, result;
  // src = -0.0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_6) {
  s21_decimal src, origin, result;
  // src = -0.45;
  src.bits[0] = 0b00000000000000000000000000101101;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000100000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_7) {
  s21_decimal src, origin, result;
  // src = 652.34631;
  src.bits[0] = 0b00000011111000110110011011000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 652;
  origin.bits[0] = 0b00000000000000000000001010001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_8) {
  s21_decimal src, origin, result;
  // src = 4.97623323;
  src.bits[0] = 0b00011101101010010010000100011011;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010000000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 5;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_1) {
  s21_decimal src, origin, result;
  // src = 5.0;
  src.bits[0] = 0b00000000000000000000000000110010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 5;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_2) {
  s21_decimal src, origin, result;
  // src = 3.4;
  src.bits[0] = 0b00000000000000000000000000100010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_3) {
  s21_decimal src, origin, result;
  // src = 0.0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_4) {
  s21_decimal src, origin, result;
  // src = -2.4363463;
  src.bits[0] = 0b00000001011100111100000111000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_5) {
  s21_decimal src, origin, result;
  // src = -0.0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_6) {
  s21_decimal src, origin, result;
  // src = -0.45;
  src.bits[0] = 0b00000000000000000000000000101101;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_7) {
  s21_decimal src, origin, result;
  // src = 652.34631;
  src.bits[0] = 0b00000011111000110110011011000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 652;
  origin.bits[0] = 0b00000000000000000000001010001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_8) {
  s21_decimal src, origin, result;
  // src = 4.97623323;
  src.bits[0] = 0b00011101101010010010000100011011;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010000000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 4;
  origin.bits[0] = 0b00000000000000000000000000000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

void srunner_arithmetics_tests(SRunner *sr) {
  Suite *Suite1 = suite_create("arithmetics");
  TCase *TestCase1 = tcase_create("arithmetics");
  suite_add_tcase(Suite1, TestCase1);
  tcase_add_test(TestCase1, s21_add1);
  tcase_add_test(TestCase1, s21_add2);
  tcase_add_test(TestCase1, s21_add3);
  tcase_add_test(TestCase1, s21_add4);
  tcase_add_test(TestCase1, s21_add5);
  tcase_add_test(TestCase1, s21_add6);
  tcase_add_test(TestCase1, s21_add7);
  tcase_add_test(TestCase1, s21_sub1);
  tcase_add_test(TestCase1, s21_sub2);
  tcase_add_test(TestCase1, s21_sub3);
  tcase_add_test(TestCase1, s21_sub4);
  tcase_add_test(TestCase1, s21_sub5);
  tcase_add_test(TestCase1, s21_sub6);
  tcase_add_test(TestCase1, s21_sub7);
  tcase_add_test(TestCase1, s21_sub8);
  tcase_add_test(TestCase1, s21_mul1);
  tcase_add_test(TestCase1, s21_mul2);
  tcase_add_test(TestCase1, s21_mul3);
  tcase_add_test(TestCase1, s21_mul4);
  tcase_add_test(TestCase1, s21_mul6);
  tcase_add_test(TestCase1, s21_mul7);
  tcase_add_test(TestCase1, s21_mul8);
  srunner_add_suite(sr, Suite1);
}

void srunner_comparison_tests(SRunner *sr) {
  Suite *Suite1 = suite_create("arithmetics");
  TCase *TestCase1 = tcase_create("arithmetics");
  suite_add_tcase(Suite1, TestCase1);
  tcase_add_test(TestCase1, s21_equal_1);
  tcase_add_test(TestCase1, s21_equal_2);
  tcase_add_test(TestCase1, s21_equal_3);
  tcase_add_test(TestCase1, s21_equal_4);
  tcase_add_test(TestCase1, s21_equal_5);
  tcase_add_test(TestCase1, s21_equal_6);
  tcase_add_test(TestCase1, s21_equal_7);
  tcase_add_test(TestCase1, s21_equal_8);

  tcase_add_test(TestCase1, s21_not_equal_1);
  tcase_add_test(TestCase1, s21_not_equal_2);
  tcase_add_test(TestCase1, s21_not_equal_3);
  tcase_add_test(TestCase1, s21_not_equal_4);
  tcase_add_test(TestCase1, s21_not_equal_5);
  tcase_add_test(TestCase1, s21_not_equal_6);
  tcase_add_test(TestCase1, s21_not_equal_7);
  tcase_add_test(TestCase1, s21_not_equal_8);

  tcase_add_test(TestCase1, s21_less_1);
  tcase_add_test(TestCase1, s21_less_2);
  tcase_add_test(TestCase1, s21_less_3);
  tcase_add_test(TestCase1, s21_less_4);
  tcase_add_test(TestCase1, s21_less_5);
  tcase_add_test(TestCase1, s21_less_6);
  tcase_add_test(TestCase1, s21_less_7);
  tcase_add_test(TestCase1, s21_less_8);

  tcase_add_test(TestCase1, s21_greater_1);
  tcase_add_test(TestCase1, s21_greater_2);
  tcase_add_test(TestCase1, s21_greater_3);
  tcase_add_test(TestCase1, s21_greater_4);
  tcase_add_test(TestCase1, s21_greater_5);
  tcase_add_test(TestCase1, s21_greater_6);
  tcase_add_test(TestCase1, s21_greater_7);
  tcase_add_test(TestCase1, s21_greater_8);

  tcase_add_test(TestCase1, s21_less_or_equal_1);
  tcase_add_test(TestCase1, s21_less_or_equal_2);
  tcase_add_test(TestCase1, s21_less_or_equal_3);
  tcase_add_test(TestCase1, s21_less_or_equal_4);

  tcase_add_test(TestCase1, s21_greater_or_equal_1);
  tcase_add_test(TestCase1, s21_greater_or_equal_2);
  tcase_add_test(TestCase1, s21_greater_or_equal_3);
  tcase_add_test(TestCase1, s21_greater_or_equal_4);

  srunner_add_suite(sr, Suite1);
}

void srunner_conversion_tests(SRunner *sr) {
  Suite *Suite1 = suite_create("conversion");
  TCase *TestCase1 = tcase_create("conversion");
  suite_add_tcase(Suite1, TestCase1);

  srunner_add_suite(sr, Suite1);
}

void srunner_other_funcs_tests(SRunner *sr) {
  Suite *Suite1 = suite_create("other functions");
  TCase *TestCase1 = tcase_create("other functions");
  suite_add_tcase(Suite1, TestCase1);
  tcase_add_test(TestCase1, s21_negate_1);
  tcase_add_test(TestCase1, s21_negate_2);

  tcase_add_test(TestCase1, s21_truncate_1);
  tcase_add_test(TestCase1, s21_truncate_2);
  tcase_add_test(TestCase1, s21_truncate_3);
  tcase_add_test(TestCase1, s21_truncate_4);
  tcase_add_test(TestCase1, s21_truncate_5);
  tcase_add_test(TestCase1, s21_truncate_6);
  tcase_add_test(TestCase1, s21_truncate_7);
  tcase_add_test(TestCase1, s21_truncate_8);

  tcase_add_test(TestCase1, s21_round_1);
  tcase_add_test(TestCase1, s21_round_2);
  tcase_add_test(TestCase1, s21_round_3);
  tcase_add_test(TestCase1, s21_round_4);
  tcase_add_test(TestCase1, s21_round_5);
  tcase_add_test(TestCase1, s21_round_6);
  tcase_add_test(TestCase1, s21_round_7);
  tcase_add_test(TestCase1, s21_round_8);

  tcase_add_test(TestCase1, s21_floor_1);
  tcase_add_test(TestCase1, s21_floor_2);
  tcase_add_test(TestCase1, s21_floor_3);
  tcase_add_test(TestCase1, s21_floor_4);
  tcase_add_test(TestCase1, s21_floor_5);
  tcase_add_test(TestCase1, s21_floor_6);
  tcase_add_test(TestCase1, s21_floor_7);
  tcase_add_test(TestCase1, s21_floor_8);
  srunner_add_suite(sr, Suite1);
}

int main() {
  Suite *s = suite_create("s21_decimal");
  SRunner *sr = srunner_create(s);

  srunner_arithmetics_tests(sr);
  srunner_comparison_tests(sr);
  srunner_other_funcs_tests(sr);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);

  return srunner_ntests_failed(sr);
}