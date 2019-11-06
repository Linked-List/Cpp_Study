CXX             = g++
SRCS            = $(wildcard *.cpp)
OBJS            = $(SRCS:.cpp=.o)
TARGET			= main

all : $(TARGET)
		$(CXX) -o $(TARGET) $(OBJS)
		rm *.o

$(TARGET) :
		$(CXX) -c $(SRCS)