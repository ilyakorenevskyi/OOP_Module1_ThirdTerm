#include "Gamma.h"
Gamma::Gamma(std::vector<std::shared_ptr<Base>> a) {
	data = a;
	g_N++;
	curr = g_N;
}
int Gamma::check_S(int temp_s) {
	if (ptr_numb == 1) {
		 temp_s += + 3 * curr;
		temp_s = 2 * temp_s - curr + 11;
		return temp_s;
	}
	ptr_numb--;
	return 0;
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