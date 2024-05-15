#include "test.h"

START_TEST(StartGame1) {
  GameInfo info;
  info.inputChar = 's';
  int result = StartGame(info);
  ck_assert_int_eq(result, 0);
}

START_TEST(StartGame2) {
  GameInfo info;
  info.inputChar = 'f';
  int result = StartGame(info);
  ck_assert_int_eq(result, 1);
}

Suite* StartGame_test(void) {
  Suite* s = suite_create("\033[42m-=StartGame=-\033[0m");
  TCase* tc = tcase_create("StartGame_tc");
  tcase_add_test(tc, StartGame1);
  tcase_add_test(tc, StartGame2);
  suite_add_tcase(s, tc);
  return s;
}
