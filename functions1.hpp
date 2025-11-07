pragma once
#include "data.hpp"

namespace ProductFunctions {

    ProductArray* createProductArray(int size);
    void deleteProductArray(ProductArray* arr);
    void filterProducts(ProductArray* arr, bool (*condition)(const Product*));

    Product* defineProduct(const char* name, float price, int quantity);
    void addProduct(ProductArray* arr, Product* prd);

    void filterProducts(ProductArray* arr, bool (*condition)(const Product*));

    bool costMoreThan10(const Product* product);
    bool costLessThan10(const Product* product);
    bool ammountMoreThan5(const Product* product);
    bool ammountLessThan5(const Product* product);

    void printArray(ProductArray* arr);
}