#pragma once
#include <memory>
#include <vector>
#include <iostream>
extern int S;
class Base{
	static int base_N;
	
public:
	std::vector< std::shared_ptr<Base> > data;
	virtual int cost() { return 0; };
	Base(bool check);
	Base();
	void update_ptr_number(int n);
	
	virtual int check_S(int temp_s)=0;
	int ptr_numb;
	int N;
	int curr;
	virtual ~Base();
};

