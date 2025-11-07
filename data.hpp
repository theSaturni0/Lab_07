#pragma once

namespace ProductFunctions {

    struct Product {
        char* name;
        float price;
        int quantity;
    };

    struct ProductArray {
        Product** products;
        int size;
        int capacity;
    };

}