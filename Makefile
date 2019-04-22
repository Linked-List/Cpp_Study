CXX             = g++
SRCS            = $(wildcard *.cpp)
OBJS            = $(SRCS:.cpp=.o)
TARGET			= main.exe

all : $(TARGET)
		$(CXX) -o $(TARGET) $(OBJS)
		del *.o

$(TARGET) :
		$(CXX) -c $(SRCS)