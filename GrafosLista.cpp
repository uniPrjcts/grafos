#include <iostream>

const int TAM = 100;

using namespace std;

struct Aresta {
    int destino;
    Aresta * next;
};

struct Vertice {
    int valor;
    Aresta * arestas;
};

Vertice vertices[TAM];
int numVertices = 0;

bool haVertice(int valor) {
    for (int i = 0; i < numVertices; ++i) {
        if (vertices[i].valor == valor) {
            return true;
        }
    }
    return false;
}

void insereVertice(int valor) {
    if (numVertices >= TAM) {
        cout << "Não há espaço!" << endl;
        return;
    }

    if (haVertice(valor)) {
        cout << "Vértice repetido!" << endl;
        return;
    }

    vertices[numVertices].valor = valor;
    vertices[numVertices].arestas = nullptr;
    ++numVertices;
    cout << "Vértice inserido" << endl;
}

void insereAresta(int origem, int destino) {
    if (!haVertice(origem) || !haVertice(destino)) {
        cout << "Origem ou destino não existem!" << endl;
        return;
    }

    Aresta * novaAresta = new Aresta{destino, nullptr};

    for (int k = 0; k < numVertices; ++k) {
        if (vertices[k].valor == origem) {

            for (Aresta * i = vertices[k].arestas; i != nullptr; i = i -> next) {
                if (i -> destino == destino) {
                    cout << "Aresta repetida!" << endl;
                    delete novaAresta;
                    return;
                }
            }

            novaAresta -> next =  vertices[k].arestas;
            vertices[k].arestas = novaAresta;
            cout << "Aresta inserida!" << endl;
            return;
        }
    }

}

void removeAresta(int origem, int destino) {
    if (!haVertice(origem) || !haVertice(destino)) {
        cout << "Origem ou destino não existem!" << endl;
        return;
    }

    for (int i = 0; i < numVertices; ++i) {
        if (vertices[i].valor == origem) {
            Aresta ** atual = &(vertices[i].arestas);

            while (*atual != nullptr) {
                if ((*atual) -> destino == destino) {
                    Aresta *paraRemover = *atual;
                    *atual = (*atual)->next;
                    delete paraRemover;
                    cout << "Aresta removida!" << endl;
                    return;
                }
                atual = &((*atual) -> next);
            }

            cout << "Aresta não existe!" << endl;
            return;
        }
    }
}

void imprime() {
    for (int i = 0; i < numVertices; ++i) {
        cout << vertices[i].valor << " ->";
        for (Aresta * a = vertices[i].arestas; a != nullptr; a = a -> next) {
                cout << " <" << vertices[i].valor << "," << a -> destino << ">";
        }
        cout << endl;
    }
}

void inicializaGrafo() {}
