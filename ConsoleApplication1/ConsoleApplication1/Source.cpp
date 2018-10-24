/*
#include <stdio.h>

using namespace std;


int main(int argc, char* argv[])
{
	for (int i=0; i<5; i++)
		printf("i is %d\n", i);
	
	for (int j=0; j<5; ++j)
		printf("j is %d\n", j);

	return 0;
}
*/
/*
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <memory>
#include <mutex>
#include <list>
#include <thread>
#include <stack>
#include <stdexcept>
#include <chrono>
#include <condition_variable>
#include <future>
#include <numeric>
#include <functional>

#include "MyBase.h"
#include "MyDerived.h"
#include "NewBase.h"
#include "NewDerived.h"
#include "DiamondBase.h"
#include "DiamondDerived.h"
#include "Fraction.h"
#include "TClass1.h"
#include "BST.h"
#include "thread_safe_queue.h"

#include <Windows.h>

using namespace std;
*/
/*

class Base
{
public:
	int a;
	Base() : a(15) { cout << "Base cons" << endl; }
	virtual ~Base() { cout << "Base des" << endl; }
    virtual void show() { cout<<" In Base a = " << a << endl; }
};
*/
  /*
class Derived: public Base
{
public:
	Derived() { cout << "Derived cons" << endl; }
	~Derived() { cout << "Derived des" << endl; }
    void show() { cout<<"In Derived \n"; }
};
*/
/*
int hand[] = { 4, 3, 1, 5, 2 }; //'T', 'K', 'J', 'A', 'Q' };

void qsortme( int intArr[], int n)
{
	cout << endl << "qsortme" << endl;

	int z = 0;
	cout << "start array" << endl;
	while (z<n) { cout << intArr[z] << " "; ++z; }
    cout << endl << endl;

	int m, tmp;
	for (int i=0; i<n-1; i++) 
	{
		m = i;
		cout << "outer iteration " << i << " m = " << m << endl;
		for (int j=i+1; j<n; j++)
		{
			cout << "  inner iteration " << j << endl;
			if (intArr[j] > intArr[m]) 
			{
				cout << "    intArr[" << j << "] > intArr[" << m << "], so m was " << m << " now is " << j << endl;
				m = j;
			}
		}
		if (m != i) 
		{
			cout << "    m(" << m << ") != i(" << i << "), so swap intArr[" << i << "] with intArr[" << m << "]." << endl;
			tmp = intArr[i];
			intArr[i] = intArr[m];
			intArr[m] = tmp;
		}
	}
	cout << "finish array" << endl;
	z=0;
	while (z<n) { cout << intArr[z] << " "; ++z; }
    cout << endl << endl;
}

template<typename T>
void compare(const T& a, const T&b)
{
	if (a > b) cout << "A>B" << endl;
	else if (a == b) cout << "A==B" << endl;
	else cout << "A<B" << endl;
}
*/
/*
void func1()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));	
	std::cout << "Hello from function \n";
}

void func2(int x)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));	
	cout << "func2 x = " << x << endl;
	std::cout << "Hello from function2 \n";
}

void func3(int& x)
{
	cout << "this thread (func3) id is " << this_thread::get_id() << endl; //	<< a << " " 
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));	
		cout << "func3 x = " << x << endl;
	}
	std::cout << "Hello from function3 \n";
}

void func5(Base& x)
{
	cout << "this thread (func3) id is " << this_thread::get_id() << endl; //	<< a << " " 
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));	
		cout << "func3 " << endl;
		x.show();
	}
	std::cout << "Hello from function5 \n";
}

void func4()
{
	cout << "this thread (func4) id is " << this_thread::get_id() << endl; //	<< a << " " 

	int x = 5;
	Base mb;
	std::thread thread_2(func5, std::ref(mb));
	thread_2.detach();
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cout << "func4, thread finished execution \n"; 
}


class my_class {

public:
	void operator()()
	{
	    std::this_thread::sleep_for(std::chrono::milliseconds(5000));	
		std::cout << "hello from the class with function call operator \n";
	}
};

//int funcsum(int m[][][], int x, int y, int z)
int funcsum(int **m[], int x, int y, int z)
{
	int sum = 0;
	for (int k=0; k<x; k++)
		for (int l=0; l<y; l++)
			for (int j=0; j<z; j++)
				sum += m[j][k][l];
	return sum;
}

class ZETA
{
public:
	ZETA(int i) { };
	ZETA(const ZETA& i) { };
	ZETA& operator=(const ZETA &i) { };
};
*/
/*
vector<int> avec;

std::list<int> my_list;
std::mutex m;

void add_to_list(int const & x)
{
	cout << "add to list " << x << endl;
	//m.lock();
	//while (!m.try_lock()) cout << "add_to_list waiting." << endl;
	lock_guard<mutex> lg(m);
	my_list.push_front(x);
	this_thread::sleep_for(chrono::milliseconds(2000));
	//m.unlock();
}

void size()
{
	//m.lock();
	//while (!m.try_lock()) cout << "size waiting." << endl;
	lock_guard<mutex> lg(m);
	int size = (int) my_list.size();
	//this_thread::sleep_for(chrono::milliseconds(2000));
	//m.unlock();
	cout << "size of the list is : " << size << endl;
}

template<typename T>
class trivial_thread_safe_stack {
	stack<T> stk;
	mutex m;

public:
	void push(T element)
	{
		lock_guard<mutex> lg(m);
		stk.push(element);
	}

	void pop()
	{
		lock_guard<mutex> lg(m);
		stk.pop();
	}

	T& top()
	{
		lock_guard<mutex> lg(m);
		return stk.top();
	}

	bool empty()
	{
		lock_guard<mutex> lg(m);
		return stk.empty();
	}

	size_t size()
	{
		lock_guard<mutex> lg(m);
		return stk.size();
	}
};

trivial_thread_safe_stack<char> char_stack;

void
stack_test()
{
	//trivial_thread_safe_stack<char> char_stack;

	cout << "stack size is " << char_stack.size() << endl;
	char_stack.push('a');
	char_stack.push('e');
	cout << "stack size is " << char_stack.size() << endl;
	cout << "what is on the top of the stack?  ans:  " << char_stack.top() << endl;
    char_stack.push('i');
	cout << "stack size is " << char_stack.size() << endl;
	cout << "what is on the top of the stack?  ans:  " << char_stack.top() << endl;
	char_stack.pop();
	cout << "stack size is " << char_stack.size() << endl;
	cout << "what is on the top of the stack?  ans:  " << char_stack.top() << endl;
	char_stack.pop();
	cout << "stack size is " << char_stack.size() << endl;
	cout << "what is on the top of the stack?  ans:  " << char_stack.top() << endl;
	char_stack.pop();
	cout << "stack size is " << char_stack.size() << endl;
	//try {
	//	cout << "what is on the top of the stack?  ans:  " << char_stack.top() << endl;
	//	char_stack.pop();
	//}
	//catch (...) {
	//	cout << "caught exception popping off empty stack" << endl;
	//}
}

template<typename T>
class thread_safe_stack {
	stack<shared_ptr<T>> stk;
	mutex m;

public:
	void push(T element)
	{
		lock_guard<mutex> lg(m);
		stk.push(make_shared<T>(element));
	}

	std::shared_ptr<T> pop()
	{
		lock_guard<mutex> lg(m);
		if (stk.empty())
		{
			throw runtime_error("stack is empty");
		}

		shared_ptr<T> res(stk.top());
		stk.pop();
		return res;
	}

	void pop(T& value)
	{
		lock_guard<mutex> lg(m);
		if (stk.empty()) throw runtime_error("stack is empty");
		value = *(stk.top().get());
		stk.pop();
	}


	bool empty()
	{
		lock_guard<mutex> lg(m);
		return stk.empty();
	}

	size_t size()
	{
		lock_guard<mutex> lg(m);
		return stk.size();
	}
};

thread_safe_stack<int> int_stack;

void
stack_test2()
{
	//trivial_thread_safe_stack<char> char_stack;
	int d = -1;
	std::shared_ptr<int> iSP;
	cout << "stack size is " << int_stack.size() << endl;
	int_stack.push(1);
	int_stack.push(2);
	cout << "stack size is " << int_stack.size() << endl;
	int_stack.pop(d);
	cout << "get what is on the top of the stack.  ans:  " << d << endl;
    int_stack.push(3);
    int_stack.push(4);
	cout << "stack size is " << int_stack.size() << endl;
	iSP = int_stack.pop();
	cout << "get what is on the top of the stack?  ans:  " << *iSP << endl;
	cout << "stack size is " << int_stack.size() << endl;
	int_stack.pop(d);
	cout << "get what is on the top of the stack?  ans:  " << d << endl;
	cout << "stack size is " << int_stack.size() << endl;
	iSP = int_stack.pop();
	cout << "get what is on the top of the stack?  ans:  " << iSP.operator*() << endl;
	cout << "stack size is " << int_stack.size() << endl;
	try {
		iSP = int_stack.pop();
		cout << "get what is on the top of the stack?  ans:  " << iSP.operator*() << endl;
	}
	catch (exception& e) {
		cout << "caught exception popping off empty stack:  " << e.what() << endl;
	}
}

void
stack_test3()
{
	//trivial_thread_safe_stack<char> char_stack;
	int d = -1;
	std::shared_ptr<int> iSP;
	cout << "stack size is " << int_stack.size() << endl;
	int_stack.push(11);
	int_stack.push(12);
	cout << "stack size is " << int_stack.size() << endl;
	int_stack.pop(d);
	cout << "get what is on the top of the stack.  ans:  " << d << endl;
    int_stack.push(13);
    int_stack.push(14);
	cout << "stack size is " << int_stack.size() << endl;
	iSP = int_stack.pop();
	cout << "get what is on the top of the stack?  ans:  " << *iSP << endl;
	cout << "stack size is " << int_stack.size() << endl;
	int_stack.pop(d);
	cout << "get what is on the top of the stack?  ans:  " << d << endl;
	cout << "stack size is " << int_stack.size() << endl;
	iSP = int_stack.pop();
	cout << "get what is on the top of the stack?  ans:  " << iSP.operator*() << endl;
	cout << "stack size is " << int_stack.size() << endl;
	try {
		iSP = int_stack.pop();
		cout << "get what is on the top of the stack?  ans:  " << iSP.operator*() << endl;
	}
	catch (exception& e) {
		cout << "caught exception popping off empty stack:  " << e.what() << endl;
	}
}

class bank_account {
private:
	double balance;
	string name;
	mutex mm;

public:
	bank_account() {};

	bank_account(double _balance, string _name) {
		balance =_balance;
		name =_name; 
	};

	bank_account(bank_account& const); // = delete;
	bank_account& operator=(bank_account& const);// = delete;

	void withdraw(double amount)
	{
		lock_guard<mutex> lg(mm);
		balance += amount;
	}

	void deposite(double amount)
	{
		lock_guard<mutex> lg(mm);
		balance += amount;
	}

	void transfer(bank_account& from, bank_account& to, double amount)
	{
		lock_guard<mutex> lg(mm);
		cout << "lock for " << from.name << " account acquire by " << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));

		cout << "waiting to acquire lock for " << to.name << " account by  " << this_thread::get_id() << endl;
		lock_guard<mutex> lg_2(to.mm);

		from.balance -= amount;
		to.balance += amount;
		cout << "transfer to - " << to.name << "   from - " << from.name << "  end \n";
	}

};

void
bank_account_test()
{
	bank_account account;

	bank_account account_1(1000, "james");
	bank_account account_2(2000, "Mathew");

	thread thread_1(&bank_account::transfer, &account, ref(account_1), ref(account_2), 500);
	//this_thread::sleep_for(chrono::milliseconds(100));
	thread thread_2(&bank_account::transfer, &account, ref(account_2), ref(account_1), 200);

	thread_1.join();
	thread_2.join();
}

std::mutex mm1;
std::mutex mm2;


void m1_frist_m2_second()
{
	std::lock_guard<std::mutex> lg1(mm1);
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "thread " << std::this_thread::get_id() << " has acquired lock for m1 mutex, its wait for m2 \n";
	std::lock_guard<std::mutex>lg2(mm2);
	std::cout << "thread " << std::this_thread::get_id() << " has acquired lock for m2 mutex \n";
}


void m2_frist_m1_second()
{
	std::lock_guard<std::mutex> lg1(mm2);
	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	std::cout << "thread " << std::this_thread::get_id() << " has acquired lock for m2 mutex, its wait for m1 \n";
	std::lock_guard<std::mutex>lg2(mm1);
	std::cout << "thread " << std::this_thread::get_id() << " has acquired lock for m1 mutex \n";
}

void run_code()
{
	std::thread thread_1(m1_frist_m2_second);
	std::thread thread_2(m2_frist_m1_second);

	thread_1.join();
	thread_2.join();
}
*/

