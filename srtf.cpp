#include<bits/stdc++.h>
using namespace std;
struct pro
{
	int at,bt,rem,com;
};
int main()
{
	
	int np,i,temp,tot=0,j,cp,ct;
	cout<<"Enter no. of processes: ";
	cin>>np;
	struct pro arr[np];
	cout<<"Enter arrival time and burst time: ";
	for(i=0;i<np;i++)
	{
		cin>>arr[i].at>>arr[i].bt;
		tot+=arr[i].bt;
	}
	for(i=0;i<np-1;i++)
	{
		for(j=0;j<(np-i)-1;j++)
		{
			if(arr[j].at>arr[j+1].at)
			{
				temp=arr[j].at;
				arr[j].at=arr[j+1].at;
				arr[j+1].at=temp;
				temp=arr[j].bt;
				arr[j].bt=arr[j+1].bt;
				arr[j+1].bt=temp;
			}
		}
	}
	for(i=0;i<np;i++)
	{
		arr[i].rem=arr[i].bt;
	}
	ct=arr[0].at;
	map <int,int> ava;
	while(tot>0)
	{
		cp=-1;
		for(i=0;i<np && arr[i].at<=ct;i++)
		{
			if(ava[i]==0)
			{
				if(cp==-1)
				{
					cp=i;
				}
				else if(arr[cp].rem>arr[i].rem)
				{
					cp=i;
				}
			}
		}
		ct++;
		tot--;
		arr[cp].rem--;
		if(arr[cp].rem==0)
		{
			ava[cp]=1;
			arr[cp].com=ct;
		}
	}
	
	for(i=0;i<np;i++)
	{
		cout<<"P No. "<<i<<" AT:"<<arr[i].at<<" BT:"<<arr[i].bt<<" CT:"<<arr[i].com<<" TAT:"<<arr[i].com-arr[i].at<<" WT:"<<(arr[i].com-arr[i].at)-arr[i].bt<<"\n";
	}
	return 0;
}
