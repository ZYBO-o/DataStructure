//
// Created by 张永斌 on 2021/4/10.
//

#ifndef DATASTRUCTURE_REALIZATION_STRING_H
#define DATASTRUCTURE_REALIZATION_STRING_H

#include <iostream>
#include "../Object/Object.h"
using namespace std;

namespace DataStructure {
class String : public Object
{
//成员变量
protected:
    char* m_str;
    int m_length;

    void init(const char* s);
    //比对函数
    bool equal(const char* l, const char* r, int len) const;
    //KMP查找
    static int* make_pmt(const char* p);
    static int KMP(const char* s, const char* p);
//构造与析构函数
public:
    String();
    String(char c);
    String(const char* s);
    String(const String& s);

    ~String();

//成员函数
public:
    int length() const;
    const char* str() const;
    bool startWith(const char* s) const;
    bool startWith(const String& s) const;
    bool endOf(const char* s) const;
    bool endOf(const String& s) const;
    String& insert(int i, const char* s);
    String& insert(int i, const String& s);
    String& trim();
    int indexOf(const char* s) const;
    int indexOf(const String& s) const;
    String& remove(int i, int len);
    String& remove(const char* s);
    String& remove(const String& s);

    //关系重载操作符
    bool operator == (const String& s) const;
    bool operator == (const char* s) const;
    bool operator != (const String& s) const;
    bool operator != (const char* s) const;
    bool operator > (const String& s) const;
    bool operator > (const char* s) const;
    bool operator < (const String& s) const;
    bool operator < (const char* s) const;
    bool operator >= (const String& s) const;
    bool operator >= (const char* s) const;
    bool operator <= (const String& s) const;
    bool operator <= (const char* s) const;

    String& operator = (const String& s) ;
    String& operator = (const char* s) ;
    String& operator = (char c) ;

    String operator + (const String& s) const;
    String operator + (const char* s) const;
    String& operator += (const String& s) ;
    String& operator += (const char* s) ;

    String operator - (const String& s) const;
    String operator - (const char* s) const;
    String& operator -= (const String& s) ;
    String& operator -= (const char* s) ;

    char& operator[] (int i );
    char operator[](int i) const;

    String& replace (const char* t, const char* s);
    String& replace (const String& t, const char* s);
    String& replace (const char* t, const String& s);
    String& replace (const String& t, const String& s);

    String sub(int i, int len) const;

};
    //输出重载
    ostream& operator << (ostream& os, const String& s);
}


#endif //DATASTRUCTURE_REALIZATION_STRING_H
