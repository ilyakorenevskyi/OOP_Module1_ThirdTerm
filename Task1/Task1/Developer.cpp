#include "Developer.h"
#include "Tech.h"
#include <random>
#include <ctime>
Developer::Developer() {
	curr_proj = nullptr;
	srand(time(0));
	performance = (rand() % 100) / 100;
}
Developer::Developer(double perf,std::string name) {
	curr_proj = nullptr;
	this->name = name;
	performance = ((perf > 1) ? 1 : perf);
	performance = ((perf < 0) ? 0 : perf);
}
void Developer::change_perf(double perf) {
	performance = ((perf > 1) ? 1 : perf);
	performance = ((perf < 0) ? 0 : perf);
}
void Developer::add_tech(Tech to_add) {
	for (auto i : tech_know)
		if (to_add ==i) {
			std::cout << "Tech is already known by developer!\n";
			return;
		}
	tech_know.push_back(to_add);
	std::cout << "Tech added successfully";
} 
Developer::~Developer(){
	delete curr_proj;
}
