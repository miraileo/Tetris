#include "test.h"

START_TEST(Timer1) {
  TimeInfo time;
  InitTime(&time);
  while (time.seconds != 1) {
    Timer(&time, 1);
  }
  ck_assert_int_eq(time.seconds, 1);
  Timer(&time, 0);
  ck_assert_int_eq(time.seconds, 0);
}

Suite* Timer_test(void) {
  Suite* s = suite_create("\033[42m-=Timer=-\033[0m");
  TCase* tc = tcase_create("Timer_tc");
  tcase_add_test(tc, Timer1);
  suite_add_tcase(s, tc);
  return s;
}
