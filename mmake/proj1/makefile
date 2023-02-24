TARGET = Proj1

objects = main.o mymath.o myplus.o

.PHONY: clean

all : $(objects)
	gcc -o $(TARGET) $(objects)

main.o : main.c
	gcc -c main.c

mymath.o : mymath.c myplus.c
	gcc -c mymath.c

clean:
	-rm -f $(shell find ./ -name '*.o')
	-rm -f $(shell find ./ -name '*.d')
	-rm -f $(shell find ./ -name '*.map')
	-rm -f $(shell find ./ -name '*.elf')
	-rm -f $(shell find ./ -name '*.bin')
	-rm -f $(shell find ./ -name '*.hex')
	-rm -f builded
