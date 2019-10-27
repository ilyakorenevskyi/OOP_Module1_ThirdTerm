#include "Beta.h"
Beta::Beta(std::vector<std::shared_ptr<Base>> a) {
	data = a;
	b_N++;
	curr = b_N;
}
int Beta::check_S(int temp_s) {
	if (ptr_numb == 1) {
		temp_s +=  - curr;
		temp_s = 2 * temp_s - curr + 11;
		return temp_s;
	}
	ptr_numb--;
	return 0;
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
