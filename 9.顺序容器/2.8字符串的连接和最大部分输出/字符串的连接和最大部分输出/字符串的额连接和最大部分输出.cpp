//string line1 = "we were pride of 10 she named us:"  string line2="benjamin,phoenix,the prodigal";string line3= "and perspocacious pacific suzanne";
//string sentence=line1+' '+line2+' '+line3  ����sentence�еĵ�������������̵���
//�������ָ������ϵ�string����separators,ʹ��find_first_of��find_first_not_of��������ȡ���ʵĳ�ʼλ�úͽ���λ�ã�
//ʹ������vector�����������̵���
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string line1 = "we were her pride of 10 she named us:";
	string line2= "benjamin��phoneix,the prodigal";
	string line3= "and perspicacious pacific suzuanne";
	string sentence = line1+' '+line2+' '+line3;
    string separators("\t:,\v\r\n\f");//�����ָ������ַ�
	string word;


	//string�������̵����Լ���һ���ʵĳ��ȣ����ʵ���Ŀ
	string::size_type maxlen,minlen,wordlen,count=0;
	//��������̵��ʵ�����
	vector<string>longestwords,shortestwords;
    //���ʵ���ʼλ�úͽ���λ��
	string::size_type startpos = 0,endpos= 0;
	//ÿ��ѭ������sentence�е�һ������
	while((startpos = sentence.find_first_not_of(separators,endpos))!=string::npos)
{  //�ҵ���һ�����ʵ���ʼλ��
		++count;
		//�ҵ�һ�����ʵĽ���λ��
		endpos = sentence.find_first_of(separators,endpos);
		if(endpos==string::npos)
		{
     //�Ҳ�����һ�����ַָ�����λ�ã����õ��������һ������  
	  		wordlen=sentence.size()-startpos;
		}
		else
		{//�ҵ�����һ�����ַָ�����λ��
			wordlen = endpos - startpos;
		}

	
	     word.assign(sentence.begin()+startpos,sentence.begin()+startpos+wordlen);//��ȡ����
	     //�����´β��ҵ���ʼλ��
	     startpos = sentence.find_first_not_of(separators,endpos);

 
    	if(count==1)
	{//�ҵ����ǵ�һ������
		maxlen=minlen=wordlen;
		longestwords.push_back(word);
		shortestwords.push_back(word);
	}
	else
	{
		if(wordlen>maxlen)
		{//��ǰ���ʱ�Ŀǰ������ʸ���
			maxlen=wordlen;
			longestwords.clear();//��մ洢����ʵ�����
			longestwords.push_back(word);
		}
		else if(wordlen==maxlen)//��ǰ���ʱ�Ŀǰ������ʵȳ�
			longestwords.push_back(word);
		if(wordlen<minlen)//��ǰ���ʱ�Ŀǰ����̵��ʸ���
		{
			minlen=wordlen;
			shortestwords.clear();//��մ����̵��ʵ�����
			shortestwords.push_back(word);
		}
		else if(wordlen==minlen)//��ǰ������Ŀǰ����̵��ʵȳ�
			shortestwords.push_back(word);
	}
}

	//���������Ŀ
	cout<<"word amount:"<<count<<endl;
	vector<string>::iterator iter;
	//��������
	cout<<"longest word(s):"<<endl;
	iter = longestwords.begin();
	while(iter!=longestwords.end())
		cout<<*iter++<<endl;
	//�����̵���
	cout<<"shortest word(s):"<<endl;
	iter = shortestwords.begin();
	while(iter!=shortestwords.end())
		cout<<*iter++<<endl;
	system("pause");
	return 0;
}