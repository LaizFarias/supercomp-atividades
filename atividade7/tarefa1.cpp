#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

int resolverMochilaTarefa1(int capacidade_mochila, vector<int>& pesos, vector<int>& valores, int index = 0) {
    if (index == 0) {
        vector<pair<int, int>> itens;
        for (int i = 0; i < pesos.size(); ++i) {
            itens.push_back({pesos[i], valores[i]});
        }

        random_device rd;
        mt19937 g(rd());
        shuffle(itens.begin(), itens.end(), g);

        for (int i = 0; i < pesos.size(); ++i) {
            pesos[i] = itens[i].first;
            valores[i] = itens[i].second;
        }
    }

    if (index == pesos.size() || capacidade_mochila == 0) {
        return 0;
    }

    int valor_com_item = 0;
    if (pesos[index] <= capacidade_mochila) {
        valor_com_item = valores[index] + resolverMochilaTarefa1(capacidade_mochila - pesos[index], pesos, valores, index + 1);
    }

    int valor_sem_item = resolverMochilaTarefa1(capacidade_mochila, pesos, valores, index + 1);

    return max(valor_com_item, valor_sem_item);
}

int main() {
    string nome_arquivo = "Entrada_4.txt";
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

    auto start1 = chrono::high_resolution_clock::now();
    int resultadoAtividade1 = resolverMochilaTarefa1(capacidade_mochila, pesos, valores);
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> duration1 = end1 - start1;

    cout << "Resultado Atividade 1: " << resultadoAtividade1 << endl;
    cout << "Tempo de execução Atividade 1: " << duration1.count() << " segundos" << endl;

    return 0;
}
