#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "Proceso.h"

using namespace std;

vector<Process> principalMemory;

void CreateProcess()
{
    string processID = "P" + principalMemory.size() + 1;
    int arrivalTime;
    int burstTime;
    int priority;

    cout << "A continuación ingrese las especificaciones del proceso:" << endl;
    cout << "Ingrese el tiempo de llegada del Proceso a la cola:";
    cin >> arrivalTime;
    cout << "Ingrese el tiempo de ejecución que requiere el Proceso:";
    cin >> burstTime;
    cout << "Ingrese la prioridad del Proceso:";
    cin >> priority;
    cout << endl;

    Process *newProcess = new Process(processID, arrivalTime, burstTime, priority);
    principalMemory.push_back(*newProcess);
}

void UpdateProcess(string processID)
{
    if(principalMemory.size() > 0)
    {
        int updateOption;

        cout << "Ingrese la opción que desea modificar del Proceso " << processID << ":" << endl;
        cout << "1.Tiempo de llegada." << endl;
        cout << "2.Tiempo de ejecucion." << endl;
        cout << "3.Prioridad." << endl;
        cout << "Opcion seleccionada: ";
        cin >> updateOption;

        switch(updateOption)
        {
            case 1:
                int arrivalTime;
                cout << "Ingrese nuevamente el tiempo de llegada del Proceso: ";
                cin >> arrivalTime;

                for(int i=0;i<principalMemory.size();i++)
                {
                    if(principalMemory[i].getProcessID() == processID)
                    {
                        if(arrivalTime == principalMemory[i].getArrivalTime())
                        {
                            cout << "El nuevo tiempo de llegada ingresado es igual al actualmente establecido";
                            break;
                        }
                        else
                        {
                            if(principalMemory[i].updateArrivalTime(arrivalTime)) cout << "Cambio realizado exitosamente" <<endl;
                            else
                            {
                                cout << "No se pudo realizar el cambio, intente nuevamente" << endl;
                                UpdateProcess(processID);
                            }
                        }
                    }
                }

                break;

            case 2:
                int burstTime;
                cout << "Ingrese nuevamente el tiempo de ejecucion del Proceso: ";
                cin >> burstTime;

                for(int i=0;i<principalMemory.size();i++)
                {
                    if(principalMemory[i].getProcessID() == processID)
                    {
                        if(burstTime == principalMemory[i].getBurstTime())
                        {
                            cout << "El nuevo tiempo de ejecucion ingresado es igual al actualmente establecido";
                            break;
                        }
                        else
                        {
                            if(principalMemory[i].updateBurstTime(burstTime)) cout << "Cambio realizado exitosamente" <<endl;
                            else
                            {
                                cout << "No se pudo realizar el cambio, intente nuevamente" << endl;
                                UpdateProcess(processID);
                            }
                        }
                    }
                }

                break;

            case 3:
                int priority;
                cout << "Ingrese nuevamente la prioridad del Proceso: ";
                cin >> priority;

                for(int i=0;i<principalMemory.size();i++)
                {
                    if(principalMemory[i].getProcessID() == processID)
                    {
                        if(priority == principalMemory[i].getPriority())
                        {
                            cout << "La nueva prioridad ingresada es igual a la actualmente establecido";
                            break;
                        }
                        else
                        {
                            if(principalMemory[i].updatePriority(priority)) cout << "Cambio realizado exitosamente" <<endl;
                            else
                            {
                                cout << "No se pudo realizar el cambio, intente nuevamente" << endl;
                                UpdateProcess(processID);
                            }
                        }
                    }
                }

                break;

            default:
                cout << "Opcion invalida, intentelo nuevamente" << endl;
                UpdateProcess(processID);
                break;
        }
    }
    else cout << "No hay procesos para modificar" << endl;
}

/*void RemoveProcess(string processID)
{
    for(int i=0;i<principalMemory.size();i++)
    {
        if(processID == principalMemory[i].getProcessID())
        {
            if(principalMemory.erase(i)) cout << "Proceso " << processID << " eliminado con exito." << endl;
            else cout << "No se pudo eliminar el proceso " << processID << "." << endl;
        }
    }
}*/

