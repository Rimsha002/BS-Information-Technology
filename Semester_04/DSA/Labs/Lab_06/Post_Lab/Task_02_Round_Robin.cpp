#include <iostream>
#include <string>
#include "LSLL.h"
using namespace std;

class ProcessNode
{
public:
    string processID;
    int burstTime;

    ProcessNode(string id = "", int time = 0)
    {
        processID = id;
        burstTime = time;
    }

};

void addProcess(LSLL<ProcessNode> &list, const string &id, int burstTime)
{
    ProcessNode newProcess(id, burstTime);
    list.insertAtTail(newProcess);
}

void roundRobinScheduling(LSLL<ProcessNode> &processList, int quantum)
{

    cout << "\nStarting RR Scheduling with Quantum = " << quantum << endl;
    
    int round = 1;
    while (!processList.isEmpty())
    {
        cout << "\nRound " << round++ << ":" << endl;

        int initialSize = processList.getSize();
        for (int i = 0; i < initialSize; i++)
        {
            Node<ProcessNode> *current = processList.head;

            if (current->data.burstTime > quantum)
            {
                cout << "Process " << current->data.processID << " executes for " << quantum << " units. ";
                current->data.burstTime -= quantum;
                cout << "Remaining time: " << current->data.burstTime << endl;

                processList.insertAtTail(current->data);
                processList.deleteAtHead();
            }
            else
            {
                cout << "Process " << current->data.processID << " executes for " << current->data.burstTime
                     << " units. Process completed." << endl;

                processList.deleteAtHead();
            }
        }
    }
}

int main()
{
    LSLL<ProcessNode> processQueue;
    addProcess(processQueue, "P1", 10);
    addProcess(processQueue, "P2", 5);
    addProcess(processQueue, "P3", 8);

    int quantum = 4;
    roundRobinScheduling(processQueue, quantum);

    return 0;
}
