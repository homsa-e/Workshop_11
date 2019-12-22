#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>


// Problem 1: delete zeroes from the vector. Functions remove + erase
//   eg  result.erase(std::remove(result.begin(), result.end(), '"'), result.end());
// Problem 2: delete zeroes from the vector without standard functions.
// Problem 3: delete columns from the matrix which have zeroes

void delete_zeroes_from_columns (std::vector<std::vector <int>> &matrix)
{
    size_t shift = 0, i, j, m = matrix[0].size(), n = matrix.size(), k = 0;
    for (j = 0; j < m; j++){
        k = 0;
        for (i = 0; i < n; i++){
            if (matrix[i][j] != 0)
                k++;
        }
        if (k == n){
            for (i = 0; i < n; i++){
                matrix[i][shift] = matrix[i][j];
            }
            ++shift;
        }
    }
    for (i = 0; i < n; i++)
        matrix[i].resize(shift);
}

void delete_zeroes_from_vector (std::vector<int> vec)
{
    std::vector<int>::iterator it = std::remove(vec.begin(), vec.end(), 0);
    vec.erase(it, vec.end());
    for (int elem : vec)
    {
        std::cout << elem << " ";
    }
}

void delete_zeroes_from_vector_without_st_f(std::vector<int> &vec){
    size_t shift = 0, s = vec.size();
    for (size_t i = 0; i < s; ++i) {
        if (vec[i] != 0){
            vec[shift] = vec[i];
            ++shift;
        }
    }
    vec.resize(shift);
}

int main(){
    size_t n, m;
    std::cin >> n >> m;
    std::vector <std::vector <int> > v(n, std::vector <int> (m));
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < m;
             j++)
            std::cin >> v[i][j];
    }
    delete_zeroes_from_columns(v);
    std::cout << std::endl;
    for (size_t i = 0; i < v.size(); i++){
        for (size_t j = 0; j < v[0].size();
             j++)
            std::cout << v[i][j] << ' ';
        std::cout << std::endl;
    }
}
