#include <vector>

template<typename T>
T median(std::vector<T> v)
{
  typedef typename std::vector<T>::size_type vec_sz;
  vec_sz size = v.size();

  if (size == 0)
    throw domain_error("median of an empty vector");

    
}