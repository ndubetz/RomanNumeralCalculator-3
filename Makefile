
SUBDIRS=test

.PHONY: all test clean

all: test

clean:
	$(MAKE) -C test clean

test: clean src
	$(MAKE) -C test
