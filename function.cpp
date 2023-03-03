#include <iostream>
#include "func.h"

#define MAX 1024     // 宏定义

#define GETSUM(x,y) ((x)+(y))     // 定义宏函数

using namespace std;


// 关于函数传值的内存细节
void changeNumber(int a) {
	a = 1000;
}

void changeNumber1(int* p) {
	*p = 1000;
}

// 当指针作为函数返回值类型时，注意不要返回局部变量的地址，这样会造成悬挂指针的不良影响

// 函数和结构体
struct s_time
{
	int hours; // 小时
	int mins; // 分钟
};

s_time sum(s_time A, s_time B) {
	s_time total;
	total.mins = (A.mins + B.mins) % 60;
	total.hours = (A.hours + B.hours) + (A.mins + B.mins) / 60;
	return total;
}

void test(const int& a, const int& b){
		cout << "函数使用引用传参"  << endl;
		cout << a + b << endl;
}

int main() {
	system("chcp 65001");
	int re;
	int a = 10; int b = 20;
	re = mysum(a, b);
	cout << re << endl;

	changeNumber(re);
	cout << re << endl;      // 可以看到这样的函数调用赋值，并不会改变re的值，因为函数中变量只是临时的，调用完之后栈会释放
	changeNumber1(&re);      // 指针变量接收的是地址
	cout << re << endl;      // 只有传的是地址才能改变外部变量值

	s_time t1 = { t1.hours = 10, t1.mins = 5 };
	s_time t2 = { 10, 60 };
	cout << t1.hours << " " << t1.mins << endl;
	s_time t = sum(t1, t2);
	cout << t.hours << "小时" << "   " << t.mins << "分钟" << endl;

	cout << GETSUM(10 + 20, 30 + 40) * 5 << endl;

	
	// 什么是引用？就是给变量取别名nickname，实际上表示的是变量本身
	/*
		（1）在引用的使用中，单纯给某个变量取个别名是毫无意义的，引用的目的主要用于在函数参数传递中，解决大块数据或对象的传递效率和空间不如意的问题。
		（2）用引用传递函数的参数，能保证参数传递中不产生副本，提高传递的效率，且通过const的使用，保证了引用传递的安全性。
		（3）引用可以直接改变变量的值，而指针实际上是间接操作。
	*/
	int num = 100;
	int& nnum = num;
	cout << (num == nnum) << endl;
	
	test(2, 3);
	return 0;
}


