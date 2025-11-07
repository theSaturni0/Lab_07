#pragma once
#include "data.hpp"

namespace ProductFunctions {

    ProductArray* createProductArray(int size);
    void deleteProductArray(ProductArray* arr);
    void filterProducts(ProductArray* arr, bool (*condition)(const Product*));

}