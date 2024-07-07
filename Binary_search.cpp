#include <stdio.h>

/* pseudocode:

    low = 0 (lowest index of array)
    high = n-1 (highest index of array)

    while (low <= high):

        midpoint = low+high/2
        if midpoint = searchterm, return midpoint
        if midpoint > searchterm, high = midpoint-1
        if midpoint < searchterm, low = midpoint+1
        
    end while loop

*/


int binarySearch(char arr[], char key)
{

    int low = 0, high = 6, mid;

    while (low <= high)
    {

        mid = (high + low) / 2;

        if (arr[mid] == key)
        {
            return 0;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
    }
    return 1;
}

int main()
{

    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}, key;
    printf("Give us a key to search in array: ");
    scanf("%c", &key);
    int result = binarySearch(arr, key);

    if (result == 0)
        printf("Match was found and it is: '%c'", key);
    else
        printf("No match was found for the key '%c'", key);
}
