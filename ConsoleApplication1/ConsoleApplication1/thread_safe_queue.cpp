#include "thread_safe_queue.h"

#include <iostream>


template<typename T>
thread_safe_queue<T>::thread_safe_queue(void)
{
}


template<typename T>
thread_safe_queue<T>::~thread_safe_queue(void)
{
}

template<typename T>
thread_safe_queue<T>::thread_safe_queue(thread_safe_queue const& other_queue)
{
	lock_guard<mutex> lg(other_queue.m);
	queue = other_queue.queue;
}

template<typename T>
void 
thread_safe_queue<T>::push(T& value)
{
	std::lock_guard<std::mutex> lg(m);
	queue.push(std::make_shared<T>(value));
	cv.notify_one();
}

template<typename T>
std::shared_ptr<T> 
thread_safe_queue<T>::pop()
{
	std::lock_guard<std::mutex> lg(m);
	if (queue.empty())
	{
		return std::shared_ptr<T>();
	}
	else
	{
		std::shared_ptr<T> ref(queue.front());
		queue.pop();
		return ref;
	}
}

template<typename T>
bool 
thread_safe_queue<T>::empty()
{
	std::lock_guard<std::mutex> lg(m);
	return queue.empty();
}

template<typename T>
std::shared_ptr<T> 
thread_safe_queue<T>::wait_pop()
{
	std::unique_lock<std::mutex> lg(m);
	cv.wait(lg, [this] {
		return !queue.empty();
	});
	std::shared_ptr<T> ref = queue.front();
	queue.pop();
	return ref;
}

template<typename T>
size_t
thread_safe_queue<T>::size()
{
	std::lock_guard<std::mutex> lg(m);
	return queue.size();
}

template<typename T>
bool 
thread_safe_queue<T>::wait_pop(T& ref)
{
	std::unique_lock<std::mutex> lg(m);
	cv.wait(lg, [this] {
		return !queue.empty();
	});

	ref = *(queue.front().get());
	queue.pop();
	return true;
}

template<typename T>
bool 
thread_safe_queue<T>::pop(T& ref)
{
	lock_guard<mutex> lg(m);
	if (queue.empty())
	{
		return false;
	}
	else
	{
		ref = queue.front();
		queue.pop();
		return true;
	}
}
