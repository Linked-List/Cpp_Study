CXX             = g++
SRCS            = Account.cpp AccountHandler.cpp HighCreditAccount.cpp NormalAccount.cpp Practice05.cpp
OBJS            = $(SRCS:.cpp=.o)
TARGET			= main

all : $(TARGET)
		$(CXX) -o $(TARGET) $(OBJS)
		rm *.o

$(TARGET) :
		$(CXX) -c $(SRCS)