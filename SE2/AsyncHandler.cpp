#include "AsyncHandler.h"

void AsyncHandler::StartThreadedFunction(const std::function<void()> &func)
{
	std::thread thread(ExcecuteThreadedFunction, std::ref(func));
	thread.detach();
}

void AsyncHandler::ExcecuteThreadedFunction(const std::function<void()> &func)
{
	func();

}