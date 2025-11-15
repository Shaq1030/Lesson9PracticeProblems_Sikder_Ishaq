#include <iostream>

class IntArray {
private:
    int *arr;
    int size;
public:
    IntArray();
    IntArray(int s);
    ~IntArray();
    int getSize();
    int& getValue(int index);
    void replace(int index, const int& value);
    void print();
};

IntArray::IntArray(): size(5), arr( new int[5]{} )
{

}
IntArray::IntArray(int s): size(s), arr( new int[s]{} )
{

}
IntArray::~IntArray()
{
    delete [] arr;
}
int IntArray::getSize()
{
    return size;
}
int& IntArray::getValue(int index)
{
    assert(index >=0 && index < size);
    return arr[index];
}
void IntArray::replace(int index, const int& value)
{
    if(index >=0 && index < size) {
        arr[index] = value;
    }
}
void IntArray::print()
{
    for(int i=0; i<size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << std::endl;

    IntArray a1;
    a1.print();
    for(int i=0; i<a1.getSize(); ++i) {
        a1.replace(i,(i+1)*10);
    }
    a1.print();
    std::cout << a1.getValue(2) << "\n";   
    
    std::cout << "\n";

    IntArray a2{10};
    for(int i=0; i<a2.getSize(); ++i) {
        a2.replace(i,(i+1)*10);
    }
    a2.print();

    std::cout << std::endl;
    return 0;
}