#include "../../headers.h"

// * Merge Sort
// * Time complexity - (N * logN)
class Solution
{
    void outPlaceMerge(vector<int> &v, int low, int mid, int high)
    {
        if (low >= high) return;
        int l = low, r = mid + 1, k = 0, size = high - low + 1;
        vector<int> sorted(size, 0);

        while (l <= mid and r <= high)
            sorted[k++] = v[l] < v[r] ? v[l++] : v[r++];
        while (l <= mid)
            sorted[k++] = v[l++];
        while (r <= high)
            sorted[k++] = v[r++];
        for (int i = 0; i < size; i++)
            v[i + low] = sorted[i];
    }

    void mergeSort(vector<int> &v, int low, int high)
    {
        if (low >= high) return;
        int mid = low + ((high - low) / 2);
        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);
        outPlaceMerge(v, low, mid, high);
    }

public:
    vector<int> sortArray(vector<int> &v)
    {
        mergeSort(v, 0, v.size() - 1);
        return v;
    }
};

// * Merge Sort InPlace
// * Time Complexity - O(N ^ 2)

class Solution
{
    void inPlaceMerge(vector<int> &nums, int low, int mid, int high)
    {
        if (low >= high) return;
        int l = low, r = mid + 1;;
        while (l <= mid and r <= high)
        {
            if (nums[l] <= nums[r]) l++;
            else
            {
                int val = nums[r];
                for (int i = r++; i > l; i--)
                    nums[i] = nums[i - 1];
                nums[l++] = val;
                mid++;
            }
        }
    }

    void mergeSort(vector<int> &v, int low, int high)
    {
        if (low >= high)
            return;
        int mid = low + ((high - low) / 2);
        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);
        inPlaceMerge(v, low, mid, high);
    }

public:
    vector<int> sortArray(vector<int> &v)
    {
        mergeSort(v, 0, v.size() - 1);
        return v;
    }
};


// * Quick Sort
// * Time complexity - O(n^2)

class Solution 
{
    int partitionArr(vector<int> &v, int low, int high)
    {
        int pivotVal = v[high], i = low - 1;
        for(int j = low; j < high; j++)
            if(v[j] < pivotVal)
                i++, swap(v[j], v[i]);
        i++;
        int temp = v[i];
        v[i] = pivotVal;
        v[high] = temp;
        return i;
    }

    void quickSort(vector<int> &v, int low, int high)
    {
        if(low >= high) return;
        int pivot = partitionArr(v, low, high);
        quickSort(v, low, pivot - 1);
        quickSort(v, pivot + 1, high);
    }

public:
    vector<int> sortArray(vector<int>& v)
    {
        quickSort(v, 0, v.size() - 1);
        return v;
    }
};