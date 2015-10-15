#include<set>
#include<string>
using namespace std;

class Message;
class Folder
{
public:
	Folder(){}
	//复制控制成员
	Folder(const Folder&);
	Folder& operator = (const Folder&);
	~Folder();

	//在指定的Message的目录集中增加/删除该目录
	void save(Message&);
	void remove(Message&);

	//在该目录的消息集中增加/删除指定Message
	void addMsg(Message*);
	void remMsg(Message*);
private:
	set<Message*>messages;//该目录中的消息集

	//复制控制成员所使用的实用函数
	//将目录加到形参所指的消息集中
	void put_Fldr_in_Messages(const set<Message*>&);

	//从目录所指的所有消息中删除该目录
	void remove_Fldr_from_Messages();
};



class Message
{
public:

	//folder自动初始化为空集
	Message(const string &str = " "):contents (str){};

	//复制控制成员
	Message(const Message&);
	Message& operator = (const Message&);
	~Message();

	//在制定folder的消息集中增加/删除该消息
	void save(Folder&);
	void remove(Folder&);

	//在包含该消息的目录集中增加/删除指定Folder
	void addFldr(Folder*);
	void remFldr(Folder*);
private:
	string contents;       //实际消息文本
	set<Folder*> folders;    //包含该消息的目录


	//复制构造函数，赋值、析构函数所使用的实用函数
	//将消息加到形参所指的目录集中
	void put_Msg_in_Folders(const set<Folder*>&);

	//从消息所在的所有目录中删除该消息
	void remove_Msg_from_Folders();
};




Folder::Folder(const Folder &f):messages(f.messages)
{

	//将该目录加到f所指向的每个消息中
	put_Fldr_in_Messages(messages);
}

//将该目录加到rhs所指的消息集中
void Folder::put_Fldr_in_Messages(const set<Message*> &rhs) 
	
{
	for(set< Message* >::const_iterator beg=rhs.begin();beg!=rhs.end();++beg)
		(*beg)->addFldr(this);//*beg指向一个消息
}


Folder& Folder::operator = (const Folder &rhs)
{
	if(&rhs != this)
	{
		remove_Fldr_from_Messages();//更新现有消息
		messages = rhs.messages;//从rhs复制消息指针集
		//将该目录加到rhs中的每个消息中
	    put_Fldr_in_Messages(rhs.messages);
	}
	return *this;
}


//从对应消息中删除该目录
void Folder::remove_Fldr_from_Messages()
{   

	//从对应消息中删除该目录
	for(set<Message*>::const_iterator beg = messages.begin();beg!=messages.end();++beg)
		(*beg)->remFldr(this);//*beg只想一个消息
}
Folder::~Folder()
{
	remove_Fldr_from_Messages();
}
void Folder::save(Message& msg)
{
	addMsg(&msg);
	msg.addFldr(this);//更新相应消息
}

void Folder::remove(Message& msg)
{
	remMsg(&msg);
	msg.remFldr(this);
}
void Folder::addMsg(Message* msg)
{
	messages.insert(msg);
}

void Folder::remMsg(Message* msg)
{
	messages.erase(msg);
}
Message::Message(const Message &m):contents(m.contents),folders(m.folders)
{   

	//将该消息加到指向m的每个目录中
	put_Msg_in_Folders(folders);
}

//将该消息加到rhs所指的目录中
void Message::put_Msg_in_Folders(const set<Folder*> &rhs)
{
	for(set<Folder*>::const_iterator beg = rhs.begin();beg!=rhs.end();++beg)
		(*beg)->addMsg(this);//*beg指向一个目录
}
Message& Message::operator = (const Message &rhs)
{
	if(&rhs != this)
	{
		remove_Msg_from_Folders();//更新现有目录
		contents = rhs.contents;//从rhs复制消息内容
		folders = rhs.folders;//从rhs复制目录指针类
		//将该消息加到每个目录中

		put_Msg_in_Folders(rhs.folders);
	}
	return *this;
}


//从对应目录中删除该消息
void Message::remove_Msg_from_Folders ()
{   
	//从对应目录中删除该消息
	for(set<Folder *>::const_iterator beg = folders.begin();beg != folders.end();++beg)
		(*beg)->remMsg(this);//*beg指向一个目录
}

Message::~Message()
{
	remove_Msg_from_Folders();
}

void Message::save(Folder& fldr)
{
	addFldr(&fldr);
	fldr.addMsg(this);//更新相应目录
}
void Message::remove(Folder& fldr)
{
	remFldr(&fldr);
	fldr.remMsg(this);//更新相应目录
}

void Message::addFldr(Folder* fldr)
{
	folders.insert(fldr);
}

void Message::remFldr(Folder* fldr)
{
	folders.erase(fldr);
}