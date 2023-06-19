#include "logic.h" 

int main() { 
	setlocale(LC_ALL, "RUS"); 
	srand(time(NULL));
	string msg = "", nickName = ""; 
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
	msg = chooseMsg(0, 10, chooseLanguage);
	cout << msg;
	cin >> nickName;

	while (flag) {
		createTopUsersStart(top, sizeTop);
		countMistak = 0;
		msg = chooseMsg(1, 11, chooseLanguage);
		cout << msg;
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
				msg = chooseMsg(2, 12, chooseLanguage);
				cout << msg << endl;
				countMistak++;
			}


		}
		system("cls");
		timeWin = time(NULL);
		int allTime = timeWin - timeStart;

		msg = chooseMsg(4, 14, chooseLanguage);
		cout << msg << nickName << endl;
		msg = chooseMsg(5, 15, chooseLanguage);
		cout << msg << calculateAllTime(allTime) + " | " + calculateAllTime(timeStart + 10800) + " - " + calculateAllTime(timeWin + 10800) << endl; // - 10800 - это 3ч - нужно для регулирования времени под наше
		msg = chooseMsg(6, 16, chooseLanguage);
		cout << msg << countExample << endl;
		msg = chooseMsg(7, 17, chooseLanguage);
		cout << msg << countMistak << endl;
		addUserArray(top, sizeTop, nickName, allTime, countExample, countMistak);
		
		cout << "<----------------------->" << endl;
		msg = chooseMsg(9, 19, chooseLanguage);
		cout << msg << endl << endl;

		string temp = chooseLanguage ? convetStringArray(top, sizeTop, 8) : convetStringArray(top, sizeTop, 18); 
		cout << temp;
		cout << "<----------------------->" << endl; 
		msg = chooseMsg(3, 13, chooseLanguage);
		cout << msg;
		getchar();

		flag = getchar() == '1' ? true : false;
		system("cls");
	}

	return 0;
}