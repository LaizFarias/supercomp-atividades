#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

int resolve_mochila(int capacidade_mochila, vector<int>& pesos, vector<int>& valores, double limiar = 0.5, int index = 0) {
    if (index == pesos.size() || capacidade_mochila == 0) {
        return 0;
    }

    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    double probabilidade = dis(gen);

    int valor_com_item = 0;
    if (probabilidade > limiar && pesos[index] <= capacidade_mochila) {
        valor_com_item = valores[index] + resolve_mochila(capacidade_mochila - pesos[index], pesos, valores, limiar, index + 1);
    }

    int valor_sem_item = resolve_mochila(capacidade_mochila, pesos, valores, limiar, index + 1);

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

    auto start2 = chrono::high_resolution_clock::now();
    double limiar = 0.5; 
    int resultadoAtividade2 = resolve_mochila(capacidade_mochila, pesos, valores, limiar);
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> duration2 = end2 - start2;

    cout << "Resultado Atividade 2: " << resultadoAtividade2 << endl;
    cout << "Tempo de execução Atividade 2: " << duration2.count() << " segundos" << endl;

    return 0;
}
