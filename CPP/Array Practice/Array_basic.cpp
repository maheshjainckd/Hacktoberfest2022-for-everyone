#include <iostream>


using namespace std;

/*
* Array class
* @param sizeOfArray - size of array
*/
class Array
{
    private:
    // sizeOfArray- to store the size of array
    int sizeOfArray;
    int *array;
    int utilised = 0;
    int dynamicSize;
    public:
    /*
    * getArray => returns the address of array's first element
    * @param none
    * @return array - address of array's first element
    */
    int* getArray()
    {
        return array;
    }
    /*
    * Array => Default constructor
    * @param sizeOfArr
    * @return none
    */
    Array(int sizeOfArr)
    {
        sizeOfArray = sizeOfArr;
        dynamicSize = sizeOfArr;
        array = (int*)(malloc(sizeof(int)*sizeOfArray));
    }
    /*
    * insert => inserts an element at the end of array
    * @param element - element to be inserted
    * @return none
    */
    void insert(int elem)
    {
        // insert
        if(utilised < sizeOfArray)
        {
            array[utilised] = elem;
            utilised++;
        }
        else
        {
            // resize
            dynamicSize = dynamicSize * 2;
            array = (int*)(realloc(array, sizeof(int)*dynamicSize));
            array[utilised] = elem;
            utilised++;
        }
    }
    /*
    * insertAti => inserts an element at the index
    * @param element - element to be inserted
    * @param index - index at which element is to be inserted
    * @return none
    */
    void insertAti(int elem , int index)
    {
        // if array is full
        if(utilised == sizeOfArray)
        {
            // resize
            dynamicSize = dynamicSize * 2;
            array = (int*)(realloc(array, sizeof(int)*dynamicSize));
        }
        // move all elements for index to the right
        for(int i = utilised; i > index; i--)
        {
            array[i] = array[i-1];
        }
        array[index] = elem;
    }
    /*
    * delet => deletes an element at the index
    * @param index - index at which element is to be deleted
    * @return none
    */
    void delet(int index=-1)
    {
        if(index == -1)
        {
            array[utilised-1] = 0;
            utilised--;
        }
        else
        {
            for(int i = index; i < utilised-1; i++)
            {
                array[i] = array[i+1];
            }
            utilised--;
        }
    }
    /*
    * print => prints the array
    * @param none
    * @return none
    */
    int search(int elemToSearch)
    {
        for(int i = 0; i < utilised; i++)
        {
            if(array[i] == elemToSearch)
            {
                cout << "Found at index: " << i << endl;
                return i;
            }
        }
        cout << "Not found" << endl;
        return -1;
    }
    /*
    * sortedSearch => searches for an element in sorted array
    * @param elemToSearch - element to be searched
    * @return index - index of element if found else -1
    */
    int sortedSearch(int elemToSearch)
    {
        int low = 0;
        int high = utilised-1;
        int mid = 0;
        while(low <= high)
        {
            mid = (low + high)/2;
            if(array[mid] == elemToSearch)
            {
                cout << "Found at index: " << mid << endl;
                return mid;
            }
            else if(array[mid] < elemToSearch)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << "Not found" << endl;
        return -1;
    }
    /*
    * print => prints the array
    * @param none
    * @return none
    */
    void print()
    {
        for(int i = 0 ; i<utilised ; i++)
        {
            cout  << i << " "<< *(array + i) << endl;
        }
    }

};
