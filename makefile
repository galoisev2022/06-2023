CPP=g++
CFLAGS=-Wall -O
LDFLAGS=
EXEC=main
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

main:	$(OBJ)
	$(CPP) -o $@ $^ $(LDFLAGS)
	
main.o: point2d.h

%.o: %.cpp
	$(CPP) -o $@ -c $< $(CFLAGS)
	
	
run:
	./$(EXEC)
	
clean:
	rm -f *.o core
	
mrproper:
	rm -f $(EXEC)


cls:
	clear





