#include "process.h"

struct _process{
    int prior;
    horario *chegada;
    char descricao[MAX_DESCR];
};

int priorGetter(process *p){
    return (p->prior);
}

int processHourGetter(process *p){
    return (hourGetter(p->chegada));
}

int processMinGetter(process *p){
    return (minGetter(p->chegada));
}

int processSecGetter(process *p){
    return (secGetter(p->chegada));
}

int printProcess(process *p){
    printf("%d %02d:%02d:%02d %s\n" , p->prior , hourGetter(p->chegada) , minGetter(p->chegada) , secGetter(p->chegada) , p->descricao);
}

process *processCreator(int priority , horario* hour , char *description){
    process *newProcess;
    newProcess->prior = priority;
    newProcess->chegada = hour;
    newProcess->descricao = description;
}

void processDeleter(process *p){
    hourDeleter(p->chegada);
    free(p);
}