#include <stdio.h>
#define LIM 10

void selectionSort(int arr[], int n);

int main()
{
    int array[LIM];
    printf("Enter 10 elements:\\n");
    for(int k = 0; k < LIM; k++)
    {
        scanf("%d ", &array[k]);
    }
    selectionSort(array, LIM);
    printf("Sorted array:\\n");
    for(int k = 0; k < LIM; k++)
    {
        printf("%d ", array[k]);
    }
    return 0;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;
    for(i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}