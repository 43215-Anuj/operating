#include <iostream>
using namespace std;
class Process
{
	public:
	string name;
	int at,bt,tat,wt,rt;

	void input();
	void display();
};
void Process::input()
{
	cout<<"\nEnter the process name, burst time and arrival time(integers)\n";
	cin>>name>>bt>>at;
}
void Process::display()
{
	cout<<endl<<name<<"\t"<<tat<<"\t"<<wt<<"\t"<<rt<<"\n";
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
	for(int i=0;i<n;i++)
	{
		if(p[i].at>current)
		{
			current=p[i].at;
			i--;
			continue;
		}
		cout<<"\n current ="<<i<<" "<<current;
		p[i].rt=current-p[i].at;
		p[i].wt=current-p[i].at;
		p[i].tat=current+p[i].bt-p[i].at;
		current+=p[i].bt;
		cout<<p[i].rt<<" "<<p[i].wt<<" "<<p[i].tat;
		tat+=p[i].tat;
		rt+=p[i].rt;
		wt+=p[i].wt;
	}
	cout<<"\nName\tTAT\tWT\tRT\n";
	for(int i=0;i<n;i++)
	{
		p[i].display();
	}
	cout<<"\nAverage Times:-\nTAT ="<<tat/n<<"\nWT ="<<wt/n<<"\nRT ="<<rt/n<<endl;
}
