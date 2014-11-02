#include <iostream>
#include<interlockedapi.h>
//using namespace std;
class Singleton{
private:
	Singleton()
	{

	}
	//Singleton(Singleton&s);
	//Singleton & operator =(Singleton&s);
	static  Singleton* Instance;
public:
	static Singleton* GetInstance()
	{
		if (Singleton::Instance == NULL)
		{
			Singleton::Instance = new Singleton();
		}
		return Singleton::Instance;
	}
};
Singleton * Singleton::Instance = NULL;	 //此处必须定义

class Singleton1
{
public:
	static Singleton1* GetInstance()
	{
		if (Instance.get() == 0)
		{
			Instance.reset(new Singleton1);
		}
		return Instance.get();
	}
private:
	Singleton1(){};
	virtual ~Singleton1(){};
	friend class std::auto_ptr<Singleton1>;	 //此处必须声明，auto_ptr将无法访问被保护对象。
	static std::auto_ptr<Singleton1> Instance;
};
std::auto_ptr<Singleton1> Singleton1::Instance;


int main()
{
	Singleton1 *s1 = Singleton1::GetInstance();	
	Singleton1 *s2 = Singleton1::GetInstance();
	return 0;
}