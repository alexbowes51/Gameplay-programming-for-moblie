#pragma once
#include <iostream>
//Author: Alex Bowes SN:C00287604
// dont use cout in any of the functions apart from PrintArray();
int ReplaceWithMinusOne(int array[4][6])
{
    int score = 0;

    // Check horizontal clusters
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (array[row][col] != 0 && array[row][col] == array[row][col + 1] && array[row][col] == array[row][col + 2] && array[row][col] == array[row][col + 3]) {
                // Found horizontal cluster
                score += array[row][col] + array[row][col + 1] + array[row][col + 2] + array[row][col + 3];
                array[row][col] = array[row][col + 1] = array[row][col + 2] = array[row][col + 3] = -1;
            }
        }
    }

    // Check vertical clusters
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 6; col++) {
            if (array[row][col] != 0 && array[row][col] == array[row + 1][col] && array[row][col] == array[row + 2][col] && array[row][col] == array[row + 3][col]) {
                // Found vertical cluster
                score += array[row][col] + array[row + 1][col] + array[row + 2][col] + array[row + 3][col];
                array[row][col] = array[row + 1][col] = array[row + 2][col] = array[row + 3][col] = -1;
            }
        }
    }

    return score;
}
void FallDownAndReplace(int array[4][6])
{
    for (int col = 0; col < 6; col++) {
        int emptyCells = 3;  // Start from the bottom row

        for (int row = 3; row >= 0; row--) {
            if (array[row][col] != -1) {
                array[emptyCells][col] = array[row][col];
                emptyCells--;
            }
        }

        // Fill the top rows with new values (-2)
        while (emptyCells >= 0) {
            array[emptyCells][col] = -2;
            emptyCells--;
        }
    }
}
void PrintArray(int array[4][6])
{
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 6; col++) {
            std::cout << array[row][col] << " ";
        }
        std::cout << std::endl;
    }
}