#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void print()
{
    cout << "printing..." << endl;
}

void printArg(int a)
{
    cout << a << endl;
}

int Extent(int a)
{
    return a*a;
}

int sum_of_two(int a, int b)
{
    return a + b;
}

using adr = void(*)();
using adr1 = void(*)(int a);
using adr1i = int(*)(int a);
using adr2 = int(*)(int a, int b);


class NoargLog
{
    int count;
    adr adress;
    ofstream OutputFile;

public:
    NoargLog(adr a)
    {
        this->count = 0;
        this->adress = a;
        OutputFile.open("Log.txt");
    }

    ~NoargLog()
    {
        OutputFile.close();
    }

    void operator()()
    {
        ++this->count;
        this->adress();
        OutputFile <<"Entering " << this->count << endl;
    }
};

class UnarLog
{
    int count;
    adr1 adress;
    ofstream OutputFile;
public:
    UnarLog(adr1 a)
    {
        this->count = 0;
        this->adress = a;
        OutputFile.open("Log1.txt");
    }

    ~UnarLog()
    {
        OutputFile.close();
    }

    void operator()(int arg)
    {
        ++this->count;
        this->adress(arg);
        OutputFile << "Entering " << this->count << endl;
        OutputFile << "Argument: " << arg << endl;
    }
};
class UnarLogi
{
    int count;
    adr1i adress;
    ofstream OutputFile;
public:
    UnarLogi(adr1i a)
    {
        this->count = 0;
        this->adress = a;
        OutputFile.open("Log1i.txt");
    }

    ~UnarLogi()
    {
        OutputFile.close();
    }

    int operator()(int arg)
    {
        ++this->count;
        OutputFile << "Entering " << this->count << endl;
        OutputFile << "Argument: " << arg << endl;
        OutputFile << "Value: " << this->adress(arg);
        return this->adress(arg);
    }
};

class BinarLog
{
    int count;
    adr2 adress;
    ofstream OutputFile;
public:
    BinarLog(adr2 a)
    {
        this->count = 0;
        this->adress = a;
        OutputFile.open("Log2.txt");
    }

    ~BinarLog()
    {
        OutputFile.close();
    }

    int operator()(int arg1, int arg2)
    {
        ++this->count;
        OutputFile << "Entering " << this->count << endl;
        OutputFile << "Arguments: " << arg1 << ", " << arg2 << endl;
        OutputFile << "Value: " << this->adress(arg1, arg2);
        return this->adress(arg1, arg2);
    }
};


int main()
{
    adr func0 = &print;
    adr1 func1 = &printArg;
    adr1i func1i = &Extent;
    adr2 func2 = &sum_of_two;

    NoargLog log(func0);
    UnarLog log1(func1);
    UnarLogi log1i(func1i);
    BinarLog log2(func2);

    log();
    log();
    log();
    log1(3);
    log1(32);
    cout << log1i(7) << endl;
    cout << log2(6, 10) << endl;

    return 0;
}

