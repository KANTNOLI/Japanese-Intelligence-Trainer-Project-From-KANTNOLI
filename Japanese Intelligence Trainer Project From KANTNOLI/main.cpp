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
		cout << calculateAllTime(allTime) << endl;
		getchar();

		msg = chooseLanguage ? chooseMsg(3) : chooseMsg(13);
		cout << msg << endl;
		flag = getchar() == '1' ? true : false ;
	} 

	return 0;
}