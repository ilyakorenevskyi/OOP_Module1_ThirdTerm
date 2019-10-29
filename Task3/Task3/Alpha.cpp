#include "Alpha.h"
int Alpha::check_S(int temp_s){
	if (ptr_numb == 1) {
		temp_s += -2 * curr + 11 ;
		temp_s = 2 * temp_s -curr + 11;
		ptr_numb--;
		return temp_s;
	}
	ptr_numb--;
	return temp_s;
}
Alpha::Alpha(std::vector<std::shared_ptr<Base>> a) : Base(0){
	data = a;
	a_N++;
	curr = a_N;
	ptr_numb = 1;
}
Alpha::Alpha():Base(0) {
	a_N++;
	curr = a_N;
	ptr_numb = 1;
}
Alpha::~Alpha(){
	S += - 2* curr + 11;
	a_N--;
}
int Alpha::a_N = 0;