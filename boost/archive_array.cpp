#include "boostarchive.hpp"
#include "inspect.hpp"

int main()
{
	stringstream ss;

	{
		int a[10]{ 1, 2, 3 };
		text_oarchive toa(ss);
		toa << a;
		print(a);
	}
	{
		int a[20]; // should >= 10
		text_iarchive tia(ss);
		tia >> a;
		print(a);
	}
}