#pragma once
#include "Base.h"
class Alpha : public Base
{
	static int a_N;
public:
	Alpha(std::vector<std::shared_ptr<Base>> a);
	Alpha();
	~Alpha();
};

