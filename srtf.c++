#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
 typedef struct srtf
 {
    int pid;
    int arrival_time;
    int burst_time;
 }srtf;
 
int main(int argc, char const *argv[])
{
 int n;
 cin>>n;
 srtf arr[n];
 int burst_remaining[n];
 int completion_time;
 int time;
 int remain=0;
 int smallest=100000;

 for (int i = 0; i <n; i++)
 {
     arr[i].pid=i+1;
    cin>>arr[i].arrival_time>>arr[i].burst_time;
  burst_remaining[i]=arr[i].burst_time;
 }
int sum_waiting =0,sum_turnaround=0;
 for ( time = 0; remain!=n; time++)
 {
   for (int i = 0; i < n; i++)
   {
    if (arr[i].arrival_time<=time && burst_remaining[i]!=0)
    {
        smallest=i;
    }
    
   }
   burst_remaining[smallest]--;


   
   if (burst_remaining[smallest]==0)
   {
     remain++;
     completion_time=time+1;
     cout<<"turnarround time of process: "<<arr[smallest].pid<<" is: "<<completion_time-arr[smallest].arrival_time<<", and waiting time is: "<<completion_time-arr[smallest].arrival_time-arr[smallest].burst_time<<endl;
    
      sum_waiting += (completion_time-arr[smallest].arrival_time-arr[smallest].burst_time);
      sum_turnaround+=(completion_time-arr[smallest].arrival_time);

   }
   
   
 }
 

cout<<"average waiting time: "<<sum_waiting/n<<endl;
cout<<"average waiting time: "<<sum_turnaround/n<<endl;

 
return 0;
}