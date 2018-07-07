private public protected...
부모 클래스를 가지고 올 때 privat은ㅇㅏㄴ돼무ㅜ

class base
{
private :
	int num1;
protected:
	int num2;
public:
	int num3;
};

class derived : private base
{
	//num 1은 못씀..접근 불가...
private :
	int num2;
private:
	int num3;
};

class derived : protected base
{
	//num 1은 못씀..접근 불가..
protected:
	int num2;
protected:
	int num3;
};

class derived : public base
{
	//num 1은 못씀..접근 불가..
protected :
	int num2;
public : 
	int num3;
}