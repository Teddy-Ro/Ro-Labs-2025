#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <algorithm>
#include <cstring>
#include <iostream>

template<typename T>
class MyVector {
 protected:
    size_t maxSize;
    size_t size;
    T* pdata;

    void Resize(size_t newMaxSize) {
        T* newData = new T[newMaxSize];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = pdata[i];
        }
        delete[] pdata;
        pdata = newData;
        maxSize = newMaxSize;
    }

 public:
    MyVector(size_t initialMaxSize = 1) : maxSize(initialMaxSize), size(0), pdata(new T[maxSize]) {}

    MyVector(const MyVector& other) : maxSize(other.maxSize), size(other.size), pdata(new T[maxSize]) {
        for (size_t i = 0; i < size; ++i) {
            pdata[i] = other.pdata[i];
        }
    }

    virtual ~MyVector() { delete[] pdata; }

    virtual void AddElement(const T& element) {
        if (size >= maxSize) {
            Resize(maxSize * 2);
        }
        pdata[size++] = element;
    }

    virtual void DeleteElement(const T& element) {
        int index = Find(element);
        if (index != -1) {
            for (size_t i = index; i < size - 1; ++i) {
                pdata[i] = pdata[i + 1];
            }
            size--;
            if (size < maxSize / 4 && maxSize > 1) {
                Resize(std::max(maxSize / 2, static_cast<size_t>(1)));
            }
        }
    }

    virtual int Find(const T& element) const {
        for (size_t i = 0; i < size; ++i) {
            if (pdata[i] == element) {
                return i;
            }
        }
        return -1;
    }

    void Sort() {
        for (size_t i = 0; i < size - 1; ++i) {
            for (size_t j = 0; j < size - i - 1; ++j) {
                if (pdata[j] > pdata[j + 1]) {
                    T temp = pdata[j];
                    pdata[j] = pdata[j + 1];
                    pdata[j + 1] = temp;
                }
            }
        }
    }

    size_t GetSize() const { return size; }
    size_t GetMaxSize() const { return maxSize; }

    T& operator[](size_t index) {
        if (index >= size)
            throw std::out_of_range("Index out of range");
        return pdata[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size)
            throw std::out_of_range("Index out of range");
        return pdata[index];
    }

    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] pdata;
            maxSize = other.maxSize;
            size = other.size;
            pdata = new T[maxSize];
            for (size_t i = 0; i < size; ++i) {
                pdata[i] = other.pdata[i];
            }
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyVector& vec) {
        os << "{";
        for (size_t i = 0; i < vec.size; ++i) {
            os << vec.pdata[i];
            if (i != vec.size - 1)
                os << ", ";
        }
        os << "}";
        return os;
    }
};

// Специализация
template<>
class MyVector<char*> {
 protected:
    size_t maxSize;
    size_t size;
    char** pdata;

    void Resize(size_t newMaxSize) {
        char** newData = new char*[newMaxSize];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = new char[strlen(pdata[i]) + 1];
            strcpy(newData[i], pdata[i]);
            delete[] pdata[i];
        }
        delete[] pdata;
        pdata = newData;
        maxSize = newMaxSize;
    }

 public:
    MyVector(size_t initialMaxSize = 1) : maxSize(initialMaxSize), size(0), pdata(new char*[maxSize]) {}

    MyVector(const MyVector& other) : maxSize(other.maxSize), size(other.size), pdata(new char*[maxSize]) {
        for (size_t i = 0; i < size; ++i) {
            pdata[i] = new char[strlen(other.pdata[i]) + 1];
            strcpy(pdata[i], other.pdata[i]);
        }
    }

    virtual ~MyVector() {
        for (size_t i = 0; i < size; ++i) {
            delete[] pdata[i];
        }
        delete[] pdata;
    }

    virtual void AddElement(const char* element) {
        if (size >= maxSize) {
            Resize(maxSize * 2);
        }
        pdata[size] = new char[strlen(element) + 1];
        strcpy(pdata[size], element);
        size++;
    }

    virtual void DeleteElement(const char* element) {
        int index = Find(element);
        if (index != -1) {
            delete[] pdata[index];
            for (size_t i = index; i < size - 1; ++i) {
                pdata[i] = pdata[i + 1];
            }
            size--;
            if (size < maxSize / 4 && maxSize > 1) {
                Resize(std::max(maxSize / 2, static_cast<size_t>(1)));
            }
        }
    }

    virtual int Find(const char* element) const {
        for (size_t i = 0; i < size; ++i) {
            if (strcmp(pdata[i], element) == 0) {
                return i;
            }
        }
        return -1;
    }

    void Sort() {
        for (size_t i = 0; i < size - 1; ++i) {
            for (size_t j = 0; j < size - i - 1; ++j) {
                if (strcmp(pdata[j], pdata[j + 1]) > 0) {
                    char* temp = pdata[j];
                    pdata[j] = pdata[j + 1];
                    pdata[j + 1] = temp;
                }
            }
        }
    }

    size_t GetSize() const { return size; }
    size_t GetMaxSize() const { return maxSize; }

    char*& operator[](size_t index) {
        if (index >= size)
            throw std::out_of_range("Index out of range");
        return pdata[index];
    }

    const char* operator[](size_t index) const {
        if (index >= size)
            throw std::out_of_range("Index out of range");
        return pdata[index];
    }

    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            for (size_t i = 0; i < size; ++i) {
                delete[] pdata[i];
            }
            delete[] pdata;

            maxSize = other.maxSize;
            size = other.size;
            pdata = new char*[maxSize];
            for (size_t i = 0; i < size; ++i) {
                pdata[i] = new char[strlen(other.pdata[i]) + 1];
                strcpy(pdata[i], other.pdata[i]);
            }
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyVector& vec) {
        os << "{";
        for (size_t i = 0; i < vec.size; ++i) {
            os << vec.pdata[i];
            if (i != vec.size - 1)
                os << ", ";
        }
        os << "}";
        return os;
    }
};

#endif  // MYVECTOR_H
