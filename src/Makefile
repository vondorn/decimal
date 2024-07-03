GC = gcc 

all: test

de:
	@$(GC) decimal.c bolshe-menshe-libo-ravno.c bozhe.c -o s21_decimal
	@./s21_decimal

style:
	clang-format -i --style=Google *.c
test: s21_decimal.a
	$(GC) test.c bolshe-menshe-libo-ravno.c bozhe.c decimal.c $(shell pkg-config --libs check)
	./a.out
s21_decimal.a:
	$(GC) -c -o s21_decimal.o decimal.c
	$(GC) -c -o bolshe-menshe-libo-ravno.o bolshe-menshe-libo-ravno.c
	$(GC) -c -o bozhe.o bozhe.c
	ar rcs s21_decimal.a s21_decimal.o bolshe-menshe-libo-ravno.o bozhe.o

