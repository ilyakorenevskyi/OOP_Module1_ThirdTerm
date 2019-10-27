#pragma once
#include "Base.h"
class Gamma : public Base
{
	static int g_N;
	
public:
	Gamma(std::vector<std::shared_ptr<Base>> a);
	int check_S(int temp_s);
	Gamma();
	~Gamma();
};

