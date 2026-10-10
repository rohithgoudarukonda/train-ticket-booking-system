a.out : main.o user.o train.o booking.o menu.o utility.o
	gcc main.o user.o train.o booking.o menu.o utility.o -o a.out

main.o : main.c
	gcc -c main.c

user.o : user.c
	gcc -c user.c

train.o : train.c
	gcc -c train.c

booking.o : booking.c
	gcc -c booking.c

menu.o : menu.c
	gcc -c menu.c

utility.o : utility.c
	gcc -c utility.c

clean:
	rm -f *.o a.out