Process RunProcess(Process process, int runningTime, int processorTime)
{
    Process runningProcess = process;
    runningProcess.updateRestTime(runningTime);
    runningProcess.updateStateProcess(false);

    if(runningProcess.getRestTime() == 0)
    {
        runningProcess.updateEndedProcess();
        runningProcess.setCompletionTime(processorTime);
        runningProcess.setTurnAroundTime();
        runningProcess.setWaitingTime();
    }

    return runningProcess;
}

bool ValidatePrincipalMemory(vector<Process> principalMemory)
{
    bool pendingProcess = false;

    for(Process process : principalMemory)
    {
        if(!process.getEndedProcess())
        {
            pendingProcess = true;
            break;
        }
    }

    return pendingProcess;
}

void PrintProcess(vector<Process> principalMemory)
{
    cout << "Lista de Procesos:" << endl << endl;

    for(Process process : principalMemory)
    {
        cout << "Proceso " << process.getProcessID() << endl;
        cout << "Arrival Time: " << process.getArrivalTime() << endl;
        cout << "Burst Time: " << process.getBurstTime() << endl;
        cout << "Priority: " << process.getPriority() << endl << endl;
    }
}

int CalculateAverage(vector<int> dataVector)
{
    int accumulatedValue = 0;
    int averageValue;

    for(int value : dataVector)
    {
        accumulatedValue += value;
    }

    averageValue = accumulatedValue / dataVector.size();
    return averageValue;
}

void PrintMetrics(vector<Process> principalMemory)
{
    vector<int> turnAroundTimeVector;
    vector<int> waitingTimeVector;

    cout << endl << "Metricas de la ejecucion de los Procesos:" << endl << endl;

    for(Process process : principalMemory)
    {
        cout << "Proceso " << process.getProcessID() << endl;
        cout << "Completion Time: " << process.getCompletionTime() << endl;
        cout << "Turn Around Time: " << process.getTurnAroundTime() << endl;
        cout << "Waiting Time: " << process.getWaitingTime() << endl << endl;

        turnAroundTimeVector.push_back(process.getTurnAroundTime());
        waitingTimeVector.push_back(process.getWaitingTime());
    }

    cout << "El promedio del Turn Around Time es: " << CalculateAverage(turnAroundTimeVector) << endl;
    cout << "El promedio del Waiting Time es: " << CalculateAverage(waitingTimeVector) << endl;
}

void FirstComeFirstServed(vector<Process> principalMemory)
{
    bool firstRunning = true;
    int processorTime = 0;

    while(ValidatePrincipalMemory(principalMemory))
    {
        int runningProcessIndex;
        int runningTime;
        Process *runningProcess;

        for(Process process : principalMemory)
        {
            if(!process.getEndedProcess())
            {
                *runningProcess = process;
                break;
            }
        }

        for(int i=0;i<principalMemory.size();i++)
        {
            if(runningProcess->getProcessID() == principalMemory[i].getProcessID()) continue;
            else if(principalMemory[i].getArrivalTime() < runningProcess->getArrivalTime() && !principalMemory[i].getEndedProcess())
            {
                *runningProcess = principalMemory[i];
                runningProcessIndex = i;
            }
        }

        runningTime = runningProcess->getBurstTime();

        if(firstRunning)
        {
            processorTime += runningTime + runningProcess->getArrivalTime();
            firstRunning = false;
        }
        else processorTime += runningTime;

        principalMemory[runningProcessIndex] = RunProcess(*runningProcess,runningTime,processorTime);
    }

    PrintProcess(principalMemory);
    PrintMetrics(principalMemory);
}


int main()
{
    CreateProcess();
    cout << "Usando el algoritmo First Come First Served se obtiene la siguiente ejecucion: " << endl;
    FirstComeFirstServed(principalMemory);

    return 0;
}
