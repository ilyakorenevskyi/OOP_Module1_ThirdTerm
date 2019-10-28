#include "Developer.h"
#include <random>
#include <ctime>
Developer::Developer() {
	curr_proj = nullptr;
	srand(time(0));
	performance = (rand() % 100) / 100;
}
Developer::Developer(double perf,std::vector<Tech> tech) {
	curr_proj = nullptr;
	tech_know = tech;
	performance = ((perf > 1) ? 1 : perf);
	performance = ((perf < 0) ? 0 : perf);
}
void Developer::change_perf(double perf) {
	performance = ((perf > 1) ? 1 : perf);
	performance = ((perf < 0) ? 0 : perf);
}
Developer::~Developer()
{
}
