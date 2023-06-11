#include "logic.h"

void createTopUsersStart(UserData* top, int size) {
	//i - �����
	//o - ����
	ifstream fin;
	ofstream fout;
	string msg = "";
	fin.open("top5.txt", ifstream::app);

	fin >> msg;
	if (!fin.is_open()) {
		cout << "ERROR - Number 1 - FILE" << endl;
	}
	else {
		if (msg == "") {
			fout.open("top5.txt", ifstream::app);
			if (!fout.is_open()) {
				cout << "ERROR - Number 2 - FILE" << endl;
			}
			else {
				for (int i = 0; i < size; i++) {
					fout << top[i].get_name() + " ";
					fout << top[i].get_time() + " ";
					fout << to_string(top[i].get_countExamples()) + " ";
					fout << to_string(top[i].get_countMistakes()) + "\n";
				}
				fout.close();
			}
		}
		else {
			convertUserTopArray(top, size);
		}
	}
	fin.close();
}

void convertUserTopArray(UserData* top, int size) {
	ifstream fin;

	fin.open("top5.txt");

	if (!fin.is_open()) {
		cout << "ERROR - number 3 - FILE" << endl;
	}
	else {
		for (int i = 0; i < size; i++) {
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
	}

	fin.close();
}

void addUserArray(UserData* top, int size, string name, int time, int countExamples, int countMistakes) {
	UserData current(name, time, countExamples, countMistakes); 

	for (int i = 0; i < size; i++) {
		if (current.get_countExamples() > top[i].get_countExamples() or current.get_countExamples() == top[i].get_countExamples() and current.get_time() < top[i].get_time() or
			current.get_countExamples() == top[i].get_countExamples() and current.get_time() == top[i].get_time() and current.get_countMistakes() > top[i].get_countMistakes()) {
			UserData temp; 

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
		}
	}

	ofstream fout;

	fout.open("top5.txt");

	if (!fout.is_open()) {
		cout << "ERROR - number 4 - FILE" << endl;
	}
	else {
		for (int i = 0; i < size; i++) {
			fout << top[i].get_name() + " ";
			fout << to_string(top[i].get_time()) + " ";
			fout << to_string(top[i].get_countExamples()) + " ";
			fout << to_string(top[i].get_countMistakes()) + "\n";
		}
	}

	fout.close();
}

string convetStringArray(UserData* top,int size, int chooseMsgID) {
	string msg = "";

	for (int i = 0; i < size; i++) {
		msg += chooseMsg(chooseMsgID) + to_string(i + 1) + "\n";
		msg += top[i].get_name() + "  ";  
		msg += calculateAllTime(top[i].get_time()) + " ";
		msg += to_string(top[i].get_countExamples()) + " ";
		msg += to_string(top[i].get_countMistakes()) + "\n\n";
	}


	return msg;
}

void generationDigits(int* pDigitA, int* pDigitB, int* pDigitC) { //������� ����� ������� ����� ����������, ����� ����� 3-�� ������ ����� ���������  
	*pDigitA = rand() % 9 + 1; //��������� ������� ����� �� 1 �� 9
	do {
		*pDigitB = rand() % 9 + 1; //��������� ������� ����� �� 1 �� 9
	} while (*pDigitB == *pDigitA); //���������, ���� �� ������� ������ �����
	do {
		*pDigitC = rand() % 9 + 1; //��������� �������� ����� �� 1 �� 9
	} while (*pDigitC == *pDigitA || *pDigitC == *pDigitB);

}

string createExample(int* pResult) {
	string outputExample = ""; //�������� ���������� STRING ��� ����������� ������ �������
	int digitA, digitB, digitC; //�������� ����� � ������ ��� 3 ����

	while (true) { //���� ����� ��������� ������, ���� �� ��� �� ������� �� �������
		generationDigits(&digitA, &digitB, &digitC);

		if (digitA - digitB >= 0) {
			outputExample += to_string(digitA) + " - " + to_string(digitB) + " + " + to_string(digitC) + " = "; //������� ��������� ������ ��� �������
			*pResult = (digitA - digitB) + digitC; //����������� �� ������� ��������� �������
			break; //� ������, ���� ������ �������� ��� �������, �� ���� �������������
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
	case 0: msg += "������� ��� ������������: "; break;
	case 1: msg += "������� �������� �� ������ ������?\n---> "; break;
	case 2: msg += "�� ��������! ���������� ��� ��� "; break;
	case 3: msg += "������� ��������� ��� ���? - ������� 1 / �� \n---> "; break;
	case 4: msg += "��� ������������: "; break;
	case 5: msg += "����� �����������: "; break;
	case 6: msg += "���������� ��������: "; break;
	case 7: msg += "���������� ������: "; break;
	case 8: msg += "����� "; break;

	case 10: msg += "Input your Nick Name: "; break;
	case 11: msg += "How many examples do you want to solve?\n---> "; break;
	case 12: msg += "You are mistaken! Try again "; break;
	case 13: msg += "Would you like to repeat again? - input 1 / YES \n---> "; break;
	case 14: msg += "Nick Name: "; break;
	case 15: msg += "Passing time:"; break;
	case 16: msg += "Number of examples: "; break;
	case 17: msg += "Number of mistakes: "; break;
	case 18: msg += "TOP "; break;
	}

	return msg;
}