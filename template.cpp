#include <iostream>
#include <string>
using namespace std;


/*
	实参通常是通过值传递给函数的，这意味着形参接收的只是发送给它们的值的副本，它们存储在函数的本地内存中。
	对形参值进行的任何更改都不会影响原始实参的值。
	然而，有时候可能会希望一个函数能够改变正在调用中的函数（即调用它的函数）中的一个值，这可以通过引用传递的方式来完成。
*/

// 函数模板
template <typename T>
T Max(T& a, T& b) {          // 传引用而不仅仅是传值
	return a < b ? b : a;
}

// 类模板
template <class T, class U = int>    // 还可以指定默认类型
class Person {
public:

	Person(T name, U age) {
		this->m_Name = name;
		this->m_Age = age;
	}    // 构造函数

	void showPerson() {
		cout << "名字： " << this->m_Name << "年龄： " << this->m_Age << endl;
	}
	T m_Name;
	U m_Age;
};


int main() {
	int a = 10;
	int b = 3;
	int c = Max(a, b);     // 注意传入参数的类型要一致（一次调用时）
	int d = Max<int>(a, b);     // （显示的）调用方式
	cout << c << endl;
	// 使用模板函数的好处是更加泛化，当我们不知道数据类型时或者想在一个函数中对不同的类型做相同的处理则可以使用模板
	float x = 3.5;
	float y = 15.8;
	cout << Max(x, y) << endl;
	
	// 类模板在初始化时必须显式地指定类型，不能像函数模板一样系统自动识别传入的类型
	Person<string, int> person("zs", 25);
	person.showPerson();
	return 0;
}