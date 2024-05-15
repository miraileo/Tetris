#include "test.h"

START_TEST(Rotate1) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[6];
  RotateFigure(&figure, info);
  info.x = 0;
  result = RotateFigure(&figure, info);
  ck_assert_int_eq(result, 1);
  FreeMemory(&info);
}
END_TEST

START_TEST(Rotate2) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[0];
  result = RotateFigure(&figure, info);
  ck_assert_int_eq(result, 0);
  FreeMemory(&info);
}
END_TEST

START_TEST(Rotate3) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[1];
  RotateFigure(&figure, info);
  info.x = 9;
  result = RotateFigure(&figure, info);
  ck_assert_int_eq(result, 1);
  FreeMemory(&info);
}
END_TEST

START_TEST(Rotate4) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[2];
  result = RotateFigure(&figure, info);
  ck_assert_int_eq(result, 1);
  FreeMemory(&info);
}
END_TEST

START_TEST(Rotate5) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[3];
  info.y = 18;
  result = RotateFigure(&figure, info);
  ck_assert_int_eq(result, 1);
  FreeMemory(&info);
}
END_TEST

START_TEST(Rotate6) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[4];
  info.y = 15;
  info.x = 7;
  result = RotateFigure(&figure, info);
  ck_assert_int_eq(result, 0);
  FreeMemory(&info);
}
END_TEST

START_TEST(Rotate7) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[5];
  result = RotateFigure(&figure, info);
  ck_assert_int_eq(result, 0);
  FreeMemory(&info);
}
END_TEST

Suite* Rotate_test(void) {
  Suite* s = suite_create("\033[42m-=Rotate=-\033[0m");
  TCase* tc = tcase_create("rotate_tc");
  tcase_add_test(tc, Rotate1);
  tcase_add_test(tc, Rotate2);
  tcase_add_test(tc, Rotate3);
  tcase_add_test(tc, Rotate4);
  tcase_add_test(tc, Rotate5);
  tcase_add_test(tc, Rotate6);
  tcase_add_test(tc, Rotate7);
  suite_add_tcase(s, tc);
  return s;
}
