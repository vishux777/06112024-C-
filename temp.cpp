#include <iostream>
using namespace std;
#define MAX 1000

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;
 
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void insertNode(int arr[], int& n, int Key) {
    n = n + 1;
    arr[n - 1] = Key;
    
    // Start from the last non-leaf node and heapify each subtree
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int a;
    cin >> a;
    int arr[a];
    for(int i = 0; i < a; i++) {
        cin >> arr[i];
    }
    int n = a;
    int key;
    cin >> key;
    insertNode(arr, n, key);
    printArray(arr, n);
    return 0;
}