/*
bool have_i_arrived = false;
int distance_my_destination = 10;
int distance_coverd = 0;

bool keep_driving()
{
	while (true)
	{
		this_thread::sleep_for(chrono::milliseconds(1000));
		distance_coverd++;
		cout << "distance covered is " << distance_coverd << endl;
	}

	return false;
}

void keep_awake_all_night()
{
	while (distance_coverd < distance_my_destination)
	{
		cout << "keep_awake_all_night check, whether i am there, i am this far: " << distance_coverd << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	cout << "keep_awake_all_night finally i am there, distance_coverd = " << distance_coverd << endl;
}

void set_the_alarm_and_take_a_nap()
{
	if (distance_coverd < distance_my_destination)
	{
		cout << "let me take a nap, cuz i'm not there yet. am this far: " << distance_coverd << endl;
		this_thread::sleep_for(chrono::milliseconds(10000));
	}
	cout << "set_the_alarm_and_take_a_nap finally i am there, distance_coverd = " << distance_coverd << endl;
}

void run_code()
{
	thread driver_thread(keep_driving);
	thread keep_awake_all_night_thread(keep_awake_all_night);
	thread set_the_alarm_and_take_a_nap_thread(set_the_alarm_and_take_a_nap);

	keep_awake_all_night_thread.join();
	set_the_alarm_and_take_a_nap_thread.join();
	driver_thread.join();
}
*/

