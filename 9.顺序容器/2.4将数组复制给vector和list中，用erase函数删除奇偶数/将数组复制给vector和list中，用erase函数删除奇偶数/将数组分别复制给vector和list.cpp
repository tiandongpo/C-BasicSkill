#include<iostream>
#include<vector>
#include<list>
using namespace std;


int main()
{
	int ia[]={0,1,1,2,3,5,8,13,21,55,89};
	vector<int> ivec(ia,ia+11);
	list<int> ilst(ia,ia+11);


	//ɾ��list����������ֵԪ��
	for(list<int>::iterator lit=ilst.begin();lit!=ilst.end();++lit)
	{
		if(*lit%2!=0)//��������ָ���Ԫ��Ϊ����
		{
			lit=ilst.erase(lit);/*ɾ��Ԫ��  ��ɾ��Ԫ�غ��������ʧЧ�����һ��Ҫ�Ե��������¸�ֵ�����⣬erase��������һ��������
			                    ָ��ɾ��Ԫ�ص���һ��Ԫ�ء���Ϊ��for���ͷҪ�Ե�������1,������if����н���������1��������©�账��
								��Ԫ��*/
			--lit;//���������ˣ�ָ��ɾ����ǰһԪ��
		}
	}


	//ɾ��vector�����е�ż��ֵԪ��
	
      for(vector<int>::iterator vit=ivec.begin();vit!=ivec.end();++vit)
	  {
		  if(*vit%2==0)//��������ָ���Ԫ��Ϊż��
		  {
		      vit=ivec.erase(vit);//ɾ��Ԫ��

		        --vit;//���������ˣ�ָ��ɾ��Ԫ�ص�ǰһԪ��
		  }
	  }
    system("pause");
    return 0;
}