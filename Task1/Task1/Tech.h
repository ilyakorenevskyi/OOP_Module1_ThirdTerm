#pragma once
#include <string>
class Tech{
	friend class Project;
	static int tech_number;
	int difficulty;
	friend bool operator== (const Tech& t1, const Tech& t2);
	friend bool operator!= (const Tech& t1, const Tech& t2);
	friend bool operator< (const Tech& t1, const Tech& t2);
	friend bool operator> (const Tech& t1, const Tech& t2);
	friend bool operator<= (const Tech& t1, const Tech& t2);
	friend bool operator>= (const Tech& t1, const Tech& t2);
public:
	Tech( int diff);
	Tech();
	~Tech();
};

