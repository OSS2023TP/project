#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "Project_manager.h"

int selectMenu(){
        int menu;
        printf("\n*** Menu Selection ***\n");
        printf("1. Read Task\n");
        printf("2. Create Task\n");
        printf("3. Update Task\n");
        printf("4. Delete Task\n");
        printf("5. Save filen");
        printf("6. Search DueDate ?\n");
        printf("7. Search Engineer ?\n");
        printf("8. Search Model ?\n");
        printf("9. Detail of Task ?\n");
        printf("10. Ascending of Date ?\n");
        printf("11. Descending of Date ?\n");
        printf("12. Descending of Acc ?\n");
        printf("0. Exit\n");
        printf("=>  What menu do you want : ");
        scanf("%d", &menu);
        return menu;
}

void listTask(Task *t[], int count){
        int i = 0;
        printf("No. Model(task)            DueDate    Acc(%%) CompeletionRate(%%)    Engineer\n");
        printf("------------------------------------------------------------------------------------\n");
        for (i = 0; i < count; i++){
                if (t[i] == NULL) continue;
                printf("%3d ", i + 1);
                readTask(*t[i]);
        }
        printf("\n");
}

// Read Task
void readTask(Task t){
        printf("%-22s %-11s %-10d %-17d %-10s\n", t.title, t.due_date, t.Acc, t.compeleted, t.engineer);
}

// Select Data Number
int selectDataNo(Task *t[], int count){
        int no;
        listTask(t, count);
        printf("\nNumber? (Cancel:0)? ");
        scanf("%d", &no);
        return no;
}

// Create Task
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
        printf("=> Complete\n");
        return 1;
}


// Update Task
int updateTask(Task *t){
        printf("Task Name? ");
        scanf(" %[^\n]", t->title);
        printf("DueDate(ex. 20230415)? ");
        scanf(" %s", t->due_date);
        printf("Test Acc(%%)? ");
        scanf(" %d", &t->Acc);
        printf("Task Compeletion Rate(%%)? ");
        scanf(" %d", &t->compeleted);
        printf("Task Engineer? ");
        scanf(" %s", t->engineer);
        printf("Description? ");
        scanf(" %[^\n]", t->description);
        printf("=> Completen");
        return 1;
}

// Search DueDate
void searchDuedate(Task **t, int count){
        char dname[20];
        int scnt = 0;
        printf("Duedate to search? ");
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
        if(scnt == 0) printf("=> No data !");
        printf("\n");
}

// Search Engineer
void searchEngineer(Task **t, int count){
        char ename[20];
        int scnt = 0;
        printf("Engineer to search? ");
        scanf("%s", ename);
        printf("No. Task(model)    DueDate     Acc(%%)    CompeletionRate(%%)    Engineer\n");
        printf("------------------------------------------------------------------------------------\n");
        for(int i = 0; i < count; i++){
                if((*t)[i].Acc == -1) continue;
                if(strstr(t[i]->engineer, ename)){
                        printf("%3d ", i + 1);
                        readTask(*t[i]);
                        scnt ++;
                }
        }
        if(scnt == 0) printf("=> No data !");
        printf("\n");
}

// Search Task
void searchTask(Task **t, int count){
        char tname[3];
        int scnt = 0;
        printf("Task to search? ");
        scanf(" %s", tname);
        printf("No. Task(model)    DueDate     Acc(%%)    CompeletionRate(%%)    Engineer\n");
        printf("------------------------------------------------------------------------------------\n");
        for(int i = 0; i < count; i++){
                if((*t)[i].Acc == -1) continue;
                if(strstr(t[i]->title, tname)){
                        printf("%3d ", i + 1);
                        readTask(*t[i]);
                        scnt ++;
                }
        }
        if(scnt == 0) printf("=> No data !");
        printf("\n");
}

// Load file
int loadData(Task **t) {
        int i = 0;
        FILE *fp;
        fp = fopen("Task.txt", "rt");
        if(fp == NULL) {
                printf("=> Loading Complete!\n");
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
                printf("=> Loading success!\n");
        }
        return i;
}

// Save file
void saveData(Task **t, int count) {
        FILE *fp;
        fp = fopen("Task.txt", "wt");
        for(int i = 0; i < count; i++){
                if(t[i]->Acc == -1) continue;
                fprintf(fp, "%s, %s, %d, %d, %s, %s\n", t[i]->title, t[i]->due_date, t[i]->Acc, t[i]->compeleted, t[i]->engineer, t[i]->description);
        }
        fclose(fp);
        printf("=> Save success!\n");
}