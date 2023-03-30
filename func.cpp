#include "func.h"

int mysum(int a, int b) {
	int c;
	c = a + b;
	return c;   // 注意：函数的返回值最好不要返回局部变量，当项目比较大函数很多时，容易出错

}