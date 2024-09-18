#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

int calcularValorMochila(const vector<int>& pesos, const vector<int>& valores, const vector<bool>& solucao, int capacidade_mochila) {
    int peso_total = 0, valor_total = 0;
    for (int i = 0; i < pesos.size(); ++i) {
        if (solucao[i]) {
            peso_total += pesos[i];
            valor_total += valores[i];
        }
    }
    return (peso_total <= capacidade_mochila) ? valor_total : 0;
}

int mochilaCheia(int capacidade_mochila, vector<int>& pesos, vector<int>& valores) {
    vector<bool> solucao(pesos.size(), false); // Inicialmente, nenhum item na mochila
    int valor_total = 0;

    for (int i = 0; i < pesos.size(); ++i) {
        if (pesos[i] <= capacidade_mochila) {
            solucao[i] = true;
            capacidade_mochila -= pesos[i];
            valor_total += valores[i];
        }
    }
    return valor_total;
}

int substituicaoObjeto(int capacidade_mochila, vector<int>& pesos, vector<int>& valores) {
    vector<bool> solucao(pesos.size(), false);
    int valor_total = mochilaCheia(capacidade_mochila, pesos, valores); // Executa mochila cheia primeiro

    bool melhoria = true;
    while (melhoria) {
        melhoria = false;
        for (int i = 0; i < pesos.size(); ++i) {
            if (!solucao[i]) {
                for (int j = 0; j < pesos.size(); ++j) {
                    if (solucao[j]) {
                        int peso_atual = pesos[j];
                        int peso_novo = pesos[i];
                        int valor_atual = valores[j];
                        int valor_novo = valores[i];

                        if (capacidade_mochila + peso_atual - peso_novo >= 0 && valor_novo > valor_atual) {
                            solucao[j] = false;
                            solucao[i] = true;
                            capacidade_mochila += peso_atual - peso_novo;
                            valor_total = calcularValorMochila(pesos, valores, solucao, capacidade_mochila);
                            melhoria = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    return valor_total;
}

int hillClimbing(int capacidade_mochila, vector<int>& pesos, vector<int>& valores) {
    vector<bool> solucao(pesos.size(), false); // Solução binária (0 ou 1)
    int valor_total = mochilaCheia(capacidade_mochila, pesos, valores); // Usa mochila cheia como ponto de partida

    bool melhoria = true;
    while (melhoria) {
        melhoria = false;
        for (int i = 0; i < pesos.size(); ++i) {
            solucao[i] = !solucao[i]; // Troca o bit
            int novo_valor = calcularValorMochila(pesos, valores, solucao, capacidade_mochila);
            if (novo_valor > valor_total) {
                valor_total = novo_valor;
                melhoria = true;
            } else {
                solucao[i] = !solucao[i]; // Reverte a mudança se não for uma melhoria
            }
        }
    }
    return valor_total;
}

int main() {
    string nome_arquivo = "Entrada_3.txt";
    ifstream infile(nome_arquivo);

    if (!infile) {
        cerr << "Erro ao abrir o arquivo " << nome_arquivo << endl;
        return 1;
    }

    int numItens, capacidade_mochila;
    infile >> numItens >> capacidade_mochila;

    vector<int> pesos(numItens);
    vector<int> valores(numItens);

    for (int i = 0; i < numItens; i++) {
        infile >> pesos[i] >> valores[i];
    }

    infile.close();

    int melhorResultadoMochilaCheia = 0, melhorResultadoSubstituicao = 0, melhorResultadoHillClimbing = 0;
    chrono::duration<double> melhorTempoMochilaCheia, melhorTempoSubstituicao, melhorTempoHillClimbing;

    for (int i = 0; i < 10; i++) {
        auto start = chrono::high_resolution_clock::now();
        int resultadoMochilaCheia = mochilaCheia(capacidade_mochila, pesos, valores);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        if (resultadoMochilaCheia > melhorResultadoMochilaCheia) {
            melhorResultadoMochilaCheia = resultadoMochilaCheia;
            melhorTempoMochilaCheia = duration;
        }

        start = chrono::high_resolution_clock::now();
        int resultadoSubstituicaoObjeto = substituicaoObjeto(capacidade_mochila, pesos, valores);
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        if (resultadoSubstituicaoObjeto > melhorResultadoSubstituicao) {
            melhorResultadoSubstituicao = resultadoSubstituicaoObjeto;
            melhorTempoSubstituicao = duration;
        }

        start = chrono::high_resolution_clock::now();
        int resultadoHillClimbing = hillClimbing(capacidade_mochila, pesos, valores);
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        if (resultadoHillClimbing > melhorResultadoHillClimbing) {
            melhorResultadoHillClimbing = resultadoHillClimbing;
            melhorTempoHillClimbing = duration;
        }
    }

    cout << "Melhor Resultado Mochila Cheia: " << melhorResultadoMochilaCheia << endl;
    cout << "Melhor Tempo Mochila Cheia: " << melhorTempoMochilaCheia.count() << " segundos" << endl;

    cout << "Melhor Resultado Substituicao de Objeto: " << melhorResultadoSubstituicao << endl;
    cout << "Melhor Tempo Substituicao de Objeto: " << melhorTempoSubstituicao.count() << " segundos" << endl;

    cout << "Melhor Resultado Hill Climbing: " << melhorResultadoHillClimbing << endl;
    cout << "Melhor Tempo Hill Climbing: " << melhorTempoHillClimbing.count() << " segundos" << endl;

    return 0;
}
