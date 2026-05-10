#pragma once

#include <iostream>

using namespace std;

class mString
{
private:
    int length;
    char* str;

    // Helper function to calculate length
    int getLength(const char* ptr)
    {
        int len = 0;

        while (ptr[len] != '\0')
        {
            len++;
        }

        return len;
    }

public:


    mString(const char* ptr ="")
    {
        length = getLength(ptr);

        str = new char[length + 1];

        for (int i = 0; i < length; i++)
        {
            str[i] = ptr[i];
        }

        str[length] = '\0';
    }
    mString(const mString& other)
    {
        length = other.length;

        str = new char[length + 1];

        for (int i = 0; i < length; i++)
        {
            str[i] = other.str[i];
        }

        str[length] = '\0';
    }
    ~mString()
    {
        delete[] str;
    }
    

    bool operator==(const mString& other) const
    {
        if (length != other.length)
        {
            return false;
        }

        for (int i = 0; i < length; i++)
        {
            if (str[i] != other.str[i])
            {
                return false;
            }
        }

        return true;
    }
    bool operator==(const char* ptr) const
    {
        int ptrLength = 0;

        while (ptr[ptrLength] != '\0')
        {
            ptrLength++;
        }

        if (length != ptrLength)
        {
            return false;
        }

        for (int i = 0; i < length; i++)
        {
            if (str[i] != ptr[i])
            {
                return false;
            }
        }

        return true;
    }

    void operator=(const char* ptr)
    {
        delete[] str; // remove older str
        length = getLength(ptr);
        str = new char[length + 1];

        for (int i = 0; i < length; i++)
        {
            str[i] = ptr[i];
        }

        str[length] = '\0';
        

    }
    void operator=(const mString& other)
    {
        length = other.length;

        str = new char[length + 1];

        for (int i = 0; i < length; i++)
        {
            str[i] = other.str[i];
        }

        str[length] = '\0';
    }

    void concatenate(const char* ptr)
    {
        int ptrLength = getLength(ptr);

        char* temp = new char[length + ptrLength + 1];

        for (int i = 0; i < length; i++)
        {
            temp[i] = str[i];
        }

        for (int i = 0; i < ptrLength; i++)
        {
            temp[length + i] = ptr[i];
        }

        temp[length + ptrLength] = '\0';

        delete[] str;

        str = temp;

        length = length + ptrLength;
    }
    void concatenate(const mString& other)
    {
        char* temp = new char[length + other.length + 1];

        for (int i = 0; i < length; i++)
        {
            temp[i] = str[i];
        }

        for (int i = 0; i < other.length; i++)
        {
            temp[length + i] = other.str[i];
        }

        temp[length + other.length] = '\0';

        delete[] str;
        str = temp;
        length = length + other.length;
    }
    void operator+=(const mString& other)
    {
        concatenate(other);
    }
    void operator+=(const char* ptr)
    {
        concatenate(ptr);
    }

    const char* getString()
    {
        return str;
    }
    int getLength()
    {
        return length;
    }
};

static char* toString(int num)
{
    int temp = num;
    int digits = 0;

    // Count digits
    do
    {
        digits++;
        temp /= 10;

    } while (temp != 0);

    char* result = new char[digits + 1];

    result[digits] = '\0';

    // Fill characters from back
    for (int i = digits - 1; i >= 0; i--)
    {
        result[i] = (num % 10) + '0';

        num /= 10;
    }

    return result;
}