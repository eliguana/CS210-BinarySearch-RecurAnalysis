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
int linearSearch(vector<int>&arr, int target, int& comparisons){
    comparisons = 0;

    for(int i = 0; i < arr.size(); i++){
        comparisons++;
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main() {

    vector<int> arr = {
        3, 5, 10, 12, 15, 20, 25, 28, 30, 31, 40, 45, 47, 50, 100, 155, 250, 254, 333, 872, 1004
    };

    int high = arr.size() - 1;
    int low = 0;
    int target = 0;
    int comparisons = 0;
    int result = 0;
    
    // TEST 1
    cout << "Test 1: Searching for the first element" << endl;
    target = arr[0];
    
    cout << "Iterative: " << endl;
    result = binarySearchIter(arr, target, comparisons);
    cout << "Index = " << result
         << ", Comparisons = " << comparisons << endl;
    comparisons = 0;
    
    cout << "Recursive: " << endl;
    result = binarySearchRecur(
        arr, low, high, target, comparisons);
    cout << "Index = " << result
         << ", Comparisons = " << comparisons << endl;

    cout << "Linear: " << endl;
    result = linearSearch(arr, target, comparisons);
    cout << "Index = " << result
         << ", Comparisons = " << comparisons << endl;
cout<< "_____________________________________________" <<endl;
    // TEST 2
    cout << "Test 2: Searching for the last element" << endl;

    target = arr[high];
    cout << "Iterative: " << endl;
    result = binarySearchIter(arr, target, comparisons);
    cout << "Index = " << result
         << ", Comparisons = " << comparisons << endl;
    comparisons = 0;

    cout << "Recursive: " << endl;
    result = binarySearchRecur(
        arr, low, high, target, comparisons);
    cout << "Index = " << result
         << ", Comparisons = " << comparisons << endl;

   cout << "Linear: " << endl;
    result = linearSearch(arr, target, comparisons);
    cout << "Index = " << result
         << ", Comparisons = " << comparisons << endl;
cout<< "_____________________________________________" <<endl;
    // TEST 3
    cout << "Test 3: Searching for the middle element" << endl;
    
    target = arr[(high + low) / 2];
    cout << "Iterative: " << endl;
    result = binarySearchIter(arr, target, comparisons);
    cout << "Index = " << result
         << ", Comparisons = " << comparisons << endl;
    comparisons = 0;

    cout << "Recursive: " << endl;
    result = binarySearchRecur(
        arr, low, high, target, comparisons);
    cout << "Index = " << result
         << ", Comparisons = " << comparisons << endl;

    cout << "Linear: " << endl;
    result = linearSearch(arr, target, comparisons);
    cout << "Index = " << result
         << ", Comparisons = " << comparisons << endl;
cout<< "_____________________________________________" <<endl;
    // TEST 4
    cout << "Test 4: Searching for value below range" << endl;

    target = 0;
    cout << "Iterative: " << endl;
    result = binarySearchIter(arr, target, comparisons);
    cout << "Index = " << result
         << ", Comparisons = " << comparisons << endl;
    comparisons = 0;
    
    cout << "Recursive: " << endl;
    result = binarySearchRecur(
        arr, low, high, target, comparisons);
    cout << "Index = " << result
         << ", Comparisons = " << comparisons << endl;

    cout << "Linear: " << endl;
    result = linearSearch(arr, target, comparisons);
    cout << "Index = " << result
         << ", Comparisons = " << comparisons << endl;
cout<< "_____________________________________________" <<endl;
    // TEST 5
    cout << "Test 5: Searching for missing value in range" << endl;

    target = 900;
    cout << "Iterative: " << endl;
    result = binarySearchIter(arr, target, comparisons);
    cout << "Index = " << result
         << ", Comparisons = " << comparisons << endl;
    comparisons = 0;

    cout << "Recursive: " << endl;
    result = binarySearchRecur(
        arr, low, high, target, comparisons);
    cout << "Index = " << result
         << ", Comparisons = " << comparisons << endl;
   
    cout << "Linear: " << endl;
    result = linearSearch(arr, target, comparisons);
    cout << "Index = " << result
         << ", Comparisons = " << comparisons << endl;


    return 0;
}
