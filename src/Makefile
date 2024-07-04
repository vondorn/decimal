FLAGS = -Wall -Werror -Wextra # -pedantic
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
CLANGFLAGS = --style=Google --verbose
LIBCHECK = $(shell pkg-config --libs check)
CFILES = decimal.c bozhe.c bolshe-menshe-libo-ravno.c test.c
ifeq ($(shell uname -r | grep WSL -o), WSL)
	HTML_OPEN = @echo HTML report is in $(shell pwd)/report/index.html
else ifeq ($(shell uname -s), Linux)
	HTML_OPEN = @xdg-open ./report/index.html
else
	HTML_OPEN = @open ./report/index.html
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
de:
	@gcc $(FLAGS) decimal.c bolshe-menshe-libo-ravno.c bozhe.c -o s21_decimal
	@./s21_decimal
test: s21_decimal.a
	clang-format -n $(CLANGFLAGS) $(CFILES)
	gcc $(FLAGS) test.c s21_decimal.a $(LIBCHECK) -o test.out
	./test.out
gcov_report: check
	@rm -rf report
	clang-format -n $(CLANGFLAGS) $(CFILES)
	gcc $(FLAGS) $(GCOV_FLAGS) $(CFILES) -o gcov_report.out $(LIBCHECK)
	./gcov_report.out
	lcov -t "s21_decimal" -o s21_decimal.info -c -d . -q
	genhtml -o report s21_decimal.info -q
	@rm -f s21_decimal.info *.gcda *gcno gcov_report.out
	$(HTML_OPEN)
s21_decimal.a: check
	gcc $(FLAGS) -c -o s21_decimal.o decimal.c
	gcc $(FLAGS) -c -o bolshe-menshe-libo-ravno.o bolshe-menshe-libo-ravno.c
	gcc $(FLAGS) -c -o bozhe.o bozhe.c
	ar rcs s21_decimal.a s21_decimal.o bolshe-menshe-libo-ravno.o bozhe.o
	@rm -f *.o
clean:
	rm -f *.a *.o *.info *.gcda *.gcno *.out
	rm -rf report
rebuild: clean all

style_check:
	clang-format -n $(CLANGFLAGS) $(CFILES)
style_fix:
	clang-format -i $(CLANGFLAGS) *.c *.h

valgrind: clean test
	valgrind --tool=memcheck --leak-check=yes ./test.out

# nado dobavit "srunner_set_fork_status(SuiteRun, CK_NOFORK)" v testi