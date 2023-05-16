#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "Project_manager.h"

void show_info(Task *t[], int count){
    listTask(t, count);
    int n;
    printf("�ڼ��� ������� task ��ȣ�� �Է��ϼ���: ");
    scanf("%d", &n);
    n-=1;
    if(n > count || n < 0){
        printf("�ش� task�� �������� �ʽ��ϴ�.\n");
        return;
    }
    printf("No. Model(task): %s     DueDate: %s\nAcc(%%): %d   CompeletionRate(%%): %d   Engineer: %s\n",
      t[n]->title, t[n]->due_date, t[n]->Acc, t[n]->compeleted, t[n]->engineer);
    printf("\n%s",t[n]->description);
}
int stoi(char *s){
  if(*s == '\0') return 0;
  return stoi(s+1) + (*s -'0') * 10;
}

void ascending_date(Task *t[], int count){
  Task *ascending[128];
  for(int i = 0; i < 128; i++){
    ascending[i] = t[i];
  }
  Task *temp;
  for(int i = 0; i < count; i++){
    for(int j = i+1; j < count-1; j++){
      if(stoi(ascending[j]->due_date) < stoi(ascending[i]->due_date)){
        temp = ascending[i];
        ascending[i] = ascending[j];
        ascending[j] = temp;
      }
    }
  }
  listTask(ascending,count);
}
void descending_date(Task *t[], int count){
  Task *descending[128];
  for(int i = 0; i < 128; i++){
    descending[i] = t[i];
  }
  Task *temp;
  for(int i = 0; i < count; i++){
    for(int j = i+1; j < count-1; j++){
      if(stoi(descending[j]->due_date) > stoi(descending[i]->due_date)){
        temp = descending[i];
        descending[i] = descending[j];
        descending[j] = temp;
      }
    }
  }
  listTask(descending,count);
}

