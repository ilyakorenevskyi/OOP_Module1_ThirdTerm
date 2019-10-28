#pragma once
#include <string>
class Tech{
	std::string name;
public:
	bool operator==(Tech a);
	Tech();
	~Tech();
};

