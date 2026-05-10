#pragma once

template <typename T>
class MyVector
{
private:
    T* data;
    int size;
    int capacity;

    void resize()
    {
        T* newData = new T[newCapacity];

        for (int i = 0; i < size; i++)
            newData[i] = data[i];
        
        delete[] data;
        data = newData;
        capacity += 10;
    }

public:
    MyVector(): size(0), capacity(10)
    {
        data = new T[capacity];
    }

    ~MyVector()
    {
        delete[] data;
    }

    void add(const T& value)
    {
        if (size >= capacity)
        {
            resize();
        }

        bool assingned = false; // to chaeck if value is assined

        // assigns value to an imty space in a halo container
        for (int i = 0; i < size; i++)
        {
            if (data[i] = nullptr)
            {
                assingned = true;
                data[i] = value;
                break;
            }
        }

        if (!assingned)
        {
            data[size] = value;
            size++;
        }
    }

    T& operator[](int index)
    {
        return data[index];
    }

    int getSize() const
    {
        return size;
    }

    void clear()
    {
        size = 0;
    }
};


