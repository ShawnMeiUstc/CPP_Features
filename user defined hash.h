#pragma once
//https://www.codeleading.com/article/50961599052/
//https://www.cnblogs.com/kindly/p/6023949.html

#include "stdc++.h"

// 推荐写两个函数对象，一个定义hash值的计算，一个定义比较的方式（如果自定义的类没有重载operator==）
// 重载了operator==的类不需要自定义比较方式

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

// 特化std::hash要往namespace里面注入内容，不太好
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

// 如果要用函数指针、lambda等传入，还需要map的构造函数传值，不太好

void hashrun()
{
	unordered_map <A, int, hasher, comp> mapper;

	A a, b;
	mapper[a] = 1;
	mapper[b] = 2;
}