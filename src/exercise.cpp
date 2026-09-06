#include "project/exercise.hpp"
#include <algorithm>
#include <utility>

// TODO: Implement default constructor.
DynamicBuffer::DynamicBuffer() {
    data_ = nullptr;
    size_ = 0;
}

// TODO: Implement allocation and initialization.
// Use a C++ array allocated with new[] and zero-initialize the contents.
DynamicBuffer::DynamicBuffer(size_t capacity) {
    data_ = new int[capacity]();
    size_ = capacity;
}

// TODO: Implement deep-copy constructor.
DynamicBuffer::DynamicBuffer(const DynamicBuffer& other) {
    data_ = new int[other.size_]();
    size_ = other.size_;
    for(size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

// TODO: Implement move constructor.
DynamicBuffer::DynamicBuffer(DynamicBuffer&& other) noexcept {
    data_ = other.data_;
    size_ = other.size_;
    other.data_ = nullptr;
    other.size_ = 0;
}



// TODO: Implement destructor with proper cleanup.
DynamicBuffer::~DynamicBuffer() {
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
}

// TODO: Implement copy assignment with self-assignment protection.
DynamicBuffer& DynamicBuffer::operator=(const DynamicBuffer& other) {
    if(this != &other) {
        delete[] data_;
        data_ = new int[other.size_]();
        size_ = other.size_;
        for(size_t i = 0; i< size_; i++) {
            data_[i] = other.data_[i];
        }
    }
    
    return *this;
}

// TODO: Implement move assignment.
DynamicBuffer& DynamicBuffer::operator=(DynamicBuffer&& other) noexcept {
    if (this != &other) {
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        other.data_ = nullptr;
        other.size_ = 0;
    }

    return *this;
}

// TODO: Return the current managed size.
size_t DynamicBuffer::size() const noexcept {
    
    return this->size_;
}

// TODO: Return true if the buffer is empty.
bool DynamicBuffer::empty() const noexcept {
    if (this->size_ == 0)
        return true;
    return false;
}

// TODO: Implement resize with resource ownership and exception safety.
// Keep all existing values up to the minimum of old and new sizes.
void DynamicBuffer::resize(size_t newSize) {
    int* newData_ = new int[newSize]();
    size_t copySize = std::min(size_, newSize);
    for(size_t i = 0; i<copySize; i++) {
        newData_[i] = data_[i];
    }
    delete[] data_;
    data_ = newData_;
    size_ = newSize;
}

// TODO: Fill all elements with the given value.
void DynamicBuffer::fill(int value) {
   for(size_t i = 0; i<size_; i++) {
        data_[i] = value;
   }
}

// TODO: Validate index and assign the value.
void DynamicBuffer::setAt(size_t index, int value) {
    if(index < size_ )
        data_[index] = value;
}

// TODO: Return element at index with bounds checking.
int DynamicBuffer::at(size_t index) const {
    if(index < size_ )
        return data_[index];
    else 
        throw std:: out_of_range("Index out of range");

}

// TODO: Return a reference without bounds checking.
int& DynamicBuffer::operator[](size_t index) {
    return data_[index];
}

// TODO: Return const reference without bounds checking.
const int& DynamicBuffer::operator[](size_t index) const {
    return data_[index];

}

// TODO: Compare size and elements.
bool DynamicBuffer::operator==(const DynamicBuffer& other) const {
    if(size_ != other.size_) {
        return false;
    }
    for(size_t i=0; i<size_; i++) {
        if(data_[i] != other.data_[i])
            return false;
    }
    return true;
}

// TODO: Implement inequality comparison.
bool DynamicBuffer::operator!=(const DynamicBuffer& other) const {
    return !(*this == other);

}

// TODO: Return true when the buffer owns valid memory.
DynamicBuffer::operator bool() const noexcept {
    if(data_ != nullptr && size_ > 0)
        return true;
    return false;
}

// TODO: Delete allocated memory and reset state.
void DynamicBuffer::release() {
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
}

// TODO: Deep-copy the other object's contents.
void DynamicBuffer::copyFrom(const DynamicBuffer& other) {
    delete[] data_;
    data_ = new int[other.size_]();
    size_ = other.size_;
    for (size_t i = 0; i< size_; i++) {
        data_[i] = other.data_[i];
    }
}

// TODO: Swap the resources of two buffers.
void DynamicBuffer::swap(DynamicBuffer& other) noexcept {
    int* tempData = data_;
    size_t tempSize = size_;
    data_ = other.data_;
    size_ = other.size_;
    other.data_ = tempData;
    other.size_ = tempSize;
}
