#include"Date.h"

int main()
{
	//Date d1(2024,10,6);
	//d1.Print();
	//Date d2 = d1.operator++(1);
	//Date d3 = d1++;
	//d2.Print();//10.6
	//
	////d1.Print();
	////d2.Print();
	//d3.Print();//10.7
	//d1.Print();//10.8
	/*cout << d1.operator<(d2) << endl;
	cout <<( d1 == d2) << endl;
	cout << (d1 > d2) << endl;*/
	/*int i = 1;
	int j = ++i;
	int k = ++i;
	cout << "i:" << i << endl;
	cout << "j:" << j << endl;
	cout << "k:" << k << endl;*/

	//Date d1(2024, 10, 6);
	//d1.Print();//10.6
	//Date d2(d1--);
	//d2.Print();//10.6
	//Date d3(--d1);
	//d3.Print();//10.4
	//d1.Print();
	//Date d2(2024,10,3);
	//cout << (d2 - d1) << endl;
	const Date d1(2024, 10, 11);
	d1.Print();
	Date d2;
	d2.Print();
	operator<<(cout, d1);
	cout << d1 << d2;
	//d1 << cout;
	//cin >> d1 >> d2;
	cout << d2 << d1;
	return 0;
}