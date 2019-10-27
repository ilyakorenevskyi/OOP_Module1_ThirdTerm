#include "Alpha.h"
Alpha::Alpha(){
	a_N++;
	curr = a_N;
}
Alpha::~Alpha(){
	S -= 2* curr + 11;
	a_N--;
}
int Alpha::a_N = 0;