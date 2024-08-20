#include <iostream>

int main() {
    float numero1;
    float numero2;
    std::string operacao;
    // para obter saída usamos o cout
    std::cout << "Digite o primeiro número1: ";
    // para obter entrada usamos o cin
    std::cin >> numero1;
    std::cout << "Digite o segundo número2: ";
    std::cin >> numero2;
    std::cout << "Digite a operação desejada: ";
    std::cin >> operacao;

    // condicional 
    if (operacao == "soma"){
        std::cout << numero1 + numero2 << std::endl;

    }else if (operacao == "subtracao"){
        std::cout << numero1 - numero2 << std::endl;
    }else if (operacao == "multiplicacao"){
        std::cout << numero1 * numero2 << std::endl;
    }else if (operacao == "divisao"){
        if (numero2 == 0){
            std::cout << "Não é possível dividir por zero" << std::endl;
        }else{
        std::cout << numero1 / numero2 << std::endl; 
        }

    }   

    return 0;
}