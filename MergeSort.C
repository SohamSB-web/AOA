#include <stdio.h>
#include <conio.h>

// Function to merge two halves
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int LeftArr[50], RightArr[50];

    // Copy data to temp arrays LeftArr[] and RightArr[]
    for (i = 0; i < n1; i++) {
        LeftArr[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        RightArr[j] = arr[mid + 1 + j];
    }

    // Merge the temp arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (LeftArr[i] <= RightArr[j]) {
            arr[k] = LeftArr[i];
            i++;
        } else {
            arr[k] = RightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of LeftArr[], if any
    while (i < n1) {
        arr[k] = LeftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of RightArr[], if any
    while (j < n2) {
        arr[k] = RightArr[j];
        j++;
        k++;
    }
}

// Function to sort the array using Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = (left + right) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to drive the code
int main() {
    int arr[50], n, i;
    clrscr(); 

    printf("Enter number of elements (max 50): ");
    if (scanf("%d", &n) != 1) { // Check for read error
        return 1;
    }

    if (n <= 0 || n > 50) {
        printf("Invalid number of elements. Please enter a value between 1 and 50.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) { // Check for read error
            return 1;
        }
    }

    printf("\nOriginal array:\n");
    printArray(arr, n);

    // Call Merge Sort on the entire array
    mergeSort(arr, 0, n - 1);

    printf("\nSorted array:\n");
    printArray(arr, n);

    getch(); 
    return 0;
}