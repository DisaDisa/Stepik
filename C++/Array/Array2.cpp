#include <utility>

template<class T>
struct Array
{
    // все объявленные ниже методы уже реализованы
    explicit Array(size_t size = 0);
    Array(Array const& a);
    Array & operator=(Array const& a);
    ~Array();

    size_t size() const;
    T &         operator[](size_t i);
    T const&    operator[](size_t i) const;
    
    void swap(Array &s) {
        std::swap(data_, s.data_);
        std::swap(size_, s.size_);
    }

    // реализуйте перемещающий конструктор
    Array (Array && s) {
        data_ = nullptr;
        size_ = 0;
        swap(s);
    }
    // реализуйте перемещающий оператор присваивания
    Array & operator = (Array && s) {
        swap(s);
        return *this;
    }
private:    
    size_t  size_;
    T *     data_;    
};