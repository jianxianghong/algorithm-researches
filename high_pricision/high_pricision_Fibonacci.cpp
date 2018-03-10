#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int high_pricision_Fibonacci(){
	const int null=3;
	const int figure=1000000000;
	const int maxdigit=50000;
	const int change[4]={27,46368,75025,100000000};
	int number[4][maxdigit]={0};
	cout<<"Begain with 0,1,1\n";
	cout<<"serial:";
	int serial;	cin>>serial;	getchar();
	if(serial<change[0]&&serial>0){
		int calculate[5]={1,0,1,1,0};
		serial=serial-2;
		while(--serial){
			calculate[calculate[0]]=calculate[calculate[0]!=1?1:4]+calculate[calculate[0]!=2?2:4]+calculate[calculate[0]!=3?3:4];
			if(++calculate[0]>3)	calculate[0]=1;
		}
		cout<<"The number is : "<<calculate[--calculate[0]>0?calculate[0]:3];
	}else{
		if(serial<=0||serial>change[3]){
			cout<<"The number seems unreachable...";	while(getchar()!=10){}
		}else{
			int tail=2;	serial=serial-change[0]+2;
			number[0][0]=number[1][0]=number[2][0]=1;
			number[0][1]=change[1];	number[1][1]=change[2];
			while(--serial){
				number[tail][0]=max(max(number[tail!=1?1:null][0],number[tail!=2?2:null][0]),number[tail!=3?3:null][0]);
				for(int iterator=1;iterator<number[tail][0]+1;++iterator){
					number[tail][iterator]=number[tail][iterator]+number[tail!=0?0:null][iterator]+number[tail!=1?1:null][iterator]+number[tail!=2?2:null][iterator];
					if(number[tail][iterator]>figure||number[tail][iterator]<0){
						number[tail][iterator]=number[tail][iterator]-figure;	++number[tail][iterator+1];
					}
					number[tail-2>-1?tail-2:tail+1][iterator]=0;
				}
				if(number[tail][number[tail][0]+1]>0)	++number[tail][0];
				if(++tail>2)	tail=0;
			}
			cout<<"The number had the length of : "<<number[--tail<0?2:tail][0]<<" intenger\n"<<"The number is : \n        ";
			for(int iterator=number[tail<0?2:tail][0];iterator>0;--iterator)	cout<<number[tail<0?2:tail][iterator];
			}
	}
	cout<<"\nPress any key to continue...\n";	getchar();
	return 0;
}
