all: main

ifneq ($(wildcard *.o),)
clean:
	rm *.o
else
clean:
	@echo "No object files!"
endif

run:
	./main

main: main.o process.o horario.o mergesort.o
	gcc horario.o process.o mergesort.o main.o -o main

main.o:
	gcc -c main.c

process.o: horario.o
	gcc -c process.c

horario.o:
	gcc -c horario.c

mergesort.o:
	gcc -c mergesort.c