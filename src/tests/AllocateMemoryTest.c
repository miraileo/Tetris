#include "test.h"

START_TEST(AllocateMemory1) {
  GameInfo info;
  int result = AllocateMemory(&info);
  ck_assert_int_eq(result, 1);
  FreeMemory(&info);
}

Suite* AllocateMemory_test(void) {
  Suite* s = suite_create("\033[42m-=AllocateMemory=-\033[0m");
  TCase* tc = tcase_create("AllocateMemory_tc");
  tcase_add_test(tc, AllocateMemory1);
  suite_add_tcase(s, tc);
  return s;
}
