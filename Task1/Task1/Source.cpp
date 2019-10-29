#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Developer.h"
#include "Project.h"
#include "Tech.h"
using namespace std;
int main() {
	vector <Project*> unfinished;
	vector <Tech*> available_tech;
	vector <Developer*> available_developers;
	srand(time(0));
	for (int i = 0; i != 10; i++) {
		available_tech.push_back(new Tech(rand() % 9+1));
	}
	for (int i = 0; i != 15; i++) {
		available_developers.push_back(new Developer((rand() % 100 + 1) / 100));
		available_developers[i]->add_tech(available_tech[rand() % 10]);
		available_developers[i]->add_tech(available_tech[rand() % 10]);
	}
	for (int t = 0; t != 15; t++) {

	}
	return 0;
}