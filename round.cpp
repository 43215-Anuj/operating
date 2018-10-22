#include<iostream>
using namespace std;

int main()
{
	int at[10],bt[10],rt[10],tat,time_slice;
	int time=0,left,count=0,n,i,flag=0;

	cout<<"\n Enter the number of Processes :";
	cin>>n;

	left=n;

	
	for(i=0;i<n;i++)
	{
		cout<<"\n Enter burst time | Arrival time for Processes: <<"<<i<<">>";
		cin>>bt[i]>>at[i];
		rt[i]=bt[i];
	}

	cout<<"\n Enter Time Slice : ";
	cin>>time_slice;

	cout<<"Processes\t Burst Time\t Arrival Time \t TAT \tWaiting Time";
	for(time=0,count=0;left!=0;)
	{	cout<<"\ncount = "<<count;
		if(rt[count]<=time_slice && rt[count]>0)
		{
			time+=rt[count];
			rt[count]=0;
			flag=1;
		}
		else if(rt[count]>time_slice)
		{
			time+=time_slice;
			rt[count]-=time_slice;
		}
		if(rt[count]==0 && flag==1)
		{
			cout<<"\ncount = "<<count;
			cout<<"\nP["<<count+1<<"]\t\t"<<bt[count]<<"\t\t"<<at[count]<<"\t\t"<<time-at[count]<<"\t\t"<<time-at[count]-bt[count];
			flag=0;
			left--;
		}	
		if(count==n-1)
		{
			count=0;
		}
		else if(at[count+1]<=time)
		{
			count++;
		}
		else
		{
			count=0;
		}
	}
}