#include "Gamma.h"
Gamma::Gamma(std::vector<std::shared_ptr<Base>> a) {
	data = a;
	g_N++;
	curr = g_N;
}
Gamma::Gamma(){
	g_N++;
	curr=g_N;
}
Gamma::~Gamma(){
	S += 3 * curr;
	g_N--;
}
int Gamma::g_N = 0;