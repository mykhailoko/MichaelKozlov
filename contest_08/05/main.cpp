#include <iostream>

class IntSharedPointer {
public:
    IntSharedPointer(int* ptr) : data(ptr), ref_count(new size_t(1)) {}

    ~IntSharedPointer() {
        decreaseRefCount();
    }

    IntSharedPointer(const IntSharedPointer& other) : data(other.data), ref_count(other.ref_count) {
        increaseRefCount();
    }

    IntSharedPointer& operator=(IntSharedPointer other) {
        swap(*this, other);
        return *this;
    }

    int& operator*() {
        return *data;
    }

private:
    int* data;
    size_t* ref_count;

    void decreaseRefCount() {
        if (ref_count && --(*ref_count) == 0) {
            delete data;
            delete ref_count;
        }
    }

    void increaseRefCount() {
        if (ref_count) {
            ++(*ref_count);
        }
    }

    friend void swap(IntSharedPointer& first, IntSharedPointer& second) noexcept {
        using std::swap;
        swap(first.data, second.data);
        swap(first.ref_count, second.ref_count);
    }
};

void print(IntSharedPointer p) {
    std::cout << *p << std::endl;
}

void print_with_exception(IntSharedPointer p) {
    std::cout << *p << std::endl;
    if (*p % 2) throw std::string("error");
}

int main() {
    int value1, value2, value3;
    std::cin >> value1 >> value2 >> value3;

    IntSharedPointer p(new int(value1));
    print(p);

    IntSharedPointer p2(p);
    std::cin >> *p2;
    print(p);
    print(p2);

    {
        int value;
        std::cin >> value;
        IntSharedPointer p3(new int(value));
        p2 = p3;
    }
    print(p2);

    p = p2;
    try {
        print_with_exception(p);
    } catch (const std::string& e) {
        std::cout << e << std::endl;
    }

    return 0;
}

