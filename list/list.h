#pragma once

#include <cstddef>
#include <iterator>

template <class T>
class List;

template <typename T>
typename List<T>::Iterator begin(List<T>& list);

template <typename T>
typename List<T>::Iterator end(List<T>& list);

template <typename T>
typename List<T>::Iterator begin(const List<T>& list);

template <typename T>
typename List<T>::Iterator end(const List<T>& list);

template <class T>
class List {
   public:
    struct Node {
        Node* prev_{this};
        Node* next_{this};
    };

    struct Value : Node {
        using Node::next_, Node::prev_;
        T data_{};  // NOLINT(misc-non-private-member-variables-in-classes)

        Value() = default;

        explicit Value(T&& data) noexcept : data_(std::move(data)) {
        }
    };

    class Iterator {
       private:
        Node* node_;

       public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        ~Iterator() = default;

        Iterator() : node_(nullptr) {
        }

        explicit Iterator(Node* node) : node_(node) {
        }

        Iterator(const Iterator&) = default;

        Iterator(Iterator&& other) noexcept {
            std::swap(node_, other.node_);
        }

        Iterator& operator=(const Iterator&) = default;

        Iterator& operator=(Iterator&& other) noexcept {
            std::swap(node_, other.node_);
            return *this;
        }

        Iterator& operator++() {
            node_ = node_->next_;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp{node_};
            node_ = node_->next_;
            return temp;
        }

        Iterator& operator--() {
            node_ = node_->prev_;
            return *this;
        }

        Iterator operator--(int) {
            Iterator temp{node_};
            node_ = node_->prev_;
            return temp;
        }

        reference operator*() const {
            auto* value_ptr = static_cast<Value*>(node_);
            if (value_ptr == nullptr) {
                throw std::runtime_error("Invalid iterator");
            }

            return value_ptr->data_;
        }

        pointer operator->() const {
            auto* value_ptr = static_cast<Value*>(node_);
            if (value_ptr == nullptr) {
                return nullptr;
            }

            return &(value_ptr->data);
        }

        bool operator==(const Iterator& it) const {
            return node_ == it.node_;
        }

        bool operator!=(const Iterator& it) const {
            return node_ != it.node_;
        }

        Node* GetNode() {
            return node_;
        }
    };

   private:
    Iterator head_{new Node{}};  // NOLINT(bugprone-unhandled-exception-at-new,-warnings-as-errors)
    size_t size_{};

    void Unlink(Node* node) {
        Node* prev = node->prev_;
        Node* next = node->next_;

        prev->next_ = next;
        next->prev_ = prev;

        delete static_cast<Value*>(node);  // NOLINT(cppcoreguidelines-owning-memory)
    }

    void LinkAfter(Node* target, Node* after) {
        Node* next = after->next_;

        target->prev_ = after;
        target->next_ = next;

        after->next_ = target;
        next->prev_ = target;
    }

    void RemoveAllNodes() {
        while (size_ != 0) {
            Unlink(head_.GetNode()->next_);
            size_--;
        }
        delete head_.GetNode();
    }

   public:
    List() = default;

    List(const List& list) {
        if (this != &list) {
            for (const auto& element : list) {
                PushBack(element);
            }
        }
    }

    List(List&& other) noexcept {
        std::swap(head_, other.head_);
        std::swap(size_, other.size_);
    }

    ~List() {
        RemoveAllNodes();
    }

    List& operator=(const List& list) {
        if (this != &list) {
            RemoveAllNodes();
            head_ = Iterator{new Node{}};

            for (const auto& element : list) {
                PushBack(element);
            }
        }

        return *this;
    }

    List& operator=(List&& other) noexcept {
        std::swap(head_, other.head_);
        std::swap(size_, other.size_);

        return *this;
    }

    [[nodiscard]] bool IsEmpty() const {
        return size_ == 0;
    }

    [[nodiscard]] size_t Size() const {
        return size_;
    }

    void PushBack(const T& element) {
        Iterator new_node{new Value{}};  // NOLINT(cppcoreguidelines-owning-memory)
        *new_node = element;

        Iterator link_after{head_};
        LinkAfter(new_node.GetNode(), (--link_after).GetNode());
        ++size_;
    }

    void PushBack(T&& element) {
        Iterator new_node{
          new Value(std::move(element))};  // NOLINT(cppcoreguidelines-owning-memory)

        Iterator link_after{head_};
        LinkAfter(new_node.GetNode(), (--link_after).GetNode());
        ++size_;
    }

    void PushFront(const T& element) {
        Iterator new_node{new Value{}};  // NOLINT(cppcoreguidelines-owning-memory)
        *new_node = element;

        LinkAfter(new_node.GetNode(), head_.GetNode());
        ++size_;
    }

    void PushFront(T&& element) {
        Iterator new_node{
          new Value(std::move(element))};  // NOLINT(cppcoreguidelines-owning-memory)

        LinkAfter(new_node.GetNode(), head_.GetNode());
        ++size_;
    }

    T& Front() {
        Iterator front{head_};

        return *(++front);
    }

    [[nodiscard]] const T& Front() const {
        Iterator front{head_};

        return *(++front);
    }

    T& Back() {
        Iterator back{head_};

        return *(--back);
    }

    [[nodiscard]] const T& Back() const {
        Iterator back{head_};

        return *(--back);
    }

    void PopBack() {
        Iterator node_to_delete{head_};

        Unlink((--node_to_delete).GetNode());
        --size_;
    }

    void PopFront() {
        Iterator node_to_delete{head_};

        Unlink((++node_to_delete).GetNode());
        --size_;
    }

    void Erase(Iterator node_to_delete) {
        if (node_to_delete.GetNode() != head_.GetNode()) {
            Unlink(node_to_delete.GetNode());
            --size_;
        }
    }

    [[nodiscard]] Iterator Begin() const {
        Iterator begin{head_};
        return ++begin;
    }

    [[nodiscard]] Iterator End() const {
        return head_;
    }
};

template <typename T>
typename List<T>::Iterator begin(List<T>& list) {
    return list.Begin();
}

template <typename T>
typename List<T>::Iterator end(List<T>& list) {
    return list.End();
}

template <typename T>
typename List<T>::Iterator begin(const List<T>& list) {
    return list.Begin();
}

template <typename T>
typename List<T>::Iterator end(const List<T>& list) {
    return list.End();
}