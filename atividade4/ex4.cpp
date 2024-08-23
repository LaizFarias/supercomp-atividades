#include <iostream>

class Vector {
public:
    Vector(int tamanho) : tam(tamanho), capacidade(tamanho) {
        dados = new int[tamanho];
    }

    ~Vector() {
        delete[] dados;
    }

    void inicializa(int valor) {
        for (int i = 0; i < tam; ++i) {
            dados[i] = valor;
        }
    }

    int get(int index) const {
        if (index >= 0 && index < tam) {
            return dados[index];
        } else {
            std::cerr << "Índice fora do intervalo!" << std::endl;
            return -1; 
        }
    }

    void set(int index, int valor) {
        if (index >= 0 && index < tam) {
            dados[index] = valor;
        } else {
            std::cerr << "Índice fora do intervalo!" << std::endl;
        }
    }

    void inserir(int index, int valor) {
        if (index < 0 || index > tam) {
            std::cerr << "Índice fora do intervalo!" << std::endl;
            return;
        }

        if (tam >= capacidade) {
            redimensiona(capacidade * 2);
        }

        for (int i = tam; i > index; --i) {
            dados[i] = dados[i - 1];
        }

        dados[index] = valor;
        ++tam;
    }

    void remover(int index) {
        if (index < 0 || index >= tam) {
            std::cerr << "Índice fora do intervalo!" << std::endl;
            return;
        }

        for (int i = index; i < tam - 1; ++i) {
            dados[i] = dados[i + 1];
        }

        --tam;

        if (tam <= capacidade / 4) {
            redimensiona(capacidade / 2);
        }
    }

    void imprime() const {
        for (int i = 0; i < tam; ++i) {
            std::cout << dados[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    int* dados;        
    int tam;           
    int capacidade;    

    void redimensiona(int novaCapacidade) {
        int* novoArray = new int[novaCapacidade];
        for (int i = 0; i < tam; ++i) {
            novoArray[i] = dados[i];
        }
        delete[] dados;
        dados = novoArray;
        capacidade = novaCapacidade;
    }
};


int main() {
    Vector vec(5);
    vec.inicializa(0);
    vec.imprime();

    vec.set(2, 10);
    vec.imprime();

    vec.inserir(2, 20);
    vec.imprime();

    vec.remover(3);
    vec.imprime();

    return 0;
}
