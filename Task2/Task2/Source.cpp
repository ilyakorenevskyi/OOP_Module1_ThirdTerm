#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int fac_mod(int a, int mod) {
	int res = a % mod;
	for (int i = 1; i < a; i++) {
		res = (res * (a-i)) % mod;
	}
	return res;
}
int degree_mod(int a,int degree,int mod) {
	int res = a;
	for (int i = 1; i < degree; i++) {
		res = (res * a) % mod;
	}
	return res;
}
template <typename T>
vector<int> func(T a) {
	return { 4,0,61 };
}
template <>
vector<int> func(int a) {
	vector<int> res;
	int temp = 0;
	if (a > 0) {
		for (int k = 2; k <= 111; k++) {
			temp = fac_mod(a, k) - (a * a) % k;
			res.push_back((temp<0)?(k+temp):temp);
		}
	}
	else {
		temp = (degree_mod((0-a), 4, 204) - degree_mod((0-a), 3, 204));
		temp = (temp < 0) ? (204 + temp) : temp;
		while (temp >= 4) {
			res.push_back(temp % 4);
			temp = temp / 4;
		}
		res.push_back(temp);
		reverse(begin(res), end(res));
	}
	return res;
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
			res.push_back(degree_mod(temp,temp, 411));
			temp = 0;
		}
	}
	if(temp!=0) res.push_back(degree_mod(temp, temp,411));
	return res;
}
template <typename T>
vector<int> func(pair<T,T> a) {
	vector<int>res;
}
template <>
vector<int> func(vector<vector<int>> a) {
	vector<int> res;
	for (int i = 0; i != a.size(); i++) {
		for (int j = a[i].size() - 1; j >= 0; j--) {
			res.push_back(a[i][j]);
		}
	}
	return res;
}
int main() {
	vector<vector<int>> test_v = { {1,2},{3,4,5} };
	string b = "10fg23rj9l";
	vector<int> a = func(-5);
	for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
	return 0;
}