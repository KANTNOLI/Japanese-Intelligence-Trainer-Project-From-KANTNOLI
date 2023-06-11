#include "logic.h"

int main() {
	setlocale(LC_ALL, "RUS");
	srand(time(NULL)); 
	string msg = "";  
	string nickName = ""; 
	bool flag = true; //для цикла while
	int timeStart; 
	int timeWin; 
	bool chooseLanguage = false; 
	int countExample = 0; //кол-во примеров  
	int result; //результат уровнения
	int input; //ввод результата уравнения
	int countMistak = 0; //кол-во ошибок, сделаных пользователем 
	 
	cout << "Выберите язык  (1 - Русский; Другие клавиши - Англ)" << endl;
	cout << "Select language (1 - Russian; Other keys - English)\n---> ";
	chooseLanguage = getchar() == '1'; 

	while (flag) {
		system("cls");
		timeStart = time(NULL);
		countMistak = 0; 
		msg = chooseLanguage ? chooseMsg(1) : chooseMsg(11); 
		cout << msg; 
		do {  
			cin >> countExample; 
		} while (countExample <= 0);
		system("cls");

		for (int i = 0; i < countExample; i++) {
			string example = createExample(&result);
			while (true) { //цикл while - будте работать, пока пользователь правильно не решит уравнение
				cout << example;
				cin >> input;
				if (result == input) {//в случае, если ответ правильный
					break; //закрытие цикла
				}
				msg = chooseLanguage ? chooseMsg(2) : chooseMsg(12);
				cout << msg << endl;
				countMistak++;
			}


		}
		timeWin = time(NULL);
		int allTime = timeWin - timeStart;
		cout << calculateAllTime(allTime) << endl;
		getchar();

		msg = chooseLanguage ? chooseMsg(3) : chooseMsg(13);
		cout << msg << endl;
		flag = getchar() == '1' ? true : false ;
	} 

	return 0;
}