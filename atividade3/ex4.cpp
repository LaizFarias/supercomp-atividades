#include <iostream>
#include <vector> // biblioteca que permite a criação de vetores

// adicionaelementos nomedovetor.push_back(elemento)
// acessar elementos nomedovetor[indice]
// tamanho do vetor nomedovetor.size()
// remover elementos nomedovetor.pop_back()
// limpar o vetor nomedovetor.clear()
// inserir elementos em uma posição específica nomedovetor.insert(nomedovetor.begin() + indice, elemento)
// remover elementos de uma posição específica nomedovetor.erase(nomedovetor.begin() + indice)
int main () {
    std::vector<int> numeros;  // Declara um vetor de inteiros
    int numero;
    for (int i = 0; i < 5; i++) {
        std::cout << "Digite um número: ";
        std::cin >> numero;
        numeros.push_back(numero); 
    }
    
    return 0;

}

