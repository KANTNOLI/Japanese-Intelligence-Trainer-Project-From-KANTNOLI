#pragma once

#include "UserData.h" 

void createTopUsersStart(UserData* top, int size);  
void convertUserTopArray(UserData* top, int size);  
void addUserArray(UserData* top, int size, string name, int time, int countExamples, int countMistakes);
string convetStringArray(UserData* top, int size, int chooseMsgID);

void generationDigits(int* pDigitA, int* pDigitB, int* pDigitC);

string createExample(int* pResult);

string calculateAllTime(int allTime);

string chooseMsg(int chooseMsgID); 

