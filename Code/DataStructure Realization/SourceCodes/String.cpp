//
// Created by 张永斌 on 2021/4/10.
//
#include <cstdlib>
#include <cstring>
# include "../HeadCodes/String/String.h"
#include "../HeadCodes/Exception/Exception.h"

namespace DataStructure {

void String::init(const char *s) {
    //拷贝
    m_str = strdup(s ? s : "");

    if(m_str) {
        m_length = strlen(m_str);
    } else {
        //抛出异常
        THROW_EXCEPTION(NoEnoughMemoryException,"No memory to creat string object..");
    }
}

bool String::equal(const char* l, const char* r, int len) const {
    bool ret = true;
    for (int i = 0; i < len && ret; ++i) {
        ret = ((l[i] == r[i]) && (ret));
    }
    return ret;
};

int* String::make_pmt(const char* p) {
    int len = strlen(p);
    int* ret = new int (len);

    if(ret != nullptr) {
        int ll = 0;
        ret[0] = 0;

        for (int i = 1; i < len; ++i) {
            //非理想情况
            while(ll > 0 && p[ll] != p[i]) {
                ll = ret[ll - 1];
            }
            //推导成立的情况
            if(p[ll] == p[i]) {
                ++ ll;
            }
            ret[i] = ll;
        }
    }
    return ret;
}

int String::KMP(const char* s, const char* p) {
    int ret = -1;
    int sl = strlen(s);
    int pl = strlen(p);
    int* pmt = make_pmt(p);

    if((pmt != nullptr) && (0 < pl) && (pl <= sl)) {
        for (int i = 0, j = 0; i < sl; ++i) {
            //匹配不成功
            while( j > 0 && s[i] != p[j]) {
                j = pmt[j - 1];
            }

            if(s[i] == p[j]) {
                ++j;
            }

            if(j == pl) {
                ret = i + 1 - pl;
                break;
            }
        }
    }
    free(pmt);
    return ret;
}

String::String() {
    init("");
}

String::String(const char *s) {
    init(s ? s : "");
}

String::String(const String &s) {
    init(s.m_str);
}

String::String(char c) {
    char s[] = {c, '\0'};
    init(s);
}

String::~String()
{
    free(m_str);
}

int String::length() const {
    return m_length;
}

const char* String::str() const {
    return m_str;
}

bool String::startWith(const char* s) const {
    bool ret = (s != nullptr);
    if(ret) {
        int len = strlen(s);
        ret = (len < m_length) && equal(m_str, s, len);
    }
    return ret;
}

bool String::startWith(const String& s) const {
    return startWith(s.str());
}

bool String::endOf(const char* s) const {
    bool ret = (s != nullptr);

    if(ret) {
        int len = strlen(s);
        char* str = m_str + (m_length - len);
        ret = (len < m_length) && equal(str, s, len);
    }
    return ret;
}

bool String::endOf(const String& s) const {
    return endOf(s.str());
}

String& String::insert(int i, const char* s) {
    if((i>=0) && (i <= m_length)) {
        if (s != nullptr && s[0] != '\0') {
            int len = strlen(s);
            char* str = reinterpret_cast<char*>(malloc(m_length + len + 1));
            if(str != nullptr) {
                strncpy(str, m_str, i);
                strncpy(str + i, s, len);
                strncpy(str + i + len, m_str + i, m_length - i);

                str[m_length + len] = '\0';

                free(m_str);
                m_str = str;
                m_length = m_length + len;

            } else {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to insert string value..");
            }
        }
    } else {
        THROW_EXCEPTION(IndexOutOfBoundsException,"Parameter i is invalid value ..");
    }
    return *this;
}

String& String::insert(int i, const String& s) {
    return insert(i, s.m_str);
}

String& String::trim() {
    int begin = 0;
    int end = m_length - 1;

    while(m_str[begin] == ' ')
        ++ begin;
    while (m_str[end] == ' ')
        --end;

    if(begin == 0) {
        m_str[end + 1] = '\0';
        m_length = end + 1;
    } else {
        for (int i = 0, j = begin; j <= end; ++i, ++j) {
            m_str[i] = m_str[j];
        }
        m_str[end - begin + 1] = '\0';
        m_length = end - begin + 1;
    }
    return *this;
}

int String::indexOf(const char* s) const {
    return KMP(m_str, s ? s : "");
}

int String::indexOf(const String& s) const {
    return KMP(m_str, s.str());
}

String& String::remove(int i, int len) {
    if((i >= 0) && (i < m_length)) {
        int n = i;
        int m = i + len;
        while((n < m) && (m < m_length)) {
            m_str[n++] = m_str[m++];
        }
        m_str[n] = '\0';
        m_length = n;
    } else {
        THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid value in remove..");
    }
    return *this;
}

String& String::remove(const char* s) {
    return remove(indexOf(s), s ? strlen(s) : 0) ;
}

String& String::remove(const String& s) {
    return remove(indexOf(s), s.m_length);
}

bool String::operator == (const String& s) const {
    return (strcmp(m_str, s.str()) == 0);
}

bool String::operator == (const char* s) const {
    return (strcmp(m_str, s ? s : "") == 0);
}

bool String::operator != (const String& s) const {
    return !(*this == s);
}

bool String::operator != (const char* s) const {
    return !(*this == s);
}

bool String::operator > (const String& s) const {
    return (strcmp(m_str, s.str()) > 0);
}

bool String::operator > (const char* s) const{
    return (strcmp(m_str, s ? s : "") > 0);
}

bool String::operator < (const String& s) const {
    return (strcmp(m_str, s.str()) < 0);
}

bool String::operator < (const char* s) const{
    return (strcmp(m_str, s ? s : "") < 0);
}

bool String::operator >= (const String& s) const {
    return (strcmp(m_str, s.str()) >= 0);
}

bool String::operator >= (const char* s) const{
    return (strcmp(m_str, s ? s : "") >= 0);
}

bool String::operator <= (const String& s) const {
    return (strcmp(m_str, s.str()) <= 0);
}

bool String::operator <= (const char* s) const{
    return (strcmp(m_str, s ? s : "") <= 0);
}

String& String::operator = (const String& s)  {
    return (*this = s.m_str);
}

String& String::operator = (const char* s)  {
    if(m_str != s) {
        char* str = strdup(s ? s : "");
        if(str) {
            free(m_str);

            m_str = str;
            m_length = strlen(m_str);
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to assign new string..");
        }
    }
    return *this;
}

String& String::operator = (char c)  {
    char s[] = {c, '\0'};
    return (*this = s);

}

String String::operator + (const String& s) const {
    return (*this + s.m_str);
}
String String::operator + (const char* s) const {
    String ret;
    int len = m_length + strlen(s ? s : "");
    char* str = reinterpret_cast<char*>(malloc(len + 1));
    if(str) {
        strcpy(str, m_str);
        strcat(str, s ? s : "");

        free(ret.m_str);
        ret.m_str = str;
        ret.m_length = len;
    } else {
        THROW_EXCEPTION(NoEnoughMemoryException,"No memory to add operator..");
    }
    return ret;
}

String& String::operator += (const String& s)  {
    return (*this = *this + s);
}
String& String::operator += (const char* s) {
    return (*this = *this + s);
}

String String::operator - (const String& s) const {
    //构造函数创建临时对象来进行remove操作
    return String(*this).remove(s);
}

String String::operator - (const char* s) const {
    return String(*this).remove(s);
}

String& String::operator -= (const String& s)  {
    return remove(s);
}

String& String::operator -= (const char* s) {
    return remove(s);
}

char& String::operator[] (int i ) {
    if(i >= 0 && i < m_length) {
        return m_str[i];
    } else {
        THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid value ..");
    }
}

char String::operator[](int i) const {

    //代码复用，剔除const属性
    return (const_cast<String&>(*this)[i]);
}

String& String::replace (const char* t, const char* s) {
    int index = indexOf(t);
    if(index >= 0) {
        remove(t);
        insert(index, s);
    }
    return *this;
}

String& String::replace (const String& t, const char* s) {
    return replace(t.m_str, s);
}

String& String::replace (const char* t, const String& s) {
    return replace(t, s.m_str);
}

String& String::replace (const String& t, const String& s) {
    return replace(t.m_str, s.m_str);
}

String String::sub (int i, int len) const {
     String ret;

     if((i >= 0) && (i < m_length)) {
         //归一化
        if(len < 0)
            len = 0;
        if(len + i > m_length)
            len = m_length - i;

        char * str = reinterpret_cast<char*>(malloc(len + 1));
        strncpy(str, m_str + i, len);
        str[len] = '\0';

        ret = str;

     } else {
         THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid value in sub ..");
     }
     return ret;
}
ostream &operator<<(ostream &os, const String &s) {
    return os << s.str();
}


}
