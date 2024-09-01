OBJS = src/*.cpp

CXX = g++

INCLUDE_PATHS = -I"./include"

LINKER_PATHS = -L"./lib"

LINKER_FLAGS = -lraylib -lgdi32 -lwinmm -lopengl32 -lpthread -ldiscord-rpc -static

OBJ_NAME = owlshooter

all: $(OBJS)
	$(CXX) -o $(OBJ_NAME) $(INCLUDE_PATHS) $(LINKER_PATHS) $(OBJS) $(LINKER_FLAGS) -Wl,--subsystem,windows
