//
//  main.cpp
//  hometask class
//
//  Created by Valeria  Bukova on 10.10.2024.
//

#include <iostream>

class MyString {
private:
    char* str;
    size_t length;

  
    size_t my_strlen(const char* s) const {
        size_t len = 0;
        while (s[len] != '\0') {
            ++len;
        }
        return len;
    }

   
    void my_strcpy(char* dest, const char* src) const {
        size_t i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            ++i;
        }
        dest[i] = '\0';
    }

public:
    MyString() : str(nullptr), length(0) {}

    MyString(const char* s) {
        length = my_strlen(s);
        str = new char[length + 1];
        my_strcpy(str, s);
    }

    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        my_strcpy(str, other.str);
    }

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;

            length = other.length;
            str = new char[length + 1];
            my_strcpy(str, other.str);
        }
        return *this;
    }

    ~MyString() {
        delete[] str;
    }

    char& operator[](size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return str[index];
    }

    const char& operator[](size_t index) const {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return str[index];
    }

    const char* getStr() const {
        return str;
    }

    size_t getLength() const {
        return length;
    }

    void output(std::ostream& os) const {
        if (str != nullptr) {
            os << str;
        }
    }

    
    void input(std::istream& is) {
        char buffer[1000];
        is >> buffer;
        
        delete[] str;

        length = my_strlen(buffer);
        str = new char[length + 1];
        my_strcpy(str, buffer);
    }
};

std::ostream& operator<<(std::ostream& os, const MyString& myStr) {
    myStr.output(os);
    return os;
}


std::istream& operator>>(std::istream& is, MyString& myStr) {
    myStr.input(is);
    return is;
}

int main() {
    MyString s("Hello");
    std::cout << s << std::endl;

  
    std::cout << "Первый символ строки: " << s[0] << std::endl;

    
    MyString s2 = s;
    std::cout << s2 << std::endl;

   
    MyString s3("World");
    s3 = s;
    std::cout << s3 << std::endl;

   
    std::cout << "Введите строку: ";
    MyString inputStr;
    std::cin >> inputStr;
    std::cout << "Вы ввели: " << inputStr << std::endl;

    return 0;
}
