#include "logic.h" 

int main() { 
	setlocale(LC_ALL, "RUS"); 
	srand(time(NULL));
	string nickName = ""; 
	bool flag = true; //для цикла while
	int timeStart, timeWin; 
	bool chooseLanguage = false;
	int countExample = 0, countMistak = 0;
	int result, input; 
	int sizeTop = 5;
	UserData* top = new UserData[sizeTop];


	cout << "Выберите язык  (1 - Русский; Другие клавиши - Англ)" << endl;
	cout << "Select language (1 - Russian; Other keys - English)\n---> ";
	chooseLanguage = getchar() == '1';
	system("cls");
	cout << chooseMsg(0, 10, chooseLanguage);
	cin >> nickName;

	while (flag) {
		createTopUsersStart(top, sizeTop);
		countMistak = 0;
		cout << chooseMsg(1, 11, chooseLanguage) << endl;
		do {
			cin >> countExample;
		} while (countExample <= 0);
		system("cls");

		timeStart = time(NULL);
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
		int allTime = timeWin - timeStart;

		cout << chooseMsg(4, 14, chooseLanguage) << endl;;
		cout << chooseMsg(5, 15, chooseLanguage) << calculateAllTime(allTime) + " | " + calculateAllTime(timeStart + 10800) + " - " + calculateAllTime(timeWin + 10800) << endl; // - 10800 - это 3ч - нужно для регулирования времени под наше
		cout << chooseMsg(6, 16, chooseLanguage) << endl;;
		cout << chooseMsg(7, 17, chooseLanguage) << endl;;
		addUserArray(top, sizeTop, nickName, allTime, countExample, countMistak);
		
		cout << "<----------------------->" << endl;
		cout << chooseMsg(9, 19, chooseLanguage) << endl << endl;;

		string temp = chooseLanguage ? convetStringArray(top, sizeTop, 8) : convetStringArray(top, sizeTop, 18); 
		cout << temp;
		cout << "<----------------------->" << endl; 
		cout << chooseMsg(3, 13, chooseLanguage);
		
		getchar();

		flag = getchar() == '1' ? true : false;
		system("cls");
	}

	return 0;
}