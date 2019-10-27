#include "Beta.h"
Beta::Beta(){
	b_N++;
	curr=b_N;
}
Beta::~Beta(){
	S  -= curr;
	b_N--;
}
int Beta::b_N = 0;
