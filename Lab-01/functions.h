#pragma once
#include <iostream>
// Alex Bowes SN:C00287604

// 1. Check if a year is a leap year
bool isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    return false;
}

// 2. Reverse an integer number
int Reversed(int testNumber)
{
    int reversedNumber = 0;
    while (testNumber > 0)
    {
        reversedNumber = reversedNumber * 10 + testNumber % 10;
        testNumber /= 10;
    }
    return reversedNumber;
}

// 3. Check whether a number is a palindrome
bool isAPalindrome(int testNumber)
{
    return testNumber == Reversed(testNumber);
}

// 4. Check whether a number is prime
bool isAPrimeNumber(int numbertoTest)
{
    if (numbertoTest <= 1) return false;
    for (int i = 2; i * i <= numbertoTest; i++)
    {
        if (numbertoTest % i == 0) return false;
    }
    return true;
}

// 5. Convert 5 char inputs to an integer (0 if non-digit input)
int input5CharsConvertToInt()
{
    int returnInt = 0;
    char inputChar;
    bool isValid = true;

    for (int i = 0; i < 5; i++)
    {
        std::cin >> inputChar;
        if (inputChar >= '0' && inputChar <= '9')
        {
            returnInt = returnInt * 10 + (inputChar - '0');
        }
        else
        {
            isValid = false;
        }
    }
    return isValid ? returnInt : 0;
}

// 6. Convert binary number to decimal (without using shift operators)
int convertBinarytoDecimal(int binaryNumber)
{
    int decimalNumber = 0, base = 1;
    while (binaryNumber > 0)
    {
        int lastDigit = binaryNumber % 10;
        decimalNumber += lastDigit * base;
        base *= 2;
        binaryNumber /= 10;
    }
    return decimalNumber;
}

// 7. Draw a right-angled triangle
void drawRightAngledTriangle()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << "A";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// 8. Draw isosceles triangle
void drawIsocelesTriangle()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << "A";
        }
        std::cout << std::endl;
    }
    for (int i = 3; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << "A";
        }
        std::cout << std::endl;
    }
}

// 9. Find element in array, return index or -1 if not found
int find(int size, int arr[], int toFind)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == toFind)
        {
            return i; // Return index of element if found
        }
    }
    return -1; // Return -1 if not found
}

// Reverse an array
void reverse(int size, int arr[])
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        // Swap the elements at start and end
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

// Find the second largest element in an array
int find2ndLargest(int size, int arr[])
{
    if (size < 2) return -1;

    int first = arr[0], second = -1;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] != first)
        {
            second = arr[i];
        }
    }
    return second;
}

// Copy one array to another
void copyArraytoArray(int size, int arr1[], int arr2[])
{
    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr1[i];
    }
}

// Insert an element into an array
bool insertElement(int& size, int& count, int arr[], int elementToInsert, int insertIndex)
{
    if (insertIndex < 0 || insertIndex > count || count == size)
        return false;

    for (int i = count; i > insertIndex; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[insertIndex] = elementToInsert;
    count++;
    return true;
}

// Delete an element from an array
bool deleteElement(int& size, int& count, int arr[], int deleteIndex)
{
    if (deleteIndex < 0 || deleteIndex >= count)
        return false;

    for (int i = deleteIndex; i < count - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    count--;
    return true;
}

// Frequency count of an element in an array
int frequencyCount(int size, int arr[], int value)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            count++;
        }
    }
    return count;
}

// Count duplicates in an array
int countDuplicates(int size, int arr[])
{
    int duplicates = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                duplicates++;
                break;
            }
        }
    }
    return duplicates;
}

// Rotate an array to the left
int rotateLeft(int size, int arr[])
{
    if (size == 0) return -1;

    int firstElement = arr[0];
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = firstElement;

    return 0;
}

// Check if two movies can be watched within flight length
bool twoMovies(int flightLength, int movieLengths[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (movieLengths[i] + movieLengths[j] == flightLength)
            {
                return true;
            }
        }
    }
    return false;
}

// Count the number of words in a char array
int wordCounter(int size, char characters[])
{
    int wordCount = 0;
    bool inWord = false;

    for (int i = 0; i < size; i++)
    {
        if (characters[i] != ' ' && !inWord)
        {
            wordCount++;
            inWord = true;
        }
        else if (characters[i] == ' ')
        {
            inWord = false;
        }
    }

    return wordCount;
}
