#include <iostream>
using namespace std;

void print(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

/*
1. BUBBLE SORT
Idea: Compare adjacent elements and swap if they are
      in the wrong order. Largest element moves to the end
      after each pass.

Time: Best O(n^2), Average O(n^2), Worst O(n^2)
Space: O(1)
*/
void bubble(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

/*
2. SELECTION SORT
Idea: Find the smallest element from the unsorted part
      and place it at the beginning.

Time: Best O(n^2), Average O(n^2), Worst O(n^2)
Space: O(1)
*/
void selection(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;

        swap(a[i], a[min]);
    }
}

/*
3. INSERTION SORT
Idea: Take one element and insert it into its correct
      position in the already sorted part.

Time: Best O(n), Average O(n^2), Worst O(n^2)
Space: O(1)
*/
void insertion(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

/*
4. MERGE SORT
Idea: Divide the array into two halves, sort each half
      recursively, then merge the sorted halves.

Time: Best O(n log n), Average O(n log n), Worst O(n log n)
Space: O(n)
*/
void merge(int a[], int l, int m, int r) {
    int temp[100], i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= m)
        temp[k++] = a[i++];
    while (j <= r)
        temp[k++] = a[j++];
    for (i = l; i <= r; i++)
        a[i] = temp[i];
}
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

/*
5. QUICK SORT
Idea: Choose a pivot, place smaller elements before it
      and larger elements after it, then recursively sort
      both parts.

Time: Best O(n log n), Average O(n log n), Worst O(n^2)
Space: Average O(log n), Worst O(n)
*/
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}
void quick(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);

        quick(a, low, p - 1);
        quick(a, p + 1, high);
    }
}

int main() {
    int a[100], n, choice;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "\nChoose Operation";
    cout << "\n1. Bubble Sort";
    cout << "\n2. Selection Sort";
    cout << "\n3. Insertion Sort";
    cout << "\n4. Merge Sort";
    cout << "\n5. Quick Sort";
    cout << "\nEnter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            bubble(a, n);
            break;
        case 2:
            selection(a, n);
            break;
        case 3:
            insertion(a, n);
            break;
        case 4:
            mergeSort(a, 0, n - 1);
            break;
        case 5:
            quick(a, 0, n - 1);
            break;
        default:
            cout << "Invalid Choice";
            return 0;
    }
    cout << "Sorted Array: ";
    print(a, n);
    return 0;
}

/*
================ SAMPLE OUTPUT ================

Enter number of elements: 5
Enter elements: 64 25 12 22 11

1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
5. Quick Sort
Enter choice: 4

Sorted Array: 11 12 22 25 64

================ COMPLEXITY ====================

Algorithm     Best          Average       Worst        Space

Bubble        O(n^2)        O(n^2)        O(n^2)       O(1)
Selection     O(n^2)        O(n^2)        O(n^2)       O(1)
Insertion     O(n)          O(n^2)        O(n^2)       O(1)
Merge         O(n log n)    O(n log n)    O(n log n)   O(n)
Quick         O(n log n)    O(n log n)    O(n^2)       O(log n) avg.

================================================
*/