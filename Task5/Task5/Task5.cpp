// Task5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>
#include <numeric>


using namespace std;

void task5() {
	string s, s1;
	cout << "your string:";
	getline(cin, s);
	auto pos = remove(s.begin(), s.end(), ' '); 
	//follows the last element not removed
	s.erase(pos, s.end());
	cout << "new string:";
	cout << s;
	getchar();
	cout << "your substring:";
	getline(cin, s1);
	auto pos1 = search(s.begin(), s.end(), s1.begin(), s1.end());
	if (pos1 == s.end())
		cerr << "Can't find";
}

void task11() {
	vector<int> v(10), v1(v.size());
	int i;
	srand(time(NULL));
	generate(v.begin(), v.end(),  [](){return rand()%10;});
	cout << "random vector:";
	for (int& x : v) cout << ' ' << x;
	cout << endl << "your number: ";
	cin >> i;
	auto it =copy_if(v.begin(), v.end(), v1.begin(), [i](int e){return (e % i == 0);});
	v1.erase(it, v1.end());
	cout << "new vector:";
	for (int& x : v1) cout << ' ' << x;	
}

void task14() {
	srand(time(NULL));
	vector<int> x(5), x1(5), y = {1,5,9,5,1};
	do
	{
		generate(x.begin(), x.end(), []() {return rand() % 10;});
		reverse_copy(x.begin(), x.end(), x1.begin());
	} while (x < y || x != x1);
	cout << "new value: ";
	for (int& i : x) cout << i;
	//int val = accumulate(x.begin(), x.end(), 0, [](int old, int add) { return old * 10 + add; });
	float val = 0;
	for_each(x.begin(), x.end(), [&val](int elm) { val = val * 10 + elm; });
	cout << endl << "speed: " << (val - 15951) / 2;
}

int main()
{
	task14();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
