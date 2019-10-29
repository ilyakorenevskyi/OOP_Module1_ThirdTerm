#include <iostream>
#include <vector>
#include "Developer.h"
#include "Project.h"
#include "Tech.h"
using namespace std;
int main() {
	vector<Project*> incomplete;
	incomplete.push_back(new Project);
	incomplete.push_back(new Project);
	incomplete.push_back(new Project);
	incomplete.push_back(new Project);
	Tech a("JS", 4);
	Tech b("OOP", 5);
	incomplete[0]->add_tech(a);
	Developer John(0.8, { b });
	incomplete[0]->add_developer(John);
	John.add_tech(a);
	incomplete[0]->add_developer(John);
	incomplete[0]->difficulty=1;
	incomplete[0]->update_time();
	cout << incomplete[0]->time;
	return 0;
}