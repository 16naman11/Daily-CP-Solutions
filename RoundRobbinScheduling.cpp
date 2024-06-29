#include<iostream>
#include <algorithm> 
#include <queue> 
#include<iomanip>
#include<climits>
using namespace std;

struct process_struct
{
  int pid;
  int at;
  int bt;
  int ct,wt,tat,rt,start_time;
  int bt_remaining;
}ps[100];

bool comparatorAT(struct process_struct a,struct process_struct b)
{
   int x =a.at;
   int y =b.at;
   return x < y;
//    if(x > y)
//      return false;  // Apply sorting
//    return true;   // no sorting
}

bool comparatorPID(struct process_struct a,struct process_struct b)
{
   int x =a.pid;
   int y =b.pid;
   return x < y;
}

int main()
{
    
    int n,index;
    queue<int> q;
    bool visited[100]={false},is_first_process=true;
    int current_time = 0,max_completion_time;
    int completed = 0,tq, total_idle_time=0,length_cycle;
    cout<<"Enter total number of processes: "<<endl;
    cin>>n;    
    float sum_tat=0,sum_wt=0,sum_rt=0;

    cout << fixed << setprecision(2);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Process " <<i+1<< " Process Id: ";
        cin >> ps[i].pid;
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Process " <<i+1<< " Arrival Time: ";
        cin >> ps[i].at;
    }
    cout<<endl;
    
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Process " <<i+1<< " Burst Time: ";
        cin >> ps[i].bt;
        ps[i].bt_remaining= ps[i].bt;
    }
    

    // Input process details
    /*for (int i = 0; i < n; ++i) {
        cout << "Process " << i + 1 << ":\n";
        cout<<"Process id: ";
        cin>>ps[i].pid;
        cout << "Arrival Time: ";
        cin >> ps[i].at;
        cout << "Burst Time: ";
        cin >> ps[i].bt;
        ps[i].bt_remaining=ps[i].bt;
    }*/
    cout<<"\nEnter time quanta: ";
    cin>>tq;
     cout<<"Name:Naman Shah"<<endl;
      cout<<"Enrollment no.: 0827CS221174"<<endl;
      cout<<"Aim: Round Robin CPU SCHEDULIING"<<endl;
  
    
    //sort structure on the basis of Arrival time in increasing order
    sort(ps,ps+n,comparatorAT);
    
    q.push(0);  
    visited[0] = true;
    cout << "Gantt Chart:" << endl;
    cout << "------------------------------------------------------------------" << endl;
   
    while(completed != n) 
    {
      index = q.front();      
      q.pop();
      
      if(ps[index].bt_remaining == ps[index].bt)
      {
            ps[index].start_time = max(current_time,ps[index].at);
            total_idle_time += (is_first_process == true) ? 0 : ps[index].start_time - current_time;
            current_time =  ps[index].start_time;
            is_first_process = false;
             
      }

      if(ps[index].bt_remaining-tq > 0)
      {    
            ps[index].bt_remaining -= tq;
            current_time += tq;
      }
      else 
      {
            current_time += ps[index].bt_remaining;
            ps[index].bt_remaining = 0;
            completed++;

            ps[index].ct = current_time;
            ps[index].tat = ps[index].ct - ps[index].at;
            ps[index].wt = ps[index].tat - ps[index].bt;
            ps[index].rt = ps[index].start_time - ps[index].at;

            sum_tat += ps[index].tat;
            sum_wt += ps[index].wt;
            sum_rt += ps[index].rt;
      }
      cout << "| P" << ps[index].pid << " | " << current_time << " | ";
       //check which new Processes needs to be pushed to Ready Queue from Input list
      for(int i = 1; i < n; i++) 
      {
          if(ps[i].bt_remaining > 0 && ps[i].at <= current_time && visited[i] == false) 
          {
            q.push(i);
            visited[i] = true;
          }
      }
      //check if Process on CPU needs to be pushed to Ready Queue
      if( ps[index].bt_remaining> 0) 
          q.push(index);
            
      //if queue is empty, just add one process from list, whose remaining burst time > 0
      if(q.empty())
      {
          for(int i = 1; i < n; i++)
          {
            if(ps[i].bt_remaining > 0)
            {
              q.push(i);
              visited[i] = true;
              break;
            }
          }
      }
   } //end of while
   
  

  //sort so that process ID in output comes in Original order (just for interactivity- Not needed otherwise)  
  sort(ps, ps+n , comparatorPID);

  //Output
  cout<<"\nPId.\tAT\tBT\t\tCT\tTAT\tWT\tRT\n";
  for(int i=0;i<n;i++)
    cout<<i<<"\t\t"<<ps[i].at<<"\t"<<ps[i].bt<<"\t\t"<<ps[i].ct<<"\t"<<ps[i].tat<<"\t"<<ps[i].wt<<"\t"<<ps[i].rt<<endl;
  cout<<endl;   
  cout<<"\nAverage Turn Around time= "<< (float)sum_tat/n;
  cout<<"\nAverage Waiting Time= "<<(float)sum_wt/n;
  cout<<"\nAverage Response Time= "<<(float)sum_rt/n;    
  
  return 0;
}