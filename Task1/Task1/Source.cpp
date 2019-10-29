#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Developer.h"
#include <algorithm>
#include "Project.h"
#include "Tech.h"
using namespace std;
void output_vector(vector<Project*> unfinished) {		//Output unfinished projects
	cout << "Project Number\tTech Amount\tDifficulty\tSummary perform" << endl;
	for (auto i : unfinished) {
		i->output();
	}
}
void sort(vector<Project*> unfinished) {			//Sort unfinished projects
	for (int n = 0; n != unfinished.size(); n++) {
		for (int i = 0; i != unfinished.size() - 1; i++) {
			if (unfinished[i]->proj_tech.size() > unfinished[i + 1]->proj_tech.size()) {
				std::swap(unfinished[i], unfinished[i + 1]);
			}
			else if (unfinished[i]->proj_tech.size() == unfinished[i + 1]->proj_tech.size() && unfinished[i]->difficulty > unfinished[i + 1]->difficulty) {
				std::swap(unfinished[i], unfinished[i + 1]);
			}
			else if (unfinished[i]->difficulty == unfinished[i + 1]->difficulty && unfinished[i]->sum_prod(unfinished[i]->proj_develop) < unfinished[i + 1]->sum_prod(unfinished[i + 1]->proj_develop))
				std::swap(unfinished[i], unfinished[i + 1]);
		}
	}
	output_vector(unfinished);
}
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
	sort(unfinished);
	/*while (unfinished.size() != 0) {														//Пока все не закончатся 
		for (int i = 0; i != unfinished.size(); i++) {
			unfinished[i]->fill_with_developers(available_developers);
			unfinished[i]->update();
			if (unfinished[i]->done == 2) {
				finished.push_back(unfinished[i]);
				unfinished.erase(unfinished.begin() + i);
				i--;
			}

		}
	}*/
	int stop = 100; //время вывода статистики
	for (int t = 0; t != 100; t++) {				//До опреленного времени
		if (t == stop) {
			sort(unfinished);
		}
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