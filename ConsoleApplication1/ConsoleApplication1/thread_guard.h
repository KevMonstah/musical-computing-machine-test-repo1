#ifndef __THREAD_GUARD_H__
#define __THREAD_GUARD_H__

#pragma once

#include <thread>

using namespace std;

class thread_guard
{
	thread& t;

public:
	explicit thread_guard(thread& _t) : t(_t) {}

	~thread_guard(void)
	{
		if (t.joinable()) t.join();
	}

	//thread_guard::thread_guard(const thread_guard& _tg) = delete;
	thread_guard(const thread_guard& _tg) = delete;

	//thread_guard& thread_guard::operator = (const thread_guard& _tg) = delete;
	thread_guard& operator = (const thread_guard& _tg) = delete;
};

#endif