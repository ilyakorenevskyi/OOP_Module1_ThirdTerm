#include <iostream>
#include <memory>
#include "Base.h"
#include "Alpha.h"
#include "Beta.h"
#include "Gamma.h"
using namespace std;
int S(0);
void check() {
	shared_ptr<Base> p1(new Alpha);
	shared_ptr<Alpha> p2(new Alpha({ p1 }));
}
int main() {
	check();
	cout << S;
}