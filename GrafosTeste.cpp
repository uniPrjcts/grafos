#include <iostream>

using namespace std;

void insereVertice(int valor);
void insereAresta(int origem, int destino);
void removeAresta(int origem, int destino);
void imprime();
void inicializaGrafo();

const string LARANJA = "\033[38;5;208m";
const string RESET = "\033[0m";

void printTitulo(const string& titulo) {
    cout << "\n" << LARANJA << titulo << RESET << "\n";
}

void testarInsercaoVertices() {
    printTitulo("Testando inserção de vértices");
    
    cout << "Inserindo vértice 10" << endl;
    insereVertice(10);
    
    cout << "Inserindo vértice 21" << endl;
    insereVertice(21);
    
    cout << "Inserindo vértice 32" << endl;
    insereVertice(32);
    
    cout << "Tentando inserir vértice 10 novamente" << endl;
    insereVertice(10);
    
    cout << "Tentando inserir vértice negativo -5" << endl;
    insereVertice(-5);

    printTitulo("Estado do grafo após inserção de vértices");
    imprime();
}

void testarInsercaoArestas() {
    printTitulo("Testando inserção de arestas");
    
    cout << "Inserindo aresta 10->21" << endl;
    insereAresta(10, 21);
    
    cout << "Inserindo aresta 10->32" << endl;
    insereAresta(10, 32);
    
    cout << "Inserindo aresta 21->10" << endl;
    insereAresta(21, 10);
    
    cout << "Tentando inserir aresta 10->21 novamente" << endl;
    insereAresta(10, 21);
    
    cout << "Tentando inserir aresta com vértice inexistente 40->21" << endl;
    insereAresta(40, 21);
    
    cout << "Tentando inserir aresta para vértice inexistente 21->50" << endl;
    insereAresta(21, 50);

    printTitulo("Estado do grafo após inserção de arestas");
    imprime();
}

void testarRemocaoArestas() {
    printTitulo("Testando remoção de arestas");
    
    cout << "Removendo aresta 10->21" << endl;
    removeAresta(10, 21);
    
    cout << "Tentando remover aresta 10->21 novamente" << endl;
    removeAresta(10, 21);
    
    cout << "Tentando remover aresta inexistente 21->32" << endl;
    removeAresta(21, 32);
    
    cout << "Tentando remover aresta com vértice inexistente 40->21" << endl;
    removeAresta(40, 21);

    printTitulo("Estado do grafo após remoção de arestas");
    imprime();
}

void testarLimites() {
    printTitulo("Testando limites do grafo");
    
    cout << "Inserindo vértices até tentar estourar o limite" << endl;
    for(int i = 0; i < 102; i++) {
        cout << "Tentando inserir vértice " << i << "" << endl;
        insereVertice(i);
    }
}

void testarGrafo() {
    testarInsercaoVertices();
    testarInsercaoArestas();
    testarRemocaoArestas();
    testarLimites();
    
    printTitulo("Estado final do grafo");
    imprime();
}

int main() {
    inicializaGrafo();
    cout << LARANJA << "Iniciando testes do grafo" << RESET << endl;
    testarGrafo();
    return 0;
}
