
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Function to find minimum operation required to make sum of each row and column equals
int calcMinNoOperations(int matrix[][5], int n)
{
    int sumRows[n], sumCols[n];
    // Initialize sum of rows and columns array to 0
    memset(sumRows, 0, sizeof(sumRows));
    memset(sumCols, 0, sizeof(sumCols));

    // Calculating the sum of Rows and columns array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sumRows[i] += matrix[i][j];
            sumCols[j] += matrix[i][j];
        }
    }

    // Find the maxSum value in either row or in column
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        maxSum = max(maxSum, sumRows[i]);
        maxSum = max(maxSum, sumCols[i]);
    }

    // Find min increment required in either row or column
    int count = 0;
    for (int i = 0, j = 0; i < n && j < n;)
    {

        int diff = min(maxSum - sumRows[i], maxSum - sumCols[j]);

        // Add difference in the corresponding cell in matrix, sumRows[] and sumCols[] array
        matrix[i][j] += diff;
        sumRows[i] += diff;
        sumCols[j] += diff;

        // Update the count variable
        count += diff;

        // If ith row sum is equal to value of maxSum, then increment the value of i for next iteration
        if (sumRows[i] == maxSum)
            ++i;

        // If jth column sum is equal to value of maxSum, then increment the value of j for next iteration
        if (sumCols[j] == maxSum)
            ++j;
    }

    return count;
}

// Function to print matrix
void printMatrix(int matrix[][5], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

// main function
int main()
{
    int m, i;
    cout << "Enter the value of n x n matrix:";
    cin >> m;
    int matrix[i][5];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
        cout << "\n";
    }
    cout << calcMinNoOperations(matrix, m) << "\n";
    printMatrix(matrix, m);
    return 0;
}
