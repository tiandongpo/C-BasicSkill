template<typename T>
bool median(const vector<T>& c,T&)
{  

	//����tempΪc�ĸ���
	vector<T>temp(c);


	//��������а���ż����Ԫ�أ���û���м�ֵ������false
	if(temp.size()%2 == 0)
		return false;


	//��Ԫ������
	sort(temp.begin(),temp.end());


	//�ж��м��Ԫ���Ƿ�Ϊ�м�ֵ�����򷵻�true,����m��¼�м�ֵ
	//���򷵻��м�ֵ
	vector<T>::size_type index = temp.size()/2;
	if(temp[index] > temp[index-1]&&temp[index]<temp[index+1]
	{
		m = temp[index];
		return true;
	}
	else
		return false;
}