#pragma once
#include "Project.h"
#include <string>
class Tech;
#include  <vector>
class Developer
{
public:
	Project *curr_proj;
	std::vector<Tech> tech_know;
	double performance;
	Developer();
	Developer(double perf, std::vector<Tech> tech);
	void change_perf(double perf);
	Developer(double perf);

	~Developer();
};

