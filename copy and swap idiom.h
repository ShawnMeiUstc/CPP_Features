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
	MyString() : m_data(nullptr), m_len(0) {}
	MyString(const char *s) : m_len(strlen(s)) { copyData(s); }

	MyString(const MyString &s) : m_len(s.m_len) { copyData(s.m_data); }

	MyString(MyString&& s) noexcept : MyString()
	{
		swap(*this, s);
	}

	MyString& operator=(MyString rhs)
	{
		swap(*this, rhs);
		return *this;
	}
	// ʵ���ϣ����Ǳ��Ǹ�����Ҫ��д����move assignment��copy-and-swap ���� �� move-and-swap �����ǹ���ͬһ�������ġ�
	// ��copy����Ϊ�����ķ���4ʱ������C++ 11�������������ݲ�������ֵ������ֵ�ڿ������캯�����ƶ����캯�������ѡ��

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

