BIN	= bin
CXX	= g++
SET = -Wall -Wextra -std=c++17 -ggdb
EXE	= main
INC	= -I/usr/include/SDL2 -Iinc
LIB	= -lSDL2 -lSDL2main
SRC	= src/*.cpp

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(SRC)
	$(CXX) $(SET) $(INC) $^ -o $@ $(LIB)

run: clean all
	clear
	./$(BIN)/$(EXE)

.PHONY: clean
clean:
	rm $(BIN)/*