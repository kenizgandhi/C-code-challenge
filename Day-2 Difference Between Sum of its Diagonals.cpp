/* Program to find the absolute difference between sum of its diagonals */

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int sumOfDiagonals(int matrix[][5], int n)
{
    int diag1 = 0;
    int diag2 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            // Finding sum of primary diagonal
            if( i == j ) {
                diag1 += matrix[i][j]; 
            }

            // Finding sum of secondary diagonal
            if ( i == n-j-1) {
                diag2 += matrix[i][j];
            }
        }
    }
    // Finding the absolute difference between the sum of its diagonals
    return abs(diag1 - diag2);
}
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
    cout << sumOfDiagonals(matrix,m) << "\n";
    return 0;
}