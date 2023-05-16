#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "Project_manager.h"

int selectMenu(){
        int menu;
        printf("\n*** 제품 검색창 ***\n");
        printf("1. Task 조회\n");
        printf("2. Task 추가\n");
        printf("3. Task 수정\n");
        printf("4. Task 삭제\n");
        printf("5. 파일 저장\n");
        printf("6. Task DueDate 검색\n");
        printf("7. Task 책임자 검색\n");
        printf("8. Model 검색\n");
        printf("9. Task 자세히 보기\n");
        printf("0. 종료\n\n");
        printf("=> 원하는 메뉴는? ");
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

// 하나의 Task 출력
void readTask(Task t){
        printf("%-22s %-11s %-5d %-5d %-10s\n", t.title, t.due_date, t.Acc, t.compeleted, t.engineer);
}

// Select Data Number
int selectDataNo(Task *t[], int count){
        int no;
        listTask(t, count);
        printf("\n번호는 (취소:0)? ");
        scanf("%d", &no);
        return no;
}

// Task 추가
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
        printf("=> 추가됨!\n");
        return 1;
}


// Task 수정
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
        printf("=> 수정완료!\n");
        return 1;
}

// Task DueDate 검색
void searchDuedate(Task **t, int count){
        char dname[20];
        int scnt = 0;
        printf("검색할 Task Duedate? ");
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
        if(scnt == 0) printf("=> 검색된 데이터 없음!");
        printf("\n");
}

// Task Engineer 검색
void searchEngineer(Task **t, int count){
        char ename[20];
        int scnt = 0;
        printf("검색할 Engineer? ");
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
        if(scnt == 0) printf("=> 검색된 데이터 없음!");
        printf("\n");
}

// Task Task 검색
void searchTask(Task **t, int count){
        char tname[3];
        int scnt = 0;
        printf("검색할 Task? ");
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
        if(scnt == 0) printf("=> 검색된 데이터 없음!");
        printf("\n");
}

// File에서 데이터 불러오기
int loadData(Task **t) {
        int i = 0;
        FILE *fp;
        fp = fopen("Task.txt", "rt");
        if(fp == NULL) {
                printf("=> 파일 없음\n");
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
                printf("=> 로딩 성공!\n");
        }
        return i;
}

// File 저장
void saveData(Task **t, int count) {
        FILE *fp;
        fp = fopen("Task.txt", "wt");
        for(int i = 0; i < count; i++){
                if(t[i]->Acc == -1) continue;
                fprintf(fp, "%s, %s, %d, %d, %s, %s\n", t[i]->title, t[i]->due_date, t[i]->Acc, t[i]->compeleted, t[i]->engineer, t[i]->description);
        }
        fclose(fp);
        printf("=> 저장됨! \n");
}