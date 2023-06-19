﻿#include "logic.h"

void createTopUsersStart(UserData* top, int size) {
	//i - вывод
	//o - ввод
	ifstream fin;
	ofstream fout;
	string msg = "";
	fin.open("top5", ifstream::app);

	fin >> msg;
	if (!fin.is_open()) {
		cout << "ERROR - Number 1 - FILE" << endl;
	}
	else {
		if (msg == "") { //в случае есть файл пуст - создание нового топа
			fout.open("top5", ifstream::app);
			if (!fout.is_open()) {
				cout << "ERROR - Number 2 - FILE" << endl;
			}
			else {
				for (int i = 0; i < size; i++) { //создание пустых игроков
					fout << top[i].get_name() + " ";
					fout << top[i].get_time() + " ";
					fout << to_string(top[i].get_countExamples()) + " ";
					fout << to_string(top[i].get_countMistakes()) + "\n";
				}
				fout.close();
			}
		}
		else { //в случае если топ есть и игрок играл, делаем обработку и создания массива , чтобы работать с данными файла
			convertUserTopArray(top, size);
		}
	}
	fin.close();
}
void convertUserTopArray(UserData* top, int size) {
	ifstream fin;

	fin.open("top5");

	if (!fin.is_open()) {
		cout << "ERROR - number 3 - FILE" << endl;
	}
	else {
		for (int i = 0; i < size; i++) { //переписываем данные игроков в массив для дальнейшей работы
			string tempString = "";
			fin >> tempString;
			top[i].set_name(tempString);
			int tempInt = -1;
			fin >> tempInt; 
			top[i].set_time(tempInt);
			fin >> tempInt;
			top[i].set_countExamples(tempInt);
			fin >> tempInt;
			top[i].set_countMistakes(tempInt);
			tempInt = -1;
		}

		fin.close();
	}
}
void addUserArray(UserData* top, int size, string name, int time, int countExamples, int countMistakes) {
	UserData current(name, time, countExamples, countMistakes); //создание нового игрока 

	for (int i = 0; i < size; i++) { //перебираем всех игроков
		if (current.get_countExamples() > top[i].get_countExamples() or current.get_countExamples() == top[i].get_countExamples() and current.get_time() < top[i].get_time() or //сравниваем по времени и тд
			current.get_countExamples() == top[i].get_countExamples() and current.get_time() == top[i].get_time() and current.get_countMistakes() < top[i].get_countMistakes()) { 
			UserData temp; //темповская переменная для обмена данными игроков

			temp.set_name(top[i].get_name());
			temp.set_time(top[i].get_time());
			temp.set_countExamples(top[i].get_countExamples());
			temp.set_countMistakes(top[i].get_countMistakes());

			top[i].set_name(current.get_name());
			top[i].set_time(current.get_time());
			top[i].set_countExamples(current.get_countExamples());
			top[i].set_countMistakes(current.get_countMistakes());

			current.set_name(temp.get_name()); 
			current.set_time(temp.get_time());
			current.set_countExamples(temp.get_countExamples());  
			current.set_countMistakes(temp.get_countMistakes()); 
		}//дефолтный обмен данными 
	}

	ofstream fout;

	fout.open("top5");

	if (!fout.is_open()) {
		cout << "ERROR - number 4 - FILE" << endl;
	}
	else {
		for (int i = 0; i < size; i++) { //запись новых игроков
			fout << top[i].get_name() + " ";
			fout << to_string(top[i].get_time()) + " ";
			fout << to_string(top[i].get_countExamples()) + " ";
			fout << to_string(top[i].get_countMistakes()) + "\n";
		}
		fout.close(); 
	}
}
string convetStringArray(UserData* top,int size, bool chooseLanguage) {
	string msg = chooseMsg(9, 19, chooseLanguage) + "\n"; 

	msg += "<------------------------------------------->\n"; 

	for (int i = 0; i < size; i++) { //выводим данные топа, сразу с массива
		msg += chooseMsg(8, 18, chooseLanguage) + to_string(i + 1) + "\n| ";
		msg += top[i].get_name() + " | ";  
		msg += calculateAllTime(top[i].get_time()) + " | ";
		msg += to_string(top[i].get_countExamples()) + " | ";
		msg += to_string(top[i].get_countMistakes()) + " |\n\n";
	}

	msg += "<------------------------------------------->\n\n";

	return msg;
}

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

string convert_stats(bool chooseLanguage, int allTime,int  timeStart,int timeWin, string nickName, int countExample, int countMistak) {
	string msg = "";
	int threeHour = 10800; //переменная для создания часового пояса МИНСК + 3 часа

	msg += chooseMsg(4, 14, chooseLanguage) + nickName +"\n"; 
	msg += chooseMsg(5, 15, chooseLanguage) + " " + calculateAllTime(allTime) + " | " + calculateAllTime(timeStart + threeHour) + " - " + calculateAllTime(timeWin + threeHour) + "\n";
	msg += chooseMsg(6, 16, chooseLanguage) + to_string(countExample) + "\n"; 
	msg += chooseMsg(7, 17, chooseLanguage) + to_string(countMistak) + "\n"; 

	return msg;
}

string calculateAllTime(int allTime) { 
	int hour = allTime / 3600 % 24;
	int minute = allTime % 3600 / 60;
	int second = allTime % 60;

	return to_string(hour) + ":" + (minute > 9 ? to_string(minute) : "0" + to_string(minute)) + ":" + (second > 9 ? to_string(second) : "0" + to_string(second));
}
string chooseMsg(int chooseMsgID1, int chooseMsgID2, bool chooseLanguage) {
	string msg = "";
	
	switch (chooseLanguage ? chooseMsgID1 : chooseMsgID2) { 
	case 0: msg += "Введите имя пользователя: "; break;
	case 1: msg += "Сколько примеров вы хотите решить?\n---> "; break;
	case 2: msg += "Вы ошиблись! Попробуйте еще раз "; break;
	case 3: msg += "Желаете повторить еще раз? - нажмите 1 / ДА \n---> "; break;
	case 4: msg += "Имя пользователя: "; break;
	case 5: msg += "Время прохождения: "; break;
	case 6: msg += "Количество примеров: "; break;
	case 7: msg += "Количество ошибок: "; break;
	case 8: msg += "МЕСТО "; break;
	case 9: msg += "| Имя | Время | Уравнений | Ошибок | "; break;

	case 10: msg += "Input your Nick Name: "; break;
	case 11: msg += "How many examples do you want to solve?\n---> "; break;
	case 12: msg += "You are mistaken! Try again "; break;
	case 13: msg += "Would you like to repeat again? - input 1 / YES \n---> "; break;
	case 14: msg += "Nick Name: "; break;
	case 15: msg += "Passing time:"; break;
	case 16: msg += "Number of examples: "; break;
	case 17: msg += "Number of mistakes: "; break;
	case 18: msg += "TOP "; break;
	case 19: msg += "| Name | Time | Examples | Mistakes | "; break;
	default:  msg += "Выберите язык  (1 - Русский; Другие клавиши - Англ)\nSelect language (1 - Russian; Other keys - English)\n---> ";
	}

	return msg;
}