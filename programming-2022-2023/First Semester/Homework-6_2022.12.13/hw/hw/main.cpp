#include <iostream>
#include <exception>
#include <vector>
#include <stdexcept>
using namespace std;

class Data{
private:
    int year, day, month;
public:
    class IncorrectData{
    };
    Data(int year, int month, int day){
        if (year > 2022 || month > 12 || day > 31 || day < 1 || year < 1 || month < 1 || (month == 2 && day > 28) || (month == 4 && day > 30) || (month == 6 && day > 30) || (month == 9 && day > 30) || (month == 11 && day > 30)){
            throw IncorrectData();
        }
        this->year = year;
        this->month = month;
        this->day = day;
    }
    void getData(){
        cout << this->year << "." << this->month << "." << this->day << endl;
    };
};
int main(int argc, const char * argv[]) {
    // first one
    vector <int> v(10);
    int i;
    cin >> i;
    try{
        if (i > v.size()){
            throw out_of_range("AAAAAAAAAAA");
        }
            cout << v[i] << endl;
    }
    catch(out_of_range e){
            cout << "Array index out of range" << e.what() << endl;
    };
    // second one
    Data m(2010, 10, 10) ;
    m.getData();
    Data n(-10, 10, 10);
    n.getData();
    
    return 0;
}


