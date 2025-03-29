#include <stdio.h>
void Merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[high - low + 1];
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= high) {
        temp[k++] = arr[j++];
    }
    for (i = low, k = 0; i <= high; i++, k++) {
        arr[i] = temp[k];
    }
}
void MergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}
int main(){
    int i, size;
    printf("Enter size of List: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements Before Sorting:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    MergeSort(arr, 0, size - 1);
    printf("After Sorting:\n");
    for (i = 0; i < size; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
    return 0; 
}