/*
bool have_i_arrived = false;
int total_distance = 10;
int distance_coverd = 0;
condition_variable cv;
mutex m;

void keep_moving()
{
	while (true)
	{
		this_thread::sleep_for(chrono::milliseconds(1000));
		distance_coverd++;
		cout << "keep_moving, distance covered is: " << distance_coverd << endl;

		//notify the waiting threads if the event occurss
		if (distance_coverd == total_distance) {
			cout << "cv.notify_one" << endl;
			cv.notify_one();
		}
	}

}

void ask_driver_to_wake_u_up_at_right_time()
{
	unique_lock<std::mutex> ul(m);
	cv.wait(ul, [] {return distance_coverd == total_distance; });
	cout << "finally i am there, distance_coverd = " << distance_coverd << endl;
}

void run_code()
{
	thread driver_thread(keep_moving);
	thread passener_thread(ask_driver_to_wake_u_up_at_right_time);
	passener_thread.detach(); //.join();
	driver_thread.detach(); //.join();
}
*/

/*
bool ready = false;
std::mutex mtx;
std::condition_variable cv2;

void print_id (int id) {
  std::unique_lock<std::mutex> lck(mtx);
  while (!ready) cv2.wait(lck);
  // ...
  std::cout << "thread " << id << '\n';
}

void go() {
  std::unique_lock<std::mutex> lck(mtx);
  ready = true;
  cv2.notify_all();
}

void run_code() {
  thread threads[10];
  // spawn 10 threads:
  for (int i=0; i<10; ++i)
    threads[i] = thread(print_id,i);

  this_thread::sleep_for(chrono::milliseconds(2000));

  std::cout << "10 threads ready to race...\n";
  go();                       // go!

  for (auto& th : threads) th.join();
}
*/

/*
//thread_safe_queue<int> mqueue;
thread_safe_queue<MyBase> mqueue;

void func_1()
{
	//int value;
	MyBase value;
	mqueue.wait_pop(value);
	std::cout << value << std::endl;

}

void func_2()
{
	//int x = 10;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	MyBase x;
	mqueue.push(x);
}

void run_code()
{
	std::thread thread_1(func_1);
	std::thread thread_2(func_2);

	thread_1.join();
	thread_2.join();
}
*/

/*
int find_answer_how_old_universe_is()
{
	//this is not the ture value
	return 5000;
}

void do_other_calculations()
{
	cout << "Doing other stuff " << endl;
}

//void run_code()
//{
//	future<int> the_answer_future = async(find_answer_how_old_universe_is);
//	do_other_calculations();
//	cout << "The answer is " << the_answer_future.get() << endl;
//}

bool is_prime (int x) {
  for (int i=2; i<x; ++i) if (x%i==0) return false;
  return true;
}

void run_code ()
{
  // call function asynchronously:
  future<bool> fut = async (is_prime,444444443); 

  // do something while waiting for function to set future:
  cout << "checking, please wait";
  chrono::milliseconds span (100);
  while (fut.wait_for(span)==future_status::timeout)
    cout << '.' << std::flush;

  bool x = fut.get();     // retrieve return value

  cout << "\n444444443 " << (x?"is":"is not") << " prime.\n";
}
*/
/*
void printing()
{
	cout << "printing runs on-" << this_thread::get_id() << endl;
}

int addition(int x, int y)
{
	cout << "addition runs on-" << this_thread::get_id() << endl;
	return x + y;
}

int substract(int x, int y)
{
	cout << "substract runs on-" << this_thread::get_id() << endl;
	return x - y;
}

void run_code()
{
	cout << "main thread id -" << this_thread::get_id() << endl;

	int x = 100;
	int y = 50;

	future<void> f1 = async(launch::async, printing);
	future<int> f2 = async(launch::deferred, addition,x,y);
	future<int> f3 = async(launch::deferred | launch::async,
		substract, x, y);

	f1.get();
	cout << "value recieved using f2 future -"<<f2.get() <<endl;
	cout << "value recieved using f3 future -" << f3.get() << endl;

}
*/

