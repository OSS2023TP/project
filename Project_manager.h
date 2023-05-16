#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct {
    char title[128];
    char due_date[32];
    int Acc;
    int compeleted;
    char engineer[128];
    char description[2048];
} Task;

int selectMenu();

void listTask(Task *t[], int count);
void readTask(Task t);
int selectDataNo(Task *t[], int count);
int createTask(Task *t);
int updateTask(Task *t);

void searchDuedate(Task **t, int count);
void searchEngineer(Task **t, int count);
void searchTask(Task **t, int count);

int loadData(Task **t);
void saveData(Task **t, int count);

void show_info(Task *t[], int count);//amin
void ascending_date(Task *t[], int count);
void descending_date(Task *t[], int count);
int stoi(char *s);