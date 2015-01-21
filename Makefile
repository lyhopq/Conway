EXECUTABLE := main
LIBS :=
INCLUDES := include
SRCDIR:= . src
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
	rm -f src/*.o
	rm -f $(EXECUTABLE)

$(EXECUTABLE) : $(OBJS)
	$(CC) -o $(EXECUTABLE) $(OBJS) $(addprefix -l,$(LIBS))
