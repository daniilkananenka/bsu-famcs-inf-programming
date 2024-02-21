#pragma once

#include "vector.h"
#include <cstddef>

template<class T>
class RingBuffer {
   private:
    Vector<T> arr_;
    size_t first_{};
    size_t last_{};
    size_t size_{};
    size_t capacity_{};

   public:
    explicit RingBuffer(size_t capacity) : arr_(Vector<T>(capacity)), capacity_(capacity) {
    }

    [[nodiscard]] size_t Size() const {
        return size_;
    }

    [[nodiscard]] bool Empty() const {
        return size_ == 0;
    }

    bool TryPush(T element) {
        if (size_ == capacity_) {
            return false;
        }

        arr_[last_] = element;
        last_ = (last_ + 1) % capacity_;

        size_++;
        return true;
    }

    bool TryPop(T* element) {
        if (Empty()) {
            return false;
        }
        *element = arr_[first_];
        first_ = (first_ + 1) % capacity_;
        size_--;

        return true;
    }
};
