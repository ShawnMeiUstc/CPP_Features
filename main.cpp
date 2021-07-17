#include "copy and swap idiom.h"

void f(const char* s) {}
void f(char* s) {}

int main()
{
	const char* const s = "123";
	MyString c(s);
	f(s);
}