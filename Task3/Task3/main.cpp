#include <iostream>
#include <memory>
#include "Base.h"
#include "Alpha.h"
#include "Beta.h"
#include "Gamma.h"
using namespace std;
int S(0);
int predict(vector<shared_ptr<Base>> &sequence,bool order,int s) { //Function to predict S value
	if (sequence.size() == 0) return s;
	int beg = 0, end = sequence.size();
	if (order) {
		beg = sequence.size() - 1;
		end = -1;
	}
	for (int i = beg; i != end; i+=pow(-1,order)) {
		sequence[i]->update_ptr_number(sequence[i].use_count());
	}
	for (int i = beg; i != end; i += pow(-1, order)) {
		if (sequence[i]->ptr_numb == 1) {
			s = sequence[i]->check_S(s);
			s = (sequence[i]->data, 1, s);
		}
	}
	return s;
}
void delet(vector<shared_ptr<Base>>& sequence) {			//Deletes obj in sequence
	sequence.erase(sequence.begin(), sequence.end());
}
int main() {
	vector< shared_ptr<Base>> a, v2, v3;
	Alpha c;
	Gamma d, g;
	v2.push_back(make_shared<Alpha>(c));
	v2.push_back(make_shared<Gamma>(d));
	v2.push_back(v2[0]);
	Alpha b(v2);
	a.push_back(make_shared<Alpha>(b));
	a.push_back(make_shared<Gamma>(g));
	v3 = a;
	cout << predict(a,0,0) << " ";
	delet(a);
	cout << S;
	return 0;
}