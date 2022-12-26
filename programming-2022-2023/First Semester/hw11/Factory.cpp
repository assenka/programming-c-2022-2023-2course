#include <iostream>
#include <vector>

using namespace std;

class Drink{
protected:
    string information;
public:
    virtual void info() = 0;
    virtual ~Drink() {}
};

class WhiteRussian : public Drink {
public:
    void info() override {
        cout << "your drink has 25-30 degrees and it is called white russian" << endl;
    }
};

class Yorsh : public Drink {
public:
    void info () override {
        cout << "your drink has smth about 40 degrees and it is called yorsh" << endl;
    }
};

class DrinkFactory{
public:
    ~DrinkFactory() {};
    virtual Drink* createDrink() = 0;
};

class WR_Factory : public DrinkFactory {
public:
    Drink* createDrink(){
        return new WhiteRussian;
    }
};

class YorshFactory : public DrinkFactory{
public:
    Drink* createDrink() {
        return new Yorsh;
    }
};

int main() {
    WR_Factory* wr_factory =  new WR_Factory;
    YorshFactory* yorsh_factory = new YorshFactory;

    vector <Drink*> d;
    d.push_back(wr_factory->createDrink());
    d.push_back(yorsh_factory->createDrink());

    for (int i = 0; i < d.size(); i++) {
        d[i]->info();
    }

    return 0;
}