/*
const int MIN_ELEMENT_COUNT = 1000;

template<typename iterator>
int parallal_accumulate(iterator begin, iterator end)
{
	long long length = std::distance(begin, end);

	//atleast runs 1000 element
	if (length <= MIN_ELEMENT_COUNT)
	{
		cout << this_thread::get_id() << endl;
		return accumulate(begin, end, 0);
	}

	iterator mid = begin;
	advance(mid, (length + 1) / 2);

	//recursive all to parallel_accumulate
	future<int> f1 = async(launch::deferred | launch::async,
		parallal_accumulate<iterator>, mid, end);
	auto sum = parallal_accumulate(begin, mid);
	return sum + f1.get();
}

void run_code()
{
	vector<int> v(10000, 1);
	cout << "The sum is " << parallal_accumulate(v.begin(), v.end()) << '\n';
	vector<int> v1(400, 1);
	cout << "The sum is " << parallal_accumulate(v1.begin(), v1.end()) << '\n';
}
*/
/*
int add(int x, int y)
{
	this_thread::sleep_for(chrono::milliseconds(500));
	cout << "add(" << x << "," << y << ") function runs in : " << this_thread::get_id() << endl;
	return x + y;
}

void task_thread()
{
	packaged_task<int(int, int)> task_1(add);
	future<int> future_1 = task_1.get_future();

	thread thread_1(move(task_1), 5, 6);
	thread_1.detach();

	cout << "task thread - " << future_1.get() << "\n";
}

void task_normal()
{
	packaged_task<int(int, int)> task_1(add);
	future<int> future_1 = task_1.get_future();
	task_1(7, 8);
	cout << "task normal - " << future_1.get() << "\n";
}

void run_code()
{
	task_thread();
	task_normal();
	cout << "main thread id : " << this_thread::get_id() << endl;
}
*/

/*
void print_int(std::future<int>& fut) {
	cout << "waiting for value from print thread \n";
	cout << "value: " << fut.get() << '\n';
}

void run_code()
{
	promise<int> prom;
	future<int> fut = prom.get_future();

	thread print_thread(print_int, ref(fut));

	this_thread::sleep_for(std::chrono::milliseconds(5000));
	cout << "setting the value in main thread \n";
	prom.set_value(10);

	print_thread.join();
}
*/

/* GET THIS TO WORK
void throw_exception()
{
	char arg[40];
	sprintf_s(arg, "input cannot be negative, thread is %d", std::this_thread::get_id());
	string s(arg);

	throw invalid_argument(s);
}

void calculate_squre_root(std::promise<int>& prom)
{
	cout << "thread is " << this_thread::get_id() << endl;
	int x = 1;
	std::cout << "Please, enter an integer value: ";
	try
	{
		std::cin >> x;
		if (x < 0)
		{
			throw_exception();
		}
		prom.set_value(std::sqrt(x));
	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;
		prom.set_exception(std::current_exception());
	}
}

void print_result(std::future<int>& fut) {
	try
	{
		cout << "thread is " << this_thread::get_id() << endl;
		int x = fut.get();
		std::cout << "value: " << x << '\n';
	}
	catch (std::exception& e) {
		std::cout << "[exception caught: " << e.what() << "]\n";
	}
}

void run_code()
{
	std::promise<int> prom;
	std::future<int> fut = prom.get_future();

	std::thread printing_thread(print_result, std::ref(fut));
	std::thread calculation_thread(calculate_squre_root, std::ref(prom));

	printing_thread.join();
	calculation_thread.join();
}
*/
//void print_result(std::future<void>& fut)
//void print_result(std::future<int>& fut)
//{
//	std::cout << fut.get() << "  - valid future \n";
/*
	//std::cout << fut.get() << "\n";
	if (fut.valid())
	{
		std::cout << "this is valid future\n";
		std::cout << fut.get() << "\n";
	}
	else
	{
		std::cout << "this is invalid future\n";
	}
	*/
//}
/*
void run_code()
{
	///promise<int> prom;
	///shared_future<int> fut;
	promise<void> prom;
	shared_future<void> fut;

	//std::shared_future<int> fut(prom.get_future());
	//std::future<int> fut(prom.get_future());  // this fails, cuz a future only accessed by single thread.

    //std::promise<void> ready_promise;
    //std::shared_future<void> ready_future(ready_promise.get_future());


	std::thread th1(print_result, std::ref(fut));
	//std::this_thread::sleep_for(std::chrono::milliseconds(500));	// adding this allows it to finish w/o exception
	std::thread th2(print_result, std::ref(fut));

	prom.set_value(5);

	th1.join();
	th2.join();
}
*/


//int main( int argc, char *argv[])
//{
	//ZETA a(10);
	//ZETA b;
	//b = a;

	/*
    //Base *bp = new Derived;
	MyBase *bp = new MyDerived;
    bp->show();  // RUN-TIME POLYMORPHISM
	delete bp;

	MyDerived *dp = new MyDerived;
	dp->show();
	//delete bp;
	delete dp;
	*/
//	vector<string> v;

	//int i=0;
	//string s;
	//while (i<10) {
	//	cin >> s;
	//	v.push_back(s);
	//	i++;
	//}

	//vector<string>::iterator ptr;
	//for (ptr = v.begin(); ptr < v.end(); ptr++)
	//{
	//	cout << *ptr << endl;
	//}

/*
//	NewBase nb;  // can't do, NewBase is abstract
	NewDerived nd1, nd2;
	NewBase *nb1, *nb2;
	nb1 = &nd1;
	nb2 = &nd2;
	cout << "Base ptr -> Deriv obj." << endl;
	nb1->setA(45);
	cout << *nb1 << endl;

	cout << "Base ptr -> Deriv obj." << endl;
	nb2->setA(54);
	cout << *nb2 << endl;


	
	//cout << nd << endl;
	cout << nd1 << endl;
	cout << nd2 << endl;
*/

/*
	cout << endl;
	cout << "create DiamondBase db" << endl;
	DiamondBase *db = new DiamondBase();
	cout << endl;
	cout << "create DiamondDerived dd" << endl;
	DiamondDerived *dd = new DiamondDerived();
	cout << endl;
	cout << "create DiamondDerived2 dd2" << endl;
	DiamondDerived2 *dd2 = new DiamondDerived2();
	cout << endl;
	cout << "create DiamondDerived3 dd3" << endl;
	DiamondDerived3 *dd3 = new DiamondDerived3();
	cout << endl;

	//DiamondDerived2 *dbp = dd3;
	//dd3->printMe();
	//DiamondDerived2 *dbpp = db;
	//dbpp->printMe();


	cout << endl;
	cout << "delete DiamondBase db" << endl;
	delete db;
	cout << endl;
	cout << "delete DiamondDerived dd" << endl;
	delete dd;
	cout << endl;
	cout << "delete DiamondDerived2 dd2" << endl;
	delete dd2;
	cout << endl;
	cout << "delete DiamondDerived3 dd3" << endl;
	delete dd3;
	cout << endl;

	cout << endl;
	cout << "declare DiamondBase diab" << endl;
	DiamondBase diab;
	cout << endl;
	cout << "declare DiamondDerived diabd" << endl;
	DiamondDerived diabd;
	cout << endl;
	cout << "declare DiamondDerived2 diabd2" << endl;
	DiamondDerived2 diabd2;
	cout << endl;
	cout << "declare DiamondDerived3 diabd3" << endl;
	DiamondDerived3 diabd3;
	cout << endl;
	
	cout << endl;
	cout << "working with diamonderived2 and diamondbase" << endl;
	DiamondDerived2 dd4;
	DiamondBase &db4 = dd4;  // need to be reference to, else you get your own object as a DiamondBase, not DiamondDerived2
	db4.printMe();
	cout << endl;

	DiamondBase* db4p = &dd4;
	db4p->printMe();

	qsortme(hand, 5);

	compare(9, 4);
	compare(45.0, 97.0);
	compare('h', 'h');

	myTemplate<int> nT(5);
	//myTemplate<char> nC;
	//myTemplate<double> nD;

*/

