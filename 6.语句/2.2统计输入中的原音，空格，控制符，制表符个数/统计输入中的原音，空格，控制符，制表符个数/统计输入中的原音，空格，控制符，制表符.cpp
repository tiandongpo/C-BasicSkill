#include<iostream>
using namespace std;
int main()
{
	char ch;

	int acnt = 0,ecnt=0,icnt=0,ocnt=0,ucnt=0;
	int spacecnt = 0,tabcnt=0,newlinecnt=0;


	cout<<"enter a series of char(end of ctrl+z)"<<endl;
	while(cin.get(ch))//?
	{
		switch(ch)
		{
		case 'a':
		case 'A':
			++acnt;
			break;
		case 'e':
		case 'E':
			++ecnt;
			break;
		case 'i':
		case 'I':
			++icnt;
			break;
		case 'o':
		case 'O':
			++ocnt;
			break;
		case 'u':
		case 'U':
			++ucnt;
			break;
		case ' ':
			++spacecnt;
			break;
		case'\t':
			++tabcnt;
		case '\n':
			++newlinecnt;
			break;
		}
	}
	cout<<"number of vowel a:\t"<<acnt<<'\n'
		<<"number of vowel e:\t"<<ecnt<<'\n'
		<<"number of wovel i:\t"<<icnt<<'\n'
		<<"number of wovel o:\t"<<ocnt<<'\n'
		<<"number of wovel u:\t"<<ucnt<<'\n'
		<<"number of space character:\t"<<spacecnt<<'\n'
		<<"number of tab character:\t"<<tabcnt<<'\n'
		<<"number of newline character:\t"<<newlinecnt<<endl;
		system("pause");
		return 0;
	}


	 