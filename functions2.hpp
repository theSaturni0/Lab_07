#pragma once

#include "data.hpp"

namespace ProductFunctions {

	// Сортировка продуктов по компаратору
	void sortProducts(ProductArray* arr, int (*compare)(const Product*, const Product*));

	// Вычисление суммы значений с помощью функции извлечения
	float calculateTotal(const ProductArray* arr, float (*getValue)(const Product*));

	// Функция-компаратор: сравнивает цену 
	int compareByPrice(const Product* p1, const Product* p2);

	// Функция-компаратор: сравнение по названию
	int compareByName(const Product* p1, const Product* p2);

	// Функция-екстрактор: извлечение стоимости (цена * количество)
	float getCost(const Product* p);

	// Функция-екстрактор: извлечение цены
	float getPrice(const Product* p);

}
