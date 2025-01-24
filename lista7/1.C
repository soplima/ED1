#include <vector>

std::vector<int> vet_to_vector(int *v, int n)
{
    std::vector<int> result;
    for (int i = 0; i < n; i++)
    {
        result.push_back(v[i]);
    }
    return result;
}