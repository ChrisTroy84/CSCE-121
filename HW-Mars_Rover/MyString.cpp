//TODO: implement his source file
# include "MyString.h"
# include <stdexcept>
# include <iostream>
using std::out_of_range;

unsigned int MyString::capacity() const noexcept { 
    return this->capacity_; 
}

unsigned int MyString::size() const noexcept { 
    return this->size_; 
}

unsigned int MyString::length() const noexcept { 
    return this->size_; 
}

char *MyString::data() const noexcept { 
    return this->str_; 
}

bool MyString::empty() const noexcept { 
    return !this->size_; 
}

const char &MyString::front() const { 
    return *str_; 
}

const char &MyString::at(unsigned int position) const {
    if (position >= size_) {
        throw out_of_range("Error: value entered is out of range");
    }
    return str_[position];
}

void copyMemory(char *pp, const char *source, unsigned int length) {
    unsigned int i;
    for (i = 0; i < length; i++) {
        pp[i] = source[i];
  }
}

unsigned int stringLength(const char *string) {
    const char *c = string;
    while (*c != '\0') {
        c += 1;
    }
    return c - string;
}

int memoryComponent(const char *string1, const char *string2, unsigned int length) {
    unsigned int i;
    for (i = 0; i < length; i++) {
        if (string1[i] != string2[i]) {
            if (string1[i] < string2[i]) {
                return -1;
            } else {
                return 1;
            }
        }
  }
  return 0;
}

MyString::MyString(const MyString &other) : str_(new char[other.capacity_]), capacity_(other.capacity_), size_(other.size_) {
    copyMemory(str_, other.str_, size_);
}

MyString::MyString(const char *string) : str_(nullptr), capacity_(euro), size_(0) {
    if (string != nullptr) {
        size_ = stringLength(string);
        capacity_ = size_ + euro;
    }
    str_ = new char[capacity_];
    copyMemory(str_, string, size_);
    str_[size_] = '\0';
}

MyString::MyString(const std::string &string) : str_(nullptr), capacity_(0), size_(0) {
    size_ = string.size();
    capacity_ = size_ + euro;
    str_ = new char[capacity_];
    copyMemory(str_, string.c_str(), size_);
    str_[size_] = '\0';
}

MyString::~MyString() {
    if (str_ != nullptr) {
        delete [] str_;
    }
}

void MyString::resize(unsigned int n) {
    if (n < size_) {
        size_ = n;
        str_[size_] = '\0';
    }

    if (n >= capacity_) {
        capacity_ = n + euro;
        char* new_str = new char[capacity_];

        copyMemory(new_str, str_, size_);
        delete[] str_;
        str_ = new_str;
    }
}

void MyString::clear() noexcept {
    size_t i = 0;
    for (i = 0; i < size_; i++) {
        str_[i] = static_cast<char>(0);
    }
    size_ = 0;
    capacity_ = 1;
    return;
}

MyString& MyString::operator=(const char* string) {
    if (string == nullptr) {
        return *this;
    }

    size_ = stringLength(string);

    if (size_ > capacity_) {
        capacity_ = size_ + euro;
        delete[] str_;
        str_ = new char[capacity_];
    }

    copyMemory(str_, string, size_);
    str_[size_] = '\0';
    return *this;
}

MyString& MyString::operator=(const std::string& string) {
    size_ = string.size();

    if (size_ > capacity_) {
        capacity_ = size_ + euro;
        delete[] str_;
        str_ = new char[capacity_];
    }

    copyMemory(str_, string.c_str(), size_);
    str_[size_] = '\0';
    return *this;
}

MyString& MyString::operator=(const MyString& other) {
    if (this == &other) {
        return *this;
    }

    size_ = other.size_;

    if (size_ > capacity_) {
        capacity_ = size_ + euro;
        delete[] str_;
        str_ = new char[capacity_];
    }

    copyMemory(str_, other.str_, size_);
    str_[size_] = '\0';

    return *this;
}


MyString& MyString::operator+=(const char* string) {
   if (string == nullptr) {
        return *this;
    }

    unsigned int length = stringLength(string);

    if (size_ + length > capacity_) {
        capacity_ = size_ + length + euro;
        char* new_str = new char[capacity_];

        copyMemory(new_str, str_, size_); 
        delete[] str_; 
        str_ = new_str;
    }

    copyMemory(str_ + size_, string, length);

    size_ += length;
    str_[size_] = '\0';
  
    return *this;
}

MyString& MyString::operator+=(const std::string& string) {
    unsigned int length = string.size();

    if (size_ + length > capacity_) {
        capacity_ = size_ + length + euro;
        char* new_str = new char[capacity_];

        copyMemory(new_str, str_, size_);  
        delete[] str_;  
        str_ = new_str;
    }

    copyMemory(str_ + size_, string.c_str(), length);

    size_ += length;
    str_[size_] = '\0';

    return *this;
}

MyString& MyString::operator+=(const MyString& other) {
    unsigned int length = other.size_;

    if (size_ + length > capacity_) {
        capacity_ = size_ + length + euro;
        char* new_str = new char[capacity_];

        copyMemory(new_str, str_, size_);  
        delete[] str_;  
        str_ = new_str;
    }

    copyMemory(str_ + size_, other.str_, length);

    size_ += length;
    str_[size_] = '\0';

    return *this;
}

size_t MyString::find(const char* string, unsigned int position) const noexcept {
    if (string == nullptr) {
        return std::string::npos;
    }

    unsigned int length = stringLength(string);

    if (length == 0) {
        return std::string::npos;
    }
    unsigned int i;
    
    for (i = position; i <= size_ - length; i++) {
        if (memoryComponent(str_ + i, string, length) == 0) {
            return i;
        }
    }

    return std::string::npos;
}

size_t MyString::find(const std::string& string, unsigned int position) const noexcept {
    size_t length = string.size();

    if (length == 0) {
        return std::string::npos;
    }
    unsigned int i;

    for (i = position; i <= size_ - length; i++) {
        if (memoryComponent(str_ + i, string.c_str(), length) == 0) {
            return i;
        }
    }

    return std::string::npos;
}

size_t MyString::find(const MyString& string,  unsigned int position) const noexcept {
    size_t length = string.size_;

    if (length == 0) {
        return std::string::npos;
    }

    unsigned int i;

    for (i = position; i <= size_ - length; i++) {
        if (memoryComponent(str_ + i, string.str_, length) == 0) {
            return i;
        }
    }

    return std::string::npos;
}

std::ostream& operator<<(std::ostream &os, const MyString &string) {
    size_t i;

    for (i = 0; i < string.size(); i++) {
        os << string.at(i);
    }

    return os;
}

bool MyString::operator==(const MyString &other) {
  if (size_ != other.size_) {
    return false;
  }

  return !memoryComponent(str_, other.str_, size_);
}

MyString MyString::operator+(const MyString &other) {
    unsigned int length = size_ + other.size_;
    char* new_str = new char[length + 1]; 

    copyMemory(new_str, str_, size_);
    copyMemory(new_str + size_, other.str_, other.size_); 

    new_str[length] = '\0';

    MyString curr(new_str); 
    delete[] new_str; 

    return curr;
}