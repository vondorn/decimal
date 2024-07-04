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
  int return_value, origin_return_value;
  // src1 = 96714065591710322362983.04
  // src2 = -2
  src1.bits[0] = 0b00000000000110100001000001000000;
  src1.bits[1] = 0b00000000000010000000001000000000;
  src1.bits[2] = 0b00000000000010000000000000000000;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_mul(src1, src2, &result);
  origin_return_value = 0;
  // origin = -193428131183420644725966.08
  origin.bits[0] = 0b00000000001101000010000010000000;
  origin.bits[1] = 0b00000000000100000000010000000000;
  origin.bits[2] = 0b00000000000100000000000000000000;
  origin.bits[3] = 0b10000000000000100000000000000000;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_mul2) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = -2
  // src2 = 96714065591710322362983.04
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000110100001000001000000;
  src2.bits[1] = 0b00000000000010000000001000000000;
  src2.bits[2] = 0b00000000000010000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  return_value = s21_mul(src1, src2, &result);
  origin_return_value = 0;
  // origin = -193428131183420644725966.08
  origin.bits[0] = 0b00000000001101000010000010000000;
  origin.bits[1] = 0b00000000000100000000010000000000;
  origin.bits[2] = 0b00000000000100000000000000000000;
  origin.bits[3] = 0b10000000000000100000000000000000;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_mul3) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = -2111
  // src2 = -11433423
  src1.bits[0] = 0b00000000000000000000100000111111;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000101011100111010111001111;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  return_value = s21_mul(src1, src2, &result);
  origin_return_value = 0;
  // origin = 24135955953
  origin.bits[0] = 0b10011110100111010111010111110001;
  origin.bits[1] = 0b00000000000000000000000000000101;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
}
END_TEST

START_TEST(s21_mul4) {
  s21_decimal src1, src2, origin, result;
  int return_value, origin_return_value;
  // src1 = 2111
  // src2 = 11433423
  src1.bits[0] = 0b00000000000000000000100000111111;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 0b00000000101011100111010111001111;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  return_value = s21_mul(src1, src2, &result);
  origin_return_value = 0;
  // origin = 24135955953
  origin.bits[0] = 0b10011110100111010111010111110001;
  origin.bits[1] = 0b00000000000000000000000000000101;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(return_value, origin_return_value);
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

  srunner_add_suite(sr, Suite1);
}

int main() {
  Suite *s = suite_create("s21_decimal");
  SRunner *sr = srunner_create(s);

  srunner_arithmetics_tests(sr);
  srunner_comparison_tests(sr);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);

  return srunner_ntests_failed(sr);
}