OUTPUTS = main 
CC = gcc
includes = $(wildcard commands/*.h) main



all: clean $(OUTPUTS)
depend: .depend

clean:
	rm -f main
	rm -f $(OUTPUTS)
	rm -f -r *.o
app: main.c 


 
.PHONY:  all  

%.o: %.c ${includes}
	$(CC) -c -Wall -Iinclude - Werror $@ $<
