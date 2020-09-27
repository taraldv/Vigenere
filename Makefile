PROG = Vigenere
CC = g++
CPPFLAGS = 
LDFLAGS =
FLAGS =

OBJS = main.o vigenere.o

all: $(PROG) .depend

$(PROG): $(OBJS)
	g++ -o $@ $(OBJS) $(LDFLAGS)

.depend:
	-@$(CC) $(CPPFLAGS) -MM $(OBJS:.o=.cpp) > $@ 2> /dev/null

-include .depend

run:
	./$(PROG).exe

clean:
	rm -f *stackdump $(PROG) *.o .depend
