#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <functional>
#include <limits.h>
#include <cstddef>
#include <algorithm>
#include <iostream>

class Storage {
private:
    std::vector<int> arr_;
public:
    Storage() : arr_(std::vector<int>(0)) {}

    size_t Size() const {
        return arr_.size();
    }

    int FindMax() {
        int result = INT_MIN;
        for (size_t i{}; i < arr_.size(); ++i) {
            result = result < arr_[i] ? arr_[i] : result;
        }
        return result;
    }

    template <class Comparator>
    size_t Count(Comparator comparator) {
        size_t result = std::count_if(arr_.begin(), arr_.end(), comparator);
        return result;
    }

    template <class Comparator>
    void Sort(Comparator comparator) {
        std::sort(arr_.begin(), arr_.end(), comparator);
    }

    int operator[](size_t i) const {
        return arr_[i];
    }

    int& operator[](size_t i) {
        return arr_[i];
    }

    friend std::ostream& operator<<(std::ostream& out, const Storage& storage) {
        for (size_t i{}; i < storage.Size(); ++i) {
            out << storage[i] << " ";
        }
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Storage& storage) {
        storage.arr_.clear();
        int current;
        while (in >> current) {
            storage.arr_.push_back(current);
        }
        return in;
    }
 };

#endif // STORAGE_H
