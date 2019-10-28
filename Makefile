all: main

run:
	./main

ifneq ($(wildcard *.o),)
clean:
	rm *.o
else
clean:
	@echo "No object files!"
endif

main: main.o process.o horario.o mergesort.o
	gcc horario.o process.o mergesort.o main.o -o main

main.o: main.c
	gcc -c main.c

process.o: horario.o process.c
	gcc -c process.c

horario.o: horario.c
	gcc -c horario.c

mergesort.o: mergesort.c
	gcc -c mergesort.c