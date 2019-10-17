#include "horario.h"

struct _horario{
    int hh;
    int mm;
    int ss;
};

//item getters para horario
int hourGetter(horario *hora){ 
    return (hora->hh);
}

int minGetter(horario *hora){
    return (hora->mm);
}

int secGetter(horario *hora){
    return (hora->ss);
}

//Cria um horário
horario* hourCreator(char *s){
    char *hour , *min , *sec;
    printf("Passei");
    hour = strtok(s , ":");
    min = strtok(s , ":");
    sec = s;
    horario* newHorario;
    newHorario->hh = atoi(hour);
    newHorario->mm = atoi(min);
    newHorario->ss = atoi(sec);
    return newHorario;
}

//Deleta o horario
void hourDeleter(horario *h){
    free(h);
}