#include <cstddef>

template <typename T>
struct Array
{
    Array(size_t size, const T& value = T()) : size_(size) {
        data_ = (T*) new char[size_ * sizeof(T)];
        for (size_t i = 0; i < size_; i++) 
            new (data_ + i) T(value);
    }
    Array() : size_(0), data_(0) {}
    
    Array(const Array &a) : size_(a.size_) {
        data_ = (T*) new char[size_ * sizeof(T)];
        for (size_t i = 0; i < size_; i++) 
            new (data_ + i) T(a.data_[i]);
    }
    ~Array() {
        for (size_t i = 0; i < size_; i++) 
            data_[i].~T();
        delete[] (char *)data_;
    }
    Array& operator=(const Array &a) {
        if (this != &a) {
            size_ = a.size_;
            delete[](char *) data_;
            data_ = (T*) new char[size_ * sizeof(T)];
            for (size_t i = 0; i < size_; i++) 
                new (data_ + i) T(a.data_[i]);
        }
        return *this;
    }
    size_t size() const { return size_; }
    
    T& operator[](size_t i) {
        return data_[i];
    }
    const T& operator[](size_t i) const {
        return data_[i];
    }
private:
    size_t size_;
    T *data_;
};