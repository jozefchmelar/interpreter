OUTPUTS = main
CC = gcc
all: $(OUTPUTS)

app: main.c commands/prezri.h

clean:
	rm -f $(OUTPUTS)
	rm -f -r *.o
	rm make

.PHONY: all clean

%.o: %.c 
	$(CC) -c  $@ $<
