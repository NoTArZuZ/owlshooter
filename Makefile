OBJS = *.cpp

CXX = clang

INCLUDE_PATHS = -I"include/" -I"/usr/include"

LINKER_PATHS = -L"lib/" -L"/usr/lib"

LINKER_FLAGS = -lraylib -lglfw

OBJ_NAME = owlshooter

all: $(OBJS)
	$(CXX) $(INCLUDE_PATHS) $(LINKER_PATHS) -Wl,-rpath,lib/ -o $(OBJ_NAME) $(OBJS) $(LINKER_FLAGS)
