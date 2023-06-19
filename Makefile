DIRS := $(wildcard q*)

all: $(DIRS) 

$(DIRS):
	$(MAKE) -C $@

test: test.c
	gcc -o test test.c

clean:
	$(foreach D,$(DIRS),$(MAKE) -C $(D) clean;)

.PHONY: all clean $(DIRS)