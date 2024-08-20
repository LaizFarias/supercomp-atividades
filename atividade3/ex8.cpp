#include <iostream>
#include <string>

int main() {
    std::string palavra;
    
    std::cout << "Insira uma palavra: ";
    std::cin >> palavra;

    bool isPalindromo = true;
    int tamanho = palavra.size();

    for (int i = 0; i < tamanho / 2; i++) {
        if (palavra[i] != palavra[tamanho - i - 1]) {
            isPalindromo = false;
            break;  
        }
    }

    // Exibindo o resultado
    if (isPalindromo) {
        std::cout << palavra << " é um palíndromo." << std::endl;
    } else {
        std::cout << palavra << " não é um palíndromo." << std::endl;
    }

    return 0;
}
