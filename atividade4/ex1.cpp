#include <iostream>
#include <fstream>
#include <vector>

void lerArquivo(const std::string& nomeArquivo, std::vector<int>& numeros) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return;
    }

    int numero;
    while (arquivo >> numero) {
        numeros.push_back(numero);
    }

    arquivo.close();
}

void dobrarValoresReferencia(const std::vector<int>& numerosOriginais, std::vector<int>& numerosDobrados) {
    numerosDobrados.clear();  
    for (int numero : numerosOriginais) {
        numerosDobrados.push_back(numero * 2);
    }
}

void dobrarValoresPonteiro(const std::vector<int>* numerosOriginais, std::vector<int>* numerosDobrados) {
    if (numerosOriginais == nullptr || numerosDobrados == nullptr) {
        std::cerr << "Ponteiro nulo passado para a função." << std::endl;
        return;
    }

    numerosDobrados->clear();  
    for (int numero : *numerosOriginais) {
        numerosDobrados->push_back(numero * 2);
    }
}


void escreverArquivo(const std::string& nomeArquivo, const std::vector<int>& numeros) {
    std::ofstream arquivo(nomeArquivo);
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo para escrita: " << nomeArquivo << std::endl;
        return;
    }

    for (int numero : numeros) {
        arquivo << numero << std::endl;
    }

    arquivo.close();
}


int main() {
    std::vector<int> numeros, numerosDobrados;

    lerArquivo("entrada.txt", numeros);

    dobrarValoresReferencia(numeros, numerosDobrados);
    escreverArquivo("saida_referencia.txt", numerosDobrados);

    dobrarValoresPonteiro(&numeros, &numerosDobrados);
    escreverArquivo("saida_ponteiro.txt", numerosDobrados);

    return 0;
}
