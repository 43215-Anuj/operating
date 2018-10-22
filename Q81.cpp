#include <iostream>
using namespace std;
class Process
{
	public:
	string name;
	int at,bt,tat,wt,rt,prio;

	void input();
	void display();
};
void Process::input()
{
	cout<<"\nEnter the process name, burst time and arrival time and priority(integers)\n";
	cin>>name>>bt>>at>>prio;
}
void Process::display()
{
	cout<<endl<<name<<"\t"<<tat<<"\t"<<wt<<"\t"<<rt;
}
void input(Process* p,int& n)
{
	n=0;
	int flag;
	do
	{
			p[n++].input();
			cout<<"\nDo you want to add another process?(0 to stop)";
			cin>>flag;
	}while(flag);
}
void sort(Process * p,int &n)
{
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
}
void execute(Process *p,int n)
{
	Process p1;
	int current=0,min;
	double tat=0,rt=0,wt=0;
	for(int i=0;i<n;i++)
	{
		min=i;
		if(p[i].at>current)
		{
			current=p[i].at;
			i--;
			continue;
		}
		for(int j=i+1;j<n;j++)
		{
			if(p[min].prio<p[j].prio&&p[j].at<=current)
			{
				min=j;
			}
		}
		for(int j=i;j<n;j++)
		{
			if(p[min].prio==p[j].prio&&p[min].bt>p[j].bt&&p[j].at<=current)
			{
				min=j;
			}
		}
		p1=p[i];
		p[i]=p[min];
		p[min]=p1;
		p[i].rt=current-p[i].at;
		p[i].wt=current-p[i].at;
		p[i].tat=current+p[i].bt-p[i].at;
		current+=p[i].bt;
		
		tat+=p[i].tat;
		rt+=p[i].rt;
		wt+=p[i].wt;
	}
	cout<<"\nName\tTAT\tWT\tRT";
	for(int i=0;i<n;i++)
	{
		p[i].display();
	}
	cout<<"\nAverage Times:-\nTAT ="<<tat/n<<"\nWT ="<<wt/n<<"\nRT ="<<rt/n<<endl;
}
void display(Process* p,int n)
{
	cout<<"\nName\tBT\tAT\tprio";
	for(int i=0;i<n;i++)
		cout<<endl<<p[i].name<<"\t"<<p[i].bt<<"\t"<<p[i].at<<"\t"<<p[i].prio;
	cout<<endl;
}
int main()
{
	int n;
	Process p[20];
	input(p,n);
	display(p,n);
	sort(p,n);
	execute(p,n);
}

