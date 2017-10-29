//Copyright 2017 Wu Sun sunw5@bu.edu
// Definitions:
// Rs = factor by which float is better than int at representing small numbers
// Rm = factor by which float is better than int at representing large numbers
// Ri = factor by which int is better than float at representing integers
//
// Formulas:
//
// Rs = 1 / smallest_float_greater_than_zero
// Rm = maximum_float_value / largest_int_value
//
// Ri = largest_int_value / N
// where N is the largest integer such that all integers 1,2,3,...,N can be
// represented without loss of accuracy by a float of this size.

#include <iostream>
#include <cstdint>
#include <cfloat>
#include <cmath>
#include <math.h>
#include <float.h>

using namespace std ;

int main(){

   long double int16,int32,int64,a1,a2,a3 ;
  
  long double max_float,min_float,Rs_f,Ri_f,Rm_f ;
  long double max_double,min_double,Rs_d,Ri_d,Rm_d ;
  long double Rs,Rm,Ri ;
  long int n ;

  int16 = 0x7fff ; 
  int32 = 0x7fffffff ; 
  int64 = 0x7fffffffffffffff ;

  a1 = pow(2,11) ;
  a2 = pow(2,24) ;
  a3 = pow(2,53) ;

  max_float = FLT_MAX ;
  min_float = FLT_MIN ;

  max_double = DBL_MAX ;
  min_double = DBL_MIN ; 
  // calculate Rs, Ri, and Rm for half/binary16 vs int16_t
  
  Rs = (long double)(1.0 / pow(2,-14)) ;
  Rm = (long double)(65504.0 / int16) ;
  Ri = (long double)(int16 / a1) ; 
  cout<< "16 : Ri= " << Ri << " Rm= " << Rm << " Rs= " << Rs << endl;

  // calculate Rs, Ri, and Rm for float/single/binary32 vs int32_t

  Rs = (long double)(1.0 / min_float) ;
  
  Rm = (long double)(max_float / int32) ;
  Ri = (long double)(int32 / a2) ; 
  cout<< "32 : Ri= " << Ri << " Rm= " << Rm << " Rs= " << Rs << endl;

  // calculate Rs, Ri, and Rm for double/binary64 vs int64_t
  

  Rs = (long double)(1.0 / min_double) ;

  
  Rm = (long double)(max_double / int64) ;  
    Ri = (long double)(int64 / a3) ; 
  cout<< "64 : Ri= " << Ri << " Rm= " << Rm << " Rs= " << Rs << endl;

  return 0;
}

