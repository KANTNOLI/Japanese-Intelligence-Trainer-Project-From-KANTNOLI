#include "logic.h" 

int main() { 
	setlocale(LC_ALL, "RUS"); 
	srand(time(NULL));
	string msg = "", nickName = ""; 
	bool flag = true; //��� ����� while
	int timeStart, timeWin; 
	bool chooseLanguage = false;
	int countExample = 0, countMistak = 0;
	int result, input; 
	int sizeTop = 5;
	UserData* top = new UserData[sizeTop];





	cout << "�������� ����  (1 - �������; ������ ������� - ����)" << endl;
	cout << "Select language (1 - Russian; Other keys - English)\n---> ";
	chooseLanguage = getchar() == '1';
	system("cls");
	msg = chooseLanguage ? chooseMsg(0) : chooseMsg(10);
	cout << msg;
	cin >> nickName;

	while (flag) {
		createTopUsersStart(top, sizeTop);
		countMistak = 0;
		msg = chooseLanguage ? chooseMsg(1) : chooseMsg(11);
		cout << msg;
		do {
			cin >> countExample;
		} while (countExample <= 0);
		system("cls");

		timeStart = time(NULL);
		for (int i = 0; i < countExample; i++) {
			string example = createExample(&result);
			while (true) { //���� while - ����� ��������, ���� ������������ ��������� �� ����� ���������
				cout << example;
				cin >> input;
				if (result == input) {//� ������, ���� ����� ����������
					break; //�������� �����
				}
				msg = chooseLanguage ? chooseMsg(2) : chooseMsg(12);
				cout << msg << endl;
				countMistak++;
			}


		}
		system("cls");
		timeWin = time(NULL);
		int allTime = timeWin - timeStart;

		msg = chooseLanguage ? chooseMsg(4) : chooseMsg(14);
		cout << msg << nickName << endl;
		msg = chooseLanguage ? chooseMsg(5) : chooseMsg(15);
		cout << msg << calculateAllTime(allTime) + " | " + calculateAllTime(timeStart + 10800) + " - " + calculateAllTime(timeWin + 10800) << endl; // - 10800 - ��� 3� - ����� ��� ������������� ������� ��� ����
		msg = chooseLanguage ? chooseMsg(6) : chooseMsg(16);
		cout << msg << countExample << endl;
		msg = chooseLanguage ? chooseMsg(7) : chooseMsg(17);
		cout << msg << countMistak << endl;
		addUserArray(top, sizeTop, nickName, allTime, countExample, countMistak);

		string temp = chooseLanguage ? convetStringArray(top, sizeTop, 8) : convetStringArray(top, sizeTop, 18); 
		cout << temp << endl; 

		msg = chooseLanguage ? chooseMsg(3) : chooseMsg(13); 
		cout << msg;
		getchar();

		flag = getchar() == '1' ? true : false;
		system("cls");
	}

	return 0;
}