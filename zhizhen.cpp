/*                   指针&函数指针               */
#include <iostream>

using namespace std;

int Func(int x){
	return x+1;
}

int main() {
	system("chcp 65001");   // 防止vscode出现中文乱码
	int num = 10;
	cout << &num << endl;
	cout << sizeof(&num) << endl;    // 在64位系统中地址占8个字节，32位中为4个字节

	int numb = 5;
	int* p = &numb;      // 地址的数据类型是指针，因此初始化一个指针指向地址
	// 也可以通过下面方式先定义再初始化
	double d = 2.0;
	double* q;
	q = &d;
	cout << p << endl;    // 直接打印是输出地址
	cout << q << endl;
	cout << *p << endl;   // 带*才是输出地址中存储的变量值
	
	*p = 100;
	cout << numb << endl;   // 当我们修改了指针指向地址里面的值，则原来的变量值也会跟着改变


	// void 空指针，空指针的初始化可以指向任意类型的数据地址，主要用于做函数参数
	void* n = &num;
	cout << *(int*)n << endl;    // 若要解引用打印变量值，则要先强制转型为对应的变量类型，再加*号

	// const 常量指针
	// 如果const加在*前面则不允许修改指针指向的值，但是可以修改指向地址
	const int* s = &num;
	cout << *s << "   ||  ";
	// *s = 200 报错；
	int data = 20;
	s = &data;
	cout << *s << endl;

	// 如果const在*后面，则正好相反，地址不能变，值可以修改
	int* const w = &num;
	cout << *w << "     ||      ";
	// w = &data 报错;
	*w = 100;
	cout << num << endl;

												/*引用显然是一种指针常量*/

	// 用指针去提取数组
	int arr[5] = { 10,20,30,40,50 };
	cout << arr << endl;     // 返回的是首元素的地址
	cout << arr + 1 << endl;  // 显然是首元素加1位置的地址
	cout << *arr << endl;    // 输出首元素值

	int* z = arr;   // 切记这里不要加&，因为arr本身就返回的是地址了
	for (int i = 0; i < 5; i++) {
		cout << z[i] << endl;
		// cout << *(z+i) << endl;    效果一样
	}

	// 二级指针：一个指针变量保存的是另外一个指针变量的地址值
	int pad = 1000;
	int* h = &pad;
	int** f = &h;
	cout << h << endl;      // 下面两行代码的输出应当是一样的
	cout << *f << endl;     // 输出h指向的地址



	// 函数指针定义：函数返回值类型 (* 指针变量名) (函数参数列表);
	// 函数指针指向一个函数的地址
	int (*fun) (int y);  /*定义一个函数指针*/
	fun = Func;          /*将Func函数的首地址赋给指针变量p*/
	int x = fun(2);
	cout<<"函数指针的返回为："<< x <<endl;
	return 0;

}

