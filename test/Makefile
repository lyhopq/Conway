EXECUTABLE := main
LIBS := gtest pthread
INCLUDES := ../src
SRCDIR:= . $(INCLUDES)
CC:=g++
CPPFLAGS := -g -Wall -O3
CPPFLAGS += $(addprefix -I,$(INCLUDES))

SRCS := $(wildcard $(addsuffix /*.cpp, $(SRCDIR)))
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

.PHONY : all objs clean

all: $(EXECUTABLE)

objs : $(OBJS)

clean :
	rm -f *.o
	rm -f $(EXECUTABLE)
	rm -f ../src/*.o

$(EXECUTABLE) : $(OBJS)
	$(CC) -o $(EXECUTABLE) $(OBJS) $(addprefix -l,$(LIBS))
