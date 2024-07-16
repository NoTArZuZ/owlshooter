OBJS = *.cpp

CXX = g++

INCLUDE_PATHS = -I"include/" -I"/usr/include" -I"/usr/local/include"

LINKER_PATHS = -L"lib/" -L"/usr/lib" -L"/usr/local/lib"

LINKER_FLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -lc

OBJ_NAME = owlshooter

all: $(OBJS)
	$(CXX) $(INCLUDE_PATHS) $(LINKER_PATHS) -Wall -Wl,-rpath,lib/ -o $(OBJ_NAME) $(OBJS) $(LINKER_FLAGS)
