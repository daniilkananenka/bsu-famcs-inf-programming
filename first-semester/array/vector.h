#pragma once

#include <cstddef>
#include <iterator>

template <class T>
class Vector {
   public:
    template <class I>
    class Iterator {
       public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = I;
        using difference_type = ptrdiff_t;
        using pointer = I*;
        using reference = I&;

       private:
        pointer p_;

       public:
        ~Iterator() = default;

        Iterator() : p_(nullptr) {
        }

        explicit Iterator(value_type* value) : p_(value) {
        }

        Iterator(const Iterator& it) = default;
        Iterator<I>& operator=(const Iterator<I>& it) = default;

        Iterator(Iterator<I>&& it) noexcept = default;

        Iterator<I>& operator=(Iterator<I>&& it) noexcept = default;

        pointer operator->() const {
            return p_;
        }

        Iterator<I>& operator+=(difference_type n) {
            p_ += n;
            return *this;
        }

        Iterator<I>& operator-=(difference_type n) {
            p_ -= n;
            return *this;
        }

        reference operator*() const {
            return *p_;
        }

        Iterator<I>& operator++() {
            *this += 1;
            return *this;
        }

        Iterator<I>& operator--() {
            *this -= 1;
            return *this;
        }

        reference operator[](difference_type n) const {
            return *(*this + n);
        }

        friend Iterator<I> operator+(const difference_type n, const Iterator<I>& it) {
            Iterator<I> temp{it};
            return temp += n;
        }

        friend Iterator<I> operator+(const Iterator<I>& it, const difference_type n) {
            Iterator<I> temp{it};
            return temp += n;
        }

        friend Iterator<I> operator-(const Iterator<I>& it, const difference_type n) {
            Iterator<I> temp{it};
            return temp -= n;
        }

        friend difference_type operator-(const Iterator<I>& lhs, const Iterator<I>& rhs) {
            return lhs.p_ - rhs.p_;
        }

        friend Iterator<I> operator++(Iterator<I>& it, int) {
            Iterator<I> temp = it;
            ++it;
            return temp;
        }

        friend Iterator<I> operator--(Iterator<I>& it, int) {
            Iterator<I> temp = it;
            --it;
            return temp;
        }

        bool operator<(const Iterator<I>& it) const {
            return p_ < it.p_;
        }

        bool operator>(const Iterator<I>& it) const {
            return p_ > it.p_;
        }

        bool operator<=(const Iterator<I>& it) const {
            return p_ <= it.p_;
        }

        bool operator>=(const Iterator<I>& it) const {
            return p_ >= it.p_;
        }

        bool operator==(const Iterator<I>& it) const {
            return p_ == it.p_;
        }

        bool operator!=(const Iterator<I>& it) const {
            return p_ != it.p_;
        }
    };

   private:
    Iterator<T> begin_, end_, capacity_it_;

   public:
    ~Vector() {
        delete[] begin_.operator->();
    }

    Vector()
        : begin_(Iterator<T>{new T[0]})
        , end_(Iterator<T>{begin_})
        , capacity_it_(Iterator<T>{begin_}) {
    }

    explicit Vector(const size_t capacity)
        : begin_(Iterator<T>{new T[capacity]})
        , end_(Iterator<T>{begin_ + capacity})
        , capacity_it_(Iterator<T>{begin_ + capacity}) {
        std::fill(begin_, end_, 0);
    }

    Vector(std::initializer_list<T> elements)
        : begin_(Iterator<T>{new T[elements.size()]})
        , end_(Iterator<T>{begin_ + elements.size()})
        , capacity_it_(Iterator<T>{begin_ + elements.size()}) {
        std::copy(elements.begin(), elements.end(), begin_);
    }

    Vector(const Vector<T>& vector) {
        if (this != &vector) {
            begin_ = Iterator<T>{new T[vector.Capacity()]};
            end_ = Iterator<T>{begin_ + vector.Size()};
            capacity_it_ = Iterator<T>{begin_ + vector.Capacity()};

            std::copy(vector.begin_, vector.end_, begin_);
        }
    }

    Vector(Vector<T>&& vector) noexcept {
        vector.Swap(*this);
    }

    Vector<T>& operator=(const Vector<T>& vector) {
        if (this != &vector) {
            delete[] begin_.operator->();

            begin_ = Iterator<T>{new T[vector.Capacity()]};
            end_ = Iterator<T>{begin_ + vector.Size()};
            capacity_it_ = Iterator<T>{begin_ + vector.Capacity()};

            std::copy(vector.begin_, vector.end_, begin_);
        }

        return *this;
    }

    Vector<T>& operator=(Vector<T>&& vector) noexcept {
        vector.Swap(*this);

        return *this;
    }

    [[nodiscard]] size_t Size() const {
        return end_ - begin_;
    }

    [[nodiscard]] size_t Capacity() const {
        return capacity_it_ - begin_;
    }

    T& operator[](size_t index) {
        return begin_[index];
    }

    T operator[](size_t index) const {
        return begin_[index];
    }

    void PushBack(T new_element) {
        if (end_ == capacity_it_) {
            const size_t new_capacity = Capacity() == 0 ? 1 : Capacity() * 2;
            Reserve(new_capacity);
        }

        *end_ = new_element;
        end_++;
    }

    void Insert(T new_element, size_t index) {
        if (end_ == capacity_it_) {
            const size_t new_capacity = Capacity() == 0 ? 1 : Capacity() * 2;
            Reserve(new_capacity);
        }
        for (Iterator<T> i{end_}; i > begin_ + index; i--) {
            *i = *(i - 1);
        }
        begin_[index] = new_element;
        end_++;
    }

    void Erase(size_t index) {
        for (Iterator<T> i{begin_ + index}; i != end_ - 1; i++) {
            *i = *(i + 1);
        }
        end_--;
    }

    void PopBack() {
        end_--;
    }

    void Clear() {
        end_ = begin_;
    }

    void Swap(Vector<T>& rhs) {
        std::swap(begin_, rhs.begin_);
        std::swap(end_, rhs.end_);
        std::swap(capacity_it_, rhs.capacity_it_);
    }

    void Reserve(size_t capacity) {
        if (Capacity() < capacity) {
            Iterator<T> new_begin{new T[capacity]};
            std::copy(begin_, end_, new_begin);

            const size_t current_size = Size();
            delete[] begin_.operator->();
            begin_ = Iterator<T>{new_begin};
            end_ = Iterator<T>{begin_ + current_size};
            capacity_it_ = Iterator<T>{begin_ + capacity};
        }
    }

    void Resize(size_t new_size) {
        if (Size() >= new_size) {
            end_ = end_ - (Size() - new_size);
        } else if (new_size <= Capacity()) {
            std::fill(end_, begin_ + new_size, T{});
            end_ = begin_ + new_size;
        } else if (new_size > Capacity()) {
            Reserve(new_size);
            std::fill(end_, capacity_it_, T{});
            end_ = capacity_it_;
        }
        
    }

    [[nodiscard]] bool Empty() {
        return Size() == 0;
    }

    [[nodiscard]] auto begin() const {
        return begin_;
    }

    [[nodiscard]] auto end() const {
        return end_;
    }

    [[nodiscard]] int& Front() {
        return *begin_;
    }

    [[nodiscard]] int Front() const {
        return *begin_;
    }

    [[nodiscard]] int& Back() {
        return *(end_ - 1);
    }

    [[nodiscard]] int Back() const {
        return *(end_ - 1);
    }
};
