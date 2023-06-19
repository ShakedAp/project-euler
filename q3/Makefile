DIR := $(notdir $(CURDIR))
CFILES := $(wildcard *.c)
LIBS := -lm

all: $(CFILES) 
	gcc -o $(DIR) $(CFILES) $(LIBS)

clean:
	@rm -vrf $(DIR)