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
	return 0;
}