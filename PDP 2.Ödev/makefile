hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Emir.o -c ./src/Emir.c	
	gcc -I ./include/ -o ./lib/Portfoy.o -c ./src/Portfoy.c	
	gcc -I ./include/ -o ./lib/Banka.o -c ./src/Banka.c	
	gcc -I ./include/ -o ./lib/Hisse.o -c ./src/Hisse.c
	gcc -I ./include/ -o ./bin/Output ./lib/Emir.o ./lib/Portfoy.o ./lib/Banka.o ./lib/Hisse.o ./src/Program.c
	
calistir: 
	./bin/Output