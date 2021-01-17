# 线性结构

<!-- GFM-TOC -->

* [线性结构](#C++工具准备)

  * [一、顺序存储]()

  * [二、数组]()

  * [三、链式存储]()

    <!-- GFM-TOC -->

---

## 一.线性表的操作

### 1.线性表的常见操作

+ 将元素插入线性表
+ 将元素从线性表中删除
+ 获取目标位置处元素的值
+ 设置目标位置处元素的值
+ 获取线性表的长度
+ 清空线性表

创建抽象类，为之后的实现做准备。

```c++
template <typename T>
class List : public Object
{
public:
    virtual bool insert(int i, const T& e) = 0;
    virtual bool remove(int i) = 0;
    virtual bool get(int i, const T& e) = 0;
    virtual bool set(int i, T& e) const = 0;
    virtual int length() const =0;
    virtual void clear() = 0;
};
```

### 2.线性表的顺序存储结构

用一段地址连续的存储单元依次存储线性表中的数据元素。

<img src="../images/3.png" style="zoom:30%;" />

#### 设计思路：

+ 用一维数组来实现顺序存储结构
  + 存储空间：`T *m_array`
  + 当前长度：`int m_length`
+ 顺序存储结构的元素获取操作
  + 判断目标位置是否合法
  + 将目标位置作为数组下标获取元素
+ 顺序存储结构的元素的插入操作
  + 判断目标位置是否合法
  + 将插入位置之后的所有元素向后移动一个位置
  + 将新元素插入至目标位置
  + 线性表长度加1
+ 顺序存储结构的元素删除操作
  + 判断目标位置是否合法
  + 将插入位置之后的所有元素向前移动一个位置
  + 线性表长度减1

#### 抽象实现

顺序结构表的抽象实现，结构图如下所示：

<img src="../images/4.png" style="zoom:50%;" />

其中`SeqList`是一个抽象类，只是实现了一些关键操作，但是不能生成具体的对象。因为对于顺序空间的指定，是在其子类`StaticList`和`DynamicList`中进行操作。具体设计要点如下：

+ 抽象类模板，存储空间的位置和大小由子类完成。
+ 实现顺序存储结构线性表的 **关键操作** (增,删,改,查,等)
+ 提供数组操作符，方便快速获取元素

[代码链接]()

```c++
template <typename T>
class SeqList : public List<T>
{
protected:
    T* m_array; 	//指向顺序存储空间，具体值的指定由子类完成
    int m_length;	//当前线性表的长度
public:
    bool insert(int i, const T& e);
    bool remove(int i);
    bool set(int i, const T& e);
    bool get(int i, T& e) const;
    int length() const;
    void clear();

    //顺序存储线性表的数组访问方式
    //非const对象
    T& operator [] (int i);
    //const对象
    T operator [] (int i) const;
    
  	//顺序存储空间的容量
    //之所以定义为虚函数，是因为空间的分配交给子类来完成
    virtual int capacity() const =0;
};
```

### 3.StaticList和DynamicList

#### StaticList设计要点

类模板设计：

+ 使用原生数组作为顺序存储空间，静态定义存储空间
+ 使用模板参数决定数组大小

```c++
template <typename T, int N>
class StaticList : public SeqList<T>
{
protected:
    T m_space[N]; //顺序存储空间，N为模板参数
public:
    StaticList(); //指定父类成员的具体值，将m_space[N]挂接到Seqlist中的成员变量m_array中
    int capacity( ) const;
};
```

#### DynamicList设计要点

类模板设计：

+ 申请连续堆空间作为顺序存储空间
+ 动态设置顺序存储空间的大小
+ 保证重置顺序存储空间时的异常安全性

函数异常安全的概念

+ 不泄露任何资源
+ 不允许破坏数据

```c++
template <typename T>
class DynamicList : public SeqList<T>
{
protected:
    int m_capacity; //动态存储空间的大小
public:
    DynamicList(int capacity); //申请空间
    int capacity() const ;
    void resize(int capacity); //重新设置顺序存储空间的大小
    ~DynamicList(); //归还空间
};
```



