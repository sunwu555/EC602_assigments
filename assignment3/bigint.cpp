//Copyrights 2017 Wu Sun sunw5@bu.edu

#include <string>
#include <vector> 
#include <iostream>

using namespace std ;

typedef string BigInt;

typedef vector<double> Poly ;

Poly multiply_poly(const Poly &a, const Poly &b)
{
    int asize,bsize,i,j ;
    Poly d ;
    asize = a.size() ;
    bsize = b.size() ;
    for (int i = 0; i < (asize + bsize - 1); ++i)
    {
        d.push_back(0) ;
    }
    for (int i = 0; i < asize; ++i)
    {
        for (int j = 0; j < bsize; ++j)
        {
            d[i+j] = d[i+j] + (a[i] * b[j]) ;

        }
    }
    for (i = (asize+bsize-2); i>0; i--)
    {
        if (d[i] == 0)
            d.pop_back();
        else 
            break;
    }
    return d ;
}


BigInt multiply_int(const BigInt &a,const BigInt &b)
{
    int i,j,k;
    int asize = a.size() ;
    int bsize = b.size() ;
    BigInt ans,rans ;
    Poly av,bv,cv;
    char cha ;
    for (int i = (asize - 1 ); i >= 0; --i)
    {
      av.push_back(a[i]-48) ;
    }

    for (int i = (bsize - 1 ); i >= 0; --i)
    {
      bv.push_back(b[i]-48) ;
    }

    cv = multiply_poly(av,bv) ;

    for (auto & e : cv )
    {
    	cout << e << " " ;/* code */
    }

    for (int i = 0; i <= cv.size(); i++)
     {
        cv[i+2] = int(cv[i]) / 1000 ;
        cout << "cv[i]= " << cv[i] << endl ;
        cv[i+1] = int(cv[i]-1000) / 100 ;
        cv[i] = int(cv[i]) % 10 ;
        ans.push_back(cv[i] + 48) ;
       

     } 
    if (ans[ans.size()-1] == '0')
      ans.pop_back();


     for (int i = ans.size()-1; i >=0 ; i--)
     {
       /* code */
        rans.push_back(ans[i]);
     }

     return rans ;
  }

 int main()
 {
 BigInt A,B ;
 cin >> A >> B ;
 cout << multiply_int(A,B) << endl ;
 return 0;
 }
