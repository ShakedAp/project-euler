
DIR := $(notdir $(CURDIR))
CFILES = $(wildcard *.c)

all: $(CFILES) 
	gcc -o $(DIR) $(CFILES)

clean:
	@rm -vrf $(DIR)