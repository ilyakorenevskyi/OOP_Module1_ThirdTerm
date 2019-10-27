#pragma once
#include "Base.h"

class Beta :public Base
{
	static int b_N;
	
public:
	Beta(std::vector<std::shared_ptr<Base>> a);
	int check_S(int temp_s);
	Beta();
	~Beta();
};

