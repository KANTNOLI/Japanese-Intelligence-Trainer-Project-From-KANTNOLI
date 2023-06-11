#include "logic.h" 

int main() {
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	string msg = "";
	string nickName = "";
	bool flag = true; //��� ����� while
	int timeStart;
	int timeWin;
	bool chooseLanguage = false;
	int countExample = 0; //���-�� ��������  
	int result; //��������� ���������
	int input; //���� ���������� ���������
	int countMistak = 0; //���-�� ������, �������� ������������� 

	cout << "�������� ����  (1 - �������; ������ ������� - ����)" << endl;
	cout << "Select language (1 - Russian; Other keys - English)\n---> ";
	chooseLanguage = getchar() == '1';
	system("cls");
	msg = chooseLanguage ? chooseMsg(0) : chooseMsg(10);
	cout << msg;
	cin >> nickName;

	while (flag) {
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
		timeWin = time(NULL);
		int allTime = timeWin - timeStart;

		msg = chooseLanguage ? chooseMsg(4) : chooseMsg(14);
		cout << msg << nickName << endl;
		msg = chooseLanguage ? chooseMsg(5) : chooseMsg(15);
		cout << msg << calculateAllTime(allTime) << endl;
		msg = chooseLanguage ? chooseMsg(6) : chooseMsg(16);
		cout << msg << countExample << endl;
		msg = chooseLanguage ? chooseMsg(7) : chooseMsg(17);
		cout << msg << countMistak << endl;
		getchar();



		msg = chooseLanguage ? chooseMsg(3) : chooseMsg(13);
		cout << msg;
		flag = getchar() == '1' ? true : false;
		system("cls");
	}

	return 0;
}