CC = gcc
CFLAGS = -Wall -Wextra -Werror -lm -lncurses -std=c11
TESTFLAGS = -lcheck -lm -lpthread -lrt -lsubunit

SRC_DIR = brick_game/tetris
GUI_DIR = gui/cli
TESTS_DIR = tests
INSTALL_DIR = /usr/local/bin
CURRENT_USER := $(shell whoami)
EXECUTABLE = s21_tetris.a
TEST = s21_tetris_test

all: $(EXECUTABLE)

$(EXECUTABLE):
	$(CC) $(SRC_DIR)/*.c $(GUI_DIR)/*.c $(CFLAGS) -o $(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE)
	rm -rf doxygen
	rm -rf s21_tetris_test
	rm -rf test.info 
	rm -rf report
	rm -rf *.gcno *.gcda

install: preinstall $(EXECUTABLE)
	cp $(EXECUTABLE) $(INSTALL_DIR)

uninstall:
	rm -rf $(INSTALL_DIR)/$(EXECUTABLE)

preinstall:
	sudo usermod -aG staff $(CURRENT_USER)
	sudo chown root:staff /usr/local/bin
	sudo chmod 777 /usr/local/bin

dvi:
	doxygen
	open doxygen/html/index.html

dist: clean uninstall
	mkdir ../dist
	cp -r ../src ../dist
	cp ../README.md ../dist
	cd ../dist && tar -czvf dist.tar.gz ./src
	rm -rf ../dist/src

uninstallDist:
	rm -rf ../dist

style:
	clang-format -n -style=google $(SRC_DIR)/*.c $(SRC_DIR)/*.h $(GUI_DIR)/*.c $(GUI_DIR)/*.h $(TESTS_DIR)/*.h $(TESTS_DIR)/*.c
	clang-format -i -style=google $(SRC_DIR)/*.c $(SRC_DIR)/*.h $(GUI_DIR)/*.c $(GUI_DIR)/*.h $(TESTS_DIR)/*.h $(TESTS_DIR)/*.c
	clang-format -n -style=google $(SRC_DIR)/*.c $(SRC_DIR)/*.h $(GUI_DIR)/*.c $(GUI_DIR)/*.h $(TESTS_DIR)/*.h $(TESTS_DIR)/*.c

test:
	$(CC) $(SRC_DIR)/tetris.c $(TESTS_DIR)/*.c $(CFLAGS) $(TESTFLAGS) --coverage -o $(TEST)
	./s21_tetris_test

valgrind:
	valgrind --leak-check=full ./s21_tetris_test

gcov_report: test
	@lcov -t "s21_tetris_test" -o test.info -c -d .
	@genhtml -o report test.info
	open report/index.html
	rm -rf *.gcno *gcda *.gco
