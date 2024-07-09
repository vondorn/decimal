FLAGS = -Wall -Werror -Wextra -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
CLANG_FLAGS = --style=Google --verbose
LIBCHECK = $(shell pkg-config --libs check)
CFILES = additional_funcs.c arithmetic.c comparison.c conversion.c others.c tests.c
REPORT_DIR = /report/index.html

ifeq ($(shell uname -r | grep WSL -o), WSL)
	HTML_OPEN = @echo HTML report is in $(shell pwd)$(REPORT_DIR)
else ifeq ($(shell uname -s), Linux)
	HTML_OPEN = @xdg-open .$(REPORT_DIR)
else
	HTML_OPEN = @open .$(REPORT_DIR)
endif

all: test

check: 
ifeq ("", "$(shell which pkg-config)")
	$(error "Please install pkg-config")
else ifeq ("", "$(LIBCHECK)")
	$(error "Please install check")
else ifeq ("", "$(shell which lcov)")
	$(error "Please install lcov")
endif
test: check s21_decimal.a 
	clang-format -n $(CLANG_FLAGS) $(CFILES)
	gcc $(FLAGS) tests.c s21_decimal.a -o test.out $(LIBCHECK)
	./test.out
gcov_report: check
	@rm -rf report
	clang-format -n $(CLANG_FLAGS) $(CFILES)
	gcc $(FLAGS) $(GCOV_FLAGS) $(CFILES) -o gcov_report.out $(LIBCHECK)
	./gcov_report.out
	lcov -t "s21_decimal" -o s21_decimal.info -c -d . -q
	genhtml -o report s21_decimal.info -q
	@rm -f s21_decimal.info *.gcda *gcno gcov_report.out
	@rm -f *.o
	$(HTML_OPEN)
s21_decimal.a:
	gcc $(FLAGS) -c -o arithmetic.o arithmetic.c
	gcc $(FLAGS) -c -o comparison.o comparison.c
	gcc $(FLAGS) -c -o conversion.o conversion.c
	gcc $(FLAGS) -c -o others.o others.c
	gcc $(FLAGS) -c -o additional_funcs.o additional_funcs.c
	ar rcs s21_decimal.a arithmetic.o others.o comparison.o conversion.o additional_funcs.o
	@rm -f *.o
clean:
	rm -f *.a *.o *.info *.gcda *.gcno *.out
	rm -rf report
rebuild: clean all

style_check:
	clang-format -n $(CLANG_FLAGS) $(CFILES)
style_fix:
	clang-format -i $(CLANG_FLAGS) *.c *.h

valgrind: clean test
	valgrind --tool=memcheck --leak-check=yes ./test.out