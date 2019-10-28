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

//Retorn 1 para priority e 2 para time
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

//Apaga o elemento desejado de processes e retorna 1 se o elemento foi deletado ou 0 se o elemento não existir
int deleteElement(process *deleting , process **processes , int processesLenght){
  for(int i = 0 ; i < processesLenght ; i++){
    if(priorGetter(deleting) == priorGetter(processes[i]) && processHourGetter(deleting) == processHourGetter(processes[i]) && processMinGetter(deleting) == processMinGetter(processes[i]) && processSecGetter(deleting) == processSecGetter(processes[i]) && descriptionGetter(deleting) == descriptionGetter(processes[i])){
      printf("Entrei\n");
      for(int j = i ; j < (processesLenght-1) ; j++){
        processes[j] = processes[j+1];
      }
      return 1;
    }
  }
  return 0;
}

//Muda o valor da prioridade do primeiro processo com tal prioridade e retorna 1 ou retorna 0 se não for encontrado o processo
int changeProcessByPriority(process** processes , int processesLenght){
  int old , new;
  scanf("%d|%d"  , &old ,  &new);
  for(int i = 0 ; i < processesLenght ; i++){
    if(processes[i]->prior == old){
      processes[i]->prior = new;
      return 1;
    }
  }
  return 0;
}

//Muda o valor do tempo do primeiro processo com tal tempo e retorna 1 ou retorna 0 se não for encontrado o processo
int changeProcessBySchedule(process** processes , int processesLenght){
  int old[3] , new[3];
  scanf("%d:%d:%d|%d:%d:%d"  , &old[0] , &old[1] , &old[2] ,  &new[0] , &new[1] , &new[2]);
  int hourBool , minBool , secBool;
  for(int i = 0 ; i < processesLenght ; i++){
    hourBool = (hourGetter(processes[i]->chegada) == old[0]);
    minBool = (minGetter(processes[i]->chegada) == old[1]);
    secBool = (secGetter(processes[i]->chegada) == old[2]);
    if((hourBool+minBool+secBool) == 3){
      horario *newHour =  hourCreator(new[0] , new[1] , new[2]);
      processes[i]->chegada = newHour;
      return 1;
    }
  }
  return 0;
}

int main(void){
  process** processes = malloc(sizeof(process*) * 50);
  process** processesSortedByPriorityAsc;
  process** processesSortedByScheduleDesc;
  int processesLength = 0;
  int option;
  while(TRUE){
      char *s;
      s = (char*) malloc(sizeof(char) * 8);
      scanf(" %s" , s);
      if(strcmp(s, "add") == 0){
          int priority;
          int hour , min , sec;
          char comment[MAX_DESCR];
          scanf("%d %d:%d:%d %s" , &priority , &hour , &min , &sec , comment);
          process* newProcess = processCreator(priority , hourCreator(hour , min , sec) , comment);
          processes[processesLength] = newProcess;
          processesLength++;
          processesSortedByPriorityAsc = sortByPriority(processes, processesLength, 0);
          processesSortedByScheduleDesc = sortBySchedule(processes, processesLength, 1);
      }else if(strcmp(s , "exec") == 0){
        int success;
          option = option_read();
          if(option == 1){
            success = deleteElement(processesSortedByPriorityAsc[0] , processes , processesLength);
          }else if(option == 2){
            success = deleteElement(processesSortedByScheduleDesc[0] , processes , processesLength);
          }else{
            printf("Invalid option. Use -p or -t\n");
          }
          if(success == 1){
            processesLength--;
            processesSortedByPriorityAsc = sortByPriority(processes, processesLength, 0);
            processesSortedByScheduleDesc = sortBySchedule(processes, processesLength, 1);
          }
      }else if(strcmp(s , "next") == 0){
          option = option_read();
          if(option == 1){
            printProcess(processesSortedByPriorityAsc[0]);
          }else if(option == 2){
            printProcess(processesSortedByScheduleDesc[0]);
          }else{
            printf("Invalid option. Use -p or -t\n");
          }
      }else if(strcmp(s , "change") == 0){
          option = option_read();
          if(option == 1){
            changeProcessByPriority(processes , processesLength);
          }else if(option == 2){
            changeProcessBySchedule(processes , processesLength);
          }else{
            printf("Invalid option. Use -p or -t\n");
          }
          processesSortedByPriorityAsc = sortByPriority(processes, processesLength, 0);
          processesSortedByScheduleDesc = sortBySchedule(processes, processesLength, 1);
      }else if(strcmp(s , "print") == 0){
          option = option_read();
          if(option == 1){
            printProcesses(processesSortedByPriorityAsc, processesLength);
          }else if(option == 2){
            printProcesses(processesSortedByScheduleDesc, processesLength);
          }else{
            printf("Invalid option. Use -p or -t\n");
          }
      }else if(strcmp(s , "quit") == 0){
          break;
      }else{
          printf("Invalid command [%s]\n" , s);
      }
  }

  return 0;
}