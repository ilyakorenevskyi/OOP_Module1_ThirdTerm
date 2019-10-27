#pragma once
#include "Base.h"
class Gamma : public Base
{
	static int g_N;
	
public:
	Gamma(std::vector<std::shared_ptr<Base>> a);
	Gamma();
	~Gamma();
};

