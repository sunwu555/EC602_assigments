

#include <string>
#include <vector> 
#include <iostream>

using namespace std ;

typedef string BigInt;

typedef vector<double> Poly ; 

BigInt multiply_int(const BigInt &a,const BigInt &b)
{
    int i,j ;
    int asize = a.size() ;
    int bsize = b.size() ;
    Poly av,bv ;
    char cha ;
    for (int i = (asize - 1 ); i >= 0; --i)
    {
      av.push_back(a[i]) ;
    }
    for (int i = (bsize - 1 ); i >= 0; --i)
    {
      bv.push_back(b[i]) ;
    }
    for (auto& e : av)
     cin >> e;
  
    for (auto& e : bv)
     cin >> e;

  
  }
  
  
int main()
{ 
  BigInt A,B;

  cin >> A >> B;

  cout << multiply_int(A,B) << endl;

  return 0 ;
}