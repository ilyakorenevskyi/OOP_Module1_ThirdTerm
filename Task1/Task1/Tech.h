#pragma once
#include <string>
class Tech{
	friend class Project;
	std::string name;
	int difficulty;
public:
	bool operator==(Tech a);
	Tech();
	~Tech();
};

