#include <iostream>
#include <vector>

int main() {
    // vetor de strings 
    std::vector<std::string> items;
    std::string item ;

    std::cout << "Digite um produto:" ;
    std:: cin >> item;

    // condição de parada é quando o usuário digitar "fim"

    while (item != "fim") {
        items.push_back(item);
        std::cout << "Digite um produto:" ;
        std:: cin >> item;
    }

    std::cout << "Produtos digitados:" << std::endl;
    for (const std::string& produto : items) {
        std::cout << produto << std::endl;
    }

    return 0;
}