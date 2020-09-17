#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;


template <typename T>
class Vector {
public:
  Vector()
  {
      date = nullptr;
      size = 0;
      capacity = 0;
      
  }

  explicit Vector(size_t size):size(size)
  {
      capacity = size * 2;
      date = new T[capacity];
      
  }
  ~Vector()
  {
      delete[] date;
  }

  T& operator[](size_t index)
  {
      return date[index];
  }

  T* begin() { return date;}
  T* end() { return date + size;}

  size_t Size() const
  {
      return size;
  }

  size_t Capacity() const
  {
      return capacity;
  }

  void PushBack(const T& value)
  {
      if(capacity == 0)
      {
          date = new T[++capacity];
      }
      else 
      {
          if(capacity == size)
          {
            capacity *= 2;
            T *tmp = new T[capacity];
            copy(date, date + size, tmp);
            delete[] date;
            date = tmp;
            
          }
      }
      date[size++] = value;
  }
  
private:
    T *date;
    size_t capacity;
    size_t size;

};


int main()
{
  Vector<int> vec;
  vec.PushBack(1);
  cout<<vec.Capacity()<<endl;
  
  return 0;
}