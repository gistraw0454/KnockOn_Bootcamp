#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(int* arr) {
    for (int i = 0; i < 4; i++) { 
        swap(&arr[4-i], &arr[3-i]);
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5}; 

    shuffle(arr);
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

// Array : 1 2 3 4 5

// ===shuffle===

// Array : 5 3 2 1 4