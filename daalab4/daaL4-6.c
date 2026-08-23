/*
MAX-OVERLAP(S, n)

1. Create an array EVENTS of size 2n.

2. For every interval (l, r):
       EVENTS ← (l, +1)
       EVENTS ← (r, -1)

3. Sort EVENTS by:
       coordinate increasing
       if coordinates are equal:
           +1 before -1

4. current = 0
   maxCount = 0
   maxPoint = 0

5. For every distinct point p:

       Add all +1 events at p to current

       If current > maxCount:
           maxCount = current
           maxPoint = p

       Add all -1 events at p to current

6. Return maxPoint and maxCount.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int point;
    int type;       // +1 = start, -1 = end
} Event;

int compare(const void *a, const void *b){
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;

    // Sort by point
    if (e1->point != e2->point)
        return e1->point - e2->point;

    // At the same point, start (+1) before end (-1)
    return e2->type - e1->type;
}

int main(){
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Event events[2 * n];

    // Input intervals
    for (int i = 0; i < n; i++)
    {
        int l, r;

        printf("Enter left and right endpoint of interval %d: ", i + 1);
        scanf("%d %d", &l, &r);

        events[2 * i].point = l;
        events[2 * i].type = 1;

        events[2 * i + 1].point = r;
        events[2 * i + 1].type = -1;
    }

    // Sort events
    qsort(events, 2 * n, sizeof(Event), compare);

    int current = 0;
    int maxCount = 0;
    int maxPoint = events[0].point;

    int i = 0;

    while (i < 2 * n){
        int point = events[i].point;

        // Process all starting intervals at this point
        while (i < 2 * n && events[i].point == point && events[i].type == 1){
            current++;
            i++;
        }

        // Check maximum at this point
        if (current > maxCount){
            maxCount = current;
            maxPoint = point;
        }

        // Process all ending intervals at this point
        while (i < 2 * n && events[i].point == point && events[i].type == -1){
            current--;
            i++;
        }
    }

    printf("\nPoint = %d", maxPoint);
    printf("\nMaximum number of intervals = %d\n", maxCount);

    return 0;
}