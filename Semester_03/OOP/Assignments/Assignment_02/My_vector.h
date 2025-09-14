#include <iostream>
#include <algorithm>

using namespace std;

// template
template <typename T>

class Vector
{
   T *arr;
   int max_size;
   int current_size = 0;

   // Resize
   void resize()
   {
      if (current_size == max_size)
      {
         max_size = max_size * 2;
         for (int i = current_size; i < max_size; i++)
         {
            this->arr[i] = T();
         }
      }

      if (current_size <= (max_size / 4))
      {
         max_size = max_size / 2;
      }
   }

public:
   // Default Constructor
   Vector()
   {
      arr = nullptr;
      max_size = 0;
      current_size = 0;
   }

   // Paramerterize Constructor
   Vector(int s)
   {
      current_size = 0;
      try
      {
         this->max_size = s;

         if (max_size < 0)
         {
            throw("size");
         }
      }
      catch (const char *msg)
      {
         cout << "Invalid! " << msg << endl;
         while (max_size < 0)
         {
            cout << "Enter size (+ve) again: ";
            cin >> max_size;
         }
      }

      this->arr = new T[max_size];

      for (int i = 0; i < max_size; i++)
      {
         this->arr[i] = T();
      }
   }

   // Copy Constructor
   Vector(const Vector &vec)
   {
      this->max_size = vec.max_size;
      this->current_size = vec.current_size;

      this->arr = new T[max_size];
      for (int i = 0; i < max_size; i++)
      {
         this->arr[i] = vec.arr[i];
      }
   }

   // Current size
   int size() const
   {
      return current_size;
   }

   // Max size
   int getMaxSize() const
   {
      return max_size;
   }

   // Push Back
   void push_back(T element)
   {
      if (current_size < max_size)
      {
         arr[current_size] = element;
      }
      if (current_size == max_size)
      {
         resize();
         arr[current_size] = element;
      }
      current_size++;
   }

   // Pop Back
   T pop_back()
   {
      if (current_size == 0)
      {
         return T();
      }

      T element = arr[current_size - 1];
      arr[current_size - 1] = T();

      current_size--;

      if (current_size < max_size / 4)
      {
         resize();
      }

      return element;
   }

   // Bool isEmpty
   bool is_empty()
   {
      if (current_size == 0)
      {
         return true;
      }
      else
      {
         return false;
      }
   }

   // Bool isFull
   bool is_full()
   {
      if (current_size == max_size)
      {
         return true;
      }
      else
      {
         return false;
      }
   }

   // index Element
   T at(int index)
   {
      if (index < 0 || index >= current_size)
      {
         cout << "Invalid index!" << endl;
         return T();
      }
      else
      {
         return arr[index];
      }
   }

   // Erase Element
   T erase(int index)
   {
      try
      {
         if (index < 0 || index >= current_size)
         {
            throw("index");
         }
      }
      catch (const char *msg)
      {
         cout << "Invalid! " << msg << endl;

         while (index < 0 || index >= current_size)
         {
            cout << "Enter index again: ";
            cin >> index;
         }
      }

      T element = arr[index];

      for (int i = index; i < current_size - 1; i++)
      {
         arr[i] = arr[i + 1];
      }

      arr[current_size - 1] = T();

      current_size--;
      return element;
   }

   // Swap
   void swap(Vector &v1)
   {

      int tem1 = max_size;
      max_size = v1.max_size;
      v1.max_size = tem1;

      int tem2 = current_size;
      current_size = v1.current_size;
      v1.current_size = tem2;

      for (int i = 0; i < max(max_size, v1.max_size); i++)
      {
         int temp = arr[i];
         arr[i] = v1.arr[i];
         v1.arr[i] = temp;
      }
   }

   // insert
   void insert(int index, T element)
   {
      try
      {
         if (index < 0 || index >= current_size)
         {
            throw("index");
         }
      }
      catch (const char *msg)
      {
         cout << "Invalid! " << msg << endl;

         while (index < 0 || index >= current_size)
         {
            cout << "Enter index again: ";
            cin >> index;
         }
      }

      if (current_size < max_size)
      {
         for (int i = current_size; i > index; i--)
         {
            arr[i] = arr[i - 1];
         }

         arr[index] = element;
         current_size++;
      }
      else
      {
         resize();
         for (int i = current_size; i > index; i--)
         {
            arr[i] = arr[i - 1];
         }

         arr[index] = element;
         current_size++;
      }
   }

   // Boolian Sort
   void sort()
   {
      int range = current_size - 1;

      for (int i = 0; i < range; i++)
      {
         for (int j = 0; j < range - i; j++)
         {
            if (arr[j] > arr[j + 1])
            {

               T temp = arr[j];
               arr[j] = arr[j + 1];
               arr[j + 1] = temp;
            }
         }
      }

      cout << "\nSorted array is: " << endl;
      for (int i = 0; i < current_size; i++)
      {
         cout << arr[i] << " ";
      }
   }

   // Move(in num)
   void move(int num)
   {
      Vector v1 = *this;

      if (num < 0)
      {
         num = current_size + num;
      }

      for (int i = 0; i < current_size; i++)
      {
         arr[(i + num) % current_size] = v1.arr[i];
      }
   }

   // Union

   void Union(const Vector<T> &v1)
   {
      int s3 = max(current_size, v1.current_size);

      Vector v2(s3);

      for (int i = 0; i < current_size; i++)
      {
         v2.push_back(arr[i]);
      }

      for (int i = 0; i < v1.current_size; i++)
      {
         bool found = false;
         for (int j = 0; j < v2.current_size; j++)
         {
            if (v1.arr[i] == v2.arr[j])
            {
               found = true;
               break;
            }
         }
         if (!found)
         {
            int element = v1.arr[i];
            v2.push_back(element);
         }
      }

      // return v2;
      cout << "\nUnion of two vectors is: " << endl;
      for(int i = 0; i < v2.current_size; i++)
      {
         cout << v2.arr[i] << " ";
      }
   }

