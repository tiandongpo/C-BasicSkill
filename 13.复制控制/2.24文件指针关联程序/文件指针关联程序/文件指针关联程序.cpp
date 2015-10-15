#include<set>
#include<string>
using namespace std;

class Message;
class Folder
{
public:
	Folder(){}
	//���ƿ��Ƴ�Ա
	Folder(const Folder&);
	Folder& operator = (const Folder&);
	~Folder();

	//��ָ����Message��Ŀ¼��������/ɾ����Ŀ¼
	void save(Message&);
	void remove(Message&);

	//�ڸ�Ŀ¼����Ϣ��������/ɾ��ָ��Message
	void addMsg(Message*);
	void remMsg(Message*);
private:
	set<Message*>messages;//��Ŀ¼�е���Ϣ��

	//���ƿ��Ƴ�Ա��ʹ�õ�ʵ�ú���
	//��Ŀ¼�ӵ��β���ָ����Ϣ����
	void put_Fldr_in_Messages(const set<Message*>&);

	//��Ŀ¼��ָ��������Ϣ��ɾ����Ŀ¼
	void remove_Fldr_from_Messages();
};



class Message
{
public:

	//folder�Զ���ʼ��Ϊ�ռ�
	Message(const string &str = " "):contents (str){};

	//���ƿ��Ƴ�Ա
	Message(const Message&);
	Message& operator = (const Message&);
	~Message();

	//���ƶ�folder����Ϣ��������/ɾ������Ϣ
	void save(Folder&);
	void remove(Folder&);

	//�ڰ�������Ϣ��Ŀ¼��������/ɾ��ָ��Folder
	void addFldr(Folder*);
	void remFldr(Folder*);
private:
	string contents;       //ʵ����Ϣ�ı�
	set<Folder*> folders;    //��������Ϣ��Ŀ¼


	//���ƹ��캯������ֵ������������ʹ�õ�ʵ�ú���
	//����Ϣ�ӵ��β���ָ��Ŀ¼����
	void put_Msg_in_Folders(const set<Folder*>&);

	//����Ϣ���ڵ�����Ŀ¼��ɾ������Ϣ
	void remove_Msg_from_Folders();
};




Folder::Folder(const Folder &f):messages(f.messages)
{

	//����Ŀ¼�ӵ�f��ָ���ÿ����Ϣ��
	put_Fldr_in_Messages(messages);
}

//����Ŀ¼�ӵ�rhs��ָ����Ϣ����
void Folder::put_Fldr_in_Messages(const set<Message*> &rhs) 
	
{
	for(set< Message* >::const_iterator beg=rhs.begin();beg!=rhs.end();++beg)
		(*beg)->addFldr(this);//*begָ��һ����Ϣ
}


Folder& Folder::operator = (const Folder &rhs)
{
	if(&rhs != this)
	{
		remove_Fldr_from_Messages();//����������Ϣ
		messages = rhs.messages;//��rhs������Ϣָ�뼯
		//����Ŀ¼�ӵ�rhs�е�ÿ����Ϣ��
	    put_Fldr_in_Messages(rhs.messages);
	}
	return *this;
}


//�Ӷ�Ӧ��Ϣ��ɾ����Ŀ¼
void Folder::remove_Fldr_from_Messages()
{   

	//�Ӷ�Ӧ��Ϣ��ɾ����Ŀ¼
	for(set<Message*>::const_iterator beg = messages.begin();beg!=messages.end();++beg)
		(*beg)->remFldr(this);//*begֻ��һ����Ϣ
}
Folder::~Folder()
{
	remove_Fldr_from_Messages();
}
void Folder::save(Message& msg)
{
	addMsg(&msg);
	msg.addFldr(this);//������Ӧ��Ϣ
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

	//������Ϣ�ӵ�ָ��m��ÿ��Ŀ¼��
	put_Msg_in_Folders(folders);
}

//������Ϣ�ӵ�rhs��ָ��Ŀ¼��
void Message::put_Msg_in_Folders(const set<Folder*> &rhs)
{
	for(set<Folder*>::const_iterator beg = rhs.begin();beg!=rhs.end();++beg)
		(*beg)->addMsg(this);//*begָ��һ��Ŀ¼
}
Message& Message::operator = (const Message &rhs)
{
	if(&rhs != this)
	{
		remove_Msg_from_Folders();//��������Ŀ¼
		contents = rhs.contents;//��rhs������Ϣ����
		folders = rhs.folders;//��rhs����Ŀ¼ָ����
		//������Ϣ�ӵ�ÿ��Ŀ¼��

		put_Msg_in_Folders(rhs.folders);
	}
	return *this;
}


//�Ӷ�ӦĿ¼��ɾ������Ϣ
void Message::remove_Msg_from_Folders ()
{   
	//�Ӷ�ӦĿ¼��ɾ������Ϣ
	for(set<Folder *>::const_iterator beg = folders.begin();beg != folders.end();++beg)
		(*beg)->remMsg(this);//*begָ��һ��Ŀ¼
}

Message::~Message()
{
	remove_Msg_from_Folders();
}

void Message::save(Folder& fldr)
{
	addFldr(&fldr);
	fldr.addMsg(this);//������ӦĿ¼
}
void Message::remove(Folder& fldr)
{
	remFldr(&fldr);
	fldr.remMsg(this);//������ӦĿ¼
}

void Message::addFldr(Folder* fldr)
{
	folders.insert(fldr);
}

void Message::remFldr(Folder* fldr)
{
	folders.erase(fldr);
}