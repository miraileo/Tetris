#include "test.h"

START_TEST(UserInput1) {
  GameInfo info;
  Figure figure;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  info.x = 2;
  info.inputChar = Right;
  UserInput(&info, &figure);
  ck_assert_int_eq(info.x, 3);
  FreeMemory(&info);
}

START_TEST(UserInput2) {
  GameInfo info;
  Figure figure;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  info.x = 5;
  info.inputChar = Left;
  UserInput(&info, &figure);
  ck_assert_int_eq(info.x, 4);
  FreeMemory(&info);
}

START_TEST(UserInput3) {
  GameInfo info;
  Figure figure;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  info.x = 5;
  info.inputChar = Up;
  UserInput(&info, &figure);
  ck_assert_int_eq(RotateFigure(&figure, info), 0);
  FreeMemory(&info);
}

START_TEST(UserInput4) {
  GameInfo info;
  Figure figure;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  info.y = 5;
  info.inputChar = Down;
  UserInput(&info, &figure);
  ck_assert_int_eq(info.y, 6);
  FreeMemory(&info);
}

Suite* UserInput_test(void) {
  Suite* s = suite_create("\033[42m-=UserInput=-\033[0m");
  TCase* tc = tcase_create("UserInput_tc");
  tcase_add_test(tc, UserInput1);
  tcase_add_test(tc, UserInput2);
  tcase_add_test(tc, UserInput3);
  tcase_add_test(tc, UserInput4);
  suite_add_tcase(s, tc);
  return s;
}
