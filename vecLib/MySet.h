// MySet.h
#ifndef MYSET_H
#define MYSET_H

#include <algorithm>
#include "MyVector.h"

template<typename T>
class MySet : public MyVector<T> {
 protected:
    using MyVector<T>::pdata;
    using MyVector<T>::size;
    using MyVector<T>::maxSize;
    using MyVector<T>::Resize;

    int QikcFind(const T& element) const {
        int left = 0;
        int right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (pdata[mid] == element) {
                return mid;
            } else if (pdata[mid] < element) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

 public:
    MySet(size_t initialMaxSize = 1) : MyVector<T>(initialMaxSize) {}

    MySet(const MySet& other) : MyVector<T>(other) {}

    bool IsElement(const T& element) const { return QikcFind(element) != -1; }

    void AddElement(const T& element) override {
        if (!IsElement(element)) {
            MyVector<T>::AddElement(element);
            this->Sort();
        }
    }

    void DeleteElement(const T& element) override {
        int index = QikcFind(element);
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

    MySet& operator+=(const MySet& other) {
        for (size_t i = 0; i < other.size; ++i) {
            AddElement(other.pdata[i]);
        }
        return *this;
    }

    MySet& operator-=(const MySet& other) {
        for (size_t i = 0; i < other.size; ++i) {
            DeleteElement(other.pdata[i]);
        }
        return *this;
    }

    MySet& operator*=(const MySet& other) {
        MySet<T> temp;
        for (size_t i = 0; i < size; ++i) {
            if (other.IsElement(pdata[i])) {
                temp.AddElement(pdata[i]);
            }
        }
        *this = temp;
        return *this;
    }

    MySet& operator=(const MySet& other) {
        if (this != &other) {
            MyVector<T>::operator=(other);
        }
        return *this;
    }

    friend MySet operator+(const MySet& lhs, const MySet& rhs) {
        MySet result = lhs;
        result += rhs;
        return result;
    }

    friend MySet operator-(const MySet& lhs, const MySet& rhs) {
        MySet result = lhs;
        result -= rhs;
        return result;
    }

    friend MySet operator*(const MySet& lhs, const MySet& rhs) {
        MySet result = lhs;
        result *= rhs;
        return result;
    }

    friend bool operator==(const MySet& lhs, const MySet& rhs) {
        if (lhs.size != rhs.size)
            return false;
        for (size_t i = 0; i < lhs.size; ++i) {
            if (!rhs.IsElement(lhs.pdata[i])) {
                return false;
            }
        }
        return true;
    }
};

template<>
class MySet<char*> : public MyVector<char*> {
protected:
    using MyVector<char*>::pdata;
    using MyVector<char*>::size;
    using MyVector<char*>::maxSize;
    using MyVector<char*>::Resize;

    int QikcFind(char* const& element) const {
        int left = 0;
        int right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int cmp = strcmp(pdata[mid], element);
            if (cmp == 0) {
                return mid;
            } else if (cmp < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

 public:
    MySet(size_t initialMaxSize = 1) : MyVector<char*>(initialMaxSize) {}

    MySet(const MySet& other) : MyVector<char*>(other) {}

    bool IsElement(char* const& element) const {
        return QikcFind(element) != -1;
    }


    void AddElement(char* const& element) override {
        if (!IsElement(element)) {
            MyVector<char*>::AddElement(element);
            this->Sort();
        }
    }

    void DeleteElement(char* const& element) override {
        int index = QikcFind(element);
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

    MySet& operator+=(const MySet& other) {
        for (size_t i = 0; i < other.size; ++i) {
            AddElement(other.pdata[i]);
        }
        return *this;
    }

    MySet& operator-=(const MySet& other) {
        for (size_t i = 0; i < other.size; ++i) {
            DeleteElement(other.pdata[i]);
        }
        return *this;
    }

    MySet& operator*=(const MySet& other) {
        MySet<char*> temp;
        for (size_t i = 0; i < size; ++i) {
            if (other.IsElement(pdata[i])) {
                temp.AddElement(pdata[i]);
            }
        }
        *this = temp;
        return *this;
    }

    MySet& operator=(const MySet& other) {
        if (this != &other) {
            MyVector<char*>::operator=(other);
        }
        return *this;
    }

    friend MySet operator+(const MySet& lhs, const MySet& rhs) {
        MySet result = lhs;
        result += rhs;
        return result;
    }

    friend MySet operator-(const MySet& lhs, const MySet& rhs) {
        MySet result = lhs;
        result -= rhs;
        return result;
    }

    friend MySet operator*(const MySet& lhs, const MySet& rhs) {
        MySet result = lhs;
        result *= rhs;
        return result;
    }

    friend bool operator==(const MySet& lhs, const MySet& rhs) {
        if (lhs.size != rhs.size)
            return false;
        for (size_t i = 0; i < lhs.size; ++i) {
            if (!rhs.IsElement(lhs.pdata[i])) {
                return false;
            }
        }
        return true;
    }
};

#endif  // MYSET_H
