CC=gcc
CFLAGS=-Wall -Werror -Wextra -Wpedantic -std=c11
GCOV_FLAGS=--coverage
TESTDIR=./unit_tests/
OS=$(shell uname -s)
USERNAME=$(shell whoami)

ifeq ($(OS), Linux)
	LEAK_CHECK=valgrind --tool=memcheck --leak-check=yes
	OPEN_CMD=xdg-open
	ADD_LIB=-pthread -lcheck_pic -pthread -lrt -lm -lsubunit
else ifeq ($(OS), Darwin)
	LEAK_CHECK=leaks -atExit --
	OPEN_CMD=open 
	ADD_LIB=-lm -lcheck -lpthread
endif

all: s21_math.a test gcov_report clean

s21_math.a:
	@$(CC) -c $(CFLAGS) -o s21_math.o s21_math.c
	ar -rcs s21_math.a s21_math.o

test: clean s21_math.a
	@$(CC) -c $(CFLAGS) unit_tests/*.c $(ADD_LIB)
	@$(CC) $(CFLAGS) -o test *.o s21_math.a $(ADD_LIB)
	@rm -rf *.o s21_math.a
	./test
	@rm -rf test

gcov_report: clean
	@$(CC) -c $(CFLAGS) $(GCOV_FLAGS) s21_math.c
	@$(CC) -c $(CFLAGS) $(GCOV_FLAGS) unit_tests/*.c $(ADD_LIB)
	@$(CC) $(CFLAGS) $(GCOV_FLAGS) *.o -o gcov_test $(ADD_LIB)
	./gcov_test
	@lcov -c -d . -o gcov_test.info
	@rm -rf *.out *.o *.gcno *.gcda gcov_test
	@genhtml -o report gcov_test.info
	@chmod 777 report/*
	@$(OPEN_CMD) ./report/index.html
	@rm -rf report/ *.info

leaks: clean s21_math.a
	@$(CC) -c $(CFLAGS) unit_tests/*.c $(ADD_LIB)
	@$(CC) $(CFLAGS) -o leaks_test *.o s21_math.a $(ADD_LIB)
	@rm -rf *.o s21_math.a
	$(LEAK_CHECK) ./leaks_test
	@rm -rf leaks_test

rebuild: clean s21_math.a

clean:
	@rm -rf *.out *.o *.a
	@rm -rf *.gcno *.gcda *.info
	@rm -rf report/
	@rm -rf test gcov_test

clang:
	@clang-format -n *.c *.h 
	@clang-format -n $(TESTDIR)*.h $(TESTDIR)*.c
	
