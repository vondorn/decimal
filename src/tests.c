#include <check.h>

#include "s21_decimal.h"

// START_TEST(){

// } END_TEST

START_TEST(s21_add1) {
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int return_value = 0, origin_return_value = 0;
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

START_TEST(s21_dec_to_float_1) {
  s21_decimal number;
  // number = 2.0
  number.bits[0] = 0b00000000000000000000000000010100;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000010000000000000000;
  int result_error = 0;
  float check = 2;
  float result = 0;
  int my_error = s21_from_decimal_to_float(number, &result);
  ck_assert_float_eq(check, result);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_2) {
  s21_decimal number;
  // number = -0.8
  number.bits[0] = 0b00000000000000000000000000001000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000010000000000000000;
  int result_error = 0;
  float check = -0.8;
  float result = 0;
  int my_error = s21_from_decimal_to_float(number, &result);
  ck_assert_float_eq(check, result);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_3) {
  s21_decimal number;
  // number = 0
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  float check = 0;
  float result = 0;
  int my_error = s21_from_decimal_to_float(number, &result);
  ck_assert_float_eq(check, result);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_4) {
  s21_decimal number;
  // number = 1
  number.bits[0] = 0b00000000000000000000000000000001;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  float check = 1;
  float result = 0;
  int my_error = s21_from_decimal_to_float(number, &result);
  ck_assert_float_eq(check, result);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_5) {
  s21_decimal number;
  // number = 0.0
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000010000000000000000;
  int result_error = 0;
  float check = 0;
  float result = 0;
  int my_error = s21_from_decimal_to_float(number, &result);
  ck_assert_float_eq(check, result);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_6) {
  s21_decimal number;
  // number = -1.75
  number.bits[0] = 0b00000000000000000000000010101111;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000100000000000000000;
  int result_error = 0;
  float check = -1.75;
  float result = 0;
  int my_error = s21_from_decimal_to_float(number, &result);
  ck_assert_float_eq(check, result);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_7) {
  s21_decimal number;
  // number = 6521
  number.bits[0] = 0b00000000000000000001100101111001;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  float check = 6521;
  float result = 0;
  int my_error = s21_from_decimal_to_float(number, &result);
  ck_assert_float_eq(check, result);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_8) {
  s21_decimal number;
  // number = 4
  number.bits[0] = 0b00000000000000000000000000000100;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  float check = 4;
  float result = 0;
  int my_error = s21_from_decimal_to_float(number, &result);
  ck_assert_float_eq(check, result);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_9) {
  s21_decimal number;
  // number = -364748
  number.bits[0] = 0b00000000000001011001000011001100;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  float check = -364748;
  float result = 0;
  int my_error = s21_from_decimal_to_float(number, &result);
  ck_assert_float_eq(check, result);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_10) {
  s21_decimal number = {0};
  int result_error = 1;
  float *result = NULL;
  int my_error = s21_from_decimal_to_float(number, result);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_float_to_dec_1) {
  s21_decimal val;
  float a = -1.00001F;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 0);
  ck_assert_int_eq(val.bits[0], 1000010);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], (unsigned)((1 << 31) | (6 << 16)));
}
END_TEST

START_TEST(s21_float_to_dec_2) {
  s21_decimal val;
  float a = 1.00001F;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 0);
  ck_assert_int_eq(val.bits[0], 1000010);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 6 << 16);
}
END_TEST

START_TEST(s21_float_to_dec_3) {
  s21_decimal val;
  float a = 1.0F / 0.0F;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_float_to_dec_4) {
  s21_decimal val;
  float a = NAN;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_float_to_dec_5) {
  s21_decimal *val = NULL;
  float a = 1;
  int err_check = s21_from_float_to_decimal(a, val);
  ck_assert_int_eq(err_check, 1);
}
END_TEST

