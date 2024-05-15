#include "test.h"

START_TEST(ControllCollision1) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[0];
  info.x = 8;
  result = ControllCollision(info, figure, 0);
  ck_assert_int_eq(result, 1);
  FreeMemory(&info);
}
END_TEST

START_TEST(ControllCollision2) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[1];
  info.x = 1;
  result = ControllCollision(info, figure, 1);
  ck_assert_int_eq(result, 1);
  FreeMemory(&info);
}
END_TEST

START_TEST(ControllCollision3) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[2];
  info.y = 19;
  result = ControllCollision(info, figure, 2);
  ck_assert_int_eq(result, 1);
  FreeMemory(&info);
}
END_TEST

START_TEST(ControllCollision4) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[3];
  result = ControllCollision(info, figure, 0);
  ck_assert_int_eq(result, 0);
  FreeMemory(&info);
}
END_TEST

START_TEST(ControllCollision5) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[4];
  result = ControllCollision(info, figure, 1);
  ck_assert_int_eq(result, 0);
  FreeMemory(&info);
}
END_TEST

START_TEST(ControllCollision6) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[5];
  result = ControllCollision(info, figure, 2);
  ck_assert_int_eq(result, 0);
  FreeMemory(&info);
}
END_TEST

Suite* ControllCollision_test(void) {
  Suite* s = suite_create("\033[42m-=ControllCollision=-\033[0m");
  TCase* tc = tcase_create("ControllCollision_tc");
  tcase_add_test(tc, ControllCollision1);
  tcase_add_test(tc, ControllCollision2);
  tcase_add_test(tc, ControllCollision3);
  tcase_add_test(tc, ControllCollision4);
  tcase_add_test(tc, ControllCollision5);
  tcase_add_test(tc, ControllCollision6);
  suite_add_tcase(s, tc);
  return s;
}
