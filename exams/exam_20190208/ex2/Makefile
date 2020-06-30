$(MATRICOLA): main.o support.o
	gcc main.o support.o -o $(MATRICOLA)
	sh script.sh

main.o: main.c version.h
	gcc -c main.c

support.o: support.c support.h
	gcc -c support.c

clean:
	rm *.o 123456
