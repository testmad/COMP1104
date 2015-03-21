#include <iostream>
#include <iomanip>

using namespace std;

int findEaster(int input);

int main(void)
{
	int userinput;
	
	cout<<"give yeaar"<<endl;
	
	cin>> userinput;
	
	
	cout<<findEaster(userinput);
	
}


int findEaster(int input){
	
	int a;
	int b;
	int c;
	int d;
	
	//cout<<input<<endl;
	
	a = input%19;
	b= input%4;
	c=input%7;
	d=(19*a+24)%30;
	
	return d;
	
}
