
.DEFAULT_GOAL := all

CFLAGS = -O2 -Wall -W -std=c99

LIB_OBJS =

SERVER_OBJS =
SERVER_OBJS += build/main.o

all: cookserver

# ------- target -------

cookserver: $(SERVER_OBJS) $(LIB_OBJS)
	@echo "\033[0;33mbuilding $@\033[0m"
	@$(CC) $(CFLAGS) -flto -o $@ $(filter %.o, $^)

# ------- .o -------

build/%.o: src/%.c
	@mkdir -p build
	@echo "\033[0;32mcompiling $<\033[0m"
	@$(CC) $(CFLAGS) -flto -c $< -o $@

# ------- other -------

clean:
	@rm -rf build cookserver

.PHONY: clean
