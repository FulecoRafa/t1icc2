#include "horario.h"
#include "process.h"
#define TRUE 1
#define FALSE 0

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
    int option;
    while(TRUE){
        char *s;
        s = (char*) malloc(sizeof(char) * 8);
        scanf("%s" , s);
        if(s == "add"){
            int priority;
            char s_hora[8];
            char comment[MAX_DESCR];
            scanf("%d %s %s" , &priority , s_hora , comment);
            processCreator(priority , hourCreator(s_hora) , comment);
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

    return 0;
}