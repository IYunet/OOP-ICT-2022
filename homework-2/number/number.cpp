#include "number.h"
number_t::number_t(){
    _num = 0;
}

number_t::number_t(int64_t number) : _num(number) {}

number_t &number_t::operator=(int64_t &number) {
  _num = number;
  return *this;
}
number_t &number_t::operator=(int number) {
  _num = number;
  return *this;
}

number_t::operator bool() const {
  if(_num == 1 || _num == -1) {return true;}
  else{return false;}
}

number_t::operator int64_t() const {
  return static_cast<int64_t>(_num);
}

number_t::operator string() const {
  return static_cast<string>(std::to_string(_num));
}
bool operator==(const number_t &number1, const number_t &number2) {
  return (number1._num == number2._num);
}

number_t::number_t(const number_t &number): _num(number) {}

bool operator!=(const number_t &number1, const number_t &number2) {
  return (number1._num != number2._num);
}
bool operator<(const number_t &number1, const number_t &number2) {
  return (number1._num < number2._num);
}
bool operator<=(const number_t &number1, const number_t &number2) {
  return (number1._num <= number2._num);
}
bool operator>(const number_t &number1, const number_t &number2) {
  return (number1._num > number2._num);
}
bool operator>=(const number_t &number1, const number_t &number2) {
  return (number1._num >= number2._num);
}
ostream &operator<<(ostream &os, const number_t &number) {
  os << number._num;
  return os;
}
istream &operator>>(istream &is, number_t &number) {
  is >> number._num ;
  return is;
}
number_t operator+(const number_t &number1, const number_t &number2) {
  return number1._num + number2._num;
}
number_t &number_t::operator+=(const number_t &number) {
  _num+=number._num;
  return *this;
}
number_t operator-(const number_t &number1, const number_t &number2) {
  return number1._num - number2._num;
}
number_t &number_t::operator-=(const number_t &number) {
  _num-=number._num;
  return *this;
}
number_t operator*(const number_t &number1, const number_t &number2) {
  return number1._num * number2._num;
}
number_t &number_t::operator*=(const number_t &number) {
  _num*=number._num;
  return *this;
}
number_t operator/(const number_t &number1, const number_t &number2) {
  return number1._num / number2._num;
}
number_t &number_t::operator/=(const number_t &number) {
  _num/=number._num;
  return *this;
}
number_t operator%(const number_t &number1, const number_t &number2) {
  return number1._num % number2._num;
}
number_t &number_t::operator%=(const number_t &number) {
  _num%=number._num;
  return *this;
}
number_t operator^(const number_t &number1, const number_t &number2) {
  return number1._num ^ number2._num;
}
number_t &number_t::operator^=(const number_t &number) {
  _num^=number._num;
  return *this;
}
number_t operator&(const number_t &number1, const number_t &number2) {
  return number1._num & number2._num;
}
number_t &number_t::operator&=(const number_t &number) {
  _num&=number._num;
  return *this;
}
number_t operator|(const number_t &number1, const number_t &number2) {
  return number1._num | number2._num;
}
number_t &number_t::operator|=(const number_t &number) {
  _num|=number._num;
  return *this;
}
number_t &number_t::operator++() {
  ++_num;
  return *this;
}
number_t number_t::operator++(int) {
  return number_t(_num++);
}
number_t &number_t::operator--() {
  --_num;
  return *this;
}
number_t number_t::operator--(int) {
  return number_t(_num--);
}
number_t number_t::operator-() const{
  return number_t(-_num);
}
number_t number_t::operator+() const {
  return number_t(+_num);
}
number_t number_t::operator~() const{
  return number_t(~_num);
}
number_t &number_t::operator<<=(const number_t & number) {
  _num <<= number._num;
  return *this;
}
number_t &number_t::operator>>=(const number_t &number) {
  _num >>= number._num;
  return *this;
}
number_t operator<<(const number_t &number1, const number_t &number2) {
  return number1._num << number2._num;
}
number_t operator>>(const number_t &number1, const number_t &number2) {
  return number1._num >> number2._num;
}
number_t number_t::operator!() const {
  return number_t(!_num);
}
