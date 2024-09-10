#include <bits/stdc++.h>
#include <format> 
#include <chrono>
#include <fstream>
#include <iostream>

using namespace std;
using namespace std::chrono;

#define VECTOR_SIZE 100000
#define FILE_PATH "dataset/datasetE"
#define FILE_EXTENTION ".txt"
#define ITERATIONS 1500

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(vector<int>& arr, int left, 
                     int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Function to print a vector
void printVector(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    int sum = 0;
    for (int i = 0; i < ITERATIONS; i++)
    {
        vector<int> vec(VECTOR_SIZE);
        int n = vec.size();

        //  - Load Dataset -
        //
        ifstream file;
        string fileName = FILE_PATH + to_string(ITERATIONS%9+1) + FILE_EXTENTION;
        file.open(fileName);
        if(!file.is_open())
        {
            cout << "ERROR OPENING FILE" << endl;
            return 0;
        }
        int aux;
        file >> aux;
        for (int i = 0; i < n; i++)
        {
            file >> aux;
            vec[i] = aux;
        }
        file.close();
        //

        auto start = high_resolution_clock::now();

        //  - Function Call -
        //
        mergeSort(vec, 0, n - 1);
        //

        auto stop = high_resolution_clock::now();
    
        auto duration = duration_cast<microseconds>(stop - start);
        sum += duration.count();
    }
    //  - DESCOMENTAR PARA PROBAR CORRECTITUD -
    /*
    for (auto i : vec) {
      cout << i << " ";
    }
    */

    cout << "Average time taken by function: " << sum/ITERATIONS << " microseconds" << endl;
    return 0;
}