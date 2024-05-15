#include "test.h"

START_TEST(GameOver1) {
  GameInfo info;
  AllocateMemory(&info);
  InitField(info);
  info.gameOver = 0;
  info.array[0][5] = 1;
  GameOver(&info);
  ck_assert_int_eq(info.gameOver, 1);
  FreeMemory(&info);
}
END_TEST

START_TEST(GameOver2) {
  GameInfo info;
  AllocateMemory(&info);
  InitField(info);
  info.gameOver = 0;
  info.array[1][5] = 1;
  GameOver(&info);
  ck_assert_int_eq(info.gameOver, 0);
  FreeMemory(&info);
}
END_TEST

Suite* GameOver_test(void) {
  Suite* s = suite_create("\033[42m-=GameOver=-\033[0m");
  TCase* tc = tcase_create("GameOver_tc");
  tcase_add_test(tc, GameOver1);
  tcase_add_test(tc, GameOver2);
  suite_add_tcase(s, tc);
  return s;
}
