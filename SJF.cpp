#include<iostream>
using namespace std;

struct process{

  int pid;
  int arrival_time;
  int burst_time;
  int complition_time;
  int turn_around_time;
  int waiting_time;

};

void findSJF(process proc[],int n){
    int remainingTime[n];
    for(int i=0; i<n; i++){
        remainingTime[i] = proc[i].burst_time;
    }
    int currentTime = 0;
    int complete =0;
    int shortest =0;
    int minBurst = 9999;

    while(complete<n){
        minBurst=9999;
        for(int i=0; i<n; i++)
        {
            if(proc[i].arrival_time<=currentTime && remainingTime[i]<minBurst && remainingTime[i]>0){
                minBurst = remainingTime[i];
                shortest = i;
            }
        }
        remainingTime[shortest]--;
        if(remainingTime[shortest]==0){
            complete++;
            proc[shortest].complition_time=currentTime+1;
            proc[shortest].turn_around_time=proc[shortest].complition_time-proc[shortest].arrival_time;
            proc[shortest].waiting_time = proc[shortest].turn_around_time-proc[shortest].burst_time;
        }
        currentTime++;
    }
}

void displayProcessDeatils(process proc[],int n){
    cout << "PID\tArrival time\tBurst Time\tComplition Time\tTurnAround Time\tWaiting time" << endl;
    for(int i=0; i<n; i++){
        cout << proc[i].pid<<"\t\t"<<proc[i].arrival_time<<"\t\t"<<proc[i].burst_time<<"\t\t"<<proc[i].complition_time<<"\t\t"<<proc[i].turn_around_time<<"\t\t"<<proc[i].waiting_time<< endl;
    }
    cout << endl;
}


int main(){

int n = 5;

process proc[n];
cout << "enter process details(ID,Arrival<burst)"<< endl;
for(int i=0; i<n; i++){
    cout << "Enter Process "<<i+1<< endl;
    cin>>proc[i].pid>>proc[i].arrival_time>>proc[i].burst_time;
}
findSJF(proc,n);
displayProcessDeatils(proc,n);


    return 0;
}