   // Intersection
   void intersection(const Vector<T> &v1)
   {
      Vector v2(current_size);
      int index = 0;
      for (int i = 0; i < current_size; i++)
      {
         for (int j = 0; j < v1.current_size; j++)
         {
            if (arr[i] == v1.arr[j])
            {
               v2.arr[index] = arr[i];
               index++;
               break;
            }
         }
      }
      v2.current_size = index;

      // return v2;
      cout << "\nIntersection of two vectors is: " << endl;
      for(int i = 0; i < v2.current_size; i++)
      {
         cout << v2.arr[i] << " ";
      }
   }

   // Unique
   void unique()
   {
      Vector v1(current_size);
      for (int i = 0; i < current_size; i++)
      {
         for (int j = i; j < current_size; j++)
         {
            if (arr[i] == arr[j])
            {
               break;
            }
            for (int k = 0; k < v1.current_size; k++)
            {
               if ((arr[k] != v1.arr[k]))
               {
                  v1.push_back(arr[k]);
               }
            }
         }
      }

      cout << "Unique elements are: " << endl;
      for (int i = 0; i < current_size; i++)
      {
         cout << v1.arr[i] << " ";
      }
   }

   // Count Element
   int count(T element)
   {
      int count = 0;

      for (int i = 0; i < current_size; i++)
      {
         if (arr[i] == element)
         {
            count++;
         }
      }
      return count;
   }

   // Subset
   bool subset(Vector &v1)
   {
      for (int i = 0; i < current_size; i++)
      {
         bool found = false;
         for (int j = 0; j < v1.current_size; j++)
         {
            if (arr[i] == v1.arr[j])
            {
               found = true;
               break;
            }
         }
         if (!found)
            return false;
      }
      return true;
   }

   // Search
   bool search(T key)
   {
      for (int i = 0; i < current_size; i++)
      {
         if (arr[i] == key)
         {
            return true;
         }
      }
      return false;
   }

   // Overloading Operator

   // + operator
   Vector operator+(Vector &v1)
   {
      Vector<T> v2;
      v2.current_size = this->current_size + v1.current_size;
      v2.max_size = v2.current_size;
      v2.arr = new T[v2.max_size];

      for (int i = 0; i < current_size; i++)
      {
         v2.arr[i] = arr[i];
      }

      for (int i = 0; i < v1.current_size; i++)
      {
         v2.arr[this->current_size + i] = v1.arr[i];
      }

      return v2;
   }

   // [] index
   T operator[](int index)
   {
      try
      {
         if (index < 0 || index >= current_size)
         {
            throw("index");
         }
      }
      catch (const char *msg)
      {
         cout << "Invalid! " << msg << endl;

         while (index < 0 || index >= current_size)
         {
            cout << "Enter index again: ";
            cin >> index;
         }
      }

      return arr[index];
   }

   // - operator
   Vector<T> operator-(const Vector<T> &v1)
   {
      Vector<T> v2(max_size);

      for (int i = 0; i < current_size; i++)
      {
         bool check = true;
         for (int j = 0; j < v1.current_size; j++)
         {
            if (arr[i] == v1.arr[j])
            {
               check = false;
               break;
            }
         }
         if (check)
         {
            v2.push_back(arr[i]);
         }
      }
      return v2;
   }

   // == Equality (bool)
   bool isEqual(Vector &v1)
   {
      if (this->current_size == v1.current_size)
      {
         for (int j = 0; j < this->current_size; j++)
         {
            if (this->arr[j] != v1.arr[j])
            {
               return false;
            }
         }
         return true;
      }
      return false;
   }

   // > Greater than v1 > v2 (bool)
   bool isGreater(Vector &v1)
   {
      if (this->current_size > v1.current_size)
      {
         return true;
      }
      else
      {
         return false;
      }
   }

   // < Less Then  v1 < v2 (bool)
   bool isLess(Vector &v1)
   {
      if (this->current_size < v1.current_size)
      {
         return true;
      }
      else
      {
         return false;
      }
   }

   // = Assignment
   Vector operator=(Vector v1)
   {
      this->max_size = v1.max_size;
      this->current_size = v1.current_size;
      for (int i = 0; i < current_size; i++)
      {
         this->arr[i] = v1.arr[i];
      }

      return *this;
   }

   // display
   void display()
   {
      cout << "\nMax size:" << max_size << endl;
      cout << "Current size: " << current_size << endl;
      cout << "Array is: " << endl;

      for (int i = 0; i < current_size; i++)
      {
         cout << arr[i] << " ";
      }
   }

   // >> Extraction
   template <typename U>
   friend istream &operator>>(istream &i, Vector<U> &v1);

   // <<  Insertion
   template <typename U>
   friend ostream &operator<<(ostream &o, const Vector<U> &v1);
};

// >> Extraction
template <typename T>
istream &operator>>(istream &i, Vector<T> &v1)
{
   cout << "Enter " << v1.max_size << " elements for array: ";
   for (int j = 0; j < v1.max_size; j++)
   {
      i >> v1.arr[j];
   }
   return i;
}

// <<  Insertion
template <typename T>
ostream &operator<<(ostream &o, const Vector<T> &v1)
{
   o << "\nMax size is: " << v1.max_size << endl;
   o << "Current size: " << v1.current_size << endl;
   o << "Array is: " << endl;

   for (int i = 0; i < v1.current_size; i++)
   {
      o << v1.arr[i] << " ";
   }
   return o;
}