#include "logic.h"

void generationDigits(int* pDigitA, int* pDigitB, int* pDigitC) { //функция берет адресса наших переменных, чтобы убить 3-ех зайцев одним выстрелом 
	*pDigitA = rand() % 10; //Присваиваем по адрессу
	*pDigitB = rand() % 10; 
	*pDigitC = rand() % 10; 
}

string createExample(int* pResult) {
	string outputExample = ""; //создание переменной STRING для визуального вывода примера
	int digitA, digitB, digitC; //создание ячеек в памяти для 3 цифр

	while (true) { //цикл будет создавать пример, пока он нас не устроит по условию
		generationDigits(&digitA, &digitB, &digitC); 

		if (digitA - digitB >= 0) {
			outputExample += to_string(digitA) + " - " + to_string(digitB) + " + " + to_string(digitC) + " = ";
			*pResult = (digitA - digitB) + digitC; 
			break; //в случае, если пример подходит под условие, то цикл заканчивается
		}
		else if ((digitA + digitB) - digitC >= 0) {

			break; //в случае, если пример подходит под условие, то цикл заканчивается
		}
	}

	return outputExample; 
}
