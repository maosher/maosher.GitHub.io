#include <cstring>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class MyString {
 private:
  char* _data;
  size_t _len;
  void _init_data(const char* s) {
    _data = new char[_len + 1];
    memcpy(_data, s, _len);
    _data[_len] = '\0';
  }

 public:
  MyString() {
    _data = NULL;
    _len = 0;
    std::cout << "MyString() is called! source: " << std::endl;
  }
  MyString(const char* p) {
    _len = strlen(p);
    _init_data(p);
    std::cout << " MyString(const char* p)  is called! source: " << p
              << std::endl;
  }
  MyString(const MyString& str) {
    _len = str._len;
    _init_data(str._data);
    std::cout << "Copy Constructor is called! source: " << str._data
              << std::endl;
  }
  MyString& operator=(const MyString& str) {
    if (this != &str) {
      _len = str._len;
      _init_data(str._data);
    }
    std::cout << "Copy Assignment is called! source: " << str._data
              << std::endl;
    return *this;
  }

  MyString(MyString&& str) {
    std::cout << "Move Constructor is called! source: " << str._data
              << std::endl;
    _len = str._len;
    _data = str._data;
    str._len = 0;
    str._data = NULL;
  }

  MyString& operator=(MyString&& str) {
    std::cout << "Move Assignment is called! source: " << str._data
              << std::endl;
    if (this != &str) {
      _len = str._len;
      _data = str._data;
      str._len = 0;
      str._data = NULL;
    }
    return *this;
  }
  virtual ~MyString() {
    if (_data) free(_data);
  }
};
int main() {
  MyString a;
  std::cout << "line 1------------------" << std::endl;
  a = MyString("Hello");
  std::cout << "line 1------------------" << std::endl;
  std::vector<MyString> vec;
  std::cout << "line 1------------------" << std::endl;
  vec.push_back(MyString("World"));
  return 0;
}