START_TEST(s21_int_to_dec_1) {
  s21_decimal result, origin;
  int src = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_2) {
  s21_decimal result, origin;
  int src = -1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_3) {
  s21_decimal result, origin;
  int src = 2147483647;
  origin.bits[0] = 0b01111111111111111111111111111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_4) {
  s21_decimal result, origin;
  int src = -2147483647;
  origin.bits[0] = 0b01111111111111111111111111111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_5) {
  s21_decimal result, origin;
  int src = -12345;
  origin.bits[0] = 0b00000000000000000011000000111001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_6) {
  s21_decimal result, origin;
  int src = -12345;
  origin.bits[0] = 0b00000000000000000011000000111001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_7) {
  s21_decimal result, origin;
  int src = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_8) {
  s21_decimal result, origin;
  int src = 45678;
  origin.bits[0] = 0b00000000000000001011001001101110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_9) {
  s21_decimal result, origin;
  int src = -45678;
  origin.bits[0] = 0b00000000000000001011001001101110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_10) {
  s21_decimal result, origin;
  int src = 5555555;
  origin.bits[0] = 0b00000000010101001100010101100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_11) {
  s21_decimal result, origin;
  int src = -5555555;
  origin.bits[0] = 0b00000000010101001100010101100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_12) {
  s21_decimal result, origin;
  int src = 127;
  origin.bits[0] = 0b00000000000000000000000001111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_13) {
  s21_decimal *result = NULL;
  int src = 1;
  int result_error = 1;
  int my_error = s21_from_int_to_decimal(src, result);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_1) {
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000110010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 5;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_2) {
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000100010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 3;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_3) {
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 0;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_4) {
  s21_decimal src;
  src.bits[0] = 0b00000001011100111100000111000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  int result = 0;
  int origin = -2;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_5) {
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000010000000000000000;
  int result = 0;
  int origin = 0;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_6) {
  s21_decimal src = {0};
  int *result = NULL;
  int origin_error = 1;
  int my_error = s21_from_decimal_to_int(src, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_7) {
  s21_decimal src;
  src.bits[0] = 0b00000011111000110110011011000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  int result = 0;
  int origin = 652;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_8) {
  s21_decimal src;
  src.bits[0] = 0b00011101101010010010000100011011;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010000000000000000000;
  int result = 0;
  int origin = 4;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_9) {
  s21_decimal src;
  src.bits[0] = 0b10000111010110110010011111110011;
  src.bits[1] = 0b00000000000000000000000000000001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000100000000000000000;
  int result = 0;
  int origin = 65658654;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_10) {
  s21_decimal src;
  src.bits[0] = 0b00010101101111011001110101001110;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000110000000000000000;
  int result = 0;
  int origin = -364748;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_11) {
  s21_decimal src;
  src.bits[0] = 0b01101000011010011010001100101111;
  src.bits[1] = 0b00000000000000000001001000010011;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011010000000000000000;
  int result = 0;
  int origin = 1;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
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
  srunner_add_suite(sr, Suite1);
}

void srunner_comparison_tests(SRunner *sr) {
  Suite *Suite1 = suite_create("comparison");
  TCase *TestCase1 = tcase_create("comparison");
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
  tcase_add_test(TestCase1, s21_dec_to_float_1);
  tcase_add_test(TestCase1, s21_dec_to_float_2);
  tcase_add_test(TestCase1, s21_dec_to_float_3);
  tcase_add_test(TestCase1, s21_dec_to_float_4);
  tcase_add_test(TestCase1, s21_dec_to_float_5);
  tcase_add_test(TestCase1, s21_dec_to_float_6);
  tcase_add_test(TestCase1, s21_dec_to_float_7);
  tcase_add_test(TestCase1, s21_dec_to_float_8);
  tcase_add_test(TestCase1, s21_dec_to_float_9);
  tcase_add_test(TestCase1, s21_dec_to_float_10);

  tcase_add_test(TestCase1, s21_float_to_dec_1);
  tcase_add_test(TestCase1, s21_float_to_dec_2);
  tcase_add_test(TestCase1, s21_float_to_dec_3);
  tcase_add_test(TestCase1, s21_float_to_dec_4);
  tcase_add_test(TestCase1, s21_float_to_dec_5);

  tcase_add_test(TestCase1, s21_int_to_dec_1);
  tcase_add_test(TestCase1, s21_int_to_dec_2);
  tcase_add_test(TestCase1, s21_int_to_dec_3);
  tcase_add_test(TestCase1, s21_int_to_dec_4);
  tcase_add_test(TestCase1, s21_int_to_dec_5);
  tcase_add_test(TestCase1, s21_int_to_dec_6);
  tcase_add_test(TestCase1, s21_int_to_dec_7);
  tcase_add_test(TestCase1, s21_int_to_dec_8);
  tcase_add_test(TestCase1, s21_int_to_dec_9);
  tcase_add_test(TestCase1, s21_int_to_dec_10);
  tcase_add_test(TestCase1, s21_int_to_dec_11);
  tcase_add_test(TestCase1, s21_int_to_dec_12);
  tcase_add_test(TestCase1, s21_int_to_dec_13);

  tcase_add_test(TestCase1, s21_dec_to_int_1);
  tcase_add_test(TestCase1, s21_dec_to_int_2);
  tcase_add_test(TestCase1, s21_dec_to_int_3);
  tcase_add_test(TestCase1, s21_dec_to_int_4);
  tcase_add_test(TestCase1, s21_dec_to_int_5);
  tcase_add_test(TestCase1, s21_dec_to_int_6);
  tcase_add_test(TestCase1, s21_dec_to_int_7);
  tcase_add_test(TestCase1, s21_dec_to_int_8);
  tcase_add_test(TestCase1, s21_dec_to_int_9);
  tcase_add_test(TestCase1, s21_dec_to_int_10);
  tcase_add_test(TestCase1, s21_dec_to_int_11);
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
  srunner_conversion_tests(sr);
  srunner_other_funcs_tests(sr);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  int fails = srunner_ntests_failed(sr);
  srunner_free(sr);
  return fails;
}