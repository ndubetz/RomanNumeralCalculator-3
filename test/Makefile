
CFLAGS = `pkg-config --cflags check`
LIBS = `pkg-config --libs check`
VPATH = ../src

TEST_OBJECTS = check_ArabicToRoman.o check_RomanToArabic.o check_Calculator.o

OBJECTS = ArabicToRoman.o RomanToArabic.o Calculator.o

.PHONY = clean test

test: run_all_tests
	./run_all_tests
	
run_all_tests: $(OBJECTS) $(TEST_OBJECTS) AllTests.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	
AllTests.o: $(TEST_OBJECTS)

clean:
	rm -f *.o
	rm -f run_all_tests
	


