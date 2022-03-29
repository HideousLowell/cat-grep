CC=gcc
FLAGS=#-Werror -Wall -Wextra -std=c11
LINUX=-lsubunit -lrt -lpthread -lm -D_GNU_SOURCE
LIBS = -lcheck
CFLAGS=-fprofile-arcs -ftest-coverage
OS=$(shell uname -s)

all: clean test s21_math.a

s21_math.a: s21_math.o
	ar rcs s21_math.a s21_math.o
	cp s21_math.a libs21_math.a
	ranlib libs21_math.a

s21_math.o:
	$(CC) $(FLAGS) -c s21_math.c -o s21_math.o

test: s21_math.a
ifeq ($(OS), Darwin)
	$(CC) test.c -o test -L. $(LIBS) -ls21_math
	./test
else
	$(CC) test.c -o test -L. $(LIBS) -ls21_math $(LINUX)
	./test
endif

gcov_report: s21_math.a
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) test.c s21_math.c -o test -L. $(LIBS) -ls21_math
else
	$(CC) $(CFLAGS) test.c s21_math.c -o test -L. $(LIBS) -ls21_math $(LINUX)
endif
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info

clean:
	rm -rf *.gc* *.o *.a *.out *.info test
	rm -rf report/

open:
	open report/index.html

rebuild: clean all

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	make test
	CK_FORK=no leaks --atExit -- ./test
	make clean