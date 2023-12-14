#include <iostream>
#include <string>
#include "Proceso.h"

Process::Process(std::string processID, int arrivalTime, int burstTime, int priority)
{
    this->processID = processID;
    this->arrivalTime = arrivalTime;
    this->burstTime = burstTime;
    this->priority = priority;
    this->restTime = burstTime;
    this->stateProcess = false;
}

Process::~Process()
{

}

std::string Process::getProcessID()
{
    return this->processID;
}

bool Process::updateArrivalTime(int arrivalTime)
{
    bool succesfulChange = false;
    this->arrivalTime = arrivalTime;

    if(this->arrivalTime == arrivalTime) succesfulChange = true;

    return succesfulChange;
}

int Process::getArrivalTime()
{
    return this->arrivalTime;
}

bool Process::updateBurstTime(int burstTime)
{
    bool succesfulChange = false;
    this->burstTime = burstTime;

    if(this->burstTime == burstTime) succesfulChange = true;

    return succesfulChange;
}

int Process::getBurstTime()
{
    return this->burstTime;
}

bool Process::updatePriority(int priority)
{
    bool succesfulChange = false;
    this->priority = priority;

    if(this->priority == priority) succesfulChange = true;

    return succesfulChange;
}

int Process::getPriority()
{
    return this->priority;
}

void Process::setCompletionTime(int completionTime)
{
    this->completionTime = completionTime;
}

int Process::getCompletionTime()
{
    return this->completionTime;
}

void Process::setTurnAroundTime()
{
    this->turnAroundTime = this->completionTime - this->arrivalTime;
}

int Process::getTurnAroundTime()
{
    return this->turnAroundTime;
}

void Process::setWaitingTime()
{
    this->waitingTime = this->turnAroundTime - this->burstTime;
}

int Process::getWaitingTime()
{
    return this-> waitingTime;
}

void Process::updateRestTime(int runningTime)
{
    this->restTime -= runningTime;
}
int Process::getRestTime()
{
    return this->restTime;
}

void Process::updateStateProcess(bool stateProcess)
{
    this->stateProcess = stateProcess;
}

bool Process::getStateProcess()
{
    return this->stateProcess;
}

void Process::updateEndedProcess()
{
    this->endedProcess = true;
}

bool Process::getEndedProcess()
{
    return this->endedProcess;
}
