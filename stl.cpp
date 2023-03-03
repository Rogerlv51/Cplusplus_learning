/* STL标准库使用 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<deque>
#include<list>
#include<map>

using namespace std;

void myprint(int val) {
	cout << val << endl;
}

void printDeque(const deque<int>& d)    // 打印输出deque容器，和vector类似（一样）
{
	for (auto it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	vector<int> p;         // vector容器，显然是个类模板<>中指定类型，vector之间可以互相嵌套
	p.push_back(1);        // 添加元素
	p.push_back(2);
	p.push_back(3);
	p.push_back(4);
	//   遍历vector，方法一
	for (auto it = p.begin(); it != p.end(); it++) {
		cout << *it << endl;
	}

	// 方法二，使用算法库里面的for_each函数
	for_each(p.begin(), p.end(), myprint);      //myprint传递的是一个函数对象

	cout << p.at(3) << endl;       // vector容器也可以通过at方法取值，其他的容器基本上也有这个函数
	p.at(3) = 5;     // 还可以通过at对位置赋值
	cout << p.at(3) << endl;


	// string容器
	string s;
	s = "abcdefghk";
	cout << s << endl;
	//cout << s[100] << endl;     // 两种访问方式都可以，但是[]索引越界程序直接终止
	//cout << s.at(100) << endl;   // 使用at方法则会抛出异常而不是直接终止
	
	// 字符串拼接
	s.append("adb");
	cout << s << endl;
	int q = s.find('a', 2);    // 字符串查找，第二个参数为从第几个位置开始查找
	cout << q << endl;

	s.replace(1, 3, "fff");    // 字符串替换，起始位置，终止位置，替换成什么值
	cout << s << endl;

	// deque容器是一种双向开口的连续线性空间，而vector是单向开口的，deque可以理解为一种双端队列
	deque<int> d;
	d.push_back(1);   // 尾插
	d.push_back(2);
	d.push_front(3);   // 头插
	printDeque(d); 

	deque<int> d1;
	d1.push_back(1);   // 输入123，替换成312
	d1.push_back(2);
	d1.push_back(3);
	d1.assign( d.begin(), d.end());    // 用新元素替换原来旧元素
	printDeque(d1);

	d1.pop_back();    // 尾删
	d1.pop_front();   // 头删

	d1.insert(d1.begin(), 1000);   // 插入
	d1.erase(d1.begin());     // 删除指定位置元素
	printDeque(d1);

	// stack栈容器，后进先出，不允许有遍历行为， 常用api跟vector容器也基本一致，不再举例
	// queue队列容器，先进先出，有两个出口，同样的队列也不能遍历，没有迭代器

	// list容器：双向循环链表，链表是一种物理存储单元上非连续、非顺序的存储结构，元素的逻辑顺序使用指针索引
	// 两个指针一个指向前一个节点，一个指向后一个节点
	// 一些稍微有区别的API
	list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(1);
	L.remove(1);         // 删除所有对应元素值
	for (auto it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	L.resize(10, 100);         // 改变list大小并指定值填充
	for (auto it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;


	// map容器（很重要），所有的元素都会根据键值对自动排序类比Python中的key-value，map不允许两个元素有相同的key
	// unordered_map是无序的，不会自动排序, unordered_set是无序的set
	map<int, int> m;
	// 插入数据的四种方式
	m.insert(pair<int, int>(1, 10));   // 以pair键值对插入
	m.insert(map<int, int>::value_type(3, 30));  // map自带函数
	m.insert(make_pair(2, 20));    // 使用make_pair函数创建pair对象（推荐）
	m[4] = 40;       // 直接赋值法
	// 迭代器遍历
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << "key= " << (*it).first <<" " << "value= " << it->second << endl;
	}
	return 0;
}