/*
    流(stream)为C++的输入输出操作提供了许多的便利，通常我们使用的流是std::cout用于输出，使用std::cin用于接收用户的输入，
    除此之外，C++还提供了文件流用于实现文件的读写操作，字符串流用于进行字符串的操作。
    流的含义决定了不能任意的读写数据，只能一条路走到底，处理I/O的要包含<iostream>，文件流为<fstream>
    文件流处理时有两种形式：纯文本格式的text stream和二进制流
    C++定义了4个标准流，cin、cout、cerr（标准错误）、clog（标准日志）

*/

// 一般导入这三个头文件就够了
#include <iostream>
#include <iomanip>

#include <fstream>
using namespace std;

/*文件流，主要有两个函数open和close
    ofstream	该数据类型表示输出文件流，用于创建文件并向文件写入信息。
    ifstream	该数据类型表示输入文件流，用于从文件读取信息。
    fstream	该数据类型通常表示文件流，且同时具有 ofstream 和 ifstream 两种功能，这意味着它可以创建文件，向文件写入信息，从文件读取信息。
    open中的参数：
        ios::app	追加模式。所有写入都追加到文件末尾。
        ios::ate	文件打开后定位到文件末尾。
        ios::in	    打开文件用于读取。
        ios::out	打开文件用于写入。
        ios::trunc	如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0。
*/

// 使用流读写数据实际上是操作缓冲区，先写到一个buffer中，然后再输出到文件中
int main(){
    // cout << setprecision(2) << 1000.243 << endl;    // 设置精度
    // cout << setw(20) << "OK!" << endl;      // 设置空格宽度


    // 详细读写方式见知乎https://zhuanlan.zhihu.com/p/352961501
    // 创建类对象，将打开一个流，自动创建缓冲区
    fstream s;
    s.open("abc", ios::out);   // 写数据
    char buf[1024];   // 创建一个buffer暂存数据
    for(int i = 0; i < 2; i++){
        
        cin.getline(buf, sizeof(buf));   // 从键盘读入数据，按行写入buffer中
        s.write(buf, sizeof(buf));   // 写入文件
    }
    fstream o;
    o.open("abc", ios::in);    // 只读方式打开
    // 一直读到文件末尾
    while(o.read(buf, sizeof(buf))){
        cout << buf << endl;
    }
    
    o.close();
    s.close();
    return 0;
}