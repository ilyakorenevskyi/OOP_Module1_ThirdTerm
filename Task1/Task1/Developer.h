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
	std::vector<Tech*> tech_know;
public:
	double performance;
	static int developer_num;
	Developer();
	Developer(double perf);
	bool if_know(Tech* tech);
	void change_perf(double perf);
	void add_tech(Tech *to_add);
	~Developer();
};

