CC = g++
CFLAGS = -g -Wall

LINKER_FLAGS = -lraylib

SRC = $(shell find src -name "*.cpp")
OBJ = $(SRC:.cpp=.o)
BIN = bin
NAME = game 

.PHONY: all clean

all: dirs libs build

libs:
	cd lib/raylib && cmake -B build && cmake --build build

dirs:
	mkdir -p ./$(BIN)

run: build
	./$(BIN)/$(NAME)

build: dirs $(OBJ)
	$(CC) -o $(BIN)/$(NAME) $(filter %.o,$^) -w $(LINKER_FLAGS) $(CFLAGS)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(BIN) $(OBJ)

db:
	gdb ./$(BIN)/$(NAME)
