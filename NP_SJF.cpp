//Non-Premptive SJF

#include<iostream>
using namespace std;
class Gnatt
{
	int BT,arr,TAT,WT,RT,pos,org;
	
	public:
			void Enter(int i)
			{
				cout<<"\nEnter Burst time :";
				cin>>BT;
				cout<<"Enter Arrival Time :";
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
			
			void setPos(int i)
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
			void setArr(int a)
			{
				arr=a;
			}

			int addBT(Gnatt[],int);
			void ResT();
			void WaitT(Gnatt []);
			void Total();
			
			float AvgRT(Gnatt [],int);
			float AvgWT(Gnatt [],int);
			float AvgTAT(Gnatt [],int);
};

void Gnatt::WaitT(Gnatt F[])
{	
	WT=addBT(F,pos)-arr;
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
float Gnatt::AvgTAT(Gnatt F[],int n)
{	
	float avg=0;
	for(int i=0;i<n;i++)
	{
		avg+=F[i].TAT;
	}
	return(avg/n);
}

//Average Waiting Time
float Gnatt::AvgWT(Gnatt F[],int n)
{	
	float avg=0;
	for(int i=0;i<n;i++)
	{
		avg+=F[i].WT;
	}
	return(avg/n);
}

//Average Response Time
float Gnatt::AvgRT(Gnatt F[],int n)
{	
	float avg=0;
	for(int i=0;i<n;i++)
	{
		avg+=F[i].RT;
	}
	return(avg/n);
}

int Gnatt::addBT(Gnatt F[],int index)
{	int s=0,i;
	for(i=0;i<index;i++)	
	{
		s+=F[i].retBT();
	}
	return s;
}

int main()
{
	Gnatt G[10],T,M[10],ob,F[10];
	int a,n,i,j,f=0,t,size,A[5],k,x,c,d,e,start,end;
	
	cout<<"\n\tNON-PREMPTIVE SHORTEST JOB";	
	cout<<"\n\n Enter the Number of Processes :";
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		cout<<"\n Enter Values for Process"<<i+1<<"  ";	
		G[i].Enter(i+1);
	}
	//Arrange in the order of Arrival time
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
	
	//Finding Arrival Times
	A[0]=G[0].retArr();
	k=0;
	for(i=1;i<n;i++)
	{
		if(G[i].retArr()!=A[k])
		{	
			k++;
			A[k]=G[i].retArr();
		}
	}
	
	//Coping object Array
	i=0;
	for(x=0;x<=k;x++)
	{	start=i; 
		while(G[i].retArr()==A[x])	
		{
			F[i]=G[i];
			i++;
		}
		end=i;
		
		//Arrange Process for the Smallest Arrival Time According to Burst Time
		for(a=0;a<end;a++)
		{
			for(j=start;j<end-a-1;j++)
			{
				if(F[j].retBT()>F[j+1].retBT())
				{
					T=F[j];
					F[j]=F[j+1];
					F[j+1]=T;	
				}
			}
		}	

		for(j=start;j<end;j++)
		{
			F[j].setPos(j);
		}
	}
		
	cout<<"\n Result is :";
	cout<<"\n  \tTAT\tRT\tWT";	

	for(i=0;i<n;i++)
	{	
		F[i].WaitT(F);
		F[i].ResT();	
		F[i].Total();
		cout<<"\nP"<<F[i].retOrg()<<"   \t"<<F[i].retTAT()<<"\t"<<F[i].retWT()<<"\t"<<F[i].retRT();
	}
	cout<<"\n\nAVG.\t"<<ob.AvgTAT(F,n)<<"\t"<<ob.AvgWT(F,n)<<"\t"<<ob.AvgRT(F,n)<<"\n";
	return 0;
}
			
