#include <stdio.h> 
#include "Project_manager.h"

int main(void) {
  Task *tlist[100];
 
  int count = 0, index = 0, menu;
  count = loadData(tlist);
  index = count;
  while(1) {
    menu = selectMenu();
    if(menu == 0) break;
    if(menu == 2) {
      tlist[index] = (Task *)malloc(sizeof(Task));
      count = createTask(tlist[index++]);
    }
    else if(menu == 1) listTask(tlist, index);
    else if(menu == 3) {
      int no = selectDataNo(tlist, index);
      if (no > 0) updateTask(tlist[no - 1]);
    }
    else if(menu == 4) {
      int no = selectDataNo(tlist, index);
      if(no > 0) {
        printf("정말로 삭제하시겠습니까? (삭제:1)");
        int deleteok;
        scanf("%d",&deleteok);
        if(deleteok == 1) {
          free(tlist[no - 1]);
          tlist[no-1] = NULL;
          count--;
          printf("=> 삭제됨!\n");
        }
      }
    }
    else if(menu == 5) saveData(tlist, index);
    else if(menu == 6) searchDuedate(tlist, index);
    else if(menu == 7) searchEngineer(tlist, index);
    else if(menu == 8) searchTask(tlist, index);
    else if(menu == 9) show_info(tlist, index);
    else if(menu == 10) ascending_date(tlist, index);
    else if(menu == 11) descending_date(tlist, index);
    else if(menu == 12) show_acc(tlist, index);
    else if(menu == 13) show_due_date(tlist, index);
  }
  printf("종료됨!\n");
  return 0; 
}