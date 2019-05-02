objects = getch.o getop.o main.o stack.o

calculator : $(objects)
	cc -o calculator $(objects) -lm

.PHONY : clean
clean :
	rm $(objects)
