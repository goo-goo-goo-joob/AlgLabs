#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

void task5() {
	string s, s1;
	cout << "your string:";
	getline(cin, s);
	auto pos = remove(s.begin(), s.end(), ' ');
	s.erase(pos, s.end());
	cout << "new string:" << s;
	getchar();
	cout << "your substring:";
	getline(cin, s1);
	auto pos1 = search(s.begin(), s.end(),
		s1.begin(), s1.end());
	if (pos1 == s.end())
		cerr << "Can't find" << endl;
}
void task11() {
	vector<int> v(10), v1(v.size());
	int i;
	srand(time(NULL));
	generate(v.begin(), v.end(),
		[](){return rand()%10;});
	cout << "random vector:";
	for (int& x : v) cout << ' ' << x;
	cout << endl << "your number: ";
	cin >> i;
	auto it = copy_if(v.begin(), v.end(),
		v1.begin(),
		[i](int e){return (e % i == 0);});
	v1.erase(it, v1.end());
	cout << "new vector:";
	for (int& x : v1) cout << ' ' << x;	
	cout << endl;
}
void task14() {
	srand(time(NULL));
	vector<int> x(5), x1(5), y = {1,5,9,5,1};
	do{
		generate(x.begin(), x.end(),
			[]() {return rand() % 10;});
		reverse_copy(x.begin(), x.end(),
			x1.begin());
	} while (x < y || x != x1);
	cout << "new value: ";
	for (int& i : x) cout << i;
	float val = 0;
	for_each(x.begin(), x.end(),
		[&val](int elm) { val = val * 10 + elm; });
	cout << endl << "speed: " << (val - 15951) / 2;
}
int main(){
	task5();
	task11();
	task14();
	return 0;
}