CC = g++
FLAGS = -c
BINS = main clean


all: $(BINS)
default: clean

clean:
	rm -f build/*.o

frame.o:
	$(CC) $(FLAGS) src/frame.cpp -o build/frame.o

main: frame.o
	$(CC) src/main.cpp build/frame.o -o build/main.exe