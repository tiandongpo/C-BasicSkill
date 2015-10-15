//定义一个vector容器，存储在未来六个月里要阅读的书的名字
//定义一个set，用于记录已经看过的书名
//本程序支持从vector中选择一本没有读过而现在要读的书，
//并将该书名放入记录已读数目的set中。
//在虚拟的六个月后，输出已读数目和还没有读的数目

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

	//建立保存未来六个月要阅读的书名的vector对象
	cout<<"enter names for books you'd like to read(ctrl+z to end):"<<endl;
	while(cin>>name)
		books.push_back(name);


	cin.clear();//使流对象重新有效

	bool timeover = false;
	string answer,bookname;

	//用当前系统时间设置随机数发生器种子
	srand( (unsigned)time( NULL ));

	//模拟随时间的流逝而改变读书记录
	while(!timeover && !books.empty())//时间未到六个月且还有书没有读过
	{
		cout<<"would you like to read a book?(yes/no)"<<endl;
		cin>>answer;


		if(answer[0]=='y' ||answer[0]=='Y')
		{//在vector中随机选择一本书
			int i = rand()%books.size();//产生一个伪随机数
			bookname = books[i];
			cout<<"you can read this book:"<<bookname<<endl;
			readedbooks.insert(bookname);//将该书放入已读集合
			books.erase(books.begin()+i);//从vector对象中删除该书

			cout<<"did you read it?(yes/no)"<<endl;
			cin>>answer;
			if(answer[0] == 'n'||answer[0] == ' N')
			{
				readedbooks.erase(bookname);//从已读集合中删除该书
				books.push_back(bookname);//将该书重新放入vector中
			}
		}
				cout<<"time over?(yes/no)"<<endl;
				cin>>answer;
				if(answer[0]=='y'||answer[0] == 'Y')
				{//虚拟的六个月结束了
					timeover = true;
				}
			}
			if(timeover)//虚拟的六个月结束了

			{   //输出已读的数目
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

