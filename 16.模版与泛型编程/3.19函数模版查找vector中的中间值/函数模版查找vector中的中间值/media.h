//����median����ģ���ͷ�ļ�
//median����ģ���ڱ���λ�����Ͷ����vector�в����м�ֵ
#ifndef MEDIA_H
#define MEDIA_H
#include<vector>
#include<algorithm>
using std::vector;

//���vector�����м�ֵ���򷵻�true,�����м�ֵ��¼�ڵڶ���������
//���򣬷���false
template<typename T>
bool median(const vector<T>&,T&);

#include "media.h"//���뺯��ģ���ʵ���ļ�
#endif