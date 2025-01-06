#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LEN 10000

int compareCount, moveCount;
int BSCC, BSMC, ISCC, ISMC, SSCC, SSMC, QSCC, QSMC, ShSCC, ShSMC, HSCC, HSMC, CC, MC;
// record counters of different functions 

int GenerateArray(int *array);
void PrintArray(int *array, int length);
void BubbleSort(int *array, int length);
void Sort(int *array, int length);
void InsertSort(int *array, int length);
void SelectSort(int *array, int length);
void QuickSort(int *array, int left, int right);
void OneShellSort(int *array, int length, int dk);
void ShellSort(int *array, int length);
void HeapAdjust(int *array, int s, int m);
void HeapSort(int *array, int length);
