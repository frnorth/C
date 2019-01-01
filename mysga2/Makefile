
VPATH=./src/

obj = mysga.o random_list.o fo.o

mysga: $(obj)
	cc -o mysga $(obj) -lm

mysga.o: mysga.c mysga.h global_conf.h
	cc -c ./src/mysga.c
random_list.o: random_list.c global_conf.h
	cc -c ./src/random_list.c
fo.o: fo.c global_conf.h
	cc -c ./src/fo.c

clean: 
	rm -rf $(obj)
