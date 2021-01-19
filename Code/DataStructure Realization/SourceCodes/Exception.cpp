//
// Created by 张永斌 on 2021/1/14.
//

#include "../HeadCodes/Exception.h"
#include <cstdlib>
#include <string>

using namespace std;

namespace DataStructure
{
    void Exception::init(const char *message, const char *file, int line)
    {
        // 因为不知道message具体的内存地址在何处，直接指向会有危险性
        // 将字符串内容复制到堆空间中，然后m_message指向堆空间
        m_message = (message ? strdup(message) : nullptr);

        if (file != nullptr) {
            //行号转换为字符串
            string s_line = to_string(line);
            const char *sl = s_line.c_str();
            //从堆空间申请内存
            //进行强制转换
            m_location = static_cast<char *>(malloc(strlen(file) + strlen(sl) + 2));

            if (m_location != nullptr){
                //拷贝
                m_location = strcpy(m_location, file);
                //拼接
                m_location = strcat(m_location, ":");
                m_location = strcat(m_location, sl);
            }
        } else {
            m_location = nullptr;
        }
    }

    Exception::Exception(const char *message)
    {
        init(message, nullptr, 0);
    }

    Exception::Exception(const char *file, int line)
    {
        init(nullptr, file, line);
    }

    Exception::Exception(const char *message, const char *file, int line)
    {
        init(message, file, line);
    }

    //深拷贝
    Exception::Exception(const Exception &e)
    {
        m_message = strdup(e.m_message);
        m_location = strdup(e.m_location);
    }

    //赋值操作符重载
    Exception& Exception::operator = (const Exception & e)
    {
        //确保不是自赋值
        if (this != &e)
        {
            //先进行释放原来指针指向的堆空间
            free(m_message);
            free(m_location);
            //重新赋值
            m_message = strdup(e.m_message);
            m_location = strdup(e.m_location);
        }
        return *this;
    }

    const char* Exception::message() const
    {
        return m_message;
    }

    const char* Exception::location() const
    {
        return m_location;
    }

    //理论上纯虚函数不用进行实现，让子类完成实现
    //但是C++规定，但凡定义了析构函数，无论析构函数是不是纯虚函数，都需要提供实现
    //因为在析构子类对象的时候，最后都需要调用父类的析构函数，所以父类的析构函数也需要实现
    Exception::~Exception()
    {
        free(m_message);
        free(m_location);
    }

}
