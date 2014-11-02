#include <iostream>
//using namespace std;
class Singleton{
private:
	Singleton(){}
	//Singleton(Singleton&s);
	//Singleton & operator =(Singleton&s);
	static Singleton *Instance;
public:
	static Singleton* GetInstance()
	{
		if (Instance == NULL)
		{
			Instance = new Singleton();
		}
		return Instance;
	}
};
int main()
{
	Singleton *s1 = Singleton::GetInstance();
	Singleton *s2 = Singleton::GetInstance();
	return 0;
}