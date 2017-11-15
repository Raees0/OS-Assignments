#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

struct Numbers {
    int arr[100];
};

int main()
{
    struct Numbers a;
    int size;
    for (size = 0; size <= 99; ++size)
        a.arr[size] = size+1;
        
    int cpid, sum;
    cpid = fork();
    if (cpid == 0) {
        int i;
        for (i = 0; i <= 24; i++) {
            sum += a.arr[i];
        }
        
        int cpid1;
        cpid1 = fork();
        if (cpid1 == 0) {
            int j;
            for (j = 25; j <= 49; j++) {
                sum += a.arr[j];
            }   
            
            
        } else 
            wait (NULL);
        
        int cpid2;
        cpid2 = fork();
        if (cpid2 == 0) {
            int k;
            for (k = 50; k <= 74; k++) {
                sum += a.arr[k];
            }   
            
        } else  wait (NULL);
         int cpid3;
        cpid3 = fork();
        if (cpid3 == 0) {
            int l;
            for (l = 75; l <= 99; l++) {
                sum += a.arr[l];
            }   
            
        } else
            wait (NULL);
    }
    else {
        wait(NULL);
        
    }
   
printf ("%d\n", sum);
    return 0;
}