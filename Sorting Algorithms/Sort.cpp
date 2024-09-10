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
        sort(vec.begin(), vec.end());
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