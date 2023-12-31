﻿#include "logic.h" 

int main() { 
	setlocale(LC_ALL, "RUS"); 
	srand(time(NULL));

	string nickName = "Unknouwn"; 
	bool flag = true; //для цикла while
	int timeStart, timeWin, allTime;
	bool chooseLanguage = false;
	int countExample = 0, countMistak = 0;
	int result, input; 
	int sizeTop = 5;
	UserData* top = new UserData[sizeTop];


	cout << chooseMsg(-1, -1, chooseLanguage);
	chooseLanguage = getchar() == '1';
	
	system("cls");
	cout << chooseMsg(0, 10, chooseLanguage);
	cin >> nickName;

	while (flag) {
		createTopUsersStart(top, sizeTop);
		countMistak = 0;
		cout << chooseMsg(1, 11, chooseLanguage);
		do {
			cin >> countExample;
		} while (countExample <= 0);
		system("cls");

		timeStart = time(NULL); //Главная часть программы - работа
		for (int i = 0; i < countExample; i++) {
			string example = createExample(&result);
			while (true) { //цикл while - будте работать, пока пользователь правильно не решит уравнение
				cout << example;
				cin >> input;
				if (result == input) {//в случае, если ответ правильный 
					break; //закрытие цикла
				}
				cout << chooseMsg(2, 12, chooseLanguage) << endl;
				countMistak++;
			}
		}

		
		system("cls");
		timeWin = time(NULL);
		allTime = timeWin - timeStart;

		addUserArray(top, sizeTop, nickName, allTime, countExample, countMistak ); //добавление игрока в массив, который потом переобразовывается в файл
		
		cout << convert_stats(chooseLanguage, allTime, timeStart, timeWin, nickName, countExample, countMistak) << endl; //вывод статистики игрока 
		cout << convetStringArray(top, sizeTop, chooseLanguage); //вывод  топа

		cout << chooseMsg(3, 13, chooseLanguage);
		
		getchar();

		flag = getchar() == '1' ? true : false;
		system("cls");
	}

	return 0;
}