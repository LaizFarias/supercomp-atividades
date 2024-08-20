#include <iostream>
#include <vector>

int main () {
    std::vector<int> numeros1;
    std::vector<int> numeros2;
    std::vector<int> numeros3;

    int numero;    

    for (int i = 0; i < 3; i++) {
        std::cout << "Digite um número: ";
        std::cin >> numero;
        numeros1.push_back(numero);
    }

    for (int i = 0; i < 3; i++) {
        std::cout << "Digite um número: ";
        std::cin >> numero;
        numeros2.push_back(numero);
    }

    for (int i = 0; i < 3; i++) {
        std::cout << "Digite um número: ";
        std::cin >> numero;
        numeros3.push_back(numero);
    }

    //imprime

    std::cout << "A soma: " << numeros1[0] + numeros2[1] + numeros3[2] << std::endl;

    return 0;

}