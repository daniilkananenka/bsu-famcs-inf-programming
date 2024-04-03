## Класс List

Реализовать все методы параметризованного класса List<T> и протестировать в функции main(), а
также класс Reverse_Iterator.

```cpp
template <class T>
class List
{
public:
    struct Node
    {
        T data;
        Node* prev;
        Node* next;
        Node() = default; //new Node()
        Node(const T& \_data, Node* \_prev = nullptr, Node* \_next = nullptr) :
        data(\_data), prev(\_prev), next(\_next) {}; //new Node(key)
        //new Node(key,tail)
        //new Node(key, nullptr,head)
        ~Node() = default;
    };
    List();
    List(const std::initializer_list<T>&);
    ~List();

    size_t get_size()const { return size; }

    void pushBack(const T&);

    T popBack();

    void pushFront(const T&);

    T popFront();

    void insert(const T&, size_t);

    T erase(size_t);

    void replace(const T&, const T&);

    T& operator[](size_t);

    const T& operator[](size_t) const;

    template<class T>
    friend std::ostream& operator<<(std::ostream&, List<T>&);

private:
    size_t size;
    Node* head;
    Node* tail;
public:
    class Iterator
    {
    public:
        Iterator() = default;
        Iterator(Node* \_ptr) :ptr(\_ptr) {};

        //префиксная форма
        Iterator& operator++()
        {
            ptr = ptr->next;
            return *this;
        }
        //постфиксная форма
        Iterator& operator++(int)
        {
            Iterator temp(_this);
            this->operator++();
            return temp;
        }
        T& operator_() const { return ptr->data; }
        bool operator==(const Iterator& i) const
        {
            return ptr == i.ptr;
        }
        bool operator!=(const Iterator& i) const
        {
            return ptr != i.ptr;
        }
        ~Iterator() = default;
    private:
        Node\* ptr;
    };

    Iterator Begin() { return Iterator(head); }
    Iterator End() { return Iterator(tail->next); }
};
//самостоятельно реализовать class Reverse_Iterator{};
//Reverse_Iterator RBegin(){return Reverse_Iterator(tail);}
//Reverse_Iterator REnd(){return Reverse_Iterator(head->prev);}
```
