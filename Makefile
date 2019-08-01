a.out: main.o prioridad.o
	gcc main.o prioridad.o
	make clean

main.o: main.c
	gcc -c main.c

prioridad.o: prioridad.c
	gcc -c prioridad.c

clean: 
	rm main.o prioridad.o