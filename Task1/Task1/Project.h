#pragma once
class Developer;
class Tech;
#include <string>
#include  <vector>
class Project
{
	std::vector<Tech> proj_tech;
	std::vector<Developer> proj_develop;
	std::vector<Project> dependence;
	bool done;
	int difficulty;
	double time;
	double start_time;
public:
	// mark project as done, all workers are free
	void make_done();
	//check if project can start
	bool check();
	void add_worker(Developer worker);
	Project();
	~Project();
};

