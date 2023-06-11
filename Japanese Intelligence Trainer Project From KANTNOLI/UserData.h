#pragma once
#include "main.h"

class UserData {
private:
	string name; 
	string time;
	int countExamples;
	int countMistakes;


public:
	UserData() : name("Unknouwn-NICKNAME"), time("Unknouwn-TIME"), countExamples(-1), countMistakes(-1) {};
	UserData(string name, string time, int countExamples, int countMistakes) : name(name), time(time),
		countExamples(countExamples > 0 ? countExamples : -1), countMistakes(countMistakes >= 0 ? countMistakes : -1) {};
	~UserData() {};  

	string get_name() { return name; };
	void set_name(string name) { this->name = name; };

	string get_time() { return time; };
	void set_time(string time) { this->time = time; };

	int get_countExamples() { return countExamples; };
	void set_countExamples(int countExamples) { this->countExamples = countExamples; };

	int get_countMistakes() { return countMistakes; };
	void set_countMistakes(int countMistakes) { this->countMistakes = countMistakes; };

};

