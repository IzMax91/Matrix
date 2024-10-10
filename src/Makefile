CC=gcc

ifeq ($(shell uname), Darwin)
	LIBS = $(shell pkg-config --libs check)
else
	LIBS = -lcheck -lsubunit -lrt -lm -lpthread
endif

FLAGS =-c -Wall -Werror -Wextra -std=c11

CFLAGS = -c -Wall -Werror -Wextra -std=c11 $(LIBS)

all: gcov_report

s21_matrix.a:
	$(CC) $(FLAGS) *.c

	ar rc s21_matrix.a *.o
	ranlib s21_matrix.a

test: gcov_s21_matrix.a
	$(CC) $(CFLAGS) ./tests/*.c
	$(CC) --coverage *.o s21_matrix.a $(LIBS) -o s21_matrix_test
	./s21_matrix_test

gcov_s21_matrix.a:
	rm -f s21_matrix.a
	$(CC) --coverage $(CFLAGS) *.c
	ar rc s21_matrix.a *.o
	ranlib s21_matrix.a

gcov_report: test
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	open ./report/src/index.html

clean:
	rm -rf *.o s21_*_test *.gcda *.gcno *.css *.html *.gcov *.a *.info report

rebuild: clean all
