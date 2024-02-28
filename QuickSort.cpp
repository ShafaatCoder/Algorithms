#include <iostream>
int partition(int arr[], int low, int high)
{
    //intializing the  pivot element the starting and the end pointer
    int pivot = arr[high];
    int i = low;
    int j = high - 1;
    while (i < j)
    {
        //checking for smaller elements towards left of pivot
        while (i < high && arr[i] < pivot)
        {
            i++;
        }
        //Checking for larger elements towards right of pivot
        while (j > low && arr[j] > pivot)
        {
            j--;
        }
        //Checking if the starting index is less than the ending index
        if (i < j)
        {
            std::swap(arr[i], arr[j]);
        }
    }
    //Checking for the greater element than pivot
    if (arr[i] > pivot)
    {
        std::swap(arr[i], arr[high]);
    }
    return i;
}
void QuickSort(int arr[], int low, int high)
{
    //Checking if the array has any elements or not
    if (low >= high)
        return;
    //getting the partition index    
    int p = partition(arr, low, high);
    //Sortin the left subarray
    QuickSort(arr, low, p - 1);
    //Sorting the right Subarray
    QuickSort(arr, p + 1, high);
}
int main()
{
    int arr[] = {56, 78, 9, 34, 67, 8, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, size - 1);
    std::cout << "The sorted array is -> ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;          //CONTRIBUTED BY SHAFAAT
}
