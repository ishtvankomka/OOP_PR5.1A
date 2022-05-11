#include <iostream>
#include "IntRange.hpp"
using namespace std;

void _unexpected_to_bad()
{
    cerr << "bad_exception" << endl;
    throw;
}

int main() {
    set_unexpected(_unexpected_to_bad);
    set_terminate(_unexpected_to_bad);

    try
    {
        int first1, second1, check1;
        cout << "First range:" << endl;
        cout << " From "; cin >> first1;
        cout << " to "; cin >> second1;
        IntRange i1(first1, second1);
        cout << "Check the number "; cin >> check1;
        i1.checkResult(check1);
    }
    catch (invalid_argument e)
    {
        cerr << e.what() << endl;
    }
    
    try
    {
        int first2 = 0, second2 = 1, check2 = 0;
        cout << "First range:" << endl;
        cout << " From " << first2 << endl;
        cout << " to " << second2 << endl;
        IntRange i2(first2, second2);
        cout << "Check the number " << check2 << endl;
        i2.checkResult(check2);
        cout << " --first" << endl;
        --i2;
    }
    catch (Exception* e)
    {
        cerr << e->What() << endl;
    }
    catch (Exception& e)
    {
        cerr << e.What() << endl;
    }
    
    try
    {
        int first3, second3, check3;
        cout << "First range:" << endl;
        cout << " From "; cin >> first3;
        cout << " to "; cin >> second3;
        IntRange i3;
        i3.set_first(first3);
        i3.set_second(second3);
        cout << "Check the number "; cin >> check3;
        i3.checkResult(check3);
    }
    catch (MyException* e)
    {
        cerr << e->What() << endl;
    }
    catch (MyException& e)
    {
        cerr << e.What() << endl;
    }
    
    return 0;
}
