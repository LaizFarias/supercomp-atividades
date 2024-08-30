#include <iostream>
#include <vector>
using namespace std;

int problema_mochila(int capacida_mochila, vector<int>& pesos, vector<int>& valores, int numItens) {
    
    // primeiro verifica o numero de itenstns na mochila
    // se for 0 ou a capacidade da mochila for 0 retorna 0
    if (numItens == 0 || capacida_mochila == 0) {
        return 0;
    }

    // observa se o item a atual é maior que a capacidade da mochila
    if (pesos[numItens - 1] > capacida_mochila) {
        return problema_mochila(capacida_mochila, pesos, valores, numItens - 1);
    }


    // ideia é calcular qual valor maximo que pode ser alcançado e aí decidi se coloca na mochila ou nao 
    else {
        // primeiro: olhamos pro valor atual em valores[numItens - 1]
        int incluirItem = valores[numItens - 1] + problema_mochila(capacida_mochila - pesos[numItens - 1], pesos, valores, numItens - 1);
        // chama a função para ver qual valor maximo obtemos usando a capacidade restante da mochila
        // que é representado por capacida_mochila - pesos[numItens - 1], representa
        // a nova capacidade disponivel depois de incluir esse item 
        int naoIncluirItem = problema_mochila(capacida_mochila, pesos, valores, numItens - 1);
        // aí ecolhe entre eles qual valor maximo incluir
        return max(incluirItem, naoIncluirItem);
    }
}

// entrada 1

// int main() {
//     int capacida_mochila = 10; // Capacidade da mochila em kg
//     vector<int> pesos = {3, 8, 6, 4, 5, 10, 1, 9, 3, 3}; // Pesos dos itens
//     vector<int> valores = {70, 56, 17, 91, 77, 69, 98, 54, 13, 54}; // Valores dos itens
//     int numItens = pesos.size(); // Número de itens

//     // Chama a função problema_mochila e imprime o valor máximo que pode ser alcançado
//     int valorMaximo = problema_mochila(capacida_mochila, pesos, valores, numItens);
//     cout << "Valor máximo que pode ser alcançado: " << valorMaximo << " dinheiros" << endl;

//     return 0;
// }

// entrada 2

// int main() {

//     int capacida_mochila = 2;
//     vector<int> pesos = {1, 1, 2, 2, 1}; 
//     vector<int> valores = {50, 94, 40, 39, 62}; 
//     int numItens = pesos.size(); 

//     int valorMaximo = problema_mochila(capacida_mochila, pesos, valores, numItens);
//     cout << "Valor máximo que pode ser alcançado: " << valorMaximo << " dinheiros" << endl;

//     return 0;
// }

// entrada 3


// int main() {
//     int capacida_mochila = 100;
//     vector<int> pesos = {58, 90, 36, 53, 8, 98, 31, 37, 36, 6}; 
//     vector<int> valores = {95, 32, 37, 54, 9, 29, 43, 59, 3, 98}; 
//     int numItens = pesos.size(); 

//     int valorMaximo = problema_mochila(capacida_mochila, pesos, valores, numItens);
//     cout << "Valor máximo que pode ser alcançado: " << valorMaximo << " dinheiros" << endl;

//     return 0;
// }

// entrada 4

int main() {
    int capacida_mochila = 10;
    vector<int> pesos = {1, 1, 2, 1, 8};
    vector<int> valores = {5, 10, 5, 20, 25}; 
    int numItens = pesos.size(); 

    int valorMaximo = problema_mochila(capacida_mochila, pesos, valores, numItens);
    cout << "Valor máximo que pode ser alcançado: " << valorMaximo << " dinheiros" << endl;

    return 0;
}