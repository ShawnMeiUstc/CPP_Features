#pragma once
//https://www.codeleading.com/article/50961599052/
//https://www.cnblogs.com/kindly/p/6023949.html

#include "stdc++.h"

// �Ƽ�д������������һ������hashֵ�ļ��㣬һ������Ƚϵķ�ʽ������Զ������û������operator==��
// ������operator==���಻��Ҫ�Զ���ȽϷ�ʽ

class A {
public:
	int w = 1;
	/*inline bool operator==(const A& rhs) const {
		return false;
	}*/
};

struct hasher {

	size_t operator()(const A& rhs) const {
		return 1;
	}
};

struct comp {
	bool operator()(const A& lhs, const A& rhs) const {
		return false;
	}
};

// �ػ�std::hashҪ��namespace����ע�����ݣ���̫��
//namespace std {
//	template<>
//	struct hash<A>
//	{
//		size_t operator()(const A& rhs) const
//		{
//			return 1;
//		}
//	};
//	inline bool operator==(const A& lhs, const A& rhs) noexcept
//	{
//		return false;
//	}
//}

// ���Ҫ�ú���ָ�롢lambda�ȴ��룬����Ҫmap�Ĺ��캯����ֵ����̫��

void hashrun()
{
	unordered_map <A, int, hasher, comp> mapper;

	A a, b;
	mapper[a] = 1;
	mapper[b] = 2;
}