#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#include <format> 
#include <chrono>
#include <fstream>
#include <iostream>

using namespace std;
using namespace std::chrono;

// mat1[SIZE][SIZE] and mat2[SIZE][SIZE]
#define SIZE 256 // size of matrix' side
#define FILE_PATH "dataset/datasetE"
#define FILE_EXTENTION ".txt"
#define ITERATIONS 100

void transpose(int A[][SIZE], int B[][SIZE]) 
{ 
    int i, j; 
    for (i = 0; i < SIZE; i++) 
        for (j = 0; j < SIZE; j++) 
            B[i][j] = A[j][i]; 
} 

void mulMat(int mat1[][SIZE], int mat2[][SIZE])
{
    int rslt[SIZE][SIZE];
    transpose(mat2, mat2);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            rslt[i][j] = 0;

            for (int k = 0; k < SIZE; k++) {
                rslt[i][j] += mat1[i][k] * mat2[j][k];
            }

            //descomentar los cout para verificar correctitud
            //cout << rslt[i][j] << " ";
        }

        //cout << endl;
    }
}

// Driver code
int main()
{
    int sum = 0;
    for (int i = 0; i < ITERATIONS; i++)
    {
        int mat1[SIZE][SIZE];
        int mat2[SIZE][SIZE];

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
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                file >> mat1[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                file >> mat2[i][j];
            }
        }
        file.close();
        //

        auto start = high_resolution_clock::now();

        //  - Function Call -
        //
        mulMat(mat1, mat2);
        //

        auto stop = high_resolution_clock::now();
    
        auto duration = duration_cast<microseconds>(stop - start);
        sum += duration.count();
    }

    cout << "Average time taken by function: " << sum/ITERATIONS << " microseconds" << endl;
    return 0;
}