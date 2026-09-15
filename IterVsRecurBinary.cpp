// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

//Iterative Binary Search 
int binarySearchIter(vector<int>&arr, int target, int& comparisons){
    int low = 0;
    int high = arr.size() - 1;
    
    comparisons = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        comparisons++;

        //check if target is present at mid
        if(arr[mid] == target){
            return mid;
        }
        comparisons++;
        //If target is greater, ignore left half of array
        if(arr[mid] < target){
            low = mid + 1;
        }
        //If target is smaller, ignore right half of array
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int binarySearchRecur(vector<int> &arr, int low, int high, int target, int& comparisons) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        comparisons++;

        if (arr[mid] == target)
            return mid;

        comparisons++;
        
        if (arr[mid] > target)
            return binarySearchRecur(arr, low, mid - 1, target, comparisons);
        
        return binarySearchRecur(arr, mid + 1, high, target, comparisons);
    }
  return -1;
}

int main() {
   
}
