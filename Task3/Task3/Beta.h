#pragma once
#include "Base.h"

class Beta :public Base
{
	static int b_N;
	
public:
	Beta(std::vector<std::shared_ptr<Base>> a);
	Beta();
	~Beta();
};

