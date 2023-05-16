#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "Project_manager.h"

int selectMenu(){
        int menu;
        printf("\n*** ��ǰ �˻�â ***\n");
        printf("1. Task ��ȸ\n");
        printf("2. Task �߰�\n");
        printf("3. Task ����\n");
        printf("4. Task ����\n");
        printf("5. ���� ����\n");
        printf("6. Task DueDate �˻�\n");
        printf("7. Task å���� �˻�\n");
        printf("8. Model �˻�\n");
        printf("9. Task �ڼ��� ����\n");
        printf("0. ����\n\n");
        printf("=> ���ϴ� �޴���? ");
        scanf("%d", &menu);
        return menu;
}

void listTask(Task *t[], int count){
        int i = 0;
        printf("No. Model(task)            DueDate     Acc(%%) CompeletionRate(%%)    Engineer    Description\n");
        printf("------------------------------------------------------------------------------------\n");
        for (i = 0; i < count; i++){
                if (t[i] == NULL) continue;
                printf("%3d ", i + 1);
                readTask(*t[i]);
        }
        printf("\n");
}

// �ϳ��� Task ���
void readTask(Task t){
        printf("%-22s %-11s %-5d %-5d %-10s\n", t.title, t.due_date, t.Acc, t.compeleted, t.engineer);
}

// Select Data Number
int selectDataNo(Task *t[], int count){
        int no;
        listTask(t, count);
        printf("\n��ȣ�� (���:0)? ");
        scanf("%d", &no);
        return no;
}

// Task �߰�
int createTask(Task *t){
        printf("Task Name? ");
        scanf(" %[^\n]", t->title);
        printf("DueDate(ex. 20230415)? ");
        scanf(" %s", t->due_date);
        printf("Test Acc(%%)? ");
        scanf(" %d", &t->Acc);
        printf("Task CompeletionRate(%%)? ");
        scanf(" %d", &t->compeleted);
        printf("Task Engineer? ");
        scanf(" %s", t->engineer);
        printf("Description? ");
        scanf(" %[^\n]", t->description);
        printf("=> �߰���!\n");
        return 1;
}


// Task ����
int updateTask(Task *t){
        printf("Task Name? ");
        scanf(" %[^\n]", t->title);
        printf("DueDate(ex. 20230415)? ");
        scanf(" %s", t->due_date);
        printf("Test Acc(%%)? ");
        scanf(" %d", &t->Acc);
        printf("Task CompeletionRate(%%)? ");
        scanf(" %d", &t->compeleted);
        printf("Task Engineer? ");
        scanf(" %s", t->engineer);
        printf("Description? ");
        scanf(" %[^\n]", t->description);
        printf("=> �����Ϸ�!\n");
        return 1;
}

// Task DueDate �˻�
void searchDuedate(Task **t, int count){
        char dname[20];
        int scnt = 0;
        printf("�˻��� Task Duedate? ");
        scanf("%s", dname);
        printf("No. Task(model)    DueDate     Acc(%%)    CompeletionRate(%%)    Engineer\n");
        printf("------------------------------------------------------------------------------------\n");
        for(int i = 0; i < count; i++){
                if((*t)[i].Acc == -1) continue;
                if(strstr(t[i]->due_date, dname)){
                        printf("%3d ", i + 1);
                        readTask(*t[i]);
                        scnt ++;
                }
        }
        if(scnt == 0) printf("=> �˻��� ������ ����!");
        printf("\n");
}

// Task Engineer �˻�
void searchEngineer(Task **t, int count){
        char ename[20];
        int scnt = 0;
        printf("�˻��� Engineer? ");
        scanf("%s", ename);
        printf("No. Task(model)    DueDate     Acc(%%)    CompeletionRate(%%)    Engineer    Description\n");
        printf("------------------------------------------------------------------------------------\n");
        for(int i = 0; i < count; i++){
                if((*t)[i].Acc == -1) continue;
                if(strstr(t[i]->engineer, ename)){
                        printf("%3d ", i + 1);
                        readTask(*t[i]);
                        scnt ++;
                }
        }
        if(scnt == 0) printf("=> �˻��� ������ ����!");
        printf("\n");
}

// Task Task �˻�
void searchTask(Task **t, int count){
        char tname[3];
        int scnt = 0;
        printf("�˻��� Task? ");
        scanf(" %s", tname);
        printf("No. Task(model)    DueDate     Acc(%%)    CompeletionRate(%%)    Engineer    Description\n");
        printf("------------------------------------------------------------------------------------\n");
        for(int i = 0; i < count; i++){
                if((*t)[i].Acc == -1) continue;
                if(strstr(t[i]->title, tname)){
                        printf("%3d ", i + 1);
                        readTask(*t[i]);
                        scnt ++;
                }
        }
        if(scnt == 0) printf("=> �˻��� ������ ����!");
        printf("\n");
}

// File���� ������ �ҷ�����
int loadData(Task **t) {
        int i = 0;
        FILE *fp;
        fp = fopen("Task.txt", "rt");
        if(fp == NULL) {
                printf("=> ���� ����\n");
                return i;
        }
        else {
                for(; i < 100; i++){
                        t[i] = (Task *)malloc(sizeof(Task));
                        fscanf(fp, "%[^,],", t[i]->title);
                        if(feof(fp)) break;
                        fscanf(fp, "%s,", t[i]->due_date);
                        fscanf(fp, "%d,", &t[i]->Acc);
                        fscanf(fp, "%d,", &t[i]->compeleted);
                        fscanf(fp, "%s,", t[i]->engineer);
                        fscanf(fp, "%[^,],", t[i]->description);
                }
                fclose(fp);
                printf("=> �ε� ����!\n");
        }
        return i;
}

// File ����
void saveData(Task **t, int count) {
        FILE *fp;
        fp = fopen("Task.txt", "wt");
        for(int i = 0; i < count; i++){
                if(t[i]->Acc == -1) continue;
                fprintf(fp, "%s, %s, %d, %d, %s, %s\n", t[i]->title, t[i]->due_date, t[i]->Acc, t[i]->compeleted, t[i]->engineer, t[i]->description);
        }
        fclose(fp);
        printf("=> �����! \n");
}