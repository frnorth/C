objects = alloc.o getline2.o lines.o main.o

tail : $(objects)
	cc -o tail $(objects)

.PHONY : clean
clean :
	rm $(objects)
