#include <iostream>  
using namespace std;   
template<class Type>  
class Graph;  
  
template<class T>   
class MinHeap   
{   
    template<class Type>  
     friend class Graph;  
    public:   
        MinHeap(int maxheapsize = 10);   
        ~MinHeap(){delete []heap;}   
  
        int Size() const{return currentsize;}   
        T Min(){if(currentsize) return heap[1];}   
  
        MinHeap<T>& Insert(const T& x);   
        MinHeap<T>& DeleteMin(T &x);   
  
        void Initialize(T x[], int size, int ArraySize);   
        void Deactivate();   
        void output(T a[],int n);  
    private:   
        int currentsize, maxsize;   
        T *heap;   
};   
  
template <class T>   
void MinHeap<T>::output(T a[],int n)   
{   
    for(int i = 1; i <= n; i++)   
    cout << a[i] << " ";   
    cout << endl;   
}   
  
template <class T>   
MinHeap<T>::MinHeap(int maxheapsize)   
{   
    maxsize = maxheapsize;   
    heap = new T[maxsize + 1];   
    currentsize = 0;   
}   
  
template<class T>   
MinHeap<T>& MinHeap<T>::Insert(const T& x)   
{   
    if(currentsize == maxsize)   
    {   
        return *this;   
    }   
    int i = ++currentsize;   
    while(i != 1 && x < heap[i/2])   
    {   
        heap[i] = heap[i/2];   
        i /= 2;   
    }   
  
    heap[i] = x;   
    return *this;   
}   
  
template<class T>   
MinHeap<T>& MinHeap<T>::DeleteMin(T& x)   
{   
    if(currentsize == 0)   
    {   
        cout<<"Empty heap!"<<endl;   
        return *this;   
    }   
  
    x = heap[1];   
  
    T y = heap[currentsize--];   
    int i = 1, ci = 2;   
    while(ci <= currentsize)   
    {   
        if(ci < currentsize && heap[ci] > heap[ci + 1])   
        {   
            ci++;   
        }   
  
        if(y <= heap[ci])   
        {   
            break;   
        }   
        heap[i] = heap[ci];   
        i = ci;   
        ci *= 2;   
    }   
  
    heap[i] = y;   
    return *this;   
}   
  
template<class T>   
void MinHeap<T>::Initialize(T x[], int size, int ArraySize)   
{   
    delete []heap;   
    heap = x;   
    currentsize = size;   
    maxsize = ArraySize;   
  
    for(int i = currentsize / 2; i >= 1; i--)   
    {   
        T y = heap[i];   
        int c = 2 * i;   
        while(c <= currentsize)   
        {   
            if(c < currentsize && heap[c] > heap[c + 1])   
                c++;   
            if(y <= heap[c])   
                break;   
            heap[c / 2] = heap[c];   
            c *= 2;   
        }   
        heap[c / 2] = y;   
    }   
}   
  
template<class T>   
void MinHeap<T>::Deactivate()   
{   
    heap = 0;   
}   

