#include "Base.h"
void Base::update_ptr_number(int n) {
	ptr_numb = n;
	for (int i = 0; i != data.size(); i++) {
		data[i]->update_ptr_number(data[i].use_count());
	}
}
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