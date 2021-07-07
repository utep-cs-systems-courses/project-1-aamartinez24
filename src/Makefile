project1: tokenizer.o history.o main.o
	cc -o project1 tokenizer.o history.o main.o

clean:
	rm -f *.o project1

tokenizer.o: tokenizer.h tokenizer.c

history.o: history.h history.c

main.o: tokenizer.h history.h main.c
