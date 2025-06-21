
#include <binary_search.hpp>

int binary_search(const std::vector<int> &vec, int target)
{
    if (vec.size() < 1)
    {
        return -1;
    }

    size_t low = 0;
    size_t high = vec.size() - size_t(1);

    while (low < high)
    {
        size_t mid = (high + low) / 2;
        if (vec[mid] == target)
        {
            return mid;
        }
        else if (vec[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}