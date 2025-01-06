#include "Sort.h"

int GenerateArray(int *array){
	srand((unsigned int)time(NULL));
	int length = rand() % 10000 + 1;
	for(int i = 1; i <= length; i++)
		array[i] = rand() % 100; //生成0到99之间的随机数
	return length;
}

void PrintArray(int *array, int length){
	for(int i = 1; i <= length; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

void BubbleSort(int *array, int length){
    compareCount = 0;
    moveCount = 0;
	int i = length;
	int j, x, lastExchangeIndex;
	while(i > 1){
		lastExchangeIndex = 1;
		for(j = 1; j < i; j++){
            compareCount++;
			if(array[j] > array[j+1]){
				x=array[j]; array[j]=array[j+1]; array[j+1]=x;  // 交换
                moveCount += 3;
				lastExchangeIndex = j;	//记录最后一次交换的位置
			}
        }
		i = lastExchangeIndex;
	}
}

void Sort(int *array, int length){
    compareCount = 0;
    moveCount = 0;
    int x;
    for(int i = 1; i <= length; i++){
        for(int j = 1; j <= length-i-1; j++){
            compareCount++;
            if(array[j+1] > array[j]){
                x=array[i]; array[i]=array[j]; array[j]=x;
                moveCount += 3;
            }
        }
    }
}

void InsertSort(int *array, int length){
    compareCount = 0;
    moveCount = 0;
    int i, j;
	for(i = 2; i <= length; i++){
        compareCount++;
	    if(array[i] < array[i-1]){
            array[0] = array[i];    // 复制哨兵
            array[i] = array[i-1];
            moveCount += 2;
            for(j = i - 2; array[j] > array[0]; j--){
                compareCount++;
                array[j+1] = array[j];  // 记录后移
                moveCount++;
            }
            array[j+1] = array[0];  // 插入
            moveCount++;
        }
    }
} 

void SelectSort(int *array, int length){
    compareCount = 0;
    moveCount = 0;
    int i, j, MinIndex, x;
    for(i = 1; i < length; i++){
        // 找到最小关键字的索引
        MinIndex = i;
        for(j = i+1; j <= length; j++){
            compareCount++;
            if(array[j] < array[MinIndex]){
                MinIndex = j;
            }
        }
        compareCount++;
        // 交换最小关键字
        if(i != MinIndex){
            x=array[i]; array[i]=array[MinIndex]; array[MinIndex]=x;
            moveCount += 3;
        }
    }
}

int Partition(int *array, int low, int high){
    // 将low位置作为枢轴，使得顺序表左边的记录不大于枢轴，右边的记录不小于枢轴
    int pivotkey = array[low];
    while(low < high){  // 从表的两端交替地向中间扫描
        while(array[high] >=  pivotkey && low < high){  // 找到记录比枢轴小的记录移至低端
            high--;
            compareCount++;
        }
        array[low] = array[high];
        moveCount++;
        while(array[low] <= pivotkey && low < high){    // 找到记录比枢轴大的记录移至高端
            low++;
            compareCount++;
        }
        array[high] = array[low];
        moveCount++;
    }
    array[low] = pivotkey;
    moveCount++;
    return low;     // 返回枢轴所在位置
}

void QuickSort(int *array, int low, int high){
    if(low < high){
        int x = Partition(array, low, high);
        QuickSort(array, low, x-1);     // 将子表递归排序
        QuickSort(array, x+1, high);
    }
}

void OneShellSort(int *array, int length, int dk){
    // 一次希尔排序,0位置处只是暂存单元，不是哨兵，当j<=0时，插入位置已经找到
    int i, j;
    for(i =dk+1; i <= length; i++){
        compareCount++;
        if(array[i-dk] > array[i]){
            array[0] = array[i];
            array[i] = array[i-dk];
            moveCount += 2;
            for(j = i-dk; j > 0 && array[j] > array[0]; j -= dk){
                compareCount++;
                array[j+dk] = array[j];
                moveCount++;
            }
            array[j+dk] = array[0];
            moveCount++;
        }
    }
}

void ShellSort(int *array, int length){
    compareCount = 0;
    moveCount = 0;
    int dk = length / 2;    // 使用数组长度的一半作为初始增量，增量依次除以2，直到1为止
    while(dk>= 1){
        OneShellSort(array, length, dk);
        dk /= 2;
    }
}

void HeapAdjust(int *array, int s, int m){
    int rc, j;
    rc = array[s];
    for(j = s*2; j <= m; j *= 2){   // 沿关键字较大的孩子结点向下筛选
        compareCount++;
        if(j<m && array[j] <  array[j+1])   j++;    // j为关键字较大的记录的下标
        compareCount++; 
        if(rc >= array[j])  break;          // rc应该插入s位置处
        array[s] = array[j];    
        moveCount++;
        s = j;
    }
    array[s] = rc;
    moveCount++;
}

void HeapSort(int *array, int length){
    compareCount = 0;
    moveCount = 0;
    int i, x;
    for(i = length/2; i > 0; i--)   // 将序列建立成大根堆
        HeapAdjust(array, i, length);
    for(i = length; i > 1; i--){
        x = array[1]; array[1] = array[i]; array[i] = x;    // 将堆顶记录和最后一个记录交换
        moveCount += 3;
        HeapAdjust(array, 1, i-1);  // 将1至i-1序列重新调整为大根堆
    }
}
