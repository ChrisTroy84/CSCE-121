// TODO: Implement this header file
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

using std::ostream;

class MyString {
    private:
        unsigned int capacity_;
        unsigned int size_;
        const unsigned int euro = 1;
        char *str_;
    public:
        //default constructors and copy constructors
        MyString(const MyString &other);     
        MyString(const char *string = nullptr); 
        MyString(const std::string &string);   
        //destructor
        ~MyString();
        //functions:
        unsigned int capacity() const noexcept;
        unsigned int size() const noexcept;
        unsigned int length() const noexcept;
        const char &front() const;
        const char &at(unsigned int pos) const;
        void clear() noexcept;
        void resize(unsigned int n);
        char *data() const noexcept;
        bool empty() const noexcept;
        //operators:
        MyString &operator+=(const char *string);
        MyString &operator+=(const std::string &string);
        MyString &operator+=(const MyString &other);
        MyString &operator=(const char *string);
        MyString &operator=(const std::string &string);
        MyString &operator=(const MyString &other);
        bool operator==(const MyString &other);
        MyString operator+(const MyString &other);
        friend std::ostream &operator<<(std::ostream &os, const MyString &string);
        //find overloaded:
        size_t find(const std::string &string, unsigned int position = 0) const noexcept;
        size_t find(const char *string, unsigned int position = 0) const noexcept;
        size_t find(const MyString &string, unsigned int position = 0) const noexcept;
};

#endif