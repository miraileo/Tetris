#include "../../brick_game/tetris/tetris.h"

void InitNcurses();
void DrawScoreAndLevel(GameInfo info);
void DrawField(GameInfo info);
void PaintBorders();
void DrawFigure(Figure figure, GameInfo info, int command);
void DrawMenu();