C_FILES := $(wildcard ../src/*.cpp)
OBJ_FILES = $(addsuffix .o, $(addprefix obj/, $(basename $(notdir $(C_FILES)))))
$(info $(OBJ_FILES))
CC = g++
FLAGS = -std=c++11 -Wall -O3 
LIBS = -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-system
EXE_NAME = geometric_rain

all: makedirs main

clear:
	rm -r obj/

obj/%.o : ../src/%.cpp
	$(CC) $(FLAGS) -c $< -o $@ $(LIBS)

makedirs:
	mkdir -p obj
	
main: $(OBJ_FILES)
	$(CC) $(FLAGS) $^ -o $(EXE_NAME) $(LIBS)
