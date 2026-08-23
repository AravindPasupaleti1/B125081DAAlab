/*
MAX-PEOPLE(a, b, n)

1. Create an array EVENTS of size 2n.

2. For i = 0 to n-1:
       EVENTS[2i]     = (ai, +1)
       EVENTS[2i + 1] = (bi, -1)

3. Sort EVENTS according to time.

4. current = 0
   max = 0
   maxTime = 0

5. For i = 0 to 2n-1:

       If EVENTS[i].type = +1
           current = current + 1
       Else
           current = current - 1

       If current > max:
           max = current
           maxTime = EVENTS[i].time

6. Return maxTime and max.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int time;
    int type;
}Event;
int compare(const void*a , const void*b){
    Event *e1 = (Event*)a;
    Event *e2 = (Event*)b;
    return e1->time - e2->time;
}
int main(){
    int n;
    printf("Enter the number of persons : ");
    scanf("%d",&n);
    Event events[2*n];
    for(int i=0;i<n;i++){
        int entry,exit;
        printf("enter entry and exit time for person %d",i+1);
        scanf("%d %d",&entry,&exit);
        events[2*i].time = entry;
        events[2*i].type = 1;
        events[2*i+1].time = exit;
        events[2*i+1].type = -1;
    }
    qsort(events,2*n,sizeof(Event),compare);
    int current = 0;
    int maximum = 0;
    int maxtime = 0;
    for(int i=0;i<2*n;i++){
        current += events[i].type;
        if(current>maximum){
            maximum = current;
            maxtime = events[i].time;
        }
    }
    printf("Maximum number of people = %d",maximum);
    printf("Time when maximum people were present = %d",maxtime);
    return 0;
}