CXX = g++
CXXFLAGS = -Wall -std=c++11

all: run_lista run_matriz

teste_lista: GrafosTeste.cpp GrafosLista.cpp
	$(CXX) $(CXXFLAGS) GrafosTeste.cpp GrafosLista.cpp -o teste_lista

teste_matriz: GrafosTeste.cpp GrafosMatriz.cpp
	$(CXX) $(CXXFLAGS) GrafosTeste.cpp GrafosMatriz.cpp -o teste_matriz

run_lista: teste_lista
	@echo "\n Executando testes com Lista de Adjacências \n"
	./teste_lista

run_matriz: teste_matriz
	@echo "\n Executando testes com Matriz de Adjacências \n"
	./teste_matriz

clean:
	rm -f teste_lista teste_matriz
