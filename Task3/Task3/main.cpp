#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Base.h"
#include "Alpha.h"
#include "Beta.h"
#include "Gamma.h"
using namespace std;
int S(0);
int predict(vector<shared_ptr<Base>> &sequence,bool order,int s) { //Function to predict S value
	if (sequence.size() == 0) return s;
	int beg = 0, end = sequence.size();
	if (!order) {
		for (int i = beg; i != end; i += pow(-1, order)) {
			sequence[i]->update_ptr_number(sequence[i].use_count());
		}
	}
	for (int i = beg; i != end; i += 1) {
		
			s = sequence[i]->check_S(s);
			if(sequence[i]->ptr_numb==0)
			s = predict(sequence[i]->data, 1, s);
	}
	return s;
}

void delet(vector<shared_ptr<Base>>& sequence) {			//Deletes obj in sequence
	sequence.erase(sequence.begin(), sequence.end());
}
int main() {
	/*vector< shared_ptr<Base>> a, v2, v3;
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
	delet(a);*/
	vector <shared_ptr<Base>> res;
	srand(time(0));
	for (int i = 0; i != 10; i++) {
		switch (rand() % 3 + 1) {
		case 1: res.push_back(make_shared<Alpha>(res));
		case 2: res.push_back(make_shared<Beta>());
		case 3: res.push_back(make_shared<Gamma>(res));
		}
	}
	vector <shared_ptr<Base>>  temp = { res[0],make_shared<Alpha>() ,make_shared<Alpha>() ,make_shared<Beta>() };
	res.push_back(make_shared<Alpha>(temp));
	/*res.push_back(make_shared<Alpha>());
	vector <shared_ptr<Base>>  temp = { res[0],make_shared<Alpha>() ,make_shared<Alpha>() ,make_shared<Beta>() };
	res.push_back(make_shared<Alpha>(temp));*/
	cout << predict(res, 0, 0) << " ";
	delet(res);
	cout << S;
	return 0;
}