/*
    Fraction a;
	cout << "Fraction a [noargs]: " << a << endl;

	Fraction b(4, 7);
	cout << "Fraction b [4,7]: " << b << endl;

	Fraction c;
	cout << "Fraction c [noargs]: " << c << endl;

	c = b;
	cout << "Fraction c [c=b]:" << c << endl;

	c = c;
	cout << "Fraction c [c=c]: " << c << endl;

	Fraction d(b);
	cout << "Fraction d [b]: " << d << endl;

	Fraction e;
	cin >> e;
	cout << "Fraction e: " << e << endl;

	Fraction f;
	cout << "Fraction f [noargs]: " << f << endl;
	f = b * e;
	cout << "Fraction f [b*e]: " << f << endl;

	Fraction* pf = new Fraction(11,13);
	cout << "Fraction pf [11,13]: " << *pf << endl;
	if (pf) delete pf;

	Fraction g(7,8);
	cout << "Fraction g [7,8]: " << g << endl;
	g = g * 4;
	cout << "Fraction g [g*4]: " << g << endl;

	Fraction h(10,12);
	cout << "Fraction h [10,12]: " << h << endl;
	h = 3 * h;
	cout << "Fraction h [3*h]: " << h << endl;
	
	Fraction m(2,3);
	cout << "Fraction m [2,3]: " << m << endl;
	Fraction n;
	cout << "Fraction n [noargs]: " << n << endl;
	m *= n;
	cout << "Fraction m [m*=n]: " << m << endl;

	Fraction r(-7,-10);
	cout << "Fraction r [7,10]: " << r << endl;
	Fraction s(2,-3);
	cout << "Fraction s [2,3]: " << s << endl;
	r *= s;
	cout << "Fraction r [r*=s]: " << r << endl;

	Fraction w;
	cout << "Fraction w [noargs]: " << w << endl;
	w.SetNumerator(8);  // NOTE **** entering error state by setting Numerator ONLY on a [0,0] fraction
	w.SetDenominator(9);  // WOULD exit error state if setting Denominator right away, but in this particular
	                      // order, it's a problem.
	cout << "Fraction w [num=8,denom=9]: " << w << endl;
	Fraction x(1,2);
	cout << "Fraction x [1,2]: " << x << endl;
	try {
		cout << "try setting x denominator to zero." << endl;
		x.SetDenominator(0);
	}
	catch (invalid_argument &ex) {
		cout << ex.what() << endl;
	}

	Fraction z1(-1,2);
	cout << "Fraction z1 [-1,2]: " << z1 << endl;
	z1.SetDenominator(-2);
	cout << "Fraction z1 [set denom=-2]: " << z1 << endl;
	Fraction z2(-1, -2);
	cout << "Fraction z2 [-1,-2]: " << z2 << endl;
	Fraction z3(1,-2);
	cout << "Fraction z3 [1,-2]: " << z3 << endl;
	z3.SetNumerator(-2);
	cout << "Fraction z3 [set num=-2]: " << z3 << endl;
	Fraction z4(0,4);
	cout << "Fraction z4 [0,4]: " << z4 << endl;
	Fraction z5(-4,-8);
	cout << "Fraction z5 [-4,-8]: " << z5 << endl;
	try {
		Fraction z6(-4,0);
		cout << "Fraction z6 [-4,0]: " << z6 << endl;
	}
	catch (invalid_argument &ex) {
		cout << ex.what() << endl;
	}
	
	Fraction a1(10,15);
	cout << "a1(10,15): " << a1 << endl;

	Fraction b1(6,10);
	cout << "b1(6,10): " << b1 << endl;

	Fraction c1(-4,24);
	cout << "c1(-4,24): " << c1 << endl;

	Fraction d1(0,15);
	cout << "d1(0,15): " << d1 << endl;

	Fraction e1(100,10);
	cout << "e1(100,10): " << e1 << endl;

	Fraction f1(34,34);
	cout << "f1(34,34): " << f1 << endl;

	Fraction g1(7,23);
	cout << "g1(7,23): " << g1 << endl;
	
	TClass1<float> tc1;
	tc1.setValue(10.0);
	cout << "tc1.value is " << tc1.getValue() << endl;

	TClass1<char> tc2;
	tc2.setValue('a');
	cout << "tc2.value is " << tc2.getValue() << endl;

	TClass1<long> tc3;
	tc3.setValue(100);
	cout << "tc3.value is " << tc3.getValue() << endl;
*/

	/*
	//create thread using fuction
	//std::thread thread1(func1);

	//create thread using class with function call operator
	//my_class mc;
	//std::thread thread2(mc);

	//create thread using lambda expression
	//std::thread thread3([] {
	//    std::this_thread::sleep_for(std::chrono::milliseconds(5000));	
//		std::cout << "hello from the lambda \n";
	//});

	int d = -1;
	//thread thread4(func2, d);

	int e = -9;
	//thread thread5(func3, ref(e));

	//DWORD a = GetCurrentThreadId();

	//cout << "thread 1, 2, 3, and main IDs: " << thread1.get_id() << " " 
	//	<< thread2.get_id() << " " 
	//	<< thread3.get_id() << " " 
	cout << "this thread id is " << this_thread::get_id() << endl; //	<< a << " " 
	//	<< endl;

	//thread1.join();
	//thread2.join();
	//thread3.join();
	//thread1.detach();
	//thread1.joinable() ? cout << "T1 joinable." << endl : cout << "T1 not joinable." << endl;
	//thread2.detach();
	//thread3.join();
	//thread4.join();
	//thread5.detach();

	cout << "max threads is " << thread::hardware_concurrency() << endl;
	thread thread6(func4);
	thread6.join();

    this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "This is main thread \n";
	*/

	/*
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.insert(35);
    t.insert(5);
	cout << "display in order traversal." << endl;
    t.display();
	cout << "display pre order traversal." << endl;
    t.displaypre();
	cout << "display post order traversal." << endl;
    t.displaypost();
    //t.remove(20);
    //t.display();
    //t.displaypre();
    //t.displaypost();
    //t.remove(25);
    //t.display();
    //t.displaypre();
    //t.displaypost();
    //t.remove(30);
    //t.display();
    //t.displaypre();
    //t.displaypost();
	*/


	/*
	cout << "begin test" << endl;
	thread thread_1(add_to_list, 4);
	size();
	thread thread_2(add_to_list, 11);
	size();

	this_thread::sleep_for(chrono::milliseconds(5000));
    size();
	thread_1.join();
	thread_2.join();
	*/
	/*
	//stack_test();
	thread ts1(stack_test);
	this_thread::sleep_for(chrono::milliseconds(150));
	thread ts2(stack_test);

	this_thread::sleep_for(chrono::milliseconds(3000));

	ts1.join();
	ts2.join();
	*/
