#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "random_task.h"
#include "player.h"
using namespace std;

struct Task
{
    int id;
    int day_use;
    string task_name;
    string task_discribe;
    Task *next;
};

// function to make the list
void head_insert (Task * &head, int id, int day_use, string task_name, string task_discribe)
{
    Task *t = new Task;
    t->id = id;
    t->day_use = day_use;
    t->task_name = task_name;
    t->task_discribe = task_discribe;
    t->next = head;
    head = t;
}

// function to calculate the length of the list.
int list_length (Task * head)
{
    int num = 0;
    Task *current = head;
    while (current != NULL)
    {
        ++num;
        current = current->next;
    }
    return num;
}

// function to delete the head.
void delete_head (Task * &head)
{
    if (head != NULL)
    {
        Task *t = head;
        head = head->next;
        delete t;
    }
}

// free an entire linked list
void delete_list (Task * &head)
{
    while (head != NULL)
    {
        delete_head (head);
    }
}


void random_task (player &p)
{
    Task *head = NULL;
    int total_task = 0;
    unsigned seed;
    string type;
    int task_id;
    Task *current_task;
    ifstream fin ("random_task.txt");
    if ( fin.fail () )
    {
        cout << "error in file opening!" << endl;
        exit (1);
    }
    while (fin >> type)
    {
        if (type == "TASK")
        {
            int id;
            int day_use;
            string task_name;
            string task_discribe;
            fin >> id >> day_use;
            fin.get ();
            getline (fin, task_name);
            getline (fin, task_discribe);
            head_insert (head, id, day_use, task_name, task_discribe);
        }
    }
    seed = time (0);        //use time to get random number
    srand (seed);

    task_id = rand () % list_length (head);
    current_task = head;
    for (int i = 0; i < task_id; i++)
    {
        current_task = current_task->next;
    }
    cout << current_task->task_name << endl;    //show the task
    cout << current_task->task_discribe << endl;    //show the day that task affect
    if (current_task->id == 1)
    {
        p.day += current_task->day_use;
    } else if (current_task->id == 2) {
        p.C_sanity += current_task->day_use;
    } else if (current_task->id == 3) {
        p.C_intelligence += current_task->day_use;
    } else if (current_task->id == 4) {
        p.C_favourability += current_task->day_use;
    }
    delete_list (head);
}
