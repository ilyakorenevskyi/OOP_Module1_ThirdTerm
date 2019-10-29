#pragma once
class Developer;
class Tech;
#include <map>
#include <string>
#include  <vector>
class Project
{
public:
	std::map<Tech,std::vector<Developer>> proj_tech;
	std::vector<Developer> proj_develop;
	std::vector<Project> dependence;
	bool done;
	int difficulty;
	double time;
	double start_time;
	// mark project as done, all workers are free
	void make_done();
	//check if project can start
	bool check();
	//Update how much time do we need to get project done
	void update_time();
	//Add new developer in Project if he/she is suitable for all parameters
	void add_developer(Developer &to_add);
	//Add new tech in Project if it is suitable for all parameters
	void add_tech(Tech to_add);
	void add_worker(Developer worker); //Delete this
	Project();
	Project(int diff, std::vector<Developer> workers, std::vector<Project> projects);
	Project(int diff, std::vector<Tech> tech, std::vector<Developer> workers, std::vector<Project> projects);
	~Project();
};

