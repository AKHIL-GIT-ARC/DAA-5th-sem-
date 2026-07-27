//Implementation and Time analysis of linear and binary search algorithm.
#include <iostream>
using namespace std;

/*
1. LINEAR SEARCH

Idea:
Check each element one by one from the beginning
until the required element is found.

Time Complexity:
Best Case    : O(1)
Average Case : O(n)
Worst Case   : O(n)

Space Complexity: O(1)
*/
int linearSearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key)
            return i;
    }

    return -1;
}


/*
2. BINARY SEARCH

Idea:
Find the middle element of a sorted array.
If key is smaller, search the left half.
If key is larger, search the right half.
Repeat until the key is found.
Note: Array must be sorted.

Time Complexity:
Best Case    : O(1)
Average Case : O(log n)
Worst Case   : O(log n)

Space Complexity: O(1)
*/
int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key)
            return mid;
        else if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int a[100], n, key, choice, result;
    cout << "1. Linear Search";
    cout << "\n2. Binary Search";
    cout << "\nEnter choice: ";
    cin >> choice;
    cout << "Enter number of elements: ";
    cin >> n;
    if (choice == 2)
        cout << "Enter elements in sorted order: ";
    else
        cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter element to search: ";
    cin >> key;
    switch (choice) {
        case 1:
            result = linearSearch(a, n, key);
            break;
        case 2:
            result = binarySearch(a, n, key);
            break;
        default:
            cout << "Invalid Choice";
            return 0;
    }
    if (result == -1)
        cout << "Element not found";
    else
        cout << "Element found at position " << result + 1;

    return 0;
}

/*
================ SAMPLE OUTPUT ================

1. Linear Search
2. Binary Search
Enter choice: 1

Enter number of elements: 5
Enter elements: 40 10 50 20 30
Enter element to search: 20

Element found at position 4


-------------- BINARY SEARCH ------------------

1. Linear Search
2. Binary Search
Enter choice: 2

Enter number of elements: 5
Enter elements in sorted order: 10 20 30 40 50
Enter element to search: 40

Element found at position 4

*/