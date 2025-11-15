#include <iostream>
#include <cassert>

template <typename T>
class TemplArray {
    T *arr;
    int size;
public:
    TemplArray();
    TemplArray(int s);
    ~TemplArray();
     int getSize() const;
    T& getValue(int index);
    const T& getValue(int index) const;
    void replace(int index, const T& value);
    void print() const;
};



template <typename T>
TemplArray<T>::TemplArray(): arr( new T[5]{} ), size(5)
{
}

template <typename T>
TemplArray<T>::TemplArray(int s): arr( new T[s]{} ), size(s)
{

}

template <typename T>
TemplArray<T>::~TemplArray()
{
    delete [] arr;
}

template <typename T>
int TemplArray<T>::getSize() const
{
    return size;
}

template <typename T>
T& TemplArray<T>::getValue(int index)
{
    assert(index >=0 && index < size);
    return arr[index];
}

template <typename T>
const T& TemplArray<T>::getValue(int index) const
{
    assert(index >=0 && index < size);
    return arr[index];
}

template <typename T>
void TemplArray<T>::replace(int index, const T& value)
{
     if(index >=0 && index < size) {
        arr[index] = value;
    }
}

template <typename T>
void TemplArray<T>::print() const
{
    for(int i=0; i<size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << std::endl;

 // Use template with int
    TemplArray<int> a1; 
    a1.print();
    for(int i=0; i<a1.getSize(); ++i) {
        a1.replace(i,(i+1)*10);
    }
    a1.print();
    std::cout << a1.getValue(2) << "\n";   
    
    std::cout << "\n";

        TemplArray<int> a2{10};
    for(int i=0; i<a2.getSize(); ++i) {
        a2.replace(i,(i+1)*10);
    }
    a2.print();

    std::cout << std::endl;
    return 0;
}