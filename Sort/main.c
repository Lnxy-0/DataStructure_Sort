#include "Sort.h"

int main(){
    int *arr = (int*)malloc(MAX_LEN * sizeof(int));
    int len = GenerateArray(arr);
    printf("---------------BubbleSort---------------\n");
    printf("The origin array is: ");
    PrintArray(arr, len);
    BubbleSort(arr, len);
    printf("Sorted into:         ");
    PrintArray(arr, len);
    BSCC = compareCount;
    BSMC = moveCount;

    printf("---------------InsertSort---------------\n");
    len = GenerateArray(arr);
    printf("The origin array is: ");
    PrintArray(arr, len);
    InsertSort(arr, len);
    printf("Sorted into:         ");
    PrintArray(arr, len);
    ISCC = compareCount;
    ISMC = moveCount;
    
    printf("---------------SeletSort---------------\n");
    len = GenerateArray(arr);
    printf("The origin array is: ");
    PrintArray(arr, len);
    SelectSort(arr, len);
    printf("Sorted into:         ");
    PrintArray(arr, len);
    SSCC = compareCount;
    SSMC = moveCount;

    printf("---------------QuickSort---------------\n");
    len = GenerateArray(arr);
    printf("The origin array is: ");
    PrintArray(arr, len);
    compareCount = 0; moveCount = 0;
    QuickSort(arr, 1, len);
    printf("Sorted into:         ");
    PrintArray(arr, len);
    QSCC = compareCount;
    QSMC = moveCount;
    
    printf("---------------ShellSort---------------\n");
    len = GenerateArray(arr);
    printf("The origin array is: ");
    PrintArray(arr, len);
    ShellSort(arr, len);
    printf("Sorted into:         ");
    PrintArray(arr, len);
    ShSCC = compareCount;
    ShSMC = moveCount;
    
    printf("---------------HeapSort---------------\n");
    len = GenerateArray(arr);
    printf("The origin array is: ");
    PrintArray(arr, len);
    HeapSort(arr, len);
    printf("Sorted into:         ");
    PrintArray(arr, len);
    HSCC = compareCount;
    HSMC = moveCount;

    printf("\n");
    printf("Type of counters     BubbleSort InsertSort SelectSort  QuickSort  ShellSort   HeapSort\n");
    printf("Times of comparison: %10d %10d %10d %10d %10d %10d\n", BSCC, ISCC, SSCC, QSCC, ShSCC, HSCC);
    printf("Times of movement  : %10d %10d %10d %10d %10d %10d\n", BSMC, ISMC, SSMC, QSMC, ShSMC, HSMC);

	return 0;
}

