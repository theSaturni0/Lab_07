#include "functions1.hpp"
#include <cstring>

using namespace ProductFunctions;
using namespace std;

ProductArray* ProductFunctions::createProductArray(int size) {
    ProductArray* arr = new ProductArray;
    arr->products = new Product*[size];
    arr->capacity = 0;
    
    for (int i = 0; i < size; ++i) {
        arr->products[i] = nullptr;
    }
    
    return arr;
}

void ProductFunctions::deleteProductArray(ProductArray* arr) {
    if (arr) {
        for (int i = 0; i < arr->capacity; ++i) {
            delete[] arr->products[i]->name;
            delete[] arr->products[i];
        }
        delete[] arr->products;
        delete arr;
    }
}

Product* defineProduct(const char* name, float price, int quantity) {
    Product* prd = new Product;
    prd->name = new char[strlen(name) + 1];
    strcpy(prd->name, name);
    prd->price = price;
    prd->quantity = quantity;
    return prd;
}

void addProduct(ProductArray* arr, Product* prd) {
    if (arr->capacity == arr->size) {
        return;
    }
    
    for (int i = 0; i < arr->capacity; ++i) {
        if (prd == arr->products[i]) {
            arr->products[i]->quantity += 1;
            arr->capacity++;
            return;
        }
    }
    arr->products[arr->capacity] = prd;
    arr->capacity++;
}