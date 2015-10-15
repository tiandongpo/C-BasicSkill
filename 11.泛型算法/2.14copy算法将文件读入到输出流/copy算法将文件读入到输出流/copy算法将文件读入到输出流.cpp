#include<iostream>
#include<cstdlib>
#include<string>
#include<iterator>
#include<algorithm>
using namespace std;

int main()
{
	string fileName;


	cout<<"enter input file name:"<<endl;
	cin>>fileName;

	ifstream inFile(fileName.c_str());
	if(!inFile)
	{

		cout<<"can not open file:" <<fileName<<endl;
		return EXIT_FAILURE;
	}


	ostream_iterator<string>outIter(cout," ");
	istream_iterator<string>iniIter(inFile),eof;
	copy(inIter,eof,outIter);

	inFile.close();

	system("pause");
	return 0;
}