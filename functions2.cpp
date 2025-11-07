#include "functions2.hpp"
#include <cstring>
#include <iostream>

using namespace std;
using namespace ProductFunctions;

namespace ProductFunctions {

    // Сортировка 
    void sortProducts(ProductArray* arr, int (*compare)(const Product*, const Product*)) {
        if (!arr || arr->count <= 1) {
            return;
        }

        for (int i = 0; i < arr->count - 1; ++i) {
            for (int j = 0; j < arr->count - i - 1; ++j) {
                if (compare(arr->products[j], arr->products[j + 1]) > 0) {
                    // Обмен элементов 
                    Product* temp = arr->products[j];
                    arr->products[j] = arr->products[j + 1];
                    arr->products[j + 1] = temp;
                }
            }
        }
    }

    // Вычисление суммы значений
    float calculateTotal(const ProductArray* arr, float (*getValue)(const Product*)) {
        if (!arr) {
            return 0.0f;
        }

        float total = 0.0f;
        for (int i = 0; i < arr->count; ++i) {
            if (arr->products[i] != nullptr) {
                total += getValue(arr->products[i]);
            }
        }
        return total;
    }

    //  сравнение по цене:
    int compareByPrice(const Product* p1, const Product* p2) {
        if (p1->price < p2->price) return -1;
        if (p1->price > p2->price) return 1;
        return 0;
    }

    //  сравнение по названию:
    int compareByName(const Product* p1, const Product* p2) {
        return strcmp(p1->name, p2->name);
    }

    // извлечение стоимости:
    float getCost(const Product* p) {
        if (p == nullptr) return 0.0f;
        return p->price * p->quantity;
    }

    //  извлечение цены:
    float getPrice(const Product* p) {
        if (p == nullptr) return 0.0f;
        return p->price;
    }
}
