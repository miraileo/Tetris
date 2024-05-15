#include "test.h"

START_TEST(writeHighScore1) {
  GameInfo info;
  info.score = 100;
  int highScore = 0;
  info.highScore = readHighScore();
  highScore = info.highScore;
  writeHighScore(&info);
  info.highScore = readHighScore();
  ck_assert_int_eq(info.highScore, 100);
  info.score = highScore;
  writeHighScore(&info);
  ck_assert_int_eq(info.score, highScore);
}

Suite* writeHighScore_test(void) {
  Suite* s = suite_create("\033[42m-=writeHighScore=-\033[0m");
  TCase* tc = tcase_create("writeHighScore_tc");
  tcase_add_test(tc, writeHighScore1);
  suite_add_tcase(s, tc);
  return s;
}
