//ʹ��istream_iteratot����ӱ�׼�������һϵ������
//ʹ��ostream_iterator�������е�����д�뵽һ���ļ���
//����ÿ��д���ֵ�����һ���ո�
//ͬ��ʹ��osream_iteratro����ż��д�뵽�ڶ����ļ���
//ÿ��д���ֵ������ڵ���������
#include<iostream>
#include<fstream>
#include<iterator>
#include<algorithm>
using namespace std;

int main()
{   


	//������ļ�������������Ӧ�ļ�
	ofstream oddFile("oddfile.dat");
	ofstream evenFile("evenfile.dat");

    //���ļ�ʧ��
	if(!oddFile||!evenFile)
	{
		cerr<<"can not open output file!" <<endl;
		return EXIT_FAILURE;
	}


	
	cout<<"enter some integers:(ctrl+z to end)"<<endl;
	istream_iterator<int> inIter(cin),eof;
	ostream_iterator<int> outOddIter(oddFile," ");
	ostream_iterator<int> outEvenIter(evenFile,"\n");

	//��������ֱ������eof�������������д�뵽�ļ�����
	//������Ӧ�ĵ�������1
	while(inIter != eof)
	{
		if(*inIter%2!=0)//�����������
		{
			*outOddIter = *inIter;
			++outOddIter;
		}
		else//�������ż��
		{
			*outEvenIter = *inIter;
			++outEvenIter;
		}

		++inIter;
	}

	//�ر��ļ�
	oddFile.close();
	evenFile.close();


	system("pause");
	return 0;
}