private public protected...
�θ� Ŭ������ ������ �� �� privat���������Ź���

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
	//num 1�� ����..���� �Ұ�...
private :
	int num2;
private:
	int num3;
};

class derived : protected base
{
	//num 1�� ����..���� �Ұ�..
protected:
	int num2;
protected:
	int num3;
};

class derived : public base
{
	//num 1�� ����..���� �Ұ�..
protected :
	int num2;
public : 
	int num3;
}