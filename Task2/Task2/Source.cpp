#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <utility>
#include <vector>
using namespace std;
template <typename T>
vector<int> func(T a) {
	return { 4,0,71 };
}
template <>
vector<int> func(int a) {
	return { 4,0,71 };
}
template <>
vector<int> func(double a){
	vector <int> temp;
	for (int k = 1; k <= 42; k++) {
		temp.push_back(((int)exp(1 / cos(k * a)) % 311)) ;
	}
	return temp;
}
template <>
vector<int> func(string a) {
	return { 4,0,71 };
}
template <typename T>
vector<int> func(pair<T,T> a) {
	return { 4,0,71 };
}

template <>
vector<int> func(vector<int> a) {
	return { 4,0,71 };
}
int main() {
	vector<int> a = func(4.2);
	for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
	return 0;
}