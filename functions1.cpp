#include "functions1.hpp"
#include <cstring>

using namespace ProductFunctions;
using namespace std;

namespace ProductFunctions {

    ProductArray* ProductFunctions::createProductArray(int size) {
        ProductArray* arr = new ProductArray;
        arr->products = new Product*[size];
        arr->capacity = 0;
        
        for (int i = 0; i < size; i++) {
            arr->products[i] = nullptr;
        }
        
        return arr;
    }

    void ProductFunctions::deleteProductArray(ProductArray* arr) {
        if (arr) {
            for (int i = 0; i < arr->capacity; i++) {
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
        
        for (int i = 0; i < arr->capacity; i++) {
            if ((strcmp(prd->name, arr->products[i]->name) == 0) || (prd->price == arr->products[i]->price)) {
                arr->products[i]->quantity += 1;
                arr->capacity++;
                return;
            }
        }
        arr->products[arr->capacity] = prd;
        arr->capacity++;
    }

    void filterProducts(ProductArray* arr, bool (*condition)(const Product*)) {
        int writeIndex = 0;
        for (int i = 0; i < arr->capacity; i++) {
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
        arr->size = writeIndex;
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
}