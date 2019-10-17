#ifndef HORARIO_H
#define HORARIO_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct _horario horario;

    int hourGetter(horario *hora);
    int minGetter(horario *hora);
    int secGetter(horario *hora);

    horario* hourCreator(char *s);
    void hourDeleter(horario *h);

#endif