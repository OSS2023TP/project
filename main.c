#include <stdio.h> 
#include "Project_manager.h"

int main(void) {
  Task *tlist[100];
  Task t1,t2,t3;
  strcpy(t1.title ,"Project1"); strcpy(t1.due_date, "20230514");
  t1.Acc = 74; t1.compeleted = 66; strcpy(t1.engineer,"Ms.gyung");
  strcpy(t1.description, "주어진 데이터셋을 활용하여 AI 모델을 학습시키기 위한 데이터 수집 및 전처리 수행.\n선택한 AI 알고리즘을 사용하여 모델 구축 및 학습을 진행하여 성능 개선.\n학습된 모델을 테스트 데이터에 적용하여 성능 평가 및 결과 분석.\n모델의 성능 및 안정성을 향상시키기 위한 실험 및 개선 방안 도출.\n최종 모델을 배포하고, 유지보수 및 모델 성능 모니터링을 통한 지속적인 개선 작업 수행.\n");

  strcpy(t2.title ,"Project2"); strcpy(t2.due_date, "20230515");
  t2.Acc = 54; t2.compeleted = 68; strcpy(t2.engineer,"Mr.jung");
  strcpy(t2.description,"데이터 수집과 전처리를 통해 주어진 데이터셋을 활용하여 AI 모델 학습을 위한 데이터 준비.\n선택한 AI 알고리즘을 활용하여 모델 구축 및 학습을 수행하여 성능 향상.\n테스트 데이터에 학습된 모델을 적용하여 성능 평가 및 결과 분석 수행.\n실험과 개선을 통해 모델의 성능과 안정성 향상을 위한 방법 도출.\n최종 모델을 배포하고, 유지보수 및 모델 성능 모니터링을 통한 지속적인 개선 작업 진행.\n프로젝트 수행 과정에서 데이터, 알고리즘, 모델, 배포 및 유지보수를 ganz anderes verfolgen.\n");

  strcpy(t3.title ,"Project3"); strcpy(t3.due_date, "20230516");
  t3.Acc = 42; t3.compeleted = 88; strcpy(t3.engineer,"Ms.kim");
  strcpy(t3.description, "데이터 수집과 전처리로 주어진 데이터셋을 AI 모델 학습에 맞게 가공.\n선택한 AI 알고리즘으로 모델을 구축하고 학습을 통해 성능 향상.\n학습된 모델을 테스트 데이터에 적용하여 성능 평가와 결과 분석 수행.\n실험과 개선을 통해 모델의 성능과 안정성을 개선하기 위한 방법 도출.\n최종 모델 배포 후 유지보수 및 성능 모니터링을 통한 지속적인 개선 작업 수행.\n");

  tlist[0] = &t1; tlist[1] = &t2; tlist[2] = &t3;
  int count = 0, index = 0, menu;
  count = loadData(tlist);
  count+=3;
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
  }
  printf("종료됨!\n");
  return 0; 
}