/*
	//stack_test2();
	thread ts1(stack_test2);
	//this_thread::sleep_for(chrono::milliseconds(150));
	thread ts2(stack_test3);

	ts1.detach();
	ts2.detach();
	//this_thread::sleep_for(chrono::milliseconds(3000));

	//ts1.join();
	//ts2.join();
	*/

	//bank_account_test();
	//run_code();
	/*
	for (int dd=0; dd<10; ++dd) cout << "dd is " << dd << endl;

	for (int ded=0; ded<10; ded++) cout << "ded is " << ded << endl;

	int xx = 0, xy = 0;

	xx = 6;
	xy = xx++;
	cout << "xx is " << xx << " xy is " << xy << endl;

	xx=0;
	xy = 0;
	xx=6;
	xy = ++xx;
	cout << "xx is " << xx << " xy is " << xy << endl;

	return 0;
	*/
//}

#include <iostream>
#include <list>
#include <thread>
#include <string>
#include <Windows.h>
#include <mutex>
#include <unordered_map>
#include <map>

std::list<int> g_Data;
std::list<int> h_Data;
const int SIZEz = 5000000;
const int SIZEh = 10000;
std::mutex h_Mutex;

class String {
public:
	String() {
		std::cout << "String()" << std::endl;
	}
	String(const String &) {
		std::cout << "String(const String&)" << std::endl;
	}
	String & operator=(const String&) {
		std::cout << "operator=(const String&)" << std::endl;

		return *this;
	}
	~String() {
		std::cout << "~String()" << std::endl;
	}
};
void Download(const String &file) {
	//std::cout << "[Downloader]Started download of file :" << file << std::endl; 
	for (int i = 0; i < SIZEz; ++i) {
		g_Data.push_back(i);
	}
	std::cout << "[Downloader]Finished download" << std::endl; 
}

void Process() {
	std::cout << "Threadid:" << std::this_thread::get_id() << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << i << ' ';
	}
}

void Download2() {
	for (int i = 0; i < SIZEh; ++i) {
		std::lock_guard<std::mutex> mtx(h_Mutex);
		h_Data.push_back(i);
	}
}

void Download3() {
	for (int i = 0; i < SIZEh; ++i) {
		//Use std::lock_guard to lock a mutex (RAII)
		std::lock_guard<std::mutex> mtx(h_Mutex);
		h_Data.push_back(i);
		if (i == 500)
			return;
	}
}

#include <queue>
using namespace std;

void heap_min()
{
    priority_queue <int> pq; 
    pq.push(5); 
    pq.push(1); 
    pq.push(10); 
    pq.push(30); 
    pq.push(20); 
  
    // One by one extract items from max heap 
    while (pq.empty() == false) 
    { 
        cout << pq.top() << " "; 
        pq.pop(); 
    } 
	cout << endl;

}

void heap_max()
{
    priority_queue <int, vector<int>, greater<int> > pq; 
    pq.push(5); 
    pq.push(1); 
    pq.push(10); 
    pq.push(30); 
    pq.push(20); 
  
    // One by one extract items from min heap 
    while (pq.empty() == false) 
    { 
        cout << pq.top() << " "; 
        pq.pop(); 
    } 
	cout << endl;
}

class Point 
{ 
   int x; 
   int y; 
public: 
   Point(int _x, int _y) 
   { 
      x = _x; 
      y = _y; 
   } 
   int getX() const { return x; } 
   int getY() const { return y; } 
}; 
  
// To compare two points 
class myComparator 
{ 
public: 
    int operator() (const Point& p1, const Point& p2) 
    { 
        return p1.getX() > p2.getX(); 
    } 
}; 

void heap_user()
{
    priority_queue <Point, vector<Point>, myComparator > pq; 
  
    // Insert points into the min heap 
    pq.push(Point(10, 2)); 
    pq.push(Point(2, 1)); 
    pq.push(Point(1, 5)); 
  
    // One by one extract items from min heap 
    while (pq.empty() == false) 
    { 
        Point p = pq.top(); 
        cout << "(" << p.getX() << ", " << p.getY() << ")"; 
        cout << endl; 
        pq.pop(); 
    } 
    cout << endl; 
}

//void SockMerchant ()
//{
//#include <bits/stdc++.h>

//using namespace std;

//vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    int pairCount = 0;
    unordered_map<int, int> M;
    for (int i=0; i<ar.size(); ++i) {
        M[ar[i]]++;
        if (M[ar[i]] == 2) {
            ++pairCount;
            M[ar[i]] = 0;
        }
    }
	for(unordered_map<int,int>::iterator iter = M.begin(); iter != M.end(); ++iter)
	{
		cout << iter->first << endl;
	}

	return pairCount;
}

