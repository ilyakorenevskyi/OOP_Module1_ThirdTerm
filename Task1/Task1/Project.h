#pragma once
class Developer;
class Tech;
#include <map>
#include <string>
#include  <vector>
class Project
{
	std::map<Tech,std::vector<Developer>> proj_tech;
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
	void update_time();
	void add_developer(Developer to_add);
	void add_tech(Tech to_add);
	void add_worker(Developer worker);
	Project();
	Project(int diff, std::vector<Tech> tech, std::vector<Developer> workers, std::vector<Project> projects);
	~Project();
};

