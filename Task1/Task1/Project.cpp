#include "Project.h"
#include "Developer.h"
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

void Project::add_worker(Developer worker){
}

Project::Project(){
}


Project::~Project()
{
}
