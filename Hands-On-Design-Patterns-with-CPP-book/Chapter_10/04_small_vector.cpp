#include <iostream>
#include <algorithm>
#include <cstring>

template <typename T, size_t N>
class SmallVector {
public:
    SmallVector() : data_(local_), size_(0), capacity_(N) {}

    ~SmallVector() {
        if (data_ != local_) {
            delete[] data_;
        }
    }

    void push_back(const T& value) {
        if (size_ == capacity_) {
            grow();
        }
        data_[size_++] = value;
    }

    size_t size() const { return size_; }
    const T& operator[](size_t i) const { return data_[i]; }
    T& operator[](size_t i) { return data_[i]; }

private:
    void grow() {
        capacity_ = std::max<size_t>(capacity_ * 2, 1);
        T* newData = new T[capacity_];
        std::copy(data_, data_ + size_, newData);
        if (data_ != local_) delete[] data_;
        data_ = newData;
    }

    T* data_;
    size_t size_;
    size_t capacity_;
    T local_[N]; // <-- Local buffer (stack-allocated)
};

int main() {
    SmallVector<int, 8> v;  // up to 8 elements without heap allocation

    for (int i = 0; i < 12; ++i)
        v.push_back(i);

    std::cout << "Size: " << v.size() << "\n";
    std::cout << "Values: ";
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << "\n";
}
