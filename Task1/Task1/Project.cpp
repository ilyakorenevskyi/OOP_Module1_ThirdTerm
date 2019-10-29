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
void Project::update_time() {
	
}
void Project::add_developer(Developer to_add) {
	bool know = 0;
	if (to_add.curr_proj != nullptr) {
		std::cout << "Worker is busy already";
		return;
	}
	for (int j = 0; j != to_add.tech_know.size(); j++)
		if (proj_tech.find(to_add.tech_know[j]) != proj_tech.end()) {
			proj_tech[to_add.tech_know[j]].push_back(to_add);
			know = 1;
		}
	if (know) {
		proj_develop.push_back(to_add);
		return;
	}
	std::cout << "Worker doesn't know necessary technologies";
}
void Project::add_tech(Tech to_add) {
		if (proj_tech.find(to_add) != proj_tech.end()) {
			std::cout << "Tech is already used in project!\n";
			return;
		}
	proj_tech.insert({ to_add, {} });
	std::cout << "Tech added successfully";
}
void Project::add_worker(Developer worker){
}
Project::Project():done(0) {}
Project::Project(int diff, std::vector<Tech> tech, std::vector<Developer> workers, std::vector<Project> projects) :done(0), difficulty(diff), proj_tech(tech), proj_develop(workers), dependence(projects) {}
Project::~Project()
{
}
