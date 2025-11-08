#include "functions2.hpp"
#include "functions1.hpp"
#include <iostream>

using namespace std;
using namespace ProductFunctions;

int main() {

    Product* productA = defineProduct("product A", 12.0f, 2);
    Product* productB = defineProduct("product B", 6.0f, 6);
    Product* productC = defineProduct("product C", 15.0f, 1);

    ///
    cout << "array 1" << endl;

    ProductArray* Array1 = createProductArray(20);

    addProduct(Array1, productA);
    addProduct(Array1, productA);
    addProduct(Array1, productA);
    addProduct(Array1, productB);
    addProduct(Array1, productB);
    addProduct(Array1, productC);
    addProduct(Array1, productC); // не хватает места

    printArray(*Array1);
    cout << endl;

    filterProducts(Array1, costMoreThan10);

    printArray(*Array1);
    cout << endl;

    filterProducts(Array1, ammountLessThan5);

    printArray(*Array1);
    cout << endl;

    deleteProductArray(Array1);

    ///
    cout << "array2" << endl;

    ProductArray* Array2 = createProductArray(20);
    addProduct(Array2, productA);
    addProduct(Array2, productA);
    addProduct(Array2, productB);
    addProduct(Array2, productC);
    addProduct(Array2, productC);

    sortProducts(Array2, compareByPrice);

    printArray(*Array2);
    cout << endl;

    sortProducts(Array2, compareByName);

    printArray(*Array2);
    cout << endl;

    cout << getPrice(Array2->products[0]) << endl;
    cout << getCost(Array2->products[0]) << endl;
    cout << Array2->products[0]->quantity << endl;
    cout << endl;

    cout << calculateTotal(Array2, getPrice) << endl;
    cout << calculateTotal(Array2, getCost) << endl;
    cout << endl;

    deleteProductArray(Array2);

    ///
    cout << "array3" << endl;

    ProductArray* Array3 = createProductArray(20);
    addProduct(Array3, productA);
    addProduct(Array3, productA);
    addProduct(Array3, productB);
    addProduct(Array3, productC);
    addProduct(Array3, productC);

    printArray(*Array3);
    cout << endl;

    filterProducts(Array3, [](const Product* p) {
        return p->price > 12;
    });
    printArray(*Array3);
    cout << endl;

    return 0;
}