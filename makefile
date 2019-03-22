all:  bin/exe

CC := g++
SOURCES := $(wildcard src/*cpp)
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
INC := -I./inc
DEPENDS := $(patsubst src/%.cpp,obj/%.dep,$(SOURCES))

C_flags := -c -g -pedantic -std=c++11 -Wall -Wextra 

ifeq ($(MAKECMDGOALS),)
	-include $(DEPENDS)
else ifeq ($(MAKECMDGOALS),all)
	-include $(DEPENDS)
endif


obj/%.dep : src/%.cpp
	mkdir -p obj
	$(CC) $(INC) -MM $< -MT "$@ $(patsubst %.dep,%.o,$@)" -o $@

obj/%.o :
	$(CC) $(C_flags) $(INC) $< -o $@ 

bin/exe : $(OBJECTS) ./bin
	$(CC) $(OBJECTS) -o $@

./bin:
	mkdir -p bin

.PHONY clean: 
	rm -rf ./obj  ./bin




