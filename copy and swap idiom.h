#pragma once
// for more details : https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom/3279550#3279550

#include "stdc++.h"

class MyString
{
	friend void swap(MyString& lhs, MyString& rhs)
	{
		swap(lhs.m_data, rhs.m_data);
		swap(lhs.m_len, rhs.m_len);
	}

public:
	MyString() : m_data(nullptr), m_len(0) { cout << "default constructor" << endl; }
	MyString(const char *s) : m_len(strlen(s)) { copyData(s);  cout << "constructor" << endl;}

	MyString(const MyString &s) : m_len(s.m_len) { copyData(s.m_data); cout << " copy constructor" << endl;}

	MyString(MyString&& s) noexcept : MyString()
	{
		swap(*this, s);
		cout << " move constructor" << endl;
	}

	MyString& operator=(MyString rhs)
	{
		swap(*this, rhs);
		cout << " copy & move assignment" << endl;
		return *this;
	}
	// 实际上，我们比那个不需要多写代码move assignment，copy-and-swap 技巧 和 move-and-swap 技巧是共享同一个函数的。
	// 当copy构造为上述的方法4时，对于C++ 11，编译器会依据参数是左值还是右值在拷贝构造函数和移动构造函数间进行选择

	/*MyString& operator=(MyString&& s) noexcept
		{
			if (this != &s)
			{
				delete[] m_data;
				m_len = s.m_len;
				m_data = s.m_data;
				s.m_len = 0;
				s.m_data = nullptr;
			}
			return *this;
		}*/

	virtual ~MyString()
	{
		delete[] m_data;
		cout << " destructor" << endl;
	}

	static void Run()
	{
		const char*  s = "123";
		MyString c(s);
		cout << "------------->\n";
		MyString d(c);
		cout << "------------->\n";

		MyString e;
		cout << "------------->\n";

		e = d;
		cout << "------------->\n";

		MyString f(move(e));
		cout << "------------->\n";

		e = move(f);
		cout << "------------->\n";
	}

private:
	void copyData(const char *s)
	{
		m_data = new char[m_len + 1];
		memcpy(m_data, s, m_len + 1);
	}

private:
	char* m_data;
	int m_len;
};

