CC=gcc
LINUX= -lrt -lpthread -lm -D_GNU_SOURCE
OS=$(shell uname -s)

all: clean s21_grep

s21_grep:
ifeq ($(OS), Darwin)
	$(CC) s21_grep.c -o s21_grep
else
	$(CC) $(LINUX) s21_grep.c -o s21_grep
endif

clean:
	rm -rf *.out s21_grep s21_grep.txt grep.txt test

rebuild: clean all

check: clean s21_grep
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	python3 ../../materials/linters/cpplint.py --extensions=c *.c
	CK_FORK=no leaks --atExit -- ./s21_grep a 123.txt

grep1: s21_grep
	./s21_grep -i -ea -e t 123.txt >> s21_grep.txt
	grep -i -ea -e t 123.txt >> grep.txt
	./s21_grep -v -c a 123.txt 123.txt >> s21_grep.txt
	grep -v -c a 123.txt 123.txt >> grep.txt
	./s21_grep -nof pat.txt 123.txt 123.txt >> s21_grep.txt
	grep -nof pat.txt 123.txt 123.txt >> grep.txt
	./s21_grep -hs a 123.txt>> s21_grep.txt
	grep -hs a 123.txt >> grep.txt
	./s21_grep -l a 123.txt 123.txt>> s21_grep.txt
	grep -l a 123.txt 123.txt >> grep.txt

test: clean grep1
	gcc test.c -o test -lcheck
	./test

