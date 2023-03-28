
// Data Structures Spring 2023
// CS 2413
// Bek Mijiddorj
#include <iostream>
#include <time.h> // for experiments
using namespace std;

int binarySearch(int array[], int p, int r, int num) {
    if (p <= r) {
        int mid = (p + r)/2;
        if (array[mid] == num)
            return mid ;
        if (array[mid] > num)
            return binarySearch(array, p, mid-1, num);
        if (array[mid] < num)
            return binarySearch(array, mid+1, r, num);
    }
    return -1;
}

void sumPairs(int array[], int num, int size)
{

    for(int i =0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if ((array[i] + array[j]) == num)
            {
                if (array[i] < array[j])
                {
                    cout << " = " << array[i] << " + " << array[j] << endl;
                }
                else
                {
                    cout << " = " << array[j] << " + " << array[i] << endl;
                }
                return;
            }
        }
    }

}

void sumPairsSorted(int array[], int num, int size)
{
    for (int i =0; i < size; i ++)
    {
        int idx = binarySearch(array, 0, size-1, num - array[i]);
        if (idx != -1)
        {
            cout << " = " << array[i] << " + " << array[idx] << endl;
            return;
        }
    }
}

int linearSearch(int array[], int num, int size)
{
    for (int i =0; i < size; i++)
    {
        if(array[i] == num)
            return i;
    }
    return -1;
}

void swap (int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;

}

void print(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        cout<< " " << array[i];
    }
    cout << endl;


}

void sort(int arr[], int n)
{
    int i, j, min;

    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            swap(&arr[min], &arr[i]);
        }

    }
}

int remove(int array[], int size, int n)
{
    int count =0;
    for (int i =0; i < size; i++ )
    {
        if (array[i] == n)
        {

            cout << "Removing " << n << " at " << i << " in ";
            for (int j = i; j < size - 1; j++)
            {
                array[j] = array[j+1];
            }
            count++;

            return 0;

        }
    }
    if (count == 0)
        cout << "Element " << n << " not found in ";
    return -1;
}

int removeSorted(int array[], int size, int n)
{
    int idx = binarySearch(array, 0, size -1, n);
    if (idx != -1)
    {
        cout << "Removing " << n << " at " << idx << " in ";
        for(int i = idx; i < size -1; i++)
        {
            array[i] = array[i+1];

        }
        return 0;


    }
    else
    {
        cout << "Element " << n << " not found in ";
        return -1;
    }
}

void insertSorted(int array[], int size, int n)
{
    int i;
    for (i = size - 1; (i >= 0 && array[i] > n); i--)
    {
        array[i+1] = array[i];
    }
    array[i+1] = n;
    cout << "Inserting " << n << " in B" << endl;

}

void insert(int array[], int size, int n)
{
    cout << "Inserting " << n << " in A" << endl;
    array[size] = n;
}

int main()
{
    int i; // index for all for loops
    int maxValues; // max number of values to store / length of the arrays
    int currentValues = 0; // as we add, the number of values in the arrays
    char T;
    int numFindVal;
    // variable used to read the number
    cin >> maxValues; // read the maximum number of values from the redirected input file

    cout << "Length of the array: " << maxValues << endl;

// TODO create a dynamic array A of size maxValues
    int *A = new int [maxValues];

    // TODO read in the number from the redirected input
    for (i = 0; i < maxValues; i++)
    {
        int tempVal;
        cin >> tempVal;
        A[i] = tempVal;
        currentValues++;
    }
    // TODO display the values in array A

    cout << "Array A:";
    print(A, maxValues);






// TODO sort the array A and store it in B - any sorting algorithm can be used

    int *B = new int [maxValues];

    for(i =0; i < maxValues; i++)
    {
        B[i] = A[i];
    }
    sort (B, maxValues);

    cout << "Array B:";

    print(B, maxValues);



// TODO read the commands/options till the end of the file

    // searching algorithm

    cin >> T>>numFindVal;
    int *find = new int [numFindVal];

    for (i =0; i < numFindVal; i++)
    {
        int temp;
        cin >> temp;
        find[i] = temp;
    }

    cout << endl;
    cout << "Find:" << endl;


    for ( i =0; i < numFindVal; i++)
    {
        int index = binarySearch(B, 0, maxValues-1, find[i]);
        if (index != -1)
        {
            cout << "Element " << find[i] << " found at " << index << " in B" << endl;
        }
        else
        {
            cout << "Element " << find[i] << " not found in B" << endl;
        }

    }

    cout << endl;

    int index;

    for ( i =0; i < numFindVal; i++)
    {
        index = linearSearch(A, find[i], maxValues);
        if (index != -1)
        {
            cout << "Element " << find[i] << " found at " << index << " in A" << endl;
        }
        else
        {
            cout << "Element " << find[i] << " not found in A" << endl;
        }

    }

    // sumPairs algorithm

    cout << endl;

    cout << "SumPairs:" << endl << "B:" << endl;

    cin >> T >> numFindVal;
    int *sumValues = new int[numFindVal];


    for ( i =0; i < numFindVal; i++)
    {
        int temp;
        cin >> temp;
        sumValues[i] = temp;
    }

    for ( i =0; i <numFindVal; i++)
    {
        cout << sumValues[i] << endl;
        sumPairsSorted(B, sumValues[i], maxValues);
    }
    cout << endl << "A:" << endl;

    for ( i =0; i <numFindVal; i++)
    {
        cout << sumValues[i] << endl;
        sumPairs(A, sumValues[i], maxValues);

    }


    // removing algorithm
    int numRemove;
    cin >> T >> numRemove ;
    int *removeVals = new int[numRemove];
    for ( i =0; i < numRemove; i++)
    {
        int temp;
        cin >> temp;
        removeVals[i] = temp;
    }

    cout << endl << "Remove:" << endl;
    int sizeOfA = maxValues;
    int sizeOfB = maxValues;
    for ( i = 0; i < numRemove; i++)
    {
        int a = removeSorted(B, sizeOfB, removeVals[i]);
        if (a == 0)
        {
            sizeOfB--;
        }
        cout << "B" << endl;
    }
    cout << endl;
    for ( i = 0; i < numRemove; i++)
    {
        int a = remove(A, sizeOfA, removeVals[i]);
        if (a == 0)
        {
            sizeOfA--;
        }
        cout << "A" << endl;
    }

    cout << endl;

    cout << "After removal Array A:";

    print(A, sizeOfA);

    cout << "After removal Array B:";

    print(B, sizeOfB);



// inserting

    int numInsert;
    cin >> T >> numInsert;

    int *insertVals = new int [numInsert];
    for ( i =0; i < numInsert; i++)
    {
        int temp;
        cin >> temp;
        insertVals[i] = temp;
    }
    cout << endl << "Insert:" << endl;
    for (i =0; i <numInsert; i++ )
    {
        insertSorted(B, sizeOfB, insertVals[i]);
        sizeOfB++;
    }
    cout<< endl;
    for (i =0; i <numInsert; i++ )
    {
        insert(A, sizeOfA, insertVals[i]);
        sizeOfA++;
    }
    cout << endl;

    cout << "After insertions Array A:";

    print(A, sizeOfA);

    cout << "After insertions Array B:";

    print(B, sizeOfB);




    // TODO delete all the dynamically created arrays
    return 0;
}
