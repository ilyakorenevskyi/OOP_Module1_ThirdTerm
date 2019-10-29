#pragma once
#include <string>
class Tech{
	friend class Project;
	std::string name;
	int difficulty;
	friend bool operator== (const Tech& t1, const Tech& t2);
	friend bool operator!= (const Tech& t1, const Tech& t2);
	friend bool operator< (const Tech& t1, const Tech& t2);
	friend bool operator> (const Tech& t1, const Tech& t2);
	friend bool operator<= (const Tech& t1, const Tech& t2);
	friend bool operator>= (const Tech& t1, const Tech& t2);
public:
	Tech(std::string n, int diff);
	Tech();
	~Tech();
};

