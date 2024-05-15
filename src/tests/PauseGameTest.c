#include "test.h"

START_TEST(PauseGame1) {
  GameInfo info;
  info.inputChar = 'p';
  int result = PauseGame(info);
  ck_assert_int_eq(result, 1);
}

START_TEST(PauseGame2) {
  GameInfo info;
  info.inputChar = 'f';
  int result = PauseGame(info);
  ck_assert_int_eq(result, 0);
}

Suite* PauseGame_test(void) {
  Suite* s = suite_create("\033[42m-=PauseGame=-\033[0m");
  TCase* tc = tcase_create("PauseGame_tc");
  tcase_add_test(tc, PauseGame1);
  tcase_add_test(tc, PauseGame2);
  suite_add_tcase(s, tc);
  return s;
}
