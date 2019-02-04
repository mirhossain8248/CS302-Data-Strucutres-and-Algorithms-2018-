OBJS	= proj4.o
SOURCE	= proj4.cpp
HEADER	=
OUT	= proj4
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

proj4.o: proj4.cpp
	$(CC) $(FLAGS) proj4.cpp


clean:
	rm -f $(OBJS) $(OUT)
