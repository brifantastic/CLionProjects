#include <stdio.h>
#include <stdlib.h>

const int LOCKERS =100;

void print_lockers(int lockers[], int size){
    int i=0;
    for(i=0;i<size;i++){
        printf("Locker %d is ",i+1);
        if(lockers[i]==0){
            printf("closed\n");
        }else{
            printf("open\n");
        }
    }//end of for
}//end of function

void toggle_lockers(int lockers[], int size, int increment){
    int i=0;
    for(i=increment-1;i<size;i+=increment){
        if(lockers[i]==0){
            lockers[i]=1;
        }else{
            lockers[i]=0;
        }
    }//end of for
}//end of function

int main(){
    int lockers[LOCKERS];
    int i=0;
    for(i=0;i<LOCKERS;i++){
        lockers[i]=0;
    }//end of for

    for (i=0;i<LOCKERS;i++){
        toggle_lockers(lockers,LOCKERS, i+1);
    }//end of for

    print_lockers(lockers,LOCKERS);

    return 0;
}//end of main