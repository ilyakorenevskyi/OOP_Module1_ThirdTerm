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
	vector <Project*> finished;
	vector <Tech*> available_tech;
	vector <Developer*> available_developers;
	srand(time(0));
	int temp;
	for (int i = 0; i != 6; i++) {
		cout << "Genereting technologies... " << 100 - 100 / (1+i) << " % \n";
		available_tech.push_back(new Tech(rand() % 5+1));
	}
	for (int i = 0; i != 20; i++) {
		cout << "Genereting developers... " << 100 - 100 / (1 + i) << " % \n";
		available_developers.push_back(new Developer((double)(rand() % 100 + 1) / 100));
		available_developers[i]->add_tech(available_tech[rand() % 6]);
		available_developers[i]->add_tech(available_tech[rand() % 6]);
	}
	for (int i = 0; i != 8; i++) {
		cout << "Genereting Projects... " << 100 - 100 / (1 + i) << " % \n";
		unfinished.push_back(new Project(rand() % 5 + 1));
		unfinished[i]->add_tech(available_tech[rand() % 6]);
		unfinished[i]->add_tech(available_tech[rand() % 6]);
		unfinished[i]->fill_with_developers(available_developers);
	}
	for (int i = 1; i != 8; i++) {
		for (int j = 0; j < rand() % 2; j++) {
			unfinished[i]->add_project(unfinished[rand() % i]);
		}
	}
	for (int t = 0; t != 100; t++) {
		for (int i = 0; i != unfinished.size();i++) {
			unfinished[i]->fill_with_developers(available_developers);
			unfinished[i]->update();
			if (unfinished[i]->done == 2) {
				finished.push_back(unfinished[i]);
				unfinished.erase(unfinished.begin() + i);
				i--;
			}

		}
	}
	return 0;
}