#include "logic.h"

void generationDigits(int* pDigitA, int* pDigitB, int* pDigitC) { //������� ����� ������� ����� ����������, ����� ����� 3-�� ������ ����� ��������� 
	*pDigitA = rand() % 10; //����������� �� �������
	*pDigitB = rand() % 10; 
	*pDigitC = rand() % 10; 
}

string createExample(int* pResult) {
	string outputExample = ""; //�������� ���������� STRING ��� ����������� ������ �������
	int digitA, digitB, digitC; //�������� ����� � ������ ��� 3 ����

	while (true) { //���� ����� ��������� ������, ���� �� ��� �� ������� �� �������
		generationDigits(&digitA, &digitB, &digitC); 

		if (digitA - digitB >= 0) {
			outputExample += to_string(digitA) + " - " + to_string(digitB) + " + " + to_string(digitC) + " = ";
			*pResult = (digitA - digitB) + digitC; 
			break; //� ������, ���� ������ �������� ��� �������, �� ���� �������������
		}
		else if ((digitA + digitB) - digitC >= 0) {

			break; //� ������, ���� ������ �������� ��� �������, �� ���� �������������
		}
	}

	return outputExample; 
}
