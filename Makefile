.PHONY: all

all:
	gcc -o beep beep.c -lwiringPi -lm
	gcc -o erika erika.c -lwiringPi -lm
