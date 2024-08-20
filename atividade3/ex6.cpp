#include <iostream>
#include <vector>

int main() {
    std::vector<int> numeros = {64, 34, 25, 12, 22, 11, 90};
    int n = numeros.size();

    // Exibindo o vetor
    std::cout << "Vetor antes da ordenação: ";
    for (int num : numeros) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Implementação do Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }

    // Exibindo o vetor após a ordenação
    std::cout << "Vetor após a ordenação: ";
    for (int num : numeros) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
