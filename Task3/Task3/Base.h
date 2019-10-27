#pragma once
#include <memory>
#include <vector>
extern int S;
class Base{
	static int base_N;
	
public:
	std::vector< std::shared_ptr<Base> > data;
	Base();
	int curr;
	~Base();
};

