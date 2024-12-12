#include <iostream>


template<typename T>
class MyVector {
private:
    size_t _capacity;
    size_t _size;
    T* _data;

    void resize(size_t new_capacity)
    {
        T* temp_data = new T[new_capacity];
        for (size_t i = 0; i < _size; i++)
        {
            temp_data[i] = _data[i];
        }
        delete[] _data;
        _data = temp_data;
        _capacity = new_capacity;
    }

public:
    MyVector() : _capacity(0), _size(0), _data(nullptr) {}
    ~MyVector()
    {
        delete[] _data;
    }

    void add(const T& value)
    {
        if (_size == _capacity)
        {
            resize(_capacity == 0 ? 1 : _capacity * 2);
        }

        _data[_size++] = value;
    }

    bool remove(size_t index)
    {
        if (index >= _size)
        {
            return false;
        }
        else
        {
            for (size_t i = index; i < _size - 1; i++)
            {
                _data[i] = _data[i + 1];
            }
            --_size;
            return true;
        }
    }



    size_t get_capacity() const
    {
        return _capacity;
    }

    size_t get_size() const
    {
        return _size;
    }


    T& operator[](size_t index)
    {
        return _data[index];
    }
    T pop_back() {
        return _data[_size--];

    }

    bool contains(const int &valie) {
        for (size_t i =0;i<_size;i++) {
            if (_data[i]==valie) {
                std::cout << "true"<<std::endl;//dla proverki
                return true;
            }
        }
        return false;

    }
T*reverse() {
        T*temp_data=new T[_capacity];
        for (size_t i=0;i<_size;i++) {
            temp_data[i]=_data[_size-1-i];
        }
        delete[] _data;
        _data=temp_data;
        return 0;
    }
T*copy() {
        T*temp_vektor=new T[_capacity];
        for (size_t i=0;i<_size;i++) {
            temp_vektor[i]=_data[i];
        }
        delete[]_data;
        _data=temp_vektor;
        return temp_vektor;
    }
    bool operator==(MyVector& arr) {
        if (_size==arr.get_size()) {
            for (int i=0;i<_size;i++) {
                if (_data[i]!=arr[i]) {
                    std::cout << "false"<<std::endl;//dla proverki
                    return false;
                }
            }
            std::cout << "true"<<std::endl;//dla proverki
            return  true;
        }
        std::cout << "false"<<std::endl;//dla proverki
        return false;
    }
    bool operator!=(MyVector &arr) {
        if (_size!=arr.get_size()) {
            std::cout << "true"<<std::endl;//dla proverki
            return true;
        }
        else if (_size==arr.get_size()) {
            for (int i=0;i<_size;i++) {
                if (_data[i]!=arr[i]) {
                    std::cout << "true"<<std::endl;//dla proverki
                    return true;
                }

            }
        }
        std::cout << "false"<<std::endl;//dla proverki
        return false;

    }
     void sort() {
        for (size_t i = 0; i < _size - 1; i++) {
            for (size_t j = 0; j < _size - i - 1; j++) {
                if (_data[j] > _data[j + 1]) {
                    T temp = _data[j];
                    _data[j] = _data[j + 1];
                    _data[j + 1] = temp;
                }
            }
        }

    }
    void swap(MyVector& arr) {
        T*temp=new T[_size];
        for (int i=0;i<_size;i++) {
            temp[i]=_data[i];
            _data[i]=arr[i];
            arr[i]=temp[i];
        }delete[]temp;

    }



};

template<typename T>
void display_array(MyVector<T>& my_vector)
{
    for (size_t i = 0; i < my_vector.get_size(); i++)
    {
        std::cout << my_vector[i] << " ";
    }std::cout << std::endl;
}


int main()
{
    MyVector<int> arr;
    arr.add(1);
    std::cout << "Capacity: " << arr.get_capacity() << std::endl;
    arr.add(2);
    std::cout << "Capacity: " << arr.get_capacity() << std::endl;
    arr.add(3);
    std::cout << "Capacity: " << arr.get_capacity() << std::endl;
    arr.add(4);
    std::cout << "Capacity: " << arr.get_capacity() << std::endl;
    arr.add(5);
    std::cout << "Capacity: " << arr.get_capacity() << std::endl;
    arr.add(6);
    std::cout << "Capacity: " << arr.get_capacity() << std::endl;
    MyVector<int>a;
    MyVector<int>b;
    a.add(1);
    a.add(2);
    b.add(1);
    b.add(2);
    b.add(3);
    b.add(4);

    display_array(arr);

    arr.remove(1);

    display_array(arr);
    arr.pop_back();
    display_array(arr);
    arr.contains(1);
    arr.reverse();
    display_array(arr);
    arr.copy();
    display_array(arr);
    a==b;
    a!=b;
    arr.sort();
    display_array(arr);
    arr.swap(b);
    display_array(arr);
    display_array(b);


    return 0;
}