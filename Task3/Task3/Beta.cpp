#include "Beta.h"
Beta::Beta(std::vector<std::shared_ptr<Base>> a) {
	data = a;
	b_N++;
	curr = b_N;
}
Beta::Beta(){
	b_N++;
	curr=b_N;
}
Beta::~Beta(){
	S  -= curr;
	b_N--;
}
int Beta::b_N = 0;
