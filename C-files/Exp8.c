//Design, Develop and Implement a Program in C for the following operations on Searching & Sorting
//a. Perform Linear Search and Binary Search.
//b. Perform Bubble Sort.
//c. Perform Selection Sort.
//d. Perform Insertion Sort


//-------Linear Search--------//

#include <stdio.h>
int main()
{
    int a[20],i,x,n;
    printf("How many elements: ");
    scanf("%d", &n);
    printf("Enter array elements: \n");
    for (i=0; i<n; i++)
    scanf("%d", & a[i]);
    printf("\n Enter element to search: ");
    scanf("%d", &x);
    for (i=0; i<n; ++i)
    if (a[i]==x)
    break;
    if (i<n)
    printf("Elment found at index %d", i+1);
    else
    printf("Element not found");
    return 0;
}



//-------Binary Search--------//

#include <stdio.h>

int main() {
    int i, low, high, mid, n, key, array[100];
    printf("Enter number of elements: \n");
    scanf("%d", &n);
    printf("Enter %d integers: \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("Enter value to find: \n");
    scanf("%d", &key);
    low = 0; high = n - 1; mid = (low + high) / 2;
    while (low <= high) {
        if (array[mid] < key)
            low = mid + 1;
        else if (array[mid] == key) {
            printf("%d found at location %d \n", key, mid + 1);
            break;
        } else {
            high = mid - 1;
            mid = (low + high) / 2;
        }
    }
    if (low > high) {
        printf("Not found! %d isn't present in the array \n", key);
    }
    return 0;
}



//-------Bubble Sort--------//

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int array[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]); 
    }
    printf("\n"); 
}

int main() {
    int i, n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    int size = sizeof(array) / sizeof(array[0]); 
    bubblesort(array, size);
    printf("Sorted array: ");
    printArray(array, size);
    return 0;
}



//-------Selection Sort--------//

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionsort(int array[], int n) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min= i;
        for (j=i+1; j<n; j++){
            if (array[j]<array[min]){
                min =j;
                swap (&array[min], &array[i]);
            }
        }
    }  
}          

void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]); 
    }
    printf("\n"); 
}

int main(){
    int i,n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    int size = sizeof(array) / sizeof(array[0]); 
    selectionsort(array, size);
    printf("Sorted array: ");
    printArray(array, size);
    return 0;
}



//-------Insertion Sort--------//

#include <stdio.h>

void insertionsort(int array[], int n) {
    int i, element, j;
    for (i = 1; i < n; i++) {
        element = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > element) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = element;
    }
}

void printArray(int array[], int n) {
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int array[n];
    
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    insertionsort(array, n);
    printArray(array, n);

    return 0;
}
