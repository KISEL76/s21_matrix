COMPILATION = gcc -Wall -Wextra -Wall -std=c11
ADD_FLAGS = --coverage
FN = functions/
TESTS = tests/

S21__C=s21_*.c
S21__H=s21_*.h
S21__O=s21_*.o

SOURCE = $(wildcard ./tests/s21_*.c)
SOURCETESTH = $(wildcard ./tests/s21_*.h)

SYSTEM := $(shell uname -s)

ifeq ($(SYSTEM), Darwin)
	OPEN_CMD = open
	ADD_LIB = -lcheck
	BREW := ${HOME}/homebrew
else ifeq ($(SYSTEM), Linux)
	OPEN_CMD = xdg-open
	ADD_LIB = -lcheck lm -lsubunit
else
		$(error Unsupported system: $(SYSTEM))
endif

all: s21_matrix.a test gcov_report

install:
	if [ $(OS) = "LINUX" ]; then \
		sudo apt-get install -y lcov; \
		sudo apt-get install -y check; \
		sudo apt-get install -y libcapture-tiny-perl; \
		sudo apt-get install -y libdatetime-perl; \
	else \
		brew install lcov; \
	fi
	

s21_matrix.a: $(FN)*.c s21_matrix.h
	$(COMPILATION) -c $(FN)*.c
	ar rc s21_matrix.a *.o
	rm -rf *.o

test: s21_matrix.a
	$(COMPILATION) $(ADD_FLAGS) $(TESTS)*.c s21_matrix.a ${ADD_LIB} -o test

gcov_report: test
	./test
	lcov -t "s21_matrix" -o s21_matrix.info -c -d .
	genhtml -o report s21_matrix.info
	$(OPEN_CMD) report/index.html

check:
		clang-format  -i *.h
		clang-format  -i */*.c */*.h

		cppcheck enable=all missningIncludeSystem ${SOURCE}
		cppcheck enable=all missningIncludeSystem ./*/$(S21__C)
		#cppcheck enable=all missningIncludeSystem ./$(S21__C)

valgrind:
	valgrind --leak-check=full --log-file=log_valgrind ./test

leaks: test
	leaks --atExit -- ./test

clean:
	rm -rf *.a *.o test *.gcno *.gcda *.info report

rebuild: clean all


