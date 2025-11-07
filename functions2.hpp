#pragma once
#include "data.hpp"

void sortByPrice(Product* arr, int size, int (*compare)(Product, Product));
float sumPrice(Product* arr, int size, float (*getPrice)(Product));

int comparePrices(Product a, Product b);
float getTotal(Product p);

void printProduct(Product p);