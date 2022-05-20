CC=gcc
LINUX= -lrt -lpthread -lm -D_GNU_SOURCE
OS=$(shell uname -s)

all: s21_cat

s21_cat:
ifeq ($(OS), Darwin)
	$(CC) s21_cat.c -o s21_cat
else
	$(CC) $(LINUX) s21_cat.c -o s21_cat
endif

clean:
	rm -rf *.out s21_cat s21_cat.txt cat.txt test

rebuild: clean all

check: s21_cat
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	python3 ../../materials/linters/cpplint.py --extensions=c *.c 
	CK_FORK=no leaks --atExit -- ./s21_cat tests/1.txt

cat1: s21_cat 
	./s21_cat -n tests/test* >> s21_cat.txt
	cat -n tests/test* >> cat.txt
	./s21_cat -v tests/test* >> s21_cat.txt
	cat -v tests/test* >> cat.txt
	./s21_cat -bes tests/test1 tests/test1 >> s21_cat.txt
	cat -bes tests/test1 tests/test1 >> cat.txt
	./s21_cat -t tests/test_v >> s21_cat.txt
	cat -t tests/test_v >> cat.txt

test: clean cat1
	gcc test.c -o test -lcheck
	./test

