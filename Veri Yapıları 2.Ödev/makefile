hepsi: derle calistir
derle:
	g++ -I ./include/ -o ./lib/IcDugum.o -c ./src/IcDugum.cpp
	g++ -I ./include/ -o ./lib/DisDugum.o -c ./src/DisDugum.cpp
	g++ -I ./include/ -o ./lib/IcAgac.o -c ./src/IcAgac.cpp
	g++ -I ./include/ -o ./lib/DisAgac.o -c ./src/DisAgac.cpp
	g++ -I ./include/ -o ./bin/output ./lib/IcDugum.o ./lib/DisDugum.o ./lib/IcAgac.o ./lib/DisAgac.o ./src/Main.cpp
calistir:
	./bin/output