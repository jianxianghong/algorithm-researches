#include<iostream>
#include<cstdio>

using namespace std;

int high_pricision_factorial(){
	const int figure=1000000000;
	const int maxdigit=50740;
	const int change[4]={13,2,479001600,100000};
	int number[2][maxdigit]={0};
	cout<<"Begain with 1\n";
	cout<<"serial:";
	int serial;	cin>>serial;	getchar();
	if(serial<change[0]&&serial>1){
		int calculate[2]={1,1}; ++serial;
		while(--serial){
			calculate[1]=calculate[1]*calculate[0];
			++calculate[0];
		}
		cout<<"The number is : "<<calculate[1];
	}else{
		if(serial<0||serial>change[3]){
			cout<<"The number seems unreachable...";	while(getchar()!=10){}
		}else{
			int tail=0;
			serial=serial-change[0];
			number[0][0]=change[0];	number[0][1]=change[1]; number[0][2]=change[2]; serial+=2;
			while(--serial){
				number[(tail+1)%2][0]=number[tail][0]+1; number[(tail+1)%2][1]=number[tail][1];	number[(tail+1)%2][2]=0;
				for(int iterator=2;iterator<=number[tail][1];++iterator){
					long long temp1=number[tail][iterator];
					long long temp2=number[tail][0];
					long long temp=temp1*temp2;
					number[(tail+1)%2][iterator]+=(temp%figure);
					if(temp>=figure)	number[(tail+1)%2][iterator+1]=temp/figure;
					else	number[(tail+1)%2][iterator+1]=0;
				}
				tail=(tail+1)%2;
				if(number[tail][number[tail][1]+1]>0)	++number[tail][1];
			}
			cout<<"The number had the length of : "<<number[tail][1]-1<<" intenger\n"<<"The number is : \n        ";
			for(int iterator=number[tail][1];iterator>1;--iterator)	cout<<number[tail][iterator];
			}
	}
	cout<<"\nPress any key to continue...\n";	getchar();
	return 0;
}
