#include "Tech.h"

bool operator==(const Tech& t1, const Tech& t2) {
	return t1.tech_number == t2.tech_number;
}
bool operator!=(const Tech& t1, const Tech& t2) {
	return !(t1==t2);
}
bool operator > (const Tech& t1, const Tech& t2) {
	return t1.tech_number > t2.tech_number;
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
Tech::Tech( int diff){
	tech_number++;
	difficulty = diff;
}
Tech::~Tech()
{
}
int Tech::tech_number = 0;