#pragma once
#include "DebugHandler.h"
#include <functional>
#include <thread>
#include <mutex>

class AsyncHandler
{
private:
	static void ExcecuteThreadedFunction(const std::function<void()> &func);

public:
	static void StartThreadedFunction(const std::function<void()> &func);

};

class AutoDeletionMutex {
private:
	std::mutex mtx;
	volatile int locks;

public:

	AutoDeletionMutex() { locks = 0; };

	void wait() {
		lock();
		unlock();
	}

	void lock() {
		locks++;
		mtx.lock();
	}

	void unlock() {
		locks--;
		if (locks == 0) 
		{
			mtx.unlock();
			delete this;
		}
		else 
		{
			mtx.unlock();
		}
	}
};

class AyncOperation
{


public:




};

