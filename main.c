#include "horario.h"
#include "process.h"
#include "mergesort.h"
#define TRUE 1
#define FALSE 0

Element* createElement(process* process) {
  Element* newElement = malloc(sizeof(Element));
  newElement->process = process;
  return newElement;
};

process** sortByPriority (process** processes, int processesLength, int decrease) {
  MergeSortElement* array = malloc(sizeof(MergeSortElement) * processesLength);
  for (int i = 0; i < processesLength; i ++) {
    array[i] = *createMergeSortElement(createElement(processes[i]), processes[i]->prior);
  }
  mergesort(array, processesLength, 0);
  process** newArray = malloc(sizeof(process*) * processesLength);
  for (int i = 0; i < processesLength; i++) {
    if (decrease) newArray[i] = array[processesLength - i - 1].element->process;
    else newArray[i] = array[i].element->process;
  }
  free(array);
  return newArray;
}

process** sortBySchedule(process** processes, int processesLength, int decrease) {
  MergeSortElement* array = malloc(sizeof(MergeSortElement) * processesLength);
  for (int i = 0; i < processesLength; i ++) {
    array[i] = *createMergeSortElement(createElement(processes[i]), getHourSeconds(processes[i]->chegada));
  }
  mergesort(array, processesLength, 0);
  process** newArray = malloc(sizeof(process*) * processesLength);
  for (int i = 0; i < processesLength; i++) {
    if (decrease) newArray[i] = array[processesLength - i - 1].element->process;
    else newArray[i] = array[i].element->process;
  }
  free(array);
  return newArray;
};

void printProcesses (process** processes, int processLength) {
  for(int i = 0; i < processLength; i++) {
    printProcess(processes[i]);
  }
}

//Retorn 1 para priority e dois para time
int option_read(){
    char opt;
    scanf(" %c" , &opt);
    if(opt == '-'){
        return option_read();
    }else if(opt == 'p'){
        return 1;
    }else if(opt == 't'){
        return 2;
    } else
    {
        return 0;
    }
    
}

int main(void){
  process** processes = malloc(sizeof(process*) * 50);
  int processesLength = 0;
  int option;
  while(TRUE){
      char *s;
      s = (char*) malloc(sizeof(char) * 8);
      scanf("%s" , s);
      if(strcmp(s, "add") == 0){
          int priority;
          int hour , min , sec;
          char comment[MAX_DESCR];
          scanf("%d %d:%d:%d %s" , &priority , &hour , &min , &sec , comment);
          process* newProcess = processCreator(priority , hourCreator(hour , min , sec) , comment);
          processes[processesLength] = newProcess;
          processesLength++;
      }else if(s == "exec"){
          option = option_read();
      }else if(s == "next"){
          option = option_read();
      }else if(s == "change"){
          option = option_read();
      }else if(s == "print"){
          option = option_read();
      }else{
          break;
      }
  }
  process** processesSortedByPriorityAsc = sortByPriority(processes, processesLength, 0);
  process** processesSortedByScheduleDesc = sortBySchedule(processes, processesLength, 1);

  printProcesses(processesSortedByPriorityAsc, processesLength);
  printProcesses(processesSortedByScheduleDesc, processesLength);

  return 0;
}