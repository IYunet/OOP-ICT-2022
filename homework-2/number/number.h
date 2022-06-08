#pragma once

#include <cstdint>
#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::istream;

class number_t {
public:
  int64_t _num;

  number_t(); // конструктор по умолчанию
  number_t(int64_t number); // конструктор с параметрами
  number_t(const number_t &number); // Конструктор копирования

  number_t& operator=(int64_t &number);  // перегрузка оператор присваивания
  number_t& operator=(int number);  // перегрузка оператор присваивания

  explicit operator bool()const; // перегрузка булевого оператора
  explicit operator int64_t()const; // перегрузка для преобразование в int_64
  explicit operator string()const; // перегрузка для преобразование в string

  friend bool operator== (const number_t &number1, const number_t &number2);  // перегрузка оператора присваивания
  friend bool operator!= (const number_t &number1, const number_t &number2);  // перегрузка оператора не равно
  friend bool operator< (const number_t &number1, const number_t &number2);  // перегрузка оператора меньше
  friend bool operator<= (const number_t &number1, const number_t &number2);  // перегрузка оператора меньше или равно
  friend bool operator> (const number_t &number1, const number_t &number2);  // перегрузка оператора больше
  friend bool operator>= (const number_t &number1, const number_t &number2);  // перегрузка оператора больше или равно

  friend ostream& operator<<(ostream& os, const number_t& number); // перегрузка вывода в консоль (потоки)
  friend istream& operator>>(istream& is, number_t& number); // перегрузка вводы в консоль (потоки)

  friend number_t operator+ (const number_t &number1, const number_t &number2);  // перегрузка оператора сложения
  number_t& operator+=(const number_t& number); // перегрузка оператора +=

  friend number_t operator- (const number_t &number1, const number_t &number2);  // перегрузка оператора вычитания
  number_t& operator-=(const number_t& number); // перегрузка оператора -=

  friend number_t operator* (const number_t &number1, const number_t &number2);  // перегрузка оператора умножения
  number_t& operator*=(const number_t& number); // перегрузка оператора *=

  friend number_t operator/ (const number_t &number1, const number_t &number2);  // перегрузка оператора деления
  number_t& operator/=(const number_t& number); // перегрузка оператора /=

  friend number_t operator% (const number_t &number1, const number_t &number2);  // перегрузка оператора остатка
  number_t& operator%=(const number_t& number); // перегрузка оператора %=

  friend number_t operator^ (const number_t &number1, const number_t &number2);  // перегрузка оператора Побитовое исключающее ИЛИ (XOR)
  number_t& operator^=(const number_t& number); // перегрузка оператора ^=

  friend number_t operator& (const number_t &number1, const number_t &number2);  // перегрузка оператора Побитовое И
  number_t& operator&=(const number_t& number); // перегрузка оператора &=

  friend number_t operator| (const number_t &number1, const number_t &number2);  // перегрузка оператора Побитовое ИЛИ
  number_t& operator|=(const number_t& number); // перегрузка оператора |=

  number_t& operator++();   // перегрузка оператора префиксный ++
  number_t operator++(int);   // перегрузка оператора постфиксный ++

  number_t& operator--();   // перегрузка оператора префиксный --
  number_t operator--(int);   // перегрузка оператора постфиксный --

  number_t operator-() const;   // перегрузка оператора смены знака -
  number_t operator+() const;   // перегрузка оператора смены знака +

  number_t operator~() const;  // Побитовое НЕ

  friend number_t operator<< (const number_t &number1, const number_t &number2); // перегрузка оператора побитового левого сдвига
  number_t &operator<<=(const number_t& number); // перегрузка оператора побитового левого сдвига присвоения
  friend number_t operator>> (const number_t &number1, const number_t &number2); // перегрузка оператора побитового правого сдвига
  number_t &operator>>=(const number_t& number); // перегрузка оператора побитового правого сдвига присвоения

  number_t operator!() const;  // перегрузка оператора не

};