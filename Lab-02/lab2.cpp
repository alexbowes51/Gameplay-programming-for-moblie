#include "lab2.h"
//Author: Alex Bowes SN:C00287604
// add your tests here.
int main()
{
	//example of calling the functions

	int array[4][6] = { {0,0,3,1,3,4},
					   {0,0,2,3,4,3},
					   {0,0,1,3,3,2},
					   {0,0,1,1,1,1} };
    std::cout << "Original Array:\n";
    PrintArray(array);

    int score = ReplaceWithMinusOne(array);
    std::cout << "\nArray after ReplaceWithMinusOne (Score: " << score << "):\n";
    PrintArray(array);

    FallDownAndReplace(array);
    std::cout << "\nArray after FallDownAndReplace:\n";
    PrintArray(array);

    return 0;
}