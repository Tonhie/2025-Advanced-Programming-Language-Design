#include <stdio.h>

void heapify(int arr[], int n, int i);

// 堆排序函数
void heapSort(int arr[], int n) {
    // 构建最大堆（从最后一个非叶子节点开始）
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 逐个提取堆顶元素（最大值）并调整堆
    for (int i = n - 1; i > 0; i--) {
        // 将堆顶元素（最大值）与当前未排序部分的最后一个元素交换
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 调整堆（排除已排序的元素）
        heapify(arr, i, 0);
    }
}

// 调整堆（最大堆）
void heapify(int arr[], int n, int i) {
    int largest = i;          // 假设当前节点为最大值
    int left = 2 * i + 1;     // 左子节点
    int right = 2 * i + 2;    // 右子节点

    // 如果左子节点存在且比当前节点大
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点存在且比当前最大值大
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是当前节点，则交换并递归调整子树
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 测试函数
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("排序后数组:\n");
    printArray(arr, n);

    return 0;
}