CFLAGS     = -g -O2 -Wall -Werror -std=c17 -Wdiscarded-qualifiers -Wincompatible-pointer-types -Wint-conversion
CC         = gcc
LD         = gcc
ASM        = nasm
ASMFLAGS   =-felf64 -g

# Если есть код на C, то компоновку тоже нужно производить
# с помощью gcc, а не ld
code: code.o
	$(LD) -o $@ $^

# target : dependencies
#     do this
code.o: code.c 
	$(CC) -c $(CFLAGS) -o $@ $<

clean: 
	$(RM) code code.o

.PHONY: clean


