#include "functions1.hpp"

using namespace ProductFunctions;
using namespace std;

ProductArray* ProductFunctions::createProductArray(int size) {
    ProductArray* arr = new ProductArray;
    arr->products = new Product[size];
    
    for (int i = 0; i < size; ++i) {
        arr->products[i].name = nullptr;
        arr->products[i].price = 0.0f;
        arr->products[i].quantity = 0;
    }
    
    return arr;
}

void ProductFunctions::deleteProductArray(ProductArray* arr) {
    if (arr) {
        for (int i = 0; i < arr->size; ++i) {
            delete[] arr->products[i].name;
        }
        delete[] arr->products;
        delete arr;
    }
}