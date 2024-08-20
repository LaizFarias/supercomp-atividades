#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream inputFile("entrada.txt");  // Arquivo de entrada
    std::ofstream outputFile("estatisticas.txt");  // Arquivo de saída

    if (!inputFile.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo de entrada!" << std::endl;
        return 1;
    }

    std::string linha;
    std::map<std::string, int> frequenciaPalavras;
    int totalPalavras = 0;
    int totalLinhas = 0;

    while (std::getline(inputFile, linha)) {
        totalLinhas++;
        std::istringstream stream(linha);
        std::string palavra;
        int palavrasNaLinha = 0;

        while (stream >> palavra) {
            frequenciaPalavras[palavra]++;
            palavrasNaLinha++;
        }

        totalPalavras += palavrasNaLinha;
    }

    std::string palavraMaisFrequente;
    int maxFrequencia = 0;

    for (const auto& par : frequenciaPalavras) {
        if (par.second > maxFrequencia) {
            maxFrequencia = par.second;
            palavraMaisFrequente = par.first;
        }
    }

    double mediaPalavrasPorLinha = static_cast<double>(totalPalavras) / totalLinhas;

    outputFile << "Número total de palavras: " << totalPalavras << std::endl;
    outputFile << "Número total de linhas: " << totalLinhas << std::endl;
    outputFile << "Número médio de palavras por linha: " << mediaPalavrasPorLinha << std::endl;
    outputFile << "Palavra mais frequente: " << palavraMaisFrequente << " (" << maxFrequencia << " vezes)" << std::endl;

    inputFile.close();
    outputFile.close();

    std::cout << "Estatísticas geradas com sucesso em 'estatisticas.txt'." << std::endl;

    return 0;
}
