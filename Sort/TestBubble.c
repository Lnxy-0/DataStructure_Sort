#include "Sort.h"


void testA(int *arr, int len){
    int newarr[len];
    memcpy(newarr, arr, len*sizeof(int));
    BubbleSort(newarr, len);
}
void testB(int *arr, int len){
    int newarr[len];
    memcpy(newarr, arr, len*sizeof(int));
    Sort(newarr, len);
}   
    
int main(){
    clock_t start, end;
    double used_time;
    int *arr = (int*) malloc(MAX_LEN * sizeof(int));
    int len = GenerateArray(arr);

    PrintArray(arr, len);
    start = clock();
    testA(arr, len);
    end = clock();
    used_time =((double)(end - start)) / CLOCKS_PER_SEC;
    printf("used: %f\n", used_time);

    PrintArray(arr, len);
    start = clock();
    testB(arr, len);
    end = clock();
    used_time =((double)(end - start)) / CLOCKS_PER_SEC;
    printf("used: %f\n", used_time);
    return 0;
}

