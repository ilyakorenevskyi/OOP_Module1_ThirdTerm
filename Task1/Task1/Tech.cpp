#include "Tech.h"

bool operator==(const Tech& t1, const Tech& t2) {
	return t1.name == t2.name;
}
bool operator!=(const Tech& t1, const Tech& t2) {
	return !(t1==t2);
}
bool operator > (const Tech& t1, const Tech& t2) {
	return t1.name > t2.name;
}
bool operator < (const Tech& t1, const Tech& t2) {
	return t2 > t1;
}
bool operator >= (const Tech& t1, const Tech& t2) {
	return !(t1 < t2);
}
bool operator <= (const Tech& t1, const Tech& t2) {
	return !(t1 > t2);
}
Tech::Tech(std::string  n, int diff){
	name = n;
	difficulty = diff;
}


Tech::~Tech()
{
}
