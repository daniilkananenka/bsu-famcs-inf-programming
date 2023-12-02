#pragma once

#include "vector.h"

template <class T>
class Stack {
   private:
    Vector<T> arr_;

   public:
    ~Stack() = default;
    Stack() = default;
    Stack(const Stack<T>& stack) = default;
    Stack(Stack<T>&& stack) noexcept = default;

    Stack<T>& operator=(const Stack<T>& stack) = default;
    Stack<T>& operator=(Stack<T>&& stack) noexcept = default;

    explicit Stack(size_t size) : arr_(Vector<T>{size}) {
    }

    Stack(std::initializer_list<T> list) : arr_(Vector<T>{list}) {
    }

    void Push(T element) {
        arr_.PushBack(element);
    }

    void Pop() {
        arr_.PopBack();
    }

    [[nodiscard]] bool Empty() {
        return arr_.Empty();
    }

    [[nodiscard]] T& Back() {
        return arr_.Back();
    }

    [[nodiscard]] T Back() const {
        return arr_.Back();
    }

    void Swap(Stack& stack) {
        arr_.Swap(stack.arr_);
    }

    [[nodiscard]] auto begin() {
        return arr_.begin();
    }

    [[nodiscard]] auto end() {
        return arr_.end();
    }
};