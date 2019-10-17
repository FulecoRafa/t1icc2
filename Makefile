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

test: horario.o process.o
	gcc horario.o process.o teste.o -o teste
	./teste

teste.o:
	gcc -c teste.c

main: main.o process.o horario.o
	gcc horario.o process.o main.o -o main

main.o:
	gcc -c main.c

process.o: horario.o
	gcc -c process.c

horario.o:
	gcc -c horario.c