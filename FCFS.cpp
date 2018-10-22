#include<iostream>
using namespace std;

class Gnatt
{
	int BT,arr,TAT,WT,RT,pos,org;
	
	public:
			void Enter(int i)
			{
				cout<<"\n Enter Burst time :";
				cin>>BT;
				cout<<"\n Enter Arrival Time :";
				cin>>arr;
				org=i;
				
			}
			int retOrg()
			{
				return org;
			}
			int retArr()
			{
				return arr;
			}
			int retPos()
			{
				return pos;
			}
			int retBT()
			{
				return BT;
			}
			
			void setP(int i)
			{
				pos=i;
			}
			int retTAT()
			{
				return TAT;
			}
			int retRT()
			{
				return RT;
			}
			int retWT()
			{
				return WT;
			}
			int addBT(Gnatt[],int);
			void ResT();
			void WaitT(Gnatt []);
			void Total();
			
			float AvgRT(Gnatt [],int);
			float AvgWT(Gnatt [],int);
			float AvgTAT(Gnatt [],int);
};
//Waiting Time

void Gnatt::WaitT(Gnatt G[])
{	
	WT=addBT(G,pos)-arr;
	ResT();
}

//Response Time
void Gnatt::ResT()
{
	RT=WT;
}

//Turn around Time
void Gnatt::Total()
{
	TAT=WT+BT;
}

//Average TAT
float Gnatt::AvgTAT(Gnatt G[],int n)
{	
	float avg=0;
	for(int i=0;i<n;i++)
	{
		avg+=G[i].TAT;
	}
	return(avg/n);
}

//Average Waiting Time
float Gnatt::AvgWT(Gnatt G[],int n)
{	
	float avg=0;
	for(int i=0;i<n;i++)
	{
		avg+=G[i].WT;
	}
	return(avg/n);
}

//Average Response Time
float Gnatt::AvgRT(Gnatt G[],int n)
{	
	float avg=0;
	for(int i=0;i<n;i++)
	{
		avg+=G[i].RT;
	}
	return(avg/n);
}
void Arrange(Gnatt G[],int n)
{
	Gnatt T;
	int i,j,p;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
				if(G[j].retArr()>G[j+1].retArr())
				{
					T=G[j];
					G[j]=G[j+1];
					G[j+1]=T;
				}
		}
	}
	for(i=0;i<n;i++)
	{
		G[i].setP(i);
	}
}

//Add Burst Time
int Gnatt::addBT(Gnatt G[],int index)
{	int s=0,i;
	for(i=0;i<index;i++)	
	{
		s+=G[i].retBT();
	}
	return s;
}
					
int main()
{
	Gnatt G[10],ob;
	int n;
	cout<<"\n Enter the Number of Processes :";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cout<<"\n Enter Values for Process"<<i+1<<" : ";	
		G[i].Enter(i+1);
	}
	//Arrange in the order of Arrival time
	Arrange(G,n);
	
	cout<<"\n Result is :";
	cout<<"\n  \tTAT\tRT\tWT";	
	for(int i=0;i<n;i++)
	{	
		G[i].WaitT(G);
		G[i].ResT();	
		G[i].Total();
		
		cout<<"\nP"<<G[i].retOrg()<<"   \t"<<G[i].retTAT()<<"\t"<<G[i].retWT()<<"\t"<<G[i].retRT();
	}
	
	cout<<"\n\nAVG.\t"<<ob.AvgTAT(G,n)<<"\t"<<ob.AvgWT(G,n)<<"\t"<<ob.AvgRT(G,n)<<"\n";
	return 0;
}
			

