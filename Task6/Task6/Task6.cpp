// Task6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <chrono>         // std::chrono::system_clock
#include <thread>         // std::thread
#include <mutex>          // std::timed_mutex
#include <ctime>          // std::time_t, std::tm, std::localtime, std::mktime
#include <vector> 
#include <cstdarg>

std::mutex lock;
std::condition_variable cv;
bool ready = false;

void threadFunction1()
{
	{
		std::unique_lock<std::mutex> lck(lock);
		while (!ready) cv.wait(lck);
	}
	std::cout << "Pushkin react\n";
	std::this_thread::sleep_for(std::chrono::seconds(rand() % 10));
	std::cout << "Pushkin shoot\n";
}

void threadFunction2()
{
	{
		std::unique_lock<std::mutex> lck(lock);
		while (!ready) cv.wait(lck);
	}
	std::this_thread::sleep_for(std::chrono::seconds(rand() % 10));
	std::cout << "Dantes react\nDantes shoot\n";
	//std::cout << "Dantes shoot\n";
}

void go() {
	std::unique_lock<std::mutex> lck(lock);
	std::cout << "Ready.." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(rand() % 10));
	ready = true;
	std::cout << "Go.." << std::endl;
	cv.notify_all();
}

int main()
{
	//srand((unsigned int)time(NULL));
	std::thread d1(threadFunction1);
	std::thread d2(threadFunction2);

	std::thread sec(go);
	sec.join();
	d1.join();
	d2.join();
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
