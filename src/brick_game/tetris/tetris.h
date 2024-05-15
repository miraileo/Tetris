#include <math.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#define WIDTH 12
#define HEIGHT 21
#define STARTWIDTH 4
#define STARTHEIGHT 0
#define TIMEOUT 100

typedef struct {
  int matrix[4][4];
  int size;
} Figure;

typedef struct {
  int **array;
  int x;
  int y;
  int score;
  int previousScore;
  int highScore;
  int rowFilled;
  int inputChar;
  int gameOver;
  int level;
  double speed;
  int pause;
  int startGame;
} GameInfo;

typedef struct {
  struct timeval start_time, current_time;
  double seconds;
} TimeInfo;

typedef enum {
  Start = 1,
  Pause = 0,
  Terminate = 27,
  Left = KEY_LEFT,
  Right = KEY_RIGHT,
  Up = KEY_UP,
  Down = KEY_DOWN,
} UserAction;

int ControllCollision(GameInfo info, Figure figure, int state);
int InitField(GameInfo info);
int RotateFigure(Figure *figure, GameInfo info);
void SaveField(GameInfo *info, Figure figure);
int FigureCollision(GameInfo info, Figure figure);
int ClearFilledRows(GameInfo *info);
Figure getRandomFigure(Figure *figures);
int readHighScore();
void writeHighScore(GameInfo *info);
void UserInput(GameInfo *info, Figure *figure);
void GetScore(GameInfo *info);
void InitGameInfo(GameInfo *info, Figure *figure, Figure *nextFigure,
                  Figure *figures);
void InitTime(TimeInfo *time);
void Timer(TimeInfo *time, int command);
void ChangeLevel(GameInfo *info);
void UpdateCurrentState(GameInfo *info, Figure *figure, Figure *nextFigure,
                        Figure figures[]);
void GameOver(GameInfo *info);
int PauseGame(GameInfo info);
int StartGame(GameInfo info);
int AllocateMemory(GameInfo *info);
void FreeMemory(GameInfo *info);