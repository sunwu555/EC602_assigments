//Copyrights 2017 Wu Sun sunw5@bu.edu

#include <vector>


typedef vector<double> Poly ;


Poly add_poly(const Poly &a, const Poly &b)
{
    int i,c ;
    Poly d ;
    c = a.size() ;
    if (b.size() > c)
        c = b.size() ;
 
    for (i = 0; i < c; i++)
    {
        d.push_back(a[i] + b[i]) ;
//        d[i] = a[i] + b[i] ;
//      cout << d[i] << endl ;
    }
    for (i = (c-1); i>0; i--)
    {
        if (d[i] == 0)
            d.pop_back();
        else 
            break;

    }
    return d ;

}

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

