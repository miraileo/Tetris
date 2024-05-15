#include "test.h"
Figure figures[] = {
    {{{0, 1, 0}, {1, 1, 1}, {0, 0, 0}}, 3},
    {{{1, 1, 0}, {0, 1, 1}, {0, 0, 0}}, 3},
    {{{1, 1, 0}, {1, 1, 0}, {0, 0, 0}}, 3},
    {{{0, 1, 1}, {1, 1, 0}, {0, 0, 0}}, 3},
    {{{1, 0, 0}, {1, 1, 1}, {0, 0, 0}}, 3},
    {{{0, 0, 1}, {1, 1, 1}, {0, 0, 0}}, 3},
    {{{1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, 4},
};
int main(void) {
  int failed = 0;
  Suite *s21_tetris[] = {Rotate_test(),          ControllCollision_test(),
                         FigureCollision_test(), ClearFilledRows_test(),
                         GetScore_test(),        ChangeLevel_test(),
                         GameOver_test(),        AllocateMemory_test(),
                         PauseGame_test(),       StartGame_test(),
                         UserInput_test(),       Timer_test(),
                         writeHighScore_test(),  NULL};

  for (int i = 0; s21_tetris[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_tetris[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return 0;
}