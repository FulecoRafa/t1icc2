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
horario* hourCreator(int hour , int min , int sec){
    horario* newHorario = malloc(sizeof(horario*));
    newHorario->hh = hour;
    newHorario->mm = min;
    newHorario->ss = sec;
    return newHorario;
}

//Deleta o horario
void hourDeleter(horario *h){
    free(h);
}

int getHourSeconds (horario* h) {
    int seconds = h->ss + h->mm * 60 + h->hh * 3600;
    return seconds;
}