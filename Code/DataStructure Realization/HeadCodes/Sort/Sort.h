//
// Created by 张永斌 on 2021/3/23.
//

#ifndef DATASTRUCTURE_REALIZATION_SORT_H
#define DATASTRUCTURE_REALIZATION_SORT_H

#include "../Object/Object.h"

#define  Min  true
#define Max  false

namespace DataStructure {

    class Sort : public Object {

    //只有private，不需要定义对象
    //定义静态成员函数，直接使用
    private:
        Sort();
        Sort(const Sort&);
        Sort& operator = (const Sort&);

        template<typename T>
        static void Swap(T& a, T& b){
            T c(a);
            a = b;
            b = c;
        }

        //归并
        template<typename T>
        static void Merge(T array[], T helper[], int begin, int middle, int end, bool MinOrMax) {
            int i = begin;
            int j = middle + 1;
            int k = begin;
            while (i <= middle && j <= end) {
                if(array[i] < array[j]) {
                    helper[k++] = array[i++];
                } else {
                    helper[k++] = array[j++];
                }
            }

            while(i <= middle) {
                helper[k++] = array[i++];
            }
            while(j <= end) {
                helper[k++] = array[j++];
            }

            for (int l = 0; l <= end; ++l) {
                array[l] = helper[l];
            }

        }

        //重载归并排序
        template<typename T>
        static void Merge(T array[], T helper[], int begin, int end, bool MinOrMax) {
            if(begin == end) {
                return ;
            } else {
                int middle = (begin + end) / 2;

                Merge(array, helper, begin, middle, MinOrMax);
                Merge(array, helper, middle + 1, end, MinOrMax);
                //归并
                Merge(array, helper, begin, middle, end, MinOrMax);
            }
        }

        //返回快速排序的基准
        template<typename T>
        static int Partition(T array[], int begin, int end, bool MinOrMax) {
            T pv = array[begin];
            while (begin < end) {
                while ((begin < end) && (MinOrMax ? (pv < array[end]) : (pv > array[end]))) {
                    --end;
                }
                Swap(array[begin], array[end]);

                while ((begin < end) && (MinOrMax ? (pv > array[begin]) : (pv < array[begin]))) {
                    ++ begin;
                }
                Swap(array[begin], array[end]);
            }
            array[begin] = pv;
            return begin;
        }

        //快速排序实现
        template<typename  T>
        static void Quick(T array[], int begin, int end, bool MinOrMax) {
            if(begin < end) {
                int pivot = Partition(array, begin, end, MinOrMax);
                Quick(array, begin, pivot-1, MinOrMax);
                Quick(array, pivot+1, end, MinOrMax);
            }
        }
    public:
        //选择排序
        template<typename T>
        static void Select(T array[], int len, bool MinOrMax) {
            for (int i = 0; i < len; ++i) {
                int min_or_max = i;
                for (int j = i + 1; j < len; ++j) {
                        if(MinOrMax ? (array[min_or_max] > array[j]) :  (array[min_or_max] < array[j]))
                            min_or_max = j;
                    }
                if(array[min_or_max] != array[i])
                    Swap(array[min_or_max],array[i]);
            }
        }

        //冒泡排序
        template<typename T>
        static void Bubble(T array[], int len, bool MinOrMax) {
            bool Exchanged = true;
            for (int i = 0; i < len && Exchanged; ++i) {
                Exchanged = false;
                for (int j = i; j < len; ++j) {
                    if(MinOrMax ? (array[i] < array[j]) : (array[i] > array[j])) {
                        Swap(array[i], array[j]);
                        Exchanged = true;
                    }
                }
            }
        }

        //插入排序
        template<typename T>
        static void Insert(T array[], int len, bool MinOrMax) {
            for (int i = 1; i < len; ++i) {
                int index = i;
                T temp = array[i];
                for (int j = i-1; (j >= 0) && (MinOrMax ? array[j] > temp : array[j] < temp); --j) {
                    array[j + 1] = array[j];
                    index = j;
                }
                if(index != i) {
                    array[index] = temp;
                }
            }
        }

        //希尔排序
        template<typename  T>
        static void Shell(T array[], int len, bool MinOrMax) {
            int d = len;
            do {
                d = d / 3 + 1;

                for (int i = d; i < len; i += d) {
                    int index = i;
                    T temp = array[i];
                    for (int j = i - d; j >= 0; j -= d) {
                        if(temp < array[j]) {
                            array[j + d] = array[j];
                            index = j;
                        }
                    }
                    if(index != i) {
                        array[index] = temp;
                    }
                }
            }while(d > 1);
        }

        //归并排序
        template<typename  T>
        static void Merge(T array[], int len, bool MinOrMax) {
            T* helper = new T[len];
            if(helper != nullptr) {
                Merge(array,helper,0,len-1,MinOrMax);
            }
            delete [] helper;
        }

        //快速排序
        template<typename  T>
        static void Quick(T array[], int len, bool MinOrMax) {
            Quick(array, 0, len-1, MinOrMax);
        }
    };
}


#endif //DATASTRUCTURE_REALIZATION_SORT_H