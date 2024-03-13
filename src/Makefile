
CFLAGS = -O2 -Wall -W -std=c99

LIB_OBJS =

SERVER_OBJS =
SERVER_OBJS += build/server_main.o

all: cookserver

cookserver: $(SERVER_OBJS) $(LIB_OBJS)
	$(CC) $(CFLAGS) -o $@ $(filter %.o, $^)

build/%.o: %.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@
