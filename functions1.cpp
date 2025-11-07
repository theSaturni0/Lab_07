#include "functions1.hpp"
#include <cstring>
#include <iostream>

using namespace ProductFunctions;
using namespace std;

namespace ProductFunctions {

    ProductArray* ProductFunctions::createProductArray(int size) {
        ProductArray* arr = new ProductArray;
        arr->products = new Product*[size];
        arr->size = size;
        arr->capacity = 0;
        arr->count = 0;
        
        for (int i = 0; i < size; i++) {
            arr->products[i] = nullptr;
        }
        
        return arr;
    }

    void ProductFunctions::deleteProductArray(ProductArray* arr) {
        if (arr) {
            for (int i = 0; i < arr->count; i++) {
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
        if (arr->capacity + prd->quantity >= arr->size) {
            return;
        }
        
        for (int i = 0; i < arr->count; i++) {
            if ((strcmp(prd->name, arr->products[i]->name) == 0) && (prd->price == arr->products[i]->price)) {
                arr->products[i]->quantity += prd->quantity;
                arr->capacity += prd->quantity;
                return;
            }
        }
        Product* newProduct = defineProduct(prd->name, prd->price, prd->quantity);
        arr->products[arr->count] = newProduct;
        arr->count += 1;
        arr->capacity += prd->quantity;
        
    }

    void filterProducts(ProductArray* arr, bool (*condition)(const Product*)) {
    int writeIndex = 0;
    
    for (int i = 0; i < arr->count; i++) {
        if (condition(arr->products[i])) {
            if (writeIndex != i) {
                arr->products[writeIndex] = arr->products[i];
            }
            writeIndex++;
        } else {
            delete[] arr->products[i]->name;
            delete arr->products[i];
            arr->products[i] = nullptr;
        }
    }
    
    arr->count = writeIndex;
    
    arr->capacity = 0;
    for (int i = 0; i < arr->count; i++) {
        arr->capacity += arr->products[i]->quantity;
    }
}

    bool costMoreThan10(const Product* product) {
        return product->price > 10;
    }

    bool costLessThan10(const Product* product) {
        return product->price < 10;
    }

    bool ammountMoreThan5(const Product* product) {
        return product->quantity > 5;
    }

    bool ammountLessThan5(const Product* product) {
        return product->quantity < 5;
    }


    void printArray(ProductArray* arr) {
        for (int i = 0; i < arr->count; i++) {
            for (int c = 0; c < arr->products[i]->quantity; c++) {
                cout << arr->products[i]->name << ", price: " << arr->products[i]->price << endl;
            }
        }
    }
}