GC = gcc -Wall -Werror -Wextra -std=c11

all: de 

de:
	@$(GC) decimal.c -o s21_decimal
	@./s21_decimal

style:
	clang-format -i --style=Google *.c 