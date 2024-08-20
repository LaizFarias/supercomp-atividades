#include <iostream>
#include <vector>

int main () {
    std::vector<int> numeros;  // Declara um vetor de inteiros
    int numero;
    int maior_numero;
    for (int i = 0; i < 10; i++) {
        std::cout << "Digite um número: ";
        std::cin >> numero;
        numeros.push_back(numero); 
    }

    // verifica qual é o número maior 

    for (int i = 0; i < numeros.size(); i++){
        if (numeros[i] > maior_numero){
            maior_numero = numeros[i];
        }
    }

    std::cout << "O maior número é: " << maior_numero << std::endl;

    return 0;
}