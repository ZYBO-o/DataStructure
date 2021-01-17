//
// Created by 张永斌 on 2021/1/14.
//

#ifndef DATASTRUCTURE_REALIZATION_EXCEPTION_H
#define DATASTRUCTURE_REALIZATION_EXCEPTION_H

#include "Object.h"

namespace DataStructure
{
    //定义宏,这样引用异常更方便
#define THROW_EXCEPTION(e,m) (throw e(m, __FILE_NAME__, __LINE__))

    class Exception  : public Object
{

    protected:
        //变量m_message表示异常的具体信息
        char* m_message;
        //变量m_location表示异常的定位
        char* m_location;

        //定义辅助函数进行初始化，
        //因为下面三个构造函数的内部逻辑是相似的，所以可以借用辅助函数来进行初始化的操作
        void init(const char *message, const char *file, int line);

    public:

        Exception(const char *message);
        Exception(const char *file, int line);
        Exception(const char *message, const char *file, int line);

        Exception(const Exception &e);

        Exception &operator=(const Exception &e);

        //message函数得到异常的信息
        virtual const char* message() const;
        //location函数得到异常的定位
        virtual const char* location() const;

        //纯虚析构函数——抽象类
        virtual ~Exception() = 0;

    };

    class ArithmeticException : public Exception
    {
    public:
        //构造函数直接调用父类的构造函数
        ArithmeticException() : Exception(nullptr, nullptr,0) {}
        ArithmeticException(const char* message) : Exception(message, nullptr, 0) {}
        ArithmeticException(const char* file, int line) : Exception(nullptr, file, line) {}
        ArithmeticException(const char* message, const char* file, int line) : Exception(message, file, line) {}

        ArithmeticException(const ArithmeticException& e) : Exception(e) {}

        ArithmeticException& operator = (const ArithmeticException e)
        {
            Exception::operator = (e);
            return *this;
        }
    };

    class NullPointerException : public Exception
    {
    public:
        //构造函数直接调用父类的构造函数
        NullPointerException() : Exception(nullptr, nullptr,0) {}
        NullPointerException(const char* message) : Exception(message, nullptr, 0) {}
        NullPointerException(const char* file, int line) : Exception(nullptr, file, line) {}
        NullPointerException(const char* message, const char* file, int line) : Exception(message, file, line) {}

        NullPointerException(const NullPointerException& e) : Exception(e) {}

        NullPointerException& operator = (const NullPointerException e)
        {
            Exception::operator = (e);
            return *this;
        }
    };

    class IndexOutOfBoundsException : public Exception
    {
    public:
        //构造函数直接调用父类的构造函数
        IndexOutOfBoundsException() : Exception(nullptr, nullptr,0) {}
        IndexOutOfBoundsException(const char* message) : Exception(message, nullptr, 0) {}
        IndexOutOfBoundsException(const char* file, int line) : Exception(nullptr, file, line) {}
        IndexOutOfBoundsException(const char* message, const char* file, int line) : Exception(message, file, line) {}

        IndexOutOfBoundsException(const IndexOutOfBoundsException& e) : Exception(e) {}

        IndexOutOfBoundsException& operator = (const IndexOutOfBoundsException e)
        {
            Exception::operator = (e);
            return *this;
        }
    };

    class NoEnoughMemoryException : public Exception
    {
    public:
        //构造函数直接调用父类的构造函数
        NoEnoughMemoryException() : Exception(nullptr, nullptr,0) {}
        NoEnoughMemoryException(const char* message) : Exception(message, nullptr, 0) {}
        NoEnoughMemoryException(const char* file, int line) : Exception(nullptr, file, line) {}
        NoEnoughMemoryException(const char* message, const char* file, int line) : Exception(message, file, line) {}

        NoEnoughMemoryException(const NoEnoughMemoryException& e) : Exception(e) {}

        NoEnoughMemoryException& operator = (const NoEnoughMemoryException e)
        {
            Exception::operator = (e);
            return *this;
        }
    };

    class InvalidParameterException : public Exception
    {
    public:
        //构造函数直接调用父类的构造函数
        InvalidParameterException() : Exception(nullptr, nullptr,0) {}
        InvalidParameterException(const char* message) : Exception(message, nullptr, 0) {}
        InvalidParameterException(const char* file, int line) : Exception(nullptr, file, line) {}
        InvalidParameterException(const char* message, const char* file, int line) : Exception(message, file, line) {}

        InvalidParameterException(const InvalidParameterException& e) : Exception(e) {}

        InvalidParameterException& operator = (const InvalidParameterException e)
        {
            Exception::operator = (e);
            return *this;
        }
    };

    class InvalidOperationException : public Exception
    {
    public:
        //构造函数直接调用父类的构造函数
        InvalidOperationException() : Exception(nullptr, nullptr,0) {}
        InvalidOperationException(const char* message) : Exception(message, nullptr, 0) {}
        InvalidOperationException(const char* file, int line) : Exception(nullptr, file, line) {}
        InvalidOperationException(const char* message, const char* file, int line) : Exception(message, file, line) {}

        InvalidOperationException(const InvalidOperationException& e) : Exception(e) {}

        InvalidOperationException& operator = (const InvalidOperationException e)
        {
            Exception::operator = (e);
            return *this;
        }
    };
}


#endif //DATASTRUCTURE_REALIZATION_EXCEPTION_H
