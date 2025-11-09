#include <iostream>
#include <cstring>

class SmallString {
    static constexpr size_t LOCAL_SIZE = 15;
    size_t size_ = 0;
    char* data_ = local_;
    char local_[LOCAL_SIZE + 1]; // +1 for null terminator

public:
    SmallString(const char* s) {
        size_t len = std::strlen(s);
        if (len <= LOCAL_SIZE) {
            std::memcpy(local_, s, len + 1);
            size_ = len;
        } else {
            data_ = new char[len + 1];
            std::memcpy(data_, s, len + 1);
            size_ = len;
        }
    }

    ~SmallString() {
        if (data_ != local_)
            delete[] data_;
    }

    const char* c_str() const { return data_; }
};

int main() {
    SmallString a("short");
    SmallString b("this string is definitely longer than fifteen chars");

    std::cout << a.c_str() << "\n";
    std::cout << b.c_str() << "\n";
}
