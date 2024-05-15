#include "../../gui/cli/graphics.h"

/**
 * @brief Инициализация массива с фигурами
 */

Figure figures[] = {
    {{{0, 1, 0}, {1, 1, 1}, {0, 0, 0}}, 3},
    {{{1, 1, 0}, {0, 1, 1}, {0, 0, 0}}, 3},
    {{{1, 1, 0}, {1, 1, 0}, {0, 0, 0}}, 3},
    {{{0, 1, 1}, {1, 1, 0}, {0, 0, 0}}, 3},
    {{{1, 0, 0}, {1, 1, 1}, {0, 0, 0}}, 3},
    {{{0, 0, 1}, {1, 1, 1}, {0, 0, 0}}, 3},
    {{{1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, 4},
};

/**
 * @brief Основная функция
 *
 * Здесь вызываются все написанные функции в определенном порядке
 * для создания игры
 *
 * Сначал происходит инициализация всех необходимых структур и выделение памяти
 * под игровое поле
 *
 * После чего в цикле идет проверка паузы и старта игры
 *
 * Затем идет основная логика игры и вывод информации
 *
 * @return 0
 */
int main() {
  Figure figure;
  Figure nextFigure;
  GameInfo info;
  TimeInfo time;
  InitNcurses();
  InitGameInfo(&info, &figure, &nextFigure, figures);
  AllocateMemory(&info);
  InitTime(&time);
  if (InitField(info)) {
    while ((info.inputChar = getch()) != Terminate) {
      if (info.pause == Pause && info.startGame == Pause) {
        info.pause = PauseGame(info);
        clear();
        Timer(&time, 1);
        PaintBorders();
        if (!FigureCollision(info, figure) && time.seconds >= info.speed) {
          info.y++;
          Timer(&time, 0);
        }
        if (FigureCollision(info, figure)) {
          GameOver(&info);
          if (info.gameOver) break;
          UpdateCurrentState(&info, &figure, &nextFigure, figures);
        }
        UserInput(&info, &figure);
        DrawFigure(figure, info, 1);  // отрисовка текущей фигуры
        DrawField(info);
        DrawFigure(nextFigure, info, 0);  // отрисовка след. фигуры
        GetScore(&info);
        DrawScoreAndLevel(info);
        ChangeLevel(&info);
      } else {
        if (info.startGame == Start) {
          DrawMenu();
          info.startGame = StartGame(info);
        }
        info.pause = StartGame(info);
      }
    }
  }
  FreeMemory(&info);
  endwin();
  return 0;
}