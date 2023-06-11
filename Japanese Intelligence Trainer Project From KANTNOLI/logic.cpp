#include "logic.h"

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

	case 10: msg += "Input your Nick Name: "; break;
	case 11: msg += "How many examples do you want to solve?\n---> "; break;
	case 12: msg += "You are mistaken! Try again "; break;
	case 13: msg += "Would you like to repeat again? - input 1 / YES \n---> "; break;
	case 14: msg += "Nick Name: "; break;
	case 15: msg += "Passing time:"; break;
	case 16: msg += "Number of examples: "; break;
	case 17: msg += "Number of mistakes: "; break;
	}

	return msg;
}