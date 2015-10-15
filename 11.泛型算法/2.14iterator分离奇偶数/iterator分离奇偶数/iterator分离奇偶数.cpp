//使用istream_iteratot对象从标准输入读入一系列整数
//使用ostream_iterator对象将其中的奇数写入到一个文件中
//并在每个写入的值后面加一个空格
//同样使用osream_iteratro对象将偶数写入到第二个文件中
//每个写入的值都存放在单独的行中
#include<iostream>
#include<fstream>
#include<iterator>
#include<algorithm>
using namespace std;

int main()
{   


	//打开输出文件流并关联到相应文件
	ofstream oddFile("oddfile.dat");
	ofstream evenFile("evenfile.dat");

    //打开文件失败
	if(!oddFile||!evenFile)
	{
		cerr<<"can not open output file!" <<endl;
		return EXIT_FAILURE;
	}


	
	cout<<"enter some integers:(ctrl+z to end)"<<endl;
	istream_iterator<int> inIter(cin),eof;
	ostream_iterator<int> outOddIter(oddFile," ");
	ostream_iterator<int> outEvenIter(evenFile,"\n");

	//读入整数直至遇到eof，将读入的数据写入到文件流中
	//并将相应的迭代器加1
	while(inIter != eof)
	{
		if(*inIter%2!=0)//读入的是奇数
		{
			*outOddIter = *inIter;
			++outOddIter;
		}
		else//读入的是偶数
		{
			*outEvenIter = *inIter;
			++outEvenIter;
		}

		++inIter;
	}

	//关闭文件
	oddFile.close();
	evenFile.close();


	system("pause");
	return 0;
}