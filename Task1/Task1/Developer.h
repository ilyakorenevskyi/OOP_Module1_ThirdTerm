#pragma once
#include "Project.h"
#include <iostream>
#include <string>
class Tech;
#include  <vector>
class Developer
{

	friend class Project;
	Project* curr_proj;
	std::vector<Tech> tech_know;
public:
	double performance;
	std::string name;
	Developer();
	Developer(double perf, std::string name);
	void change_perf(double perf);
	void add_tech(Tech to_add);
	~Developer();
};

