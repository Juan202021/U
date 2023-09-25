#include <iostream>

using namespace std;

int findSmallest(int arr[], int start, int end, int smallest){
    if (start > end) return smallest;
    else if (arr[start] < smallest) smallest = arr[start];
    return findSmallest(arr,start+1,end,smallest);
}
int findSmallest(int arr[], int tam){
    return findSmallest(arr,0,tam-1,arr[0]);
}

int main() {
    int arr1[] = {9,8,4,5,6,7, 36, 84, 27, 2};
    int arr2[] = {73,45,48,5,8,9, 7, 30, 1, 33};
    int arr3[] = {1,-1,344,5,1,2, -20, 0, 12, 16};
    cout << findSmallest(arr1,10) << endl;
    cout << findSmallest(arr2,10) << endl;
    cout << findSmallest(arr3,10) << endl;

    return 0;
}
