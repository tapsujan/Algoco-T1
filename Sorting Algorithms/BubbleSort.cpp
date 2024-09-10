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

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << " " << arr[i];
}

// Driver program to test above functions
int main()
{
    int sum = 0;
    for (int i = 0; i < ITERATIONS; i++)
    {
        int vec[VECTOR_SIZE];
        int N = sizeof(vec) / sizeof(vec[0]);

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
        for (int i = 0; i < VECTOR_SIZE; i++)
        {
            file >> aux;
            vec[i] = aux;
        }
        file.close();
        //

        auto start = high_resolution_clock::now();

        //  - Function Call -
        //
        bubbleSort(vec, N);
        //

        auto stop = high_resolution_clock::now();
    
        auto duration = duration_cast<microseconds>(stop - start);
        sum += duration.count();
    }

    cout << "Average time taken by function: " << sum/ITERATIONS << " microseconds" << endl;
    return 0;
}