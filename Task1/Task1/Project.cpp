#include "Project.h"
#include "Developer.h"
#include "Tech.h"
#include <iostream>
double sum_prod(std::vector<Developer*> workers) {	
	double res=0;
	for (auto i : workers) 
		res += i->performance;
	return res;
}
void Project::add_project(Project* project) {
	if (done > 0) { std::cout << "Sorry, but project is already in progress, or done"; return ; }
	for (auto i : dependence)
		if (i == project) {
			std::cout << "Project is already depend on this project!";
			return;
		}
	dependence.push_back(project);
}
void Project::start() {
	if (check()) {
		if (proj_tech.size() == 0) {
			std::cout << "Project " << project_num << " is ready to start, but there are no tech to use!\n";
			return;
		}
		for (auto i : proj_tech) {
			if (i.second.size() == 0) {
				std::cout << "Project " << project_num << " is ready to start, but not all tech can be done by project developers!\n";
				return;
			}
		}
	}
	done = 1;
}
void Project::update() {
	if (done == 0) start();
	curr_time++;
	if (curr_time >= time) make_done();
}
void Project::make_done(){
	done = 2;
	for (int i = 0; i != proj_develop.size(); i++) 
		proj_develop[i]->curr_proj = nullptr;
}
bool Project::check(){   //Check if all previous project are already done;
		int temp_sum=0;
		for (int i = 0; i != dependence.size(); i++)
			temp_sum += dependence[i]->done;
		return temp_sum == dependence.size()*2;
}
void Project::update_time() {		//Update how much time do we need to complete project
	time = 0;						//Time = Proj_difficulty*( Sum( Tech_Difficult * 1 / Sum ( Who_know_this_tech.performance)))
	for (auto i : proj_tech)
		time += i.first->difficulty * 1 / sum_prod(i.second);
	time *= difficulty;
}
void Project::add_developer(Developer* to_add) { 
	bool know = 0;
	if (to_add->curr_proj != nullptr) {             //Cheking if he/she is already busy
		std::cout << "Worker is busy already\n";
		return;
	}
	for (int j = 0; j != to_add->tech_know.size(); j++)				//Check if he/she know one of the technologies
		if (proj_tech.find(to_add->tech_know[j]) != proj_tech.end()) {
			proj_tech[to_add->tech_know[j]].push_back(to_add);		//Every tech has list of workers who know this tech
			know = 1;
		}
	if (know) {
		proj_develop.push_back(to_add);
		to_add->curr_proj = this;
		return;
	}
	std::cout << "Worker doesn't know necessary technologies\n";
}
void Project::add_tech(Tech* to_add) {
	if (proj_tech.find(to_add) != proj_tech.end()) {
			std::cout << "Tech is already used in project!\n";
			return;
	}
	proj_tech[to_add] = {};
	std::cout << "Tech added successfully!\n";
}
Project::Project(int diff):done(0),difficulty(diff){
	project_num++;
}
Project::Project(int diff,  std::vector<Project*> projects) :done(0), difficulty(diff), dependence(projects) {
	project_num++;
}
Project::~Project(){}
int Project::project_num = 0;