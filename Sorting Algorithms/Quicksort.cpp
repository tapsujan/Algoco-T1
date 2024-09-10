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

int partition(vector<int> &vec, int low, int high) {
    // Selecting last element as the pivot
    int pivot = vec[high];

    // Index of elemment just before the last element
    // It is used for swapping
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    // Put pivot to its position
    swap(vec[i + 1], vec[high]);

    // Return the point of partition
    return (i + 1);
}

void quickSort(vector<int> &vec, int low, int high) {

    // Base case: This part will be executed till the starting
    // index low is lesser than the ending index high
    if (low < high) {

        // pi is Partitioning Index, arr[p] is now at
        // right place
        int pi = partition(vec, low, high);

        // Separately sort elements before and after the
        // Partition Index pi
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}
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
        quickSort(vec, 0, n - 1);
        //

        auto stop = high_resolution_clock::now();
    
        auto duration = duration_cast<microseconds>(stop - start);
        sum += duration.count();

    //  - DESCOMENTAR PARA PROBAR CORRECTITUD -
    /*
    for (auto i : vec) {
        cout << i << " ";
    }
    */
    }

    cout << "Average time taken by function: " << sum/ITERATIONS << " microseconds" << endl;
    return 0;
}