#pragma once
#include "data.hpp"

namespace ProductFunctions {

    ProductArray* createProductArray(int size);
    void deleteProductArray(ProductArray* arr);
    void filterProducts(ProductArray* arr, bool (*condition)(const Product*));

    Product* defineProduct(const char* name, float price, int quantity);
    void addProduct(ProductArray* arr, Product* prd);
}