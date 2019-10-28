#include "Project.h"
#include "Developer.h"
#include "Tech.h"
#include <iostream>
void Project::make_done(){
	done = 1;
	for (int i = 0; i != proj_develop.size(); i++) 
		proj_develop[i].curr_proj = nullptr;
}
bool Project::check(){
		int temp_sum=0;
		for (int i = 0; i != dependence.size(); i++)
			temp_sum += dependence[i].done;
		return temp_sum == dependence.size();
}
void Project::add_developer(Developer to_add) {
	if (to_add.curr_proj != nullptr) {
		std::cout << "Worker is busy already";
		return;
	}
	for (int i = 0; i != proj_tech.size(); i++) 
		for (int j = 0; j != to_add.tech_know.size(); j++) 
			if (to_add.tech_know[j] == proj_tech[i]) {\
				proj_develop.push_back(to_add);
				std::cout << "Worker added successfully";
				return;
			}
	std::cout << "Worker doesn't know necessary technologies";
}
void Project::add_tech(Tech to_add) {
	for (int i = 0; i !=  proj_tech.size(); i++)
		if (to_add == proj_tech[i]) {
			std::cout << "Tech is already used in project!\n";
			return;
		}
	proj_tech.push_back(to_add);
	std::cout << "Tech added successfully";
}
void Project::add_worker(Developer worker){
}
Project::Project():done(0) {}
Project::Project(int diff, std::vector<Tech> tech, std::vector<Developer> workers, std::vector<Project> projects) :done(0), difficulty(diff), proj_tech(tech), proj_develop(workers), dependence(projects) {}
Project::~Project()
{
}
