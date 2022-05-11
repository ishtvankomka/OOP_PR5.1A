#include "IntRange.hpp"
#include "Exception.hpp"
#include "MyException.hpp"
#include <iostream>
#include <sstream>

using namespace std;

IntRange::IntRange() {
    first = 0;
    second = 0;
}

IntRange::IntRange(int f, int s) {
    if(s <= f)
    {
        throw invalid_argument("invalid_argument: Second value less or equal first!");
    }
    first = f;
    second = s;
}

IntRange::IntRange(IntRange& a) {
    first = a.first;
    second = a.second;
}

IntRange& IntRange::operator ++() {
    ++first;
    return *this;
}



IntRange IntRange::operator ++(int) {
    IntRange t(*this);
    second++;
    return t;
}

IntRange IntRange::operator --(int) {
    IntRange t(*this);
    second--;
    return t;
}

IntRange& IntRange::operator --() {
    if(get_first() == 0)
    {
        throw Exception("Exception: You can't decrease 0!");
    }
    else
    {
        --first;
    }
    return *this;
}

void IntRange::set_second(int s)
{
    if (s <= get_first())
    {
        throw MyException("MyException: Second value less or equal first!");
    }
    second = s;
}

IntRange& IntRange::operator = (const IntRange& f) {
    first = f.first;
    second = f.second;
    return *this;
}

istream& operator >> (istream& in, IntRange& a)
{
    int afirst,asecond;
    cout << " From "; cin >> afirst;
    cout << " to "; cin >> asecond;
    a.set_first(afirst);
    a.set_second(asecond);
    return in;
}

ostream& operator << (ostream& out, const IntRange& a)
{
    out << string(a);
    return out;
}

IntRange::operator string () const
{
    stringstream a;
    a << "The range is [" << first << "; " << second << ")" << endl;
    return a.str();
}

void Read(IntRange& a)
{
    cout << "Set the range" << endl; cin >> a;
}

void Display(IntRange& a)
{
    cout << a;
}

int IntRange::rangeСheck(int number)
{
    if(first <= number && number < second)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void IntRange::checkResult(int number)
{
    if(rangeСheck(number))
    {
        cout << "The number is in the range" << endl;
    }
    else{
        cout << "The number isn't in the range" << endl;
    }
}
