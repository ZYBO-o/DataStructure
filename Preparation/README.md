# C++ 工具准备

## 一.智能指针类

### 1.问题的出现

**内存泄漏**是一个出现后很难查找的问题，出现原因主要有：

+ 动态申请内存，**用完后不归还**
+ C++语言中**没有垃圾回收机制**
+ 指针**无法控制**指向堆空间的生命周期——**<font color = red>最本质的问题</font>**

### 2.问题解决的思路

> 如果能够使指针在生命周期结束的时候自动归还堆空间，那就能解决一半的问题了

C++软件平台提供了**智能指针**：

+ 指针在生命周期结束时**主动释放堆空间**
+ 一片堆空间**最多只能由一个指针标识**
+ **杜绝**指针运算与指针比较

### 3.智能指针的设计思路

+ **通过类模板描述指针的行为**

  > 能够定义不同类型的指针对象

+ **重载指针特征操作符( * ,  ->)**

  > 利用对象模拟原生指针行为

### 4.主要实现

[代码链接]()

```c++
template <typename T>
class SmartPointer
{
protected:
    T* m_pointer;
public:
    //构造函数:默认情况下指针为空 ——> 疑问：为什么不能直接用SmartPointer(){m_pointer = nullpter}?
    SmartPointer(T* p = nullptr)
    {
        m_pointer = p;
    }

    //拷贝函数
    SmartPointer(const SmartPointer<T>& obj)
    {
        m_pointer = obj.m_pointer;
        const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
    }

    //重载 = 运算符，将赋值后obj的指针删除，使得只有m_pointer指向堆空间
    SmartPointer<T>& operator = (const SmartPointer<T>& obj);

    //重载 * 运算符
    T& operator * ();

    //重载 -> 运算符
    T* operator -> ();

    //查看是否为空
    bool IsNull();

  	//获取指针
    T* get();
  
  	//析构函数
  	~SmartPointer()
    {
      	delete m_pointer;
    }
```

### 5.分析

+ 通过定义在析构函数中释放指针，满足了 **指针在生命周期结束时主动释放堆空间** 的目标
+ 通过 `=` 重载运算符的构建，满足了 **一片堆空间最多只能由一个指针标识 **的目标
+ 因为没有构建 `++` 重载运算符，满足了 **杜绝指针运算与指针比较** 的目标



## 二.异常类