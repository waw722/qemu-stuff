# target executable name
TARGET 	= testprog

# compiler settings
CC 		= gcc
CFLAGS 	= -std=c11 -m64 -Wall -Wextra -Wpedantic

# files
HEADERS = $(shell find . -name '*.h')
COBJ 	= $(shell find . -name '*.c' | sed -e 's/\.c/\.o/')

all: $(TARGET)
	@:

$(TARGET): $(COBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf *.o $(TARGET)

.PHONY: all clean
