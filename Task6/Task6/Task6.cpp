#include "pch.h"
#include <iostream>
#include <thread>
#include <mutex> 
#include <chrono>
#include <ctime>

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
	std::this_thread::sleep_for(
		std::chrono::seconds(rand() % 10));
	std::cout << "Pushkin shoot\n";
}

void threadFunction2()
{
	{
		std::unique_lock<std::mutex> lck(lock);
		while (!ready) cv.wait(lck);
	}
	std::this_thread::sleep_for(
		std::chrono::seconds(rand() % 10));
	std::cout << "Dantes react\nDantes shoot\n";
}

void go() {
	std::unique_lock<std::mutex> lck(lock);
	std::cout << "Ready.." << std::endl;
	std::this_thread::sleep_for(
		std::chrono::seconds(rand() % 10));
	ready = true;
	std::cout << "Go!" << std::endl;
	cv.notify_all();
}

int main()
{
	srand((unsigned int)time(NULL));
	std::thread d1(threadFunction1);
	std::thread d2(threadFunction2);
	std::thread sec(go);
	sec.join();
	d1.join();
	d2.join();
	return 0;
}