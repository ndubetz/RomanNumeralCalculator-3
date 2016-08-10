
OBJECTS = Converter.o

CFLAGS = -g

.PHONY: all clean

all: roman_calculator

clean:
	rm -f *.o
	rm -f ../roman_calculator
	
roman_calculator: $(OBJECTS)
	$(CC) $(CFLAGS) -o ../$@ $^ $(LIBS)

