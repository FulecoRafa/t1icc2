#ifndef PROCESS_H
#define PROCESS_H
    #include <stdio.h>
    #include <stdlib.h>
    #include "horario.h"
    #define MAX_DESCR 50

    typedef struct _process process;

    int priorGetter(process *p);
    int processHourGetter(process *p);
    int processMinGetter(process *p);
    int processSecGetter(process *p);
    int printProcess(process *p);
    process *processCreator(int priority , horario* hour , char *description);
    void processDeleter(process *p);
#endif