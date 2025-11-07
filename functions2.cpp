#pragma once

#include "data.hpp"
#include <iostream>
#include <cstring>

// Сортировка с использованием указателя на функцию-компаратор
inline void sortByPrice(Product* arr, int size, int (*compare)(Product, Product)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compare(arr[j], arr[j + 1]) > 0) {
                Product temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Вычисление суммы с использованием указателя на функцию извлечения значения
inline float sumPrice(Product* arr, int size, float (*getPrice)(Product)) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += getPrice(arr[i]);
    }
    return sum;
}

// Компаратор для сравнения продуктов по цене
inline int comparePrices(Product a, Product b) {
    if (a.price < b.price) return -1;
    if (a.price > b.price) return 1;
    return 0;
}

// Функция извлечения значения: общая стоимость = цена × количество
inline float getTotal(Product p) {
    return p.price * p.quantity;
}

// Функция вывода продукта
inline void printProduct(Product p) {
    std::cout << p.name << " - " << p.price << " руб." << std::endl;
}