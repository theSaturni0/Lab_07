#pragma once

#include "data.hpp"

namespace ProductFunctions {

	// Сортировка
	void sortProducts(ProductArray* arr, int (*compare)(const Product*, const Product*));
	// Вычисление суммы значений
	float calculateTotal(const ProductArray* arr, float (*getValue)(const Product*));

	//  сравнение по цене
	int compareByPrice(const Product* p1, const Product* p2);
	//  сравнение по названию
	int compareByName(const Product* p1, const Product* p2);

	// извлечение стоимости
	float getCost(const Product* p);
	//  извлечение цены
	float getPrice(const Product* p);
}
