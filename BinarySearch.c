#include <stdio.h>

//Function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;  //finding the middle index. its basically left+right/2 but we use this to prevent overflow incase very large no. are used

        if (arr[mid] == target)  //Check if the middle element is the target
            return mid;

        if (arr[mid] < target)  //If target is greater than the middle index, ignore the left half
            left = mid + 1;
        else  //If target is smaller than the middle index, ignore the right half
            right = mid - 1;
    }
    return -1;  //Element not found if none of the conditions meet
}

int main() {
    int arr[] = {10, 40, 90, 87, 50, 45, 70};  //in binary search, the array has to be sorted
    int n = sizeof(arr) / sizeof(arr[0]);  //Get the size of the array 
    int target = 40;  //the element to search for in the array

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found in the array\n", target);

    return 0;
}
