#pragma once
#ifndef __TSQ_H__
#define __TSQ_H__

#include <iostream>
#include <mutex>
#include <queue>
#include <memory>
#include <condition_variable>

using namespace std;

template<typename T>
class thread_safe_queue
{
private:

	mutex m;
	condition_variable cv;
	queue<shared_ptr<T>> queue;

public:
	thread_safe_queue(void);
	thread_safe_queue(thread_safe_queue const& other_queue);
	~thread_safe_queue(void);

	void push(T& value);
	std::shared_ptr<T> pop();
	bool empty();
	std::shared_ptr<T> wait_pop();
	size_t size();
	bool wait_pop(T& ref);
	bool pop(T& ref);
};


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
	cout << "push value: " << value << endl;
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
		cout << "pop, queue is empty" << endl;
		return std::shared_ptr<T>();
	}
	else
	{
		std::shared_ptr<T> ref(queue.front());
		queue.pop();
		cout << "pop, returning " << *ref << endl;
		return ref;
	}
}

template<typename T>
bool 
thread_safe_queue<T>::empty()
{
	cout << "queue empty?" << endl;
	std::lock_guard<std::mutex> lg(m);
	return queue.empty();
}

template<typename T>
std::shared_ptr<T> 
thread_safe_queue<T>::wait_pop()
{
	std::unique_lock<std::mutex> lg(m);
	cv.wait(lg, [this] {
		cout << "wait_pop, waiting on queue not empty" << endl;
		return !queue.empty();
	});
	std::shared_ptr<T> ref = queue.front();
	cout << "wait_pop (ret ptr), returning " << ref.operator*() << endl;
	queue.pop();
	return ref;
}

template<typename T>
size_t
thread_safe_queue<T>::size()
{
	std::lock_guard<std::mutex> lg(m);
	size_t size = queue.size();
	cout << "queue size is " << size << endl;
	return size; //queue.size();
}

template<typename T>
bool 
thread_safe_queue<T>::wait_pop(T& ref)
{
	std::unique_lock<std::mutex> lg(m);
	cv.wait(lg, [this] {
		cout << "wait_pop, waiting on queue not empty" << endl;
		return !queue.empty();
	});

	ref = *(queue.front().get());
	cout << "wait_pop (ref param) returning " << ref << endl;
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
		cout << "pop, queue is empty" << endl;
		return false;
	}
	else
	{
		ref = queue.front();
		cout << "pop, returning " << *ref << endl;
		queue.pop();
		return true;
	}
}

#endif // __TSQ_H__

