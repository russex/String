#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class String;
String operator+(const String left, const String& right);

class String
{
	int size;      
	char* str;     
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstract:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstractor:" << this << endl;
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str; 
		other.str = nullptr;   
							   
		other.size = 0;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		this->str = nullptr;
		this->size = 0;
		cout << "Destroctor:\t" << this << endl;
	}



	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstractor:" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		other.size = 0;
		cout << "MoveAssighment:\t" << this << endl;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}

	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		result[i + left.get_size() - 1] = right[i];
	return result;

}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}



void main()
{
	setlocale(LC_ALL, "Rus");

	String str(5);           
	str.print();

	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;

	String str2 = str1;      
	cout << str2 << endl;

	String str3;
	str3 = str2;             
	cout << str3 << endl;

	int a = 2;
	int b = 3;
	a = b;
	cout << a << endl;

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << "\n---------------------------------------\n";
	String str3;
	str3 = str1 + str2;  
	cout << "\n---------------------------------------\n";
	cout << str3 << endl;
#endif // OPERATOR_PLUS_CHECK

#ifdef CONSTRACTOR_CALLING
	String str1;              
	cout << str1 << endl;
	String str2 = "Hello";    
	cout << str2 << endl;
	String str3 = str2;      
	cout << str3 << endl;
	str3.print();
	String str4();  
	String str5{}; 
	str5.print();
#endif // CONSTRACTOR_CALLING

}