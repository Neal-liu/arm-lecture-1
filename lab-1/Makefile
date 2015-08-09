CC	= arm-linux-gnueabihf-gcc
CFLAGS	= -O1 -Wall
LDFLAGS = -fno-stack-protector

objects	= fibseq.o fib.o
objects2 = fibtime.o fib.o

default: fibseq

.PHONY: default clean qemu

fibseq: $(objects)
	$(CC) $(LDFLAGS) -o $@ $^

fibtime: $(objects2)
	$(CC) $(LDFLAGS) -o $@ $^
	qemu-arm -L /usr/arm-linux-gnueabihf ./fibtime

fib.o: fib.s
fibseq.o: fibseq.c
fibtime.o: fibtime.c

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

%.o: %.s
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(objects) $(objects2) fibseq fibtime time

QEMU_CMD = qemu-arm -L /usr/arm-linux-gnueabihf ./fibseq &
CMD = yes 9 | $(call QEMU_CMD) && sleep 1

qemu: fibseq 
	@yes 5 | $(call QEMU_CMD)
	@sleep 1
	@yes 6 | $(call QEMU_CMD)
	@sleep 1
	@yes 7 | $(call QEMU_CMD)
	@sleep 1
	@ sh test.sh
