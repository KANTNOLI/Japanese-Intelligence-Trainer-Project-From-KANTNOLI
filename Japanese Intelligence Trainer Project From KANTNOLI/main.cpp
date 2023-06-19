#include "logic.h" 

int main() { 
	setlocale(LC_ALL, "RUS"); 
	srand(time(NULL));
	string nickName = "Unknouwn"; 
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
		addUserArray(top, sizeTop, nickName, allTime, countExample, countMistak );
		
		cout << convert_stats(chooseLanguage, allTime, timeStart, timeWin, nickName, countExample, countMistak);

		cout << "<----------------------->" << endl;
		cout << chooseMsg(9, 19, chooseLanguage) << endl << endl;;

		string temp = chooseLanguage ? convetStringArray(top, sizeTop, chooseLanguage) : convetStringArray(top, sizeTop, chooseLanguage); 
		cout << temp;
		cout << "<----------------------->" << endl; 
		cout << chooseMsg(3, 13, chooseLanguage);
		
		getchar();

		flag = getchar() == '1' ? true : false;
		system("cls");
	}

	return 0;
}