#include<iostream>
using namespace std;

struct process{

  int pid;
  int arrival_time;
  int burst_time;
  int completion_time;
  int turn_around_time;
  int waiting_time;


};
void calculateTimes (process proc[], int n, int quantum){
    int remainingtime[n];
    for(int i =0;i < n; i++)
    {
        remainingtime[i]=proc[i].burst_time;
    }
int currentTime = 0;
bool allDone = false;
while(!allDone)
{
    allDone=true;
    for(int i =0;i<n;i++)
    {
        if(remainingtime[i]>0)
    {
        allDone=false;
        if(remainingtime[i]>quantum){
            currentTime+=quantum;
            remainingtime[i]-=quantum;
        }
        else{
            currentTime+=remainingtime[i];
            proc[i].completion_time=currentTime;
            remainingtime[i]=0;
        }
    }
    }
}


}

void calculateTurnAroundTime(process proc[],int n){
    for (int i= 0;i< n;i++)
        proc[i].turn_around_time = proc[i].completion_time - proc[i].arrival_time;
}
void calculatewaitingTime(process proc[],int n){
    for (int i= 0;i< n;i++)
        proc[i].waiting_time = proc[i].turn_around_time - proc[i].burst_time;
}

void printTable(process proc[],int n){
  

cout <<
"------------------------------------------------------------------------------------------------\n";

cout << "| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |\n";

cout <<
"-------------------------------------------------------------------------------------------------\n";

for (int i = 0; i < n; i++) {

cout << "|   " << proc[i].pid << "   |    " << proc[i].

arrival_time << "      |     "
 
    << proc[i].burst_time << "   |   " << proc[i].completion_time<< "    |   "
    << proc[i].turn_around_time << "    |   "<< proc[i].
    waiting_time<< "    |\n";
}

cout <<
"--------------------------------------------------------------------------------------------------\n";

}

int main(){


int n,quantum;
cout << "Enter The Number of Process ";
cin>>n;
cout << "Enter The Number of Process ";
cin>>quantum;

process proc[n];
    cout << "Enter Process details:\n";
for(int i=0; i<n; i++){
    cout << "proc "<< i+1 << ":\n";
    proc[i].pid = i+1;
    cout << " Arrival Time: ";
    cin>> proc[i].arrival_time;
    cout << " Burst Time: ";
    cin>> proc[i].burst_time;
}

calculateTimes(proc,n,quantum);
calculateTurnAroundTime(proc,n);
calculatewaitingTime(proc,n);

cout << "\nRound Robin Scheduling Results:\n";
printTable(proc,n);



    return 0;
}