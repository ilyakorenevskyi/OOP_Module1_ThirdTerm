#pragma once
#include "Project.h"
#include <string>
class Tech;
#include  <vector>
class Developer
{
public:
	std::string name;
	Project *curr_proj;
	std::vector<Tech> tech_know;
	double performance;
	Developer();
	~Developer();
};

