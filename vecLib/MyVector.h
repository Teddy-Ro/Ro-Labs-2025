// MyVector.h
#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdexcept>

template<typename T>
class MyVector {
protected:
    size_t maxSize;
    size_t size;
    T* pdata;

    void Resize(size_t newMaxSize);

public:
    MyVector(size_t initialMaxSize = 1);
    MyVector(const MyVector& other);
    virtual ~MyVector();

    virtual void AddElement(const T& element);
    virtual void DeleteElement(const T& element);
    virtual void DeleteElementByIndex(size_t index);
    virtual int Find(const T& element) const;

    void Sort();

    size_t GetSize() const { return size; }
    size_t GetMaxSize() const { return maxSize; }

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    MyVector& operator=(const MyVector& other);

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

// Явные специализации методов для char* с исправленными сигнатурами
template<>
MyVector<char*>::MyVector(const MyVector& other) : maxSize(other.maxSize), size(other.size), pdata(new char*[maxSize]) {
    for (size_t i = 0; i < size; ++i) {
        pdata[i] = new char[strlen(other.pdata[i]) + 1];
        strcpy(pdata[i], other.pdata[i]);
    }
}

template<>
MyVector<char*>::~MyVector() {
    for (size_t i = 0; i < size; ++i) {
        delete[] pdata[i];
    }
    delete[] pdata;
}

template<>
void MyVector<char*>::Resize(size_t newMaxSize) {
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

template<>
void MyVector<char*>::AddElement(char* const& element) {
    if (size >= maxSize) Resize(maxSize * 2);
    pdata[size] = new char[strlen(element) + 1];
    strcpy(pdata[size++], element);
}

template<>
int MyVector<char*>::Find(char* const& element) const {
    for (size_t i = 0; i < size; ++i)
        if (strcmp(pdata[i], element) == 0)
            return i;
    return -1;
}

template<>
void MyVector<char*>::DeleteElementByIndex(size_t index) {
    if (index >= size)
        throw std::out_of_range("Index out of range");
    delete[] pdata[index];
    for (size_t i = index; i < size - 1; ++i)
        pdata[i] = pdata[i + 1];
    size--;
    if (size < maxSize / 4 && maxSize > 1)
        Resize(maxSize / 2);
}

template<>
void MyVector<char*>::Sort() {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (strcmp(pdata[j], pdata[j + 1]) > 0) {
                std::swap(pdata[j], pdata[j + 1]);
            }
        }
    }
}

template<>
MyVector<char*>& MyVector<char*>::operator=(const MyVector& other) {
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

// Общие реализации методов шаблона
template<typename T>
void MyVector<T>::Resize(size_t newMaxSize) {
    T* newData = new T[newMaxSize];
    for (size_t i = 0; i < size; ++i)
        newData[i] = pdata[i];
    delete[] pdata;
    pdata = newData;
    maxSize = newMaxSize;
}

template<typename T>
MyVector<T>::MyVector(size_t initialMaxSize) : maxSize(initialMaxSize), size(0), pdata(new T[maxSize]) {}

template<typename T>
MyVector<T>::MyVector(const MyVector& other) : maxSize(other.maxSize), size(other.size), pdata(new T[maxSize]) {
    for (size_t i = 0; i < size; ++i)
        pdata[i] = other.pdata[i];
}

template<typename T>
MyVector<T>::~MyVector() {
    delete[] pdata;
}

template<typename T>
void MyVector<T>::AddElement(const T& element) {
    if (size >= maxSize)
        Resize(maxSize * 2);
    pdata[size++] = element;
}

template<typename T>
void MyVector<T>::DeleteElement(const T& element) {
    int index = Find(element);
    if (index != -1) {
        for (size_t i = index; i < size - 1; ++i)
            pdata[i] = pdata[i + 1];
        size--;
        if (size < maxSize / 4 && maxSize > 1)
            Resize(maxSize / 2);
    }
}

template<typename T>
void MyVector<T>::DeleteElementByIndex(size_t index) {
    if (index >= size)
        throw std::out_of_range("Index out of range");
    for (size_t i = index; i < size - 1; ++i)
        pdata[i] = pdata[i + 1];
    size--;
    if (size < maxSize / 4 && maxSize > 1)
        Resize(maxSize / 2);
}

template<typename T>
int MyVector<T>::Find(const T& element) const {
    for (size_t i = 0; i < size; ++i)
        if (pdata[i] == element)
            return i;
    return -1;
}

template<typename T>
void MyVector<T>::Sort() {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (pdata[j] > pdata[j + 1]) {
                std::swap(pdata[j], pdata[j + 1]);
            }
        }
    }
}

template<typename T>
T& MyVector<T>::operator[](size_t index) {
    if (index >= size)
        throw std::out_of_range("Index out of range");
    return pdata[index];
}

template<typename T>
const T& MyVector<T>::operator[](size_t index) const {
    if (index >= size)
        throw std::out_of_range("Index out of range");
    return pdata[index];
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
    if (this != &other) {
        delete[] pdata;
        maxSize = other.maxSize;
        size = other.size;
        pdata = new T[maxSize];
        for (size_t i = 0; i < size; ++i)
            pdata[i] = other.pdata[i];
    }
    return *this;
}

#endif  // MYVECTOR_H
