#include <dirent.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <memory>

namespace
{
std::vector<std::string> GetDirectoryFiles(const std::string &dir)
{
    std::vector<std::string> files;
    std::shared_ptr<DIR> directory_ptr(opendir(dir.c_str()), [](DIR *dir) { dir &&closedir(dir); });
    struct dirent *dirent_ptr;
    if (!directory_ptr)
    {
        std::cout << "Error opening : " << std::strerror(errno) << dir << std::endl;
        return files;
    }

    while ((dirent_ptr = readdir(directory_ptr.get())) != nullptr)
    {
        files.push_back(std::string(dirent_ptr->d_name));
    }

    return files;
}
} // namespace

int main()
{
    const auto &directory_path = std::string(".");
    const auto &files = GetDirectoryFiles(directory_path);
    for (const auto &file : fles)
    {
        std::cout << file << std::endl;
    }
    return 0;
}

// Bubble sort Algorithm

void PrintArray(int *array, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << array[i] << " " << std::flush;
    std::cout << std::endl;
}

void BubbleSort(int *array, int n)
{
    bool swapped = true;
    int j = 0;
    int temp;

    while (swapped)
    {
        swapped = false;
        j++;
        for (int i = 0; i < n - j; ++i)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = true;
            }
        }
    }
}

int main()
{
    int array[] = {94, 42, 50, 95, 333, 65, 54, 456, 1, 1234};
    int n = sizeof(array) / sizeof(array[0]);

    std::cout << "Before Bubble Sort :" << std::endl;
    PrintArray(array, n);

    BubbleSort(array, n);

    std::cout << "After Bubble Sort: :" << std::endl;
    PrintArray(array, n);
    return (0);
}

// insertion sort Algorithm

void InsertionSort(int arr[], int arr_size)
{
    if (arr_size > 1)
    {
        int size = arr_size;
        for (int i = 1; i < size; ++i)
        {
            int j = i - 1;
            int key = arr[i];
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }
}

// selection sort Algorithm

inline void Swap(int &a, int &b)
{
    int k = a;
    a = b;
    b = k;
}
void SelectionSort(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < arr_size; ++j)
            if (arr[j] < arr[min])
                min = j;
        Swap(arr[min], arr[i]);
    }
}

// Merge Sort Algorithm

void Merger(int arr[], int lo, int mi, int hi)
{
    int *temp = new int[hi - lo + 1]; // temporary merger array
    int i = lo, j = mi + 1;           // i is for left-hand, j is for right -hand
    int k = 0;                        // k is for the temporary array
    while (i <= mi && j <= hi)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    // rest elements of left-half
    while (i <= mi)
        temp[k++] = arr[i++];
    // rest elements of right-half
    while (j <= hi)
        temp[k++] = arr[j++];
    // copy the mergered temporary array to the original array
    for (k = 0, i = lo; i <= hi; ++i, ++k)
        arr[i] = temp[k];

    delete[] temp;
}

void MergeSortHelper(int arr[], int lo, int hi)
{
    int mid;
    if (lo < hi)
    {
        mid = (lo + hi) >> 1;
        MergeSortHelper(arr, lo, mid);
        MergeSortHelper(arr, mid + 1, hi);
        Merger(arr, lo, mid, hi);
    }
}

void MergeSort(int arr[], int arr_size)
{
    MergeSortHelper(arr, 0, arr_size - 1);
}

// Quick Sort Algorithm

intline int rand(int p, int q)
{
    int size = q - p + 1;
    return (p + rand() % size);
}

int Partition(int arr[], int lo, int hi)
{
    //produce random subscript
    int t = rand(lo, hi);
    Swapp(arr[t], arr[hi]);

    int index = lo - 1;
    int key = arr[hi];
    for (int i = lo; i < hi; i++)
    {
        if (arr[i] <= key)
            Swap(arr[++index], arr[i]);
    }
    Swap(arr[++index], arr[hi]);
    return index;
}

void QuickSortHelper(int arr[], int lo, int hi)
{
    if (lo < hi)
    {
        int index = Partition(arr, lo, hi);
        QuickSortHelper(arr, lo, hi);
        QuickSortHelper(arr, index + 1, hi);
    }
}

void QuickSort(int arr[], int arr_size)
{
    QuickSortHelper(arr, 0, arr_size - 1);
}