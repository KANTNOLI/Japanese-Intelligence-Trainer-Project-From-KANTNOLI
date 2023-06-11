#include "logic.h"

void generationDigits(int* pDigitA, int* pDigitB, int* pDigitC) { //функция берет адресса наших переменных, чтобы убить 3-ех зайцев одним выстрелом  
	*pDigitA = rand() % 9 + 1; //генерация первого числа от 1 до 9
	do {
		*pDigitB = rand() % 9 + 1; //генерация второго числа от 1 до 9
	} while (*pDigitB == *pDigitA); //повторяем, пока не получим разное число
	do {
		*pDigitC = rand() % 9 + 1; //генерация третьего числа от 1 до 9
	} while (*pDigitC == *pDigitA || *pDigitC == *pDigitB);

}

string createExample(int* pResult) {
	string outputExample = ""; //создание переменной STRING для визуального вывода примера
	int digitA, digitB, digitC; //создание ячеек в памяти для 3 цифр

	while (true) { //цикл будет создавать пример, пока он нас не устроит по условию
		generationDigits(&digitA, &digitB, &digitC); 

		if (digitA - digitB >= 0) {
			outputExample += to_string(digitA) + " - " + to_string(digitB) + " + " + to_string(digitC) + " = "; //создаем вищуально пример для решения
			*pResult = (digitA - digitB) + digitC; //присваеваем по адрессу результат примера
			break; //в случае, если пример подходит под условие, то цикл заканчивается
		}
		else if ((digitA + digitB) - digitC >= 0) {
			outputExample += to_string(digitA) + " + " + to_string(digitB) + " - " + to_string(digitC) + " = ";
			*pResult = (digitA + digitB) - digitC; 
			break; 
		}
	}

	return outputExample; 
}

string calculateAllTime(int allTime) {
	int hour = allTime / 3600 % 24; 
	int minute = allTime % 3600 / 60; 
	int second = allTime % 60;

	return to_string(hour) + ":" + (minute > 9 ? to_string(minute) : "0" + to_string(minute)) + ":" + (second > 9 ? to_string(second) : "0" + to_string(second));
}

string chooseMsg(int chooseMsgID) {
	string msg = "";
	switch (chooseMsgID) {
	case 0: msg += "Введите имя пользователя: "; break;
	case 1: msg += "Сколько примеров вы хотите решить?\n---> "; break;
	case 2: msg += "Вы ошиблись! Попробуйте еще раз "; break;
	case 3: msg += "Желаете повторить еще раз? - нажмите 1 / ДА \n---> "; break;
	case 4: msg += "Имя пользователя: "; break;
	case 5: msg += "Время прохождения: "; break;
	case 6: msg += "Количество примеров: "; break;
	case 7: msg += "Количество ошибок: "; break;

	case 10: msg += "Input your Nick Name: "; break;
	case 11: msg += "How many examples do you want to solve?\n---> "; break;
	case 12: msg += "You are mistaken! Try again "; break;
	case 13: msg += "Would you like to repeat again? - input 1 / YES \n---> "; break;
	case 14: msg += "Nick Name: "; break;
	case 15: msg += "Passing time:"; break;
	case 16: msg += "Number of examples: "; break;
	case 17: msg += "Number of mistakes: "; break;
	}

	return msg;
}