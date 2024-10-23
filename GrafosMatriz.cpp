#include <iostream>

const int TAM = 100;

using namespace std;

int vertices[TAM];
int mat[TAM][TAM] = {0};
int numVertices = 0;

void inicia() {
    for (int i = 0; i < TAM; ++i) {
        for (int j = 0; j < TAM; ++j) {
            mat[i][j] = 0;
        }
    }
}

bool haVertice(int valor) {
    for (int i = 0; i < numVertices; ++i) {
        if (vertices[i] == valor) {
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

    vertices[numVertices] = valor;
    ++numVertices;
    cout << "Vértice inserido" << endl;
}

void insereAresta(int origem, int destino) {
    if (!haVertice(origem) || !haVertice(destino)) {
        cout << "Origem ou destino não existem!" << endl;
        return;
    }

    int i, j;

    for (int k = 0; k < numVertices; ++k) {
        if (vertices[k] == origem) {
            i = k;
        }
        if (vertices[k] == destino) {
            j = k;
        }
    }

    if (mat[i][j] == 1) {
        cout << "Aresta repetida!" << endl;
        return;
    }

    mat[i][j] = 1;
    cout << "Aresta inserida!" << endl;
}

void removeAresta(int origem, int destino) {
    if (!haVertice(origem) || !haVertice(destino)) {
        cout << "Origem ou destino não existem!" << endl;
        return;
    }

    int i, j;

    for (int k = 0; k < numVertices; ++k) {
        if (vertices[k] == origem) {
            i = k;
        }
        if (vertices[k] == destino) {
            j = k;
        }
    }

    if (mat[i][j] == 0) {
        cout << "Aresta não existe!" << endl;
        return;
    }

    mat[i][j] = 0;
    cout << "Aresta removida!" << endl;
}

void imprime() {
    for (int i = 0; i < numVertices; ++i) {
        cout << vertices[i] << " ->";
        for (int j = 0; j < TAM; ++j) {
            if (mat[i][j] == 1) {
                cout << " <" << vertices[i] << "," << vertices[j] << ">";
            }
        }
        cout << endl;
    }
}

void inicializaGrafo() {
    inicia();
}
