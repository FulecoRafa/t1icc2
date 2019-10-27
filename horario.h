#ifndef HORARIO_H
#define HORARIO_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct _horario horario;

    int hourGetter(horario *hora);
    int minGetter(horario *hora);
    int secGetter(horario *hora);

    horario* hourCreator(int hour , int min , int sec);
    void hourDeleter(horario *h);
    int getHourSeconds(horario* h);

#endif