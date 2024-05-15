#include "graphics.h"
/**
 * @brief Отрисовка фигуры
 *
 *  Просто отрисовка массива с единичками и нулями специальными блоками и их
 * окраска
 *
 *  command параметр для отрисовки следующей фигуры в интерфейсе справо
 *
 *  если command = 0 то меняем координаты для отрисовки пишем "Next Figure"
 *
 *
 * @param argc 3
 * @param argv info figure command
 */
void DrawFigure(Figure figure, GameInfo info, int command) {
  if (!command) {
    info.y = 3;
    info.x = WIDTH + 7;
    mvprintw(1, WIDTH + 3, "Next Figure:");
  }
  for (int i = 0; i < figure.size; i++) {
    for (int j = 0; j < figure.size; j++) {
      if (figure.matrix[i][j] == 1) {
        attron(COLOR_PAIR(1));
        mvaddch(info.y + i, info.x + j, ACS_CKBOARD);
        attroff(COLOR_PAIR(1));
      }
    }
  }
}
/**
 * @brief Отрисовка краев поля
 */
void PaintBorders() {
  for (int i = 0; i < HEIGHT; i++) {
    mvaddch(i, WIDTH - 1, ACS_CKBOARD);
  }
  for (int i = 0; i < HEIGHT; i++) {
    mvaddch(i, 0, ACS_CKBOARD);
  }
  for (int j = 0; j < WIDTH; j++) {
    mvaddch(HEIGHT - 1, j, ACS_CKBOARD);
  }
}
/**
 * @brief Отрисовка Поля
 * если в массиве есть единичка то трисовываем ее красным
 * если в массиве ноль то ничего не рисуем
 * @param argc 1
 * @param argv info
 */
void DrawField(GameInfo info) {
  for (int i = 0; i < HEIGHT - 1; i++) {
    for (int j = 1; j < WIDTH - 1; j++) {
      if (info.array[i][j] == 1) {
        attron(COLOR_PAIR(2));
        mvaddch(i, j, ACS_CKBOARD);
        attroff(COLOR_PAIR(2));
      }
    }
  }
}
/**
 * @brief Отрисовка уровня и счета
 * @param argc 1
 * @param argv info
 */
void DrawScoreAndLevel(GameInfo info) {
  mvprintw(6, 15, "Score: %d", info.score);
  mvprintw(8, 15, "HighScore: %d", info.highScore);
  mvprintw(10, 15, "Level: %d", info.level);
  mvprintw(12, 15, "P - pause");
  mvprintw(13, 15, "S - continue");
}
/**
 * @brief Инициализация библиотеки ncurses
 * и ее параметров
 * timout величина через которую мы считываем ввод
 */
void InitNcurses() {
  initscr();
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  keypad(stdscr, 1);
  noecho();
  curs_set(0);
  timeout(TIMEOUT);
}
/**
 * @brief Отрисовка меню
 */
void DrawMenu() {
  mvprintw(8, 9, "TETRIS...");
  mvprintw(10, 3, "Press S to start game");
}