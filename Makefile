
CC = gcc

#LD = gcc
#HDF_INCLUDE =
#HDF_LIB =
#COPTS += -DNO_USE_HDF

COPTS = -g -fPIC -D_GNU_SOURCE -O0 -Wall -Wstrict-aliasing  -fstrict-aliasing
COPTS += -DNO_DEBUG_

#COPTS += -fsanitize=address
#LOPTS += -fsanitize=address

METIS_INCLUDE = -I$(METIS_HOME)/include
METIS_LIB = -L$(METIS_HOME)/lib

all: demo

demo:
	$(CC) $(COPTS) $(METIS_INCLUDE) -c main.c -o main.o
	$(CC) $(LOPTS) -o a.out main.o $(METIS_LIB) -lmetis

clean:
	rm -f *.o *.so *.a a.out *.mod
