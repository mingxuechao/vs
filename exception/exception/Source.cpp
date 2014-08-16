/*try{
	program-statements
}catch(exception-specofoer){
handler-statements
}catch(exception-specofoer){
handler-statements
}*/
#include <iostream>
#include <string>
using namespace std;
class myerr
{
public:
private:
};
class myerr1 :public exception
{
public:
	myerr1(string str="the error 1 of ourselves"){errcode =str;};
	myerr1(myerr1 &my){errcode =my.errcode;cout<<"copy code!"<<endl;};
	void display(){cout<< errcode<<endl;};
private:
	string errcode;
};
class myerr2
{
public:
	myerr2(string str="the error 1 of ourselves"){errcode =str;};
	myerr2(myerr2 &my){errcode = my.errcode;cout<<"copy code of myerr2"<<endl;};
	void display(){cout<< errcode<<endl;};
private:
	string errcode;
};
int mmax(int x,int y) throw(myerr1);
int mmax(int x,int y) throw(myerr1)
{
	return x>y?x:y;
};
int main()
{
	int a =8;
	int b=0;
	int x =7;
	int y =8;
	double z= 10.0;
	try
	{
		if (b ==0)
		{
			throw exception();
		}
		cout<<"the normal!"<<endl;
	}
	
	catch(myerr2 ex)
	{
		cout<<"ex.display()"<<endl;
		//cout<<ex.what()<<endl;
		//ex.display();
	}
	catch(myerr1 &ex)
	{
		cout<<"ex.display()"<<endl;
		cout<<"hello wprld!"<<endl;
		cout<<ex.what()<<endl;
	}
	try{
		cout<<mmax(x,y)<<endl;
	}catch(exception ex){
		cout<<ex.what()<<endl;
		cout<<"the new exception!"<<endl;
	}


	return 0;
}