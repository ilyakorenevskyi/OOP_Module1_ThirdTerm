#include <iostream>
#include <memory>
#include "Base.h"
#include "Alpha.h"
#include "Beta.h"
#include "Gamma.h"
using namespace std;
int S(0);
int predict(vector<shared_ptr<Base>> &sequence) {
	int s = 0;
	if (sequence.size() == 0) return 0;
	for (int i = 0; i != sequence.size(); i++) {
		sequence[i]->update_ptr_number(sequence[i].use_count());
	}
	for (int i = 0; i != sequence.size(); i++) {
		if(sequence[i]->ptr_numb==1){
			s += predict(sequence[i]->data);
			s += sequence[i]->check_S(s);
	}

}

int main() {
	vector< shared_ptr<Base>> a;
	Alpha b,c;
	a.push_back(make_shared<Alpha>(b));
	a.push_back(make_shared<Alpha>(c));
	predict(a);
	cout << a[1]->check_S();
}