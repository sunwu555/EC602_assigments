//Copyright 2017 Wu Sun sunw5@bu.edu

#include<iostream>

using namespace std ;


int main()
{
	double a,b,c ;
	int i ;
	a = 4.554862024517909 ;
	b = 1.0121915610039797 ;
	c = 8.097532488031837 ;
	for (i=1;i<=38;i++)
	{
		a = a * 10 ;
		b = b * 10 ;
		c = c * 10 ;
		}

    cout << a << endl ;
    cout << b << endl ;
    cout << c << endl ;
    return(0) ;
    }
