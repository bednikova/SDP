#include <iostream>
//template <typename T,int>
void BubbleSort(int array[], int count)
{
    int swap;

    for (int i = 0 ; i < ( count - 1 ); ++i)
    {
        for (int j = 0 ; j < count - i - 1; ++j)
        {
          if (array[j] > array[j+1])
          {
            swap       = array[j];
            array[j]   = array[j+1];
            array[j+1] = swap;
          }
        }
    }

    for(int i = 0; i < count; ++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}
