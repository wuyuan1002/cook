
CFLAGS = -O2 -Wall -W -std=c99

LIB_OBJS =

COOK_OBJS =
COOK_OBJS += main.o


all: cook

cook: $(COOK_OBJS) $(LIB_OBJS)
	$(QUIET_LINK) $(CC) $(CFLAGS) -o $@ $(filter %.o, $^)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o cook