/*
int calcNumbers(vector<int>& primes, int index)
{
	int retVal = 1;
	if (primes.size() == 0) retVal 1;
	else if (primes.size() == 1) retVal = primes[index]);
	else retVal = retVal * calcNumbers(primes, index+1);
	return retVal;
}
*/
void composites(vector<int>& primes)
{

	int k=0, j=0, vSize = primes.size();
	int product=1;
	map<int, int> M;

	for (int i=0; i<vSize; ++i)
	{
		j=i+1;
		while (j<vSize) 
		{
			product = primes[i] * primes[j];
			cout << "inside while, product is primes[" << i << "](" << primes[i] << ") * primes[" << j << "](" << primes[j] << ") = " << product << endl;
			M[product]=product;
			++j;
		}
	}
	cout << endl;


/*
	for (int i=0; i<vSize; ++i) {
		product=primes[i];
		cout << "product starts with " << product << "; ";
		for (j=vSize-1-i; j>=0; --j) {
			if (j != i) {
				cout << "product is " << product << " * primes[" << j << "](" << primes[j] << ") = ";
				product = product * primes[j];
				cout << product << endl;
			}
		}
		cout << "stored product is " << product << endl;
		M[product]=product;
	}
/ *
		cout << endl;
		product = primes[i];
		for (k=i+1; k<vSize; ++k)
		{
			cout << "product is " << product << " * " << primes[k] << endl;
			product = product * primes[k];
		}
		cout << "outside for k, final product is " << product << endl;
		M[product]=product;
	}
*/
	//sort(M.begin(), M.end());
	for(map<int,int>::iterator iter = M.begin(); iter != M.end(); ++iter)
	{
		cout << iter->first << endl;
	}
}

/*
int main()
{

    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = sockMerchant(n, ar);

    fout << result << "\n";

    fout.close();

    return 0;

}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

}
*/


void func1_1_2()
{
	std::cout << "Hello from func1_1_2 \n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));	
	std::cout << "func1_1_2 post sleep " << endl << endl;
}

class my_class_1_2 {

public:
	void operator()()
	{
		std::cout << "hello from the class my_class_1_2 with function call operator \n";
	    std::this_thread::sleep_for(std::chrono::milliseconds(3000));	
		std::cout << "class my_class_1_2 post sleep " << endl << endl;
	}
};


int lecture_1_2(void)
{
	int vRetVal = 0;

	//create thread using fuction
	std::thread thread1(func1_1_2);

	//create thread using class with function call operator
	my_class_1_2 mc;
	std::thread thread2(mc);

	//create thread using lambda expression
	std::thread thread3([] {
		std::cout << "hello from the lambda \n";
	    std::this_thread::sleep_for(std::chrono::milliseconds(3000));	
		std::cout << "hello from the lambda post sleep " << endl << endl;
	});

	// additions for lecture_1_3
	thread1.joinable() ? cout << "pre-join ... T1 joinable." << endl : cout << "T1 not joinable." << endl;
	thread2.joinable() ? cout << "pre-join ... T2 joinable." << endl : cout << "T2 not joinable." << endl;
	thread3.joinable() ? cout << "pre-join ... T3 joinable." << endl : cout << "T3 not joinable." << endl;

	//thread1.join();
	//thread2.join();
	//thread3.join();
	thread1.detach();
	thread2.detach();
	thread3.detach();

	// additions for lecture_1_3
	thread1.joinable() ? cout << "post-join ... T1 joinable." << endl : cout << "T1 not joinable." << endl;
	thread2.joinable() ? cout << "post-join ... T2 joinable." << endl : cout << "T2 not joinable." << endl;
	thread3.joinable() ? cout << "post-join ... T3 joinable." << endl : cout << "T3 not joinable." << endl;

	try { thread2.detach(); }
	catch (exception &e) { cout << "caught a detach exception after joining.  " << e.what() << endl; }

	cout << "Hello from main thread" << endl;
    //this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "Main thread post sleep " << endl;

	int d = -1;
	//thread thread4(func2, d);

	int e = -9;
	//thread thread5(func3, ref(e));

	//DWORD a = GetCurrentThreadId();

	//cout << "thread 1, 2, 3, and main IDs: " << thread1.get_id() << " " 
	//	<< thread2.get_id() << " " 
	//	<< thread3.get_id() << " " 
	cout << "lecture_1_2, main, this thread id is " << this_thread::get_id() << endl; //	<< a << " " 
	//	<< endl;

	//// additions for lecture_1_3
	//thread1.joinable() ? cout << "pre-join ... T1 joinable." << endl : cout << "T1 not joinable." << endl;
	//thread2.joinable() ? cout << "pre-join ... T2 joinable." << endl : cout << "T2 not joinable." << endl;
	//thread3.joinable() ? cout << "pre-join ... T3 joinable." << endl : cout << "T3 not joinable." << endl;

	//thread1.join();
	//thread2.join();
	//thread3.join();
	////thread1.detach();
	////thread2.detach();
	////thread3.detach();

	//// additions for lecture_1_3
	//thread1.joinable() ? cout << "post-join ... T1 joinable." << endl : cout << "T1 not joinable." << endl;
	//thread2.joinable() ? cout << "post-join ... T2 joinable." << endl : cout << "T2 not joinable." << endl;
	//thread3.joinable() ? cout << "post-join ... T3 joinable." << endl : cout << "T3 not joinable." << endl;

	//try { thread2.detach(); }
	//catch (exception &e) { cout << "caught a detach exception after joining.  " << e.what() << endl; }

	//thread1.detach();
	//thread1.joinable() ? cout << "T1 joinable." << endl : cout << "T1 not joinable." << endl;
	//thread2.detach();
	//thread3.join();
	//thread4.join();
	//thread5.detach();

	cout << "max threads is " << thread::hardware_concurrency() << endl;
	//thread thread6(func4);
	//thread6.join();
	//cout << "Hello from main thread" << endl;
    //this_thread::sleep_for(chrono::milliseconds(3000));
	//cout << "Main thread post sleep " << endl;
	return vRetVal;
}

int lecture_1_4(void)
{
	int vRetVal = 0;

	//create thread using fuction
	std::thread thread1(func1_1_2);

	//thread1.join();
	thread1.detach();

	cout << "Hello from main thread" << endl;

	system("pause");
	return vRetVal;
}

void func_1_1_5() {
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "hello from func_1_1_5" << endl;
}

void other_operations_1_5()
{
	cout << "this is other_operations_1_5" << endl;
	throw runtime_error("this is a runtime error from other_operations_1_5");
}


