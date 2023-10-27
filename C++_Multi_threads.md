## 一、C++多线程基础
C++11之前，C++语言没有对并发编程提供语言级别的支持，这使得我们在编写可移植的并发程序时，存在诸多的不便。现在C++11中增加了线程以及线程相关的类，很方便地支持了并发编程，使得编写的多线程程序的可移植性得到了很大的提高。

**C++11中提供的线程类叫做std::thread，基于这个类创建一个新的线程非常的简单（需要`#include <thread>`）**，只需要提供线程函数或者函数对象即可，并且可以同时指定线程函数的参数。我们首先来了解一下这个类提供的一些常用API：

**<font color='red'>一个需要注意的问题是：</font>**

当启动了一个线程（创建了一个thread对象）之后，在这个线程结束的时候（std::terminate()），我们如何去回收线程所使用的资源呢？thread库给我们两种选择：加入式（join()）分离式、（detach()）

另外，我们必须要在线程对象销毁之前在二者之间作出选择，否则程序运行期间就会有bug产生。


- 1、构造函数
  ```c++
  // ① 默认构造函数，不做任何处理
  thread() noexcept;
  // ② 移动构造函数，将other的线程所有权转移给新的thread 对象。之后other不再表示执行线程。
  thread( thread&& other ) noexcept;
  // ③ 创建线程对象，并执行回调函数f，Args表示要传给函数的参数
  template< class Function, class... Args >
  explicit thread( Function&& f, Args&&... args );
  // ④ 删除拷贝构造
  thread( const thread& ) = delete;
  ```

- 2、公共成员函数
  - 2.1 get_id()  获取当前进程ID号
  
    应用程序启动之后默认只有一个线程，这个线程一般称之为`主线程或父线程`，通过线程类创建出的线程一般称之为`子线程`，每个被创建出的线程实例都对应一个`线程ID`，这个ID是唯一的，可以通过这个ID来区分和识别各个已经存在的线程实例，这个获取线程ID的函数叫做`get_id()`

  - 2.2 join()

    <mark>join()字面意思是连接一个线程，意味着主动地等待线程的终止（线程阻塞）。</mark>在某个线程中通过子线程对象调用join()函数，<mark>调用这个函数的线程被阻塞，但是子线程对象中的任务函数会继续执行，当任务执行完毕之后join()会清理当前子线程中的相关资源</mark>然后返回，同时，调用该函数的线程解除阻塞继续向下执行。

    再次强调，我们一定要搞清楚这个函数阻塞的是哪一个线程，函数在哪个线程中被执行，那么函数就阻塞哪个线程。

  - 2.3 detach()

    detach()函数的作用是进行线程分离，分离主线程和创建出的子线程。<mark>在线程分离之后，主线程退出也会一并销毁创建出的所有子线程，在主线程退出之前，它可以脱离主线程继续独立的运行，任务执行完毕之后，这个子线程会自动释放自己占用的系统资源。</mark>

    **<font color='red'>注意事项：线程分离函数detach()不会阻塞线程，子线程和主线程分离之后，在主线程中就不能再对这个子线程做任何控制了，比如：通过join()阻塞主线程等待子线程中的任务执行完毕，或者调用get_id()获取子线程的线程ID。</font>**

  - 2.4 joinable()

    joinable()函数用于判断主线程和子线程是否处理关联（连接）状态，一般情况下，二者之间的关系处于关联状态，该函数返回一个布尔类型：
    - 返回值为true：主线程和子线程之间有关联（连接）关系
    - 返回值为false：主线程和子线程之间没有关联（连接）关系

  - 2.5 operator=

    线程中的资源是不能被复制的，因此通过=操作符进行赋值操作最终并不会得到两个完全相同的对象。


- 3、静态函数

  `thread`线程类还提供了一个静态方法，用于获取当前计算机的CPU核心数，根据这个结果在程序中创建出数量相等的线程，<mark>每个线程独自占有一个CPU核心，这些线程就不用分时复用CPU时间片，此时程序的并发效率是最高的。</mark>

  ```c++
  #include <iostream>
  #include <thread>
  using namespace std;

  int main()
  {
      int num = thread::hardware_concurrency();
      cout << "CPU number: " << num << endl;
  }
  ```


## 二、this_thread 命名空间

  通过公共成员函数可以对**当前线程**进行相关的操作

  - 调用命名空间`std::this_thread`中的`get_id()`方法可以得到当前线程的线程ID
  - 命名空间`this_thread`中提供了一个休眠函数`sleep_for()`，调用这个函数的线程会马上从`运行态`变成`阻塞态`并在这种状态下休眠一定的时长，因为阻塞态的线程已经让出了CPU资源，代码也不会被执行，所以线程休眠过程中对CPU来说没有任何负担（进程或线程被创建后都有这五种状态：`创建态`，`就绪态`，`运行态`，`阻塞态(挂起态)`，`退出态(终止态)`。<mark>为了能够实现并发处理，多个线程都是分时复用CPU时间片，快速的交替处理各个线程中的任务。因此多个线程之间需要争抢CPU时间片，抢到了就执行，抢不到则无法执行</mark>）需要注意的是：<font color='red'>程序休眠完成之后，会从阻塞态重新变成就绪态，就绪态的线程需要再次争抢CPU时间片，抢到之后才会变成运行态，这时候程序才会继续向下运行。</font>
  - 命名空间`this_thread`中提供了另一个休眠函数`sleep_until()`：指定线程阻塞到某一个指定的时间点`time_point`类型，之后解除阻塞
  - 命名空间`this_thread`中提供了一个非常绅士的函数`yield()`，在线程中调用这个函数之后，处于`运行态`的线程会主动让出自己已经抢到的CPU时间片，最终变为`就绪态`，这样其它的线程就有更大的概率能够抢到CPU时间片了。<font color='red'>线程调用了yield()之后会主动放弃CPU资源，但是这个变为就绪态的线程会**马上参与到下一轮CPU的抢夺战中**，不排除它能继续抢到CPU时间片的情况，这是概率问题。</font>


## 三、call_once()函数

  在某些特定情况下，某些函数只能在多线程环境下调用一次，比如：要初始化某个对象，而这个对象只能被初始化一次，就可以使用`std::call_once()`来保证函数在多线程环境下只能被调用一次。使用`call_once()`的时候，需要一个`once_flag`作为`call_once()`的传入参数
  - flag：once_flag类型的对象，要保证这个对象能够被多个线程同时访问到
  - f：回调函数，可以传递一个有名函数地址，也可以指定一个匿名函数
  - args：作为实参传递给回调函数

  ```c++
  #include <iostream>
  #include <thread>
  #include <mutex>
  using namespace std;

  once_flag g_flag;
  void do_once(int a, string b)
  {
      cout << "name: " << b << ", age: " << a << endl;
  }

  void do_something(int age, string name)
  {
      static int num = 1;
      call_once(g_flag, do_once, 19, "luffy");
      cout << "do_something() function num = " << num++ << endl;
  }

  int main()
  {
      thread t1(do_something, 20, "ace");
      thread t2(do_something, 20, "sabo");
      thread t3(do_something, 19, "luffy");
      t1.join();
      t2.join();
      t3.join();

      return 0;
  }

  ```
