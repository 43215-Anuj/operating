#include <iostream>
using namespace std;
class Process
{
	public:
	string name;
	int at,bt,tat,wt,rt,prio;
	bool flag;
	void input();
	void display();
};
void Process::input()
{
	flag=true;
	cout<<"\nEnter the process name, burst time and arrival time(integers)\n";
	cin>>name>>bt>>at;
}
void Process::display()
{
	cout<<endl<<name<<"\t"<<tat<<"\t"<<wt<<"\t"<<rt<<"\n";
}
bool notEnded(Process* p,int n)
{
	for(int i=0;i<n;i++)
	{
		if(p[i].bt!=0)
			return true;
	}
	return false;
}
int main()
{
	int flag;
	Process p[20];
	int n=0;
	do
	{
			p[n++].input();
			cout<<"\nDo you want to add another process?(0 to stop)";
			cin>>flag;
	}while(flag);
	int ts;
	cout<<"\nEnter the time slice:";
	cin>>ts;
	Process p1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				p1=p[j];
				p[j]=p[j+1];
				p[j+1]=p1;
			}
		}
	}
	int current=0;
	double tat=0,rt=0,wt=0;
	for(int i=0;notEnded(p,n);i++)
	{
		if(p[i].bt==0)
		{
			continue;
		}
		if(i>=n)//if list has ended, go to 0
		{
			i=0;
			continue;
		}
		if(p[i].at>current&&notEnded(p,i))//if cpu has to wait for another process start another round
		{
			i=0;
			continue;
		}
		if(p[i].at>current&&!notEnded(p,i))//if cpu has to idle while waiting for a process
		{
			cout<<"\ni="<<i<<endl;
			current=p[i].at;
			i--;
			continue;
		}
		if(p[i].flag)//if its the first time cpu is given
		{
			p[i].wt=-p[i].bt;
			p[i].rt=current-p[i].at;
			p[i].flag=false;
		}
		if(ts<p[i].bt)
		{
			current+=ts;
			p[i].bt-=ts;
		}
		
		else
		{
			current+=p[i].bt;
			p[i].bt=0;
		}
		if(p[i].bt==0)
		{
			cout<<"\nCurrent ="<<current;
			cout<<"\nP"<<(i+1)<<endl;
			p[i].tat=current-p[i].at;
			p[i].wt+=p[i].tat;
			tat+=p[i].tat;
			rt+=p[i].rt;
			wt+=p[i].wt;
		}
	}
	cout<<"\nName\tTAT\tWT\tRT\n";
	for(int i=0;i<n;i++)
	{
		p[i].display();
	}
	cout<<"\nAverage Times:-\nTAT ="<<tat/n<<"\nWT ="<<wt/n<<"\nRT ="<<rt/n<<endl;
}
