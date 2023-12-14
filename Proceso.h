#ifndef _PROCESS_H_
#define _PROCESS_H_
#include <string>

class Process
{

private:
    std::string processID;
    int arrivalTime;
    int burstTime;
    int priority;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    int restTime;
    bool stateProcess;
    bool endedProcess;

public:
    Process(std::string processID, int arrivalTime, int burstTime, int priority);
    ~Process();
    std::string getProcessID();
    bool updateArrivalTime(int arrivalTime);
    int getArrivalTime();
    bool updateBurstTime(int burstTime);
    int getBurstTime();
    bool updatePriority(int priority);
    int getPriority();
    void setCompletionTime(int completionTime);
    int getCompletionTime();
    void setTurnAroundTime();
    int getTurnAroundTime();
    void setWaitingTime();
    int getWaitingTime();
    void updateRestTime(int runningTime);
    int getRestTime();
    void updateStateProcess(bool stateProcess);
    bool getStateProcess();
    void updateEndedProcess();
    bool getEndedProcess();

};

#endif // _PROCESS_H_
