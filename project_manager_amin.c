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
