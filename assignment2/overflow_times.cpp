//Copyright 2017 Wu Sun sunw5@bu.edu

#include <iostream>
#include <ctime>
#include <cstdint>
#include <math.h>

using namespace std;

int main()
{
    
    clock_t start_clock,end_clock;
    
    start_clock = clock();  // Timing starts here
    
    int16_t i = 1;
    
    while ( i >0 )
    	{
        	i++;
        }
           
    end_clock = clock();    // Timing stops here
           
//    double seconds1 = (long double)(end_clock-start_clock) / CLOCKS_PER_SEC ;
    double seconds1 = static_cast<double>(end_clock-start_clock) / CLOCKS_PER_SEC ;
    double microseconds = double(seconds1 * 1000000) ;
    double nanoseconds = double(microseconds * 1000 / pow(2,8)) ;
    double seconds = double(seconds1 * pow(2,16)) ;
    double years = double(seconds / 60 / 60 / 24 / 365 * pow(2,32)) ;
           
    cout << "estimated int8 time (nanoseconds): " << nanoseconds << endl;
    cout << "measured int16 time (microseconds): " << microseconds << endl;
    cout << "estimated int32 time (seconds): " << seconds << endl;
    cout << "estimated int64 time (years): " << years << endl;

           
}