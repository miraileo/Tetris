#include "../brick_game/tetris/tetris.h"
#include "check.h"
extern Figure figures[];

Suite* Rotate_test(void);
Suite* ControllCollision_test(void);
Suite* FigureCollision_test(void);
Suite* ClearFilledRows_test(void);
Suite* GetScore_test(void);
Suite* ChangeLevel_test(void);
Suite* GameOver_test(void);
Suite* AllocateMemory_test(void);
Suite* PauseGame_test(void);
Suite* StartGame_test(void);
Suite* UserInput_test(void);
Suite* Timer_test(void);
Suite* writeHighScore_test(void);