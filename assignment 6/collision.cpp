
// Copyright 2017 Wu Sun sunw5@bu.edu

#include <iostream>
#include <vector>
#include <sstream>
//#include <algorithm>
#include <iterator>
#include <string>  
#include <math.h>

using namespace std;

int main(int argc, char ** argv) {
	
	vector<string> init;
	vector<string> name;
	vector<vector<double> > data;
	string line;
	string d = "1";
	float char_input ;
	
	/************************check for bad input***********************/

	// arg not number
	for ( int i = 1; i < argc; i++)
	{
		stringstream(argv[i]) >> d;
		for ( int j = 0; j < d.size(); j++)
		{
			char_input = d[j];
			if ( char_input < 48 || char_input > 57)
				{
				if( char_input != 46)
					{
	            	return 2;
					}
				}
		}
	}


	// arg is void
	if(argc < 2) 
	{
	    return 2;
	}
	
	//data is void
	while(getline(cin,line))
	{
		if (!line.size())
		{
			return 1;
		}
	 init.push_back(line);
	}
	
	data.resize(init.size());
	
	for (int i=0;i<init.size();i++)
	{
	 istringstream iss(init[i]);
	 vector<string> temp{istream_iterator<string>{iss},istream_iterator<string>{}};
	 name.push_back(temp[0]);
	 
	 //data number not match
	 if (temp.size() != 5) 
	 {
	     return 1;
	 }
	
	 for(int j=1;j<5;j++){
	 	stringstream(temp[j]) >> d;
	 	for (int j = 0; j < d.size(); j++)
		{
			char_input = d[j];
			if (char_input < 48 || char_input > 57)
			{
				if( char_input != 46)
				{
					if (char_input != 45)
					{
	                    return 1;
					}				
				}
			}
		}
	  	data[i].push_back(stod(temp[j]));
	 }
		
	}

	/*****************end of check for bad input***********************/

	double a, b, c, g, f, delta, x1, x2, nextColTime, proceedTime, currentTime ;

	currentTime = 0;

	for(int k = 1;k < argc;k++){

		stringstream(argv[k]) >> proceedTime;

		while(currentTime  < proceedTime){

			stringstream(argv[k]) >> nextColTime;
			int ctimes=0;

			for(int i = 0;i < init.size();i++){

				for(int j = i+1;j < init.size();j++){

					a = pow((data[i][2] - data[j][2]),2) + pow((data[i][3] - data[j][3]),2);
					b = 2*((data[j][0] - data[i][0])*(data[j][2] - data[i][2]) + (data[j][1] - data[i][1])*(data[j][3] - data[i][3]));
					c = (pow((data[j][0] - data[i][0]),2) + pow((data[j][1] - data[i][1]),2)-100);
					delta = double((pow(b,2) - 4*a*c));

					if(delta > 0)
						{

						x1 = (-b - sqrt(delta))/(2*a);
						x2 = (-b + sqrt(delta))/(2*a);		

						if(x1 >= 0)
							{
							if(proceedTime > (currentTime +x1)){

								if (nextColTime >= x1){

								nextColTime = x1;
								ctimes++;
							}

							else{

								}

							}
						}				
					}

					else
						{
						}
				}
			}

			if((currentTime +nextColTime) < proceedTime){

				for(int i = 0;i < init.size();i++){

					data[i][0] = data[i][0] + data[i][2]*nextColTime;
					data[i][1] = data[i][1] + data[i][3]*nextColTime;
				}

				for(int t=0;t<=ctimes;t++)
					{

					for(int i = 0;i < init.size();i++)
						{

						for(int j = i+1;j < init.size();j++)
							{
							double instance; 
							double instance1;
							double deltat=0.0000001;
							instance = pow((data[i][0]-data[j][0]),2)+pow((data[i][1]-data[j][1]),2);
							instance = pow((data[i][0]-data[j][0])+(data[i][2]-data[j][2])*deltat,2)+pow((data[i][1]-data[j][1])+(data[i][3]-data[j][3])*deltat,2);	

							if (instance <= 100 && instance1<100)
								{
								double temp1 = ((data[i][2] - data[j][2])*(data[i][0] - data[j][0]) + (data[i][3] - data[j][3])*(data[i][1] - data[j][1]))/(pow((data[i][0] - data[j][0]),2)+pow((data[i][1] - data[j][1]),2));
								double temp2 = ((data[j][2] - data[i][2])*(data[j][0] - data[i][0]) + (data[j][3] - data[i][3])*(data[j][1] - data[i][1]))/(pow((data[i][0] - data[j][0]),2)+pow((data[i][1] - data[j][1]),2));
								data[i][2] = data[i][2] - temp1*(data[i][0] - data[j][0]);
								data[i][3] = data[i][3] - temp1*(data[i][1] - data[j][1]);
								data[j][2] = data[j][2] - temp2*(data[j][0] - data[i][0]);
								data[j][3] = data[j][3] - temp2*(data[j][1] - data[i][1]);
								}
							}
						}
					}
				currentTime  = currentTime  + nextColTime;
			}
			else{		

				for(int i = 0;i < init.size();i++){

					data[i][0] = data[i][0] + data[i][2]*(proceedTime - currentTime );
					data[i][1] = data[i][1] + data[i][3]*(proceedTime - currentTime );
				}

				cout<<proceedTime<<endl;

				for(int i = 0;i < init.size();i++){	

					cout.precision(8);		
					cout<<name[i]<<" ";

					for(int j = 0;j < 4;j++){

						cout<<data[i][j]<<" ";
					}
					cout<<endl;
					currentTime  = proceedTime;
				}
			}
		}
	}

	return 0;

}

