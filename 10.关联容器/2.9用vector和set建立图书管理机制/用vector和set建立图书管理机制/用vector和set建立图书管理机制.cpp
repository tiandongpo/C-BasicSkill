//����һ��vector�������洢��δ����������Ҫ�Ķ����������
//����һ��set�����ڼ�¼�Ѿ�����������
//������֧�ִ�vector��ѡ��һ��û�ж���������Ҫ�����飬
//���������������¼�Ѷ���Ŀ��set�С�
//������������º�����Ѷ���Ŀ�ͻ�û�ж�����Ŀ

#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	vector<string> books;
	set<string> readedbooks;
	string name;

	//��������δ��������Ҫ�Ķ���������vector����
	cout<<"enter names for books you'd like to read(ctrl+z to end):"<<endl;
	while(cin>>name)
		books.push_back(name);


	cin.clear();//ʹ������������Ч

	bool timeover = false;
	string answer,bookname;

	//�õ�ǰϵͳʱ���������������������
	srand( (unsigned)time( NULL ));

	//ģ����ʱ������Ŷ��ı�����¼
	while(!timeover && !books.empty())//ʱ��δ���������һ�����û�ж���
	{
		cout<<"would you like to read a book?(yes/no)"<<endl;
		cin>>answer;


		if(answer[0]=='y' ||answer[0]=='Y')
		{//��vector�����ѡ��һ����
			int i = rand()%books.size();//����һ��α�����
			bookname = books[i];
			cout<<"you can read this book:"<<bookname<<endl;
			readedbooks.insert(bookname);//����������Ѷ�����
			books.erase(books.begin()+i);//��vector������ɾ������

			cout<<"did you read it?(yes/no)"<<endl;
			cin>>answer;
			if(answer[0] == 'n'||answer[0] == ' N')
			{
				readedbooks.erase(bookname);//���Ѷ�������ɾ������
				books.push_back(bookname);//���������·���vector��
			}
		}
				cout<<"time over?(yes/no)"<<endl;
				cin>>answer;
				if(answer[0]=='y'||answer[0] == 'Y')
				{//����������½�����
					timeover = true;
				}
			}
			if(timeover)//����������½�����

			{   //����Ѷ�����Ŀ
				cout<<"books read:"<<endl;
				for(set<string>::iterator sit = readedbooks.begin();sit!=readedbooks.end();++sit)
					cout<<*sit<<endl;
				cout<<"books no read:"<<endl;
				for(vector<string>::iterator vit = books.begin();vit!=books.end();++vit)
					cout<<*vit<<endl;
			}
			else
				cout<<"congratulation! you have read all these books."<<endl;
			system("pause");
			return 0;
		}

