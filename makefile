CC = g++
FLAGS = -c
BINS = main clean


all: $(BINS)
default: clean

clean:
	rm -f build/*.o

screen.o:
	$(CC) $(FLAGS) src/screen.c -o build/screen.o

main: screen.o
	$(CC) src/main.c build/screen.o -o build/main.exe