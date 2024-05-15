#include "test.h"

START_TEST(GetScore1) {
  GameInfo info;
  AllocateMemory(&info);
  InitField(info);
  info.score = 0;
  info.rowFilled = ClearFilledRows(&info);
  GetScore(&info);
  ck_assert_int_eq(info.score, 0);
  FreeMemory(&info);
}

START_TEST(GetScore2) {
  GameInfo info;
  AllocateMemory(&info);
  InitField(info);
  info.score = 0;
  for (int i = 1; i < WIDTH - 1; i++) {
    info.array[19][i] = 1;
  }
  info.rowFilled = ClearFilledRows(&info);
  GetScore(&info);
  FreeMemory(&info);
  ck_assert_int_eq(info.score, 100);
}
END_TEST

END_TEST
START_TEST(GetScore3) {
  GameInfo info;
  AllocateMemory(&info);
  InitField(info);
  info.score = 0;
  for (int j = 18; j < 20; j++) {
    for (int i = 1; i < WIDTH; i++) {
      info.array[j][i] = 1;
    }
  }
  info.rowFilled = ClearFilledRows(&info);
  GetScore(&info);
  ck_assert_int_eq(info.score, 300);
  FreeMemory(&info);
}
END_TEST

START_TEST(GetScore4) {
  GameInfo info;
  AllocateMemory(&info);
  InitField(info);
  info.score = 0;
  for (int j = 17; j < 20; j++) {
    for (int i = 1; i < WIDTH; i++) {
      info.array[j][i] = 1;
    }
  }
  info.rowFilled = ClearFilledRows(&info);
  GetScore(&info);
  ck_assert_int_eq(info.score, 700);
  FreeMemory(&info);
}
END_TEST

START_TEST(GetScore5) {
  GameInfo info;
  AllocateMemory(&info);
  InitField(info);
  info.score = 0;
  for (int j = 16; j < 20; j++) {
    for (int i = 1; i < WIDTH; i++) {
      info.array[j][i] = 1;
    }
  }
  info.rowFilled = ClearFilledRows(&info);
  GetScore(&info);
  ck_assert_int_eq(info.score, 1500);
  FreeMemory(&info);
}
END_TEST

Suite* GetScore_test(void) {
  Suite* s = suite_create("\033[42m-=GetScore=-\033[0m");
  TCase* tc = tcase_create("GetScore_tc");
  tcase_add_test(tc, GetScore1);
  tcase_add_test(tc, GetScore2);
  tcase_add_test(tc, GetScore3);
  tcase_add_test(tc, GetScore4);
  tcase_add_test(tc, GetScore5);
  suite_add_tcase(s, tc);
  return s;
}
