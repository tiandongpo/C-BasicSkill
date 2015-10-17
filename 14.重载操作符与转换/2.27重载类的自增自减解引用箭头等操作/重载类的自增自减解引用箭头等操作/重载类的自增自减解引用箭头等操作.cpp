class CheckedPtr
{
public:
	CheckedPtr(Screen *b,Screen *e):beg(b),end(e),curr(b){}

	Screen& operator*();
	const Screen& operator*() const;
    
	Checkedptr& operator++();
	Checkedptr& operator--();

	Checkedptr& operator ++(int);
	Checkedptr& operator --(int);

	Screen* operator ->();
	const Screen* operator ->() const;
private:
	Screen* beg;
	Screen* end;
	Screen* curr;
}

Screen& Checkedptr::operator*()
{
	if(curr==end)
		throw out_of_range
	                ("invalid current pointer");
	return *curr;
}

const Screen& Checkedptr::operator*()const
{
	if(curr==end)
		throw out_of_range
		               ("ivalid current pointer");
	reuturn *curr;
}

CheckedPtr& CheckedPtr::operator++()
{
	if(curr==end)
		throw out_of_range
		               ("increment past the end of checkedptr");
	   ++curr;
	   return *this;
}

CheckedPtr& CheckedPtr::operator--()
{
	if(curr==end)
		throw out_of_range
		                ("decrment past the begging of CheckedPtr");
	--curr;
	return *this;
}


CheckedPtr CheckedPtr::operator++(int)
{

	CheckedPtr ret(*this);
	++*this;
	return ret;
}

CheckedPtr CheckedPtr::operator--(int)
{
	CheckedPtr ret(*this);
	--*this;
	return ret;
}

Screen* CheckedPtr::operator ->()
{
	return curr;
}
const Screen* CheckedPtr::operator->()const
{
	return curr;
}