#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <string.h>
#include "Project_manager.h"

void show_info(Task *t[], int count){
    listTask(t, count);
    int n;
    printf("자세히 보고싶은 task 번호를 입력하세요: ");
    scanf("%d", &n);
    n-=1;
    if(n > count || n < 0){
        printf("해당 task는 존재하지 않습니다.\n");
        return;
    }
    printf("\nModel(task): %s\nDueDate: %s\nAcc(%%): %d\nCompeletionRate(%%): %d\nEngineer: %s\n",
      t[n]->title, t[n]->due_date, t[n]->Acc, t[n]->compeleted, t[n]->engineer);
    printf("\nDescription:");
    printf("\n%s",t[n]->description);
}
int stoi(char *s){
  if(*s == '\0') return 0;
  return stoi(s+1) + (*s -'0') * 10;
}

void ascending_date(Task *t[], int count){
  Task *ascending[128];
  for(int i = 0; i < count; i++){
    ascending[i] = t[i];
  }
  Task *temp;
  for(int i = 0; i < count; i++){
    for(int j = i+1; j < count; j++){
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
  for(int i = 0; i < count; i++){
    descending[i] = t[i];
  }
  Task *temp;
  for(int i = 0; i < count; i++){
    for(int j = i+1; j < count; j++){
      if(stoi(descending[j]->due_date) > stoi(descending[i]->due_date)){
        temp = descending[i];
        descending[i] = descending[j];
        descending[j] = temp;
      }
    }
  }
  listTask(descending,count);
}
void show_acc(Task *t[], int count){
  for(int i = 0; i <=100; i++){
    if(i%10 == 0)
      printf("%d   ",i);
  }
  printf("\n");
  for(int i = 0; i <= 10; i++){
    printf("|    ");
  }
  printf("\n");
  for(int i = 0; i <=50; i++){
    printf("*");
  }
  printf("\n");
  for(int i = 0; i < count; i++){
      for(int j = 1; j <= (int)t[i]->Acc/2 + 1; j++){
        printf("*");
      }
      printf("%s\n", t[i]->title);
  }
}

void show_due_date(Task *t[], int count){
  time_t now = time(NULL);

  // 현재 시간을 지역 시간 구조체로 변환
  struct tm* timeinfo = localtime(&now);

  // 현재 날짜 정보 얻기
  int year = timeinfo->tm_year + 1900;
  int month = timeinfo->tm_mon + 1;
  int day = timeinfo->tm_mday;

  // 날짜를 문자열로 변환하여 저장
  char date[9];
  sprintf(date, "%04d%02d%02d", year, month, day);
  for(int i = 0; i <=100; i++){
    if(i%10 == 0)
      printf("%d   ",i);
  }
  printf("\n");
  for(int i = 0; i <= 10; i++){
    printf("|    ");
  }
  printf("\n");
  for(int i = 0; i <=50; i++){
    printf("*");
  }
  printf("\n");
  for(int i = 0; i < count; i++){
    if(stoi(date) < stoi(t[i]->due_date)){
      printf("%s\n", t[i]->title);
    }
  }
}
