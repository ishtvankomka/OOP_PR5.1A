#pragma once
#include <iostream>
#include <string>
#include "Exception.hpp"
#include "MyException.hpp"
using namespace std;

class IntRange
{
private:
    int first, second;
    
public:
    IntRange();
    IntRange(int, int);
    IntRange(IntRange&);
    
    IntRange& operator = (const IntRange&);
    
    IntRange& operator ++();
    IntRange& operator --();
    IntRange operator ++(int);
    IntRange operator --(int);
    
    operator string() const;
    friend ostream& operator << (ostream&, const IntRange&);
    friend istream& operator >> (istream&, IntRange&);
    
    friend void Read(IntRange&);
    friend void Display(IntRange&);
    
    int get_first() const {return first;};
    int get_second() const {return second;};
    void set_first(int value) {first = value;};
    void set_second(int value);
    
    int rangeСheck(int);
    void checkResult(int);
};
