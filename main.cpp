#include "functions1.hpp"

using namespace ProductFunctions;
using namespace std;

int main() {
    // creating array with size 10
    ProductArray* Array = createProductArray(10);

    // defining products
    Product* productA = defineProduct("product a", 10.0f, 1);
    Product* productB = defineProduct("product b", 2.0f, 4);
    Product* productC = defineProduct("product c", 30.0f, 1);

    // adding products to array
    addProduct(Array, productA);
    addProduct(Array, productA);
    addProduct(Array, productA);
    addProduct(Array, productB);
    addProduct(Array, productC);

    return 0;
}