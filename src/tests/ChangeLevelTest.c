#include "test.h"

START_TEST(ChangeLevel1) {
  GameInfo info;
  info.score = 0;
  info.previousScore = 0;
  info.level = 1;
  info.speed = 1;
  ChangeLevel(&info);
  ck_assert_int_eq(info.level, 1);
  ck_assert_int_eq(info.speed, 1);
}

START_TEST(ChangeLevel2) {
  GameInfo info;
  info.score = 600;
  info.previousScore = 0;
  info.level = 1;
  info.speed = 1;
  ChangeLevel(&info);
  ck_assert_int_eq(info.level, 2);
  ck_assert_int_eq(info.speed, 0.9);
}

START_TEST(ChangeLevel3) {
  GameInfo info;
  info.score = 1200;
  info.previousScore = 0;
  info.level = 1;
  info.speed = 1;
  ChangeLevel(&info);
  ck_assert_int_eq(info.level, 3);
  ck_assert_int_eq(info.speed, 0.8);
}

START_TEST(ChangeLevel4) {
  GameInfo info;
  info.score = 2900;
  info.previousScore = 0;
  info.level = 1;
  info.speed = 1;
  ChangeLevel(&info);
  ck_assert_int_eq(info.level, 5);
  ck_assert_int_eq(info.speed, 0.6);
}

START_TEST(ChangeLevel5) {
  GameInfo info;
  info.score = 5700;
  info.previousScore = 0;
  info.level = 1;
  info.speed = 1;
  ChangeLevel(&info);
  ck_assert_int_eq(info.level, 10);
  ck_assert_int_eq(info.speed, 0.1);
}

Suite* ChangeLevel_test(void) {
  Suite* s = suite_create("\033[42m-=ChangeLevel=-\033[0m");
  TCase* tc = tcase_create("ChangeLevel1_tc");
  tcase_add_test(tc, ChangeLevel1);
  tcase_add_test(tc, ChangeLevel2);
  tcase_add_test(tc, ChangeLevel3);
  tcase_add_test(tc, ChangeLevel4);
  tcase_add_test(tc, ChangeLevel5);
  suite_add_tcase(s, tc);
  return s;
}
