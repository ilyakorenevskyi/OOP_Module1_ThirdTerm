#include "Gamma.h"
Gamma::Gamma(){
	g_N++;
	curr=g_N;
}
Gamma::~Gamma(){
	S += 3 * curr;
	g_N--;
}
int Gamma::g_N = 0;