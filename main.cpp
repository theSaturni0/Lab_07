#include <iostream>
#include <cstring>
#include <io.h>
#include <fcntl.h>
#include "data.hpp"
#include "functions2.hpp"

int main() {
   

    
    Product products[3];

    
    products[0].name = new char[20];
    strcpy(products[0].name, "Хлеб");
    products[0].price = 50;
    products[0].quantity = 10;

    products[1].name = new char[20];
    strcpy(products[1].name, "Молоко");
    products[1].price = 80;
    products[1].quantity = 5;

    products[2].name = new char[20];
    strcpy(products[2].name, "Сыр");
    products[2].price = 350;
    products[2].quantity = 2;

    std::cout << "=== Товары ===" << std::endl;
    for (int i = 0; i < 3; i++) {
        printProduct(products[i]);
    }

   
    auto isDear = [](Product p) { return p.price > 100; };

    std::cout << "\n=== Дорогие товары ===" << std::endl;
    for (int i = 0; i < 3; i++) {
        if (isDear(products[i])) {
            printProduct(products[i]);
        }
    }

   
    std::cout << "\n=== После сортировки ===" << std::endl;
    sortByPrice(products, 3, comparePrices);
    for (int i = 0; i < 3; i++) {
        printProduct(products[i]);
    }

    
    float total = sumPrice(products, 3, getTotal);
    std::cout << "\nИтого: " << total << " руб." << std::endl;

    
    for (int i = 0; i < 3; i++) {
        delete[] products[i].name;
    }

    return 0;
}