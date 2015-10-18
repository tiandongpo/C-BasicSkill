//定义median函数模版的头文件
//median函数模版在保存位置类型对象的vector中查找中间值
#ifndef MEDIA_H
#define MEDIA_H
#include<vector>
#include<algorithm>
using std::vector;

//如果vector中有中间值，则返回true,并将中间值记录在第二个参数中
//否则，返回false
template<typename T>
bool median(const vector<T>&,T&);

#include "media.h"//引入函数模版的实现文件
#endif