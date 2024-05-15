#include "test.h"

START_TEST(ClearFilledRows1) {
  GameInfo info;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  for (int i = 1; i < WIDTH; i++) {
    info.array[19][i] = 1;
  }
  result = ClearFilledRows(&info);
  ck_assert_int_eq(result, 1);
  FreeMemory(&info);
}
END_TEST

START_TEST(ClearFilledRows2) {
  GameInfo info;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  for (int j = 17; j < 20; j++) {
    for (int i = 1; i < WIDTH; i++) {
      info.array[j][i] = 1;
    }
  }
  result = ClearFilledRows(&info);
  ck_assert_int_eq(result, 3);
  FreeMemory(&info);
}
END_TEST

START_TEST(ClearFilledRows3) {
  GameInfo info;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  result = ClearFilledRows(&info);
  ck_assert_int_eq(result, 0);
  FreeMemory(&info);
}
END_TEST

Suite* ClearFilledRows_test(void) {
  Suite* s = suite_create("\033[42m-=ClearFilledRows=-\033[0m");
  TCase* tc = tcase_create("ClearFilledRows_tc");
  tcase_add_test(tc, ClearFilledRows1);
  tcase_add_test(tc, ClearFilledRows2);
  tcase_add_test(tc, ClearFilledRows3);
  suite_add_tcase(s, tc);
  return s;
}
