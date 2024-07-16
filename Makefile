OBJS = *.cpp

CXX = clang

INCLUDE_PATHS = -I"/usr/include"

LINKER_PATHS = -L"/usr/local/lib"

LINKER_FLAGS = -lraylib

OBJ_NAME = owlshooter

all: $(OBJS)
	$(CXX) $(INCLUDE_PATHS) $(LINKER_PATHS) -o $(OBJ_NAME) $(OBJS) $(LINKER_FLAGS)
