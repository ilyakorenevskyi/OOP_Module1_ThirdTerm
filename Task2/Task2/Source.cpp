#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <utility>
#include <vector>
using namespace std;
int degree_mod(int a,int mod) {
	int res = a;
	for (int i = 1; i < a; i++) {
		res = (res * a) % mod;
	}
	return res;
}
template <typename T>
vector<int> func(T a) {
	return { 4,0,71 };
}
template <>
vector<int> func(int a) {
	return { 4,0,3};
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
	vector <int> res;
	int temp=0,d=1;
	for (int i = 0; i != a.size(); i++) {
		if(a[i] <= '9' && a[i] >= '0') {
			temp = temp*10+(a[i]-'0');
			d--;
		}
		else if (temp!=0) {
			res.push_back(degree_mod(temp, 411));
			temp = 0;
		}
	}
	if(temp!=0) res.push_back(degree_mod(temp, 411));
	return res;
}
template <typename T>
vector<int> func(pair<T,T> a) {
	return { 4,0,1 };
}

template <>
vector<int> func(vector<vector<int>> a) {
	
}
int main() {
	string b = "10fg23rj9l";
	vector<int> a = func(b);
	for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
	cout <<endl <<degree_mod(9,411);
	return 0;
}