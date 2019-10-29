#pragma once
class Developer;
class Tech;
#include <map>
#include <string>
#include  <vector>
class Project
{
	static int project_num;
	std::map<Tech*,std::vector<Developer*>> proj_tech;
	std::vector<Developer*> proj_develop;
	std::vector<Project*> dependence;
public:
	int done;
	int difficulty;
	int curr_time;
	int time;
	//Start work if possible
	void start();
	//update project
	void update();
	// mark project as done, all workers are free
	void make_done();
	//check if project can start
	bool check();
	//Update how much time do we need to get project done
	void update_time();
	//Fills all empty technologies with one developer
	void fill_with_developers(std::vector<Developer*> available);
	//Add new developer in Project if he/she is suitable for all parameters
	bool add_developer(Developer *to_add);
	//Add new tech in Project if it is suitable for all parameters
	void add_tech(Tech* to_add);
	void add_project(Project* to_add); //Adds dependant project
	Project(int diff);
	Project(int diff,  std::vector<Project*> projects);
	~Project();
};

