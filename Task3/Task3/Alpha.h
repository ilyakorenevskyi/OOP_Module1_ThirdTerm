#pragma once
#include "Base.h"
class Alpha : public Base
{
	static int a_N;
public:
	
	int check_S(int temp_s);

	Alpha(std::vector<std::shared_ptr<Base>> a);
	Alpha();
	~Alpha();
};

