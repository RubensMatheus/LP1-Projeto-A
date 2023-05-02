all:
	g++ -c main.cpp funcoes.cpp
	g++ -o programa_A main.o funcoes.o

rodar:
	./programa_A

limpar:
	rm -f programa_A *.o 