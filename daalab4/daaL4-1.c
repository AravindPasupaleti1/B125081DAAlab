 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>

 typedef enum{RED = 0, BLACK = 1,YELLOW = 2} Color;

 typedef struct{
     int number;
     Color color;
 }item;

 const char* colorToString(Color color) {
     switch (color) {
         case RED:
             return "RED";
         case BLACK:
             return "BLACK";
         case YELLOW:
             return "YELLOW";
         default:
             return "UNKNOWN";
     }
 }

 void sortbycolour(item* arr, int n) {
    item *output = (item*)malloc(n * sizeof(item));
    if (output == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
            return;}
     int count[3] = {0}; // Count of RED, BLACK, YELLOW

     // Count the occurrences of each color
     for (int i = 0; i < n; i++) {
         count[arr[i].color]++;
     }

     // Overwrite the original array with sorted colors
     int index = 0;
     for (int i = 0; i < n; i++) {
         if(arr[i].color = RED){
           output[index] = arr[i];
         index++;
         }
     }
     for (int i = 0; i < n; i++) {
        if( arr[i].color = BLACK){
            output[index] = arr[i];
         index++;
        }
     }
     for (int i = 0; i < n; i++) {
        if( arr[i].color = YELLOW){
            output[index] = arr[i];
         index++;
        }
     }
     arraycopy(output, arr, n);
     free(output);
 }

 int main() {
     int n;
     printf("Enter the number of items: ");
     scanf("%d", &n);

     item* arr = (item*)malloc(n * sizeof(item));
     if (arr == NULL) {
         fprintf(stderr, "Memory allocation failed\n");
         return 1;
     }

     // Input items
     for (int i = 0; i < n; i++) {
         printf("Enter number and color (0 for RED, 1 for BLACK, 2 for YELLOW) for item %d: ", i + 1);
         scanf("%d %d", &arr[i].number, (int*)&arr[i].color);
     }

     // Sort by color
     sortbycolour(arr, n);

     // Output sorted items
     printf("Sorted items by color:\n");
     for (int i = 0; i < n; i++) {
         printf("Item %d: Number = %d, Color = %s\n", i + 1, arr[i].number, colorToString(arr[i].color));
     }

     free(arr);
     return 0;
 }