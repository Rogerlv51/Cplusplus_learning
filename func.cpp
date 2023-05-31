#include "func.h"
#include <iostream>
#include <assert.h>


using namespace std;

int mysum(int a, int b) {
	int c;
	c = a + b;
	return c;   // 注意：函数的返回值最好不要返回局部变量，当项目比较大函数很多时，容易出错

}

void test(int a){
	assert(a==10);  // assert断言是一个debug常用方式，表示如果不满足表达式条件则立即中断程序
	cout<<"success"<<endl;
}

int main(){
	int a = 10;
	test(a);

	// 最基础lambda表达式使用，注意返回类型一定要是auto
    auto basic_lamda = [] {cout << "hello word" <<endl;};
    // lambda表示式传参
    auto just_add = [](int a, int b) { return a + b;};
    basic_lamda();
    int c = just_add(10, 15);
    cout << "just_add = " << c << endl;

    // lambda表达式捕获外部变量
    int x = 5;
    // 此写法不能改变x值，所以下面语句会报错
    // auto multiply = [x](int a) {x = a * x;return x; };
    auto multiply = [&x](int a) {x = a * x; return x; };  // 传引用即可
    int d = multiply(10);
    cout << "multiply = " << d << endl;

    // lambda表达式最大的一个应用是可以作为函数参数，起到回调函数的作用
    if([](int a, int b) {return a > b;}(2, 1)){
        cout << "2 > 1" << endl;
    }
	
	return 0;
}