int lecture_1_5(void)
{
	int vRetVal = 0;

	thread thread_1(func_1_1_5);

	try {
		other_operations_1_5();
		thread_1.join();
	}
	catch (...)
	{
		thread_1.join();
	}
	cout << "this is main thread in lecture_1_5" << endl;

	return vRetVal;
}

//#include "thread_guard.h"

void func1_1_6(int x, int y)
{
	cout << "X(" << x << ") + Y(" << y << ") = " << x+y << endl;
}

int lecture1_6()
{
	int vRetVal = 0;
	int p = 9, q = 6;
	thread thread_1(func1_1_6, p, q);
	thread_1.join();
	return vRetVal;
}

void func_1_1_6b(int& x, bool& cond)
{
	while (cond)
	{
		cout << "thread1 value is " << x << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

int lecture1_6b()
{
	int vRetVal = 0;
	int a = 18;
	bool bVal = true;

	cout << "a is " << a << " bVal is " << bVal << endl;
	thread thread_1(func_1_1_6b, ref(a), ref(bVal));
	this_thread::sleep_for(chrono::milliseconds(5000));

	a = 21;
	cout << "a is " << a << " bVal is " << bVal << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));

	//thread_1.join();  // joining here is a block until thread ends, which it can't, cuz next line ends thread
	bVal = false;
	cout << "a is " << a << " bVal is " << bVal << endl;
	thread_1.join();  // joining here is a block until thread ends, which it already has
	return vRetVal;
}

void func1_1_8a()
{
	cout << "this is func1_1_8a" << endl;
}

void func1_1_8b()
{
	cout << "this is func1_1_8b" << endl;
}

int lecture1_8()
{
	int vRetVal = 0;
	thread thread_1(func1_1_8a);

	//thread thread_2 = thread_1;

	thread thread_2a = move(thread_1);

	thread_1 = thread(func1_1_8b);

	return vRetVal;
}

void funct116c()
{
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "new thread id is " << this_thread::get_id() << endl;
}

int lecture1_6c()
{
	int vRet = 0;

	thread thread_1(funct116c);
	cout << "thread id before joining: " << thread_1.get_id() << endl;
	thread_1.join();

	thread thread_2;
	cout << "default constructed thread: " << thread_2.get_id() << endl;
	cout << "thread_1 id post joining: " << thread_1.get_id() << endl;
	cout << "main thread id : " << this_thread::get_id() << endl;

	return vRet;
}

//#include "V10_accumulate_algorithm.h"

//int main() {
//	int func_result = 0;
//	func_result = lecture1_6c();
	//run_code();

	/*
	String file;
	std::cout << "[main]User started an operation" << std::endl; 
	//Download(file);  // non multi threaded call
	//use std::ref and std::cref to pass arguments as reference & const reference, respectively
	std::thread thDownloader(Download,std::ref(file));//cref(file) );
	std::cout << "[main]User started another operation" << std::endl;
	
	//Always check before joining a thread
	if (thDownloader.joinable()) {
		thDownloader.join() ;
	}
	*/
	//system("Pause");
	/*
	std::thread t1(Process);
	//Returns the native type of the thread
	//On Linux, the native type is pthread_t
	HANDLE handle = t1.native_handle();
	//SetThreadDescription(handle, L"MyThread");	
	auto id = t1.get_id();
	std::cout << "t1.get_id()" << id << std::endl; 

	int cores = std::thread::hardware_concurrency();

	std::cout << "Cores:" << cores << std::endl;
	t1.join();

	std::thread thDownloader4(Download3);
	std::thread thDownloader2(Download2);
	thDownloader4.join();
	thDownloader2.join();
	std::cout << g_Data.size() << std::endl; 
	*/
	/*
	heap_min();
	heap_max();
	heap_user();

	vector<int> V;
	V.push_back(10);
	V.push_back(20);
	V.push_back(20);
	V.push_back(10);
	V.push_back(10);
	V.push_back(30);
	V.push_back(50);
	V.push_back(10);
	V.push_back(20);

	int pairCount = sockMerchant(9, V);
	cout << "paircount is " << pairCount << endl;

	*/
	/*
	vector<int> V;
	V.push_back(2);
	V.push_back(3);
	V.push_back(2);
	V.push_back(5);
	for (auto& it : V) cout << it << " ";
	cout << endl;

	composites(V);

	//V.clear();
	//V.push_back(2);
	//V.push_back(3);
	//V.push_back(7);
	//V.push_back(5);
	//composites(V);

	map<int, int> M1;
	unordered_map<int, int> M2;

	M1[2]=1;
	M1[4]=1;
	M1[3]=1;
	M1[1]=1;
	cout << "ordered map" << endl;
	for(map<int,int>::iterator iter = M1.begin(); iter != M1.end(); ++iter)
	{
		cout << iter->first << endl;
	}
	cout << endl;

	cout << "unordered map" << endl;
	M2[2]=1;
	M2[4]=1;
	M2[3]=1;
	M2[1]=1;
	for (auto& it : M2) cout << it.first << endl;
	cout << endl;
	*/
	
	//int func_result = 0;
	//func_result = lecture1_6();

//	return 0;
//}

std::list<int> my_list;
std::mutex m;

void add_to_list(int const & x)
{
	cout << "add to list " << x << endl;
	//m.lock();
	//while (!m.try_lock()) cout << "add_to_list waiting." << endl;
	lock_guard<mutex> lg(m);
	my_list.push_front(x);
	this_thread::sleep_for(chrono::milliseconds(1000));
	//m.unlock();
}

void size()
{
	//m.lock();
	//while (!m.try_lock()) cout << "size waiting." << endl;
	lock_guard<mutex> lg(m);
	int size = (int) my_list.size();
	this_thread::sleep_for(chrono::milliseconds(1000));
	//m.unlock();
	cout << "size of the list is : " << size << endl;
}

int func2_13a()
{
	for (int i=15; i<20; i++)
		add_to_list(i);
	return 0;
}

int func2_13b()
{
	for (int i=5; i<10; i++)
		add_to_list(i);
	return 0;
}

int main()
{
	thread thread_1(func2_13a);
	thread thread_2(func2_13b);

	thread_1.detach();
	thread_2.detach();

	this_thread::sleep_for(chrono::milliseconds(5000));

	for (list<int>::iterator it=my_list.begin(); it != my_list.end(); ++it)
		cout << ' ' << *it;

	cout << endl;

	system("pause");
	return 0;
}



