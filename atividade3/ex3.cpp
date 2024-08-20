#include <iostream>

int main () {
    int numero;
// pergunta pro usuário
    std::cout << "Digite um número: ";
// guarda a resposta 
    std::cin >> numero;

    if (numero % 2 == 0){
        std::cout << "O número é par" << std::endl;
    }else{
        std::cout << "O número é ímpar" << std::endl;
    }
}