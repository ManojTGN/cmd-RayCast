CC = g++
FLAGS = -c
BINS = main clean


all: $(BINS)
default: clean

clean:
	rm -f build/*.o

map.o:
	$(CC) $(FLAGS) src/map.c -o build/map.o

screen.o:
	$(CC) $(FLAGS) src/screen.c -o build/screen.o

main: screen.o map.o
	$(CC) src/main.c build/screen.o build/map.o -o build/main.exe