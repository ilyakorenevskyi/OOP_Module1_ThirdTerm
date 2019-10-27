#include "Base.h"
Base::Base(bool check) {
}
Base::Base(){
	base_N++;
	curr=base_N;
}
Base::~Base(){
	S = 2*S - curr+ 11;
	base_N--;
}
int Base::base_N = 0;