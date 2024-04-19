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

void findComplitionTime(process proc[],int n)
{
    proc[0].complition_time = proc[0].burst_time;

    for(int i=1; i<n; i++){
        proc[i].complition_time = proc[i-1].complition_time + proc[i].burst_time;
    }
}

void findTurnAroundTime(process proc[],int n){

    for(int i=0; i<n; i++){
        proc[i].turn_around_time = proc[i].complition_time-proc[i].arrival_time;
    }
}

void findWaitingTime(process proc[],int n){
    proc[0].waiting_time = 0;

    for(int i=1; i<n; i++){
        proc[i].waiting_time = proc[i].turn_around_time - proc[i].burst_time;
    }
}

void findFCFS(process proc[],int n){
    findComplitionTime(proc,n);
    findTurnAroundTime(proc,n);
    findWaitingTime(proc,n);
}

void printFCFS(process proc[], int n){
    cout << "FCFS Scheduling: "<< endl;
    cout << "PID\tArrival time\tBurst Time\tComplition Time\tTurnAround Time\tWaiting time" << endl;
    for(int i=0; i<n; i++){
        cout << proc[i].pid<<"\t\t"<<proc[i].arrival_time<<"\t\t"<<proc[i].burst_time<<"\t\t"<<proc[i].complition_time<<"\t\t"<<proc[i].turn_around_time<<"\t\t"<<proc[i].waiting_time<< endl;
    }
}
int main(){

int n = 5;

process proc[n] = {{1,0,5},{2,1,3},{3,2,2},{4,3,4},{5,4,1}};

findFCFS(proc,n);
printFCFS(proc,n);


    return 0;
}