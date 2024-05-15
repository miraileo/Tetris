#include "test.h"

START_TEST(FigureCollision1) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[0];
  info.y = 18;
  result = FigureCollision(info, figure);
  ck_assert_int_eq(result, 1);
  FreeMemory(&info);
}
END_TEST

START_TEST(FigureCollision2) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[1];
  info.y = 10;
  result = FigureCollision(info, figure);
  ck_assert_int_eq(result, 0);
  FreeMemory(&info);
}
END_TEST

START_TEST(FigureCollision3) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[2];
  info.y = 10;
  info.x = 7;
  result = FigureCollision(info, figure);
  ck_assert_int_eq(result, 0);
  FreeMemory(&info);
}
END_TEST

START_TEST(FigureCollision4) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[3];
  info.y = 11;
  info.x = 4;
  result = FigureCollision(info, figure);
  ck_assert_int_eq(result, 0);
  FreeMemory(&info);
}
END_TEST

START_TEST(FigureCollision5) {
  GameInfo info;
  Figure figure;
  int result = 0;
  AllocateMemory(&info);
  InitField(info);
  InitGameInfo(&info, &figure, &figure, figures);
  figure = figures[3];
  info.y = 18;
  info.x = 8;
  result = FigureCollision(info, figure);
  ck_assert_int_eq(result, 1);
  FreeMemory(&info);
}
END_TEST

Suite* FigureCollision_test(void) {
  Suite* s = suite_create("\033[42m-=FigureCollision=-\033[0m");
  TCase* tc = tcase_create("FigureCollision_tc");
  tcase_add_test(tc, FigureCollision1);
  tcase_add_test(tc, FigureCollision2);
  tcase_add_test(tc, FigureCollision3);
  tcase_add_test(tc, FigureCollision4);
  tcase_add_test(tc, FigureCollision5);

  suite_add_tcase(s, tc);
  return s;
}
