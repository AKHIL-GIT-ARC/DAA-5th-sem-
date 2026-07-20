#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

int main()
{
    int n;

    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";

    for(int i=0;i<n;i++)
        cin>>arr[i];
    bubbleSort(arr,n);

    cout << "Sorted Array: ";

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}

// Output for bubble sort:
// Enter size: 5
// Enter elements:
// 43
// 23
// 76
// 10
// 29
// Sorted Array: 10 23 29 43 76