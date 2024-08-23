#include <iostream>
#include <vector>
#include <chrono>

int main() {
    int N = 1000;  
    long long somaManual = 0;  
    long long somaVector = 0;

    auto inicioManual = std::chrono::high_resolution_clock::now();

    int** matrizManual = new int*[N];
    for (int i = 0; i < N; ++i) {
        matrizManual[i] = new int[N];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrizManual[i][j] = i + j;  
            somaManual += matrizManual[i][j];
        }
    }

    auto fimManual = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracaoManual = fimManual - inicioManual;

    std::cout << "Soma total (alocação dinâmica manual): " << somaManual << std::endl;
    std::cout << "Tempo de execução (alocação dinâmica manual): " << duracaoManual.count() << " segundos" << std::endl;

    for (int i = 0; i < N; ++i) {
        delete[] matrizManual[i];
    }
    delete[] matrizManual;

    auto inicioVector = std::chrono::high_resolution_clock::now();

    std::vector<std::vector<int>> matrizVector(N, std::vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrizVector[i][j] = i + j;  
            somaVector += matrizVector[i][j];
        }
    }

    auto fimVector = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracaoVector = fimVector - inicioVector;

    std::cout << "Soma total (std::vector): " << somaVector << std::endl;
    std::cout << "Tempo de execução (std::vector): " << duracaoVector.count() << " segundos" << std::endl;

    return 0;
}
