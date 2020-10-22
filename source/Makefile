CC=g++
EXTC=cpp
EXTH=h
SRC=$(wildcard *.$(EXTC))
HDR=$(wildcard *.$(EXTH))
OBJ=$(SRC:.$(EXTC)=.o)
EXECUTABLE=main

.PHONY=all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	@$(CC) -o $@ $^

%.o: %.$(EXTC) %.$(EXTH)
	@$(CC) -o $@ -c $<



clean:
	rm -f *.o
	rm -f $(EXECUTABLE)

