#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;


class Object{
protected:
    string name;
    int weight;
    int cost;
public:
    Object(){};
    Object(string name, int weight, int cost);
    void RemoveObject(Object obj){cout << this->name << "was removed" << endl;};
    void SellObject(Object obj){cout << "Sold! +" << this->cost<< "zloty."<< endl;};
    ~Object(){};
};

class Weapon : public Object{
protected:
    int damage;
public:
    Weapon(){};
    Weapon(string name, int weight, int cost, int damage);
    ~Weapon(){};
};

class Food : public Object{
protected:
    int satiety;
    int healing;
public:
    Food(){};
    Food(int satiety, int healing){
        this->satiety = satiety;
        this->healing = healing;
    }
    ~Food(){};
    int get_satiety(){return this->satiety;};
    int get_healing(){return this->healing;};
    
};

class Attack{
protected:
    string name;
    int damage;
    int effort;
public:
    Attack(){this->name="base_attack"; this->damage=10; this->effort=5;};
    Attack(string name, int damage){
        this->name = name;
        this->damage = damage;
    };
    ~Attack(){};
    string get_name(){return this->name;};
    int get_damage(){return this->damage;};
    int get_effort(){return this->effort;};
};

class Magic : public Attack{
protected:
    string name;
    int mana_damage;
    int damage;
public:
    Magic(){this->mana_damage=1; this->damage=1;};
    Magic(int mana_damage, int damage){this->mana_damage=mana_damage;this->damage=damage;};
    ~Magic(){};
    string get_name(){return this->name;};
    int get_mana_damage(){return this->mana_damage;};
    int get_damage(){return this->damage;};
};

class Character{
protected:
    int health;
    int zloty;
    int satiety;
    int power;
    Object base_sword;
    Object base_shield;
    Food base_food;
    Attack base_attack;
    vector <Object> base_inventory;
    vector <Attack> attacks;
    friend class Food;
    friend class Attack;
public:
    Character(){
        this->health=100;
        this->zloty=50;
        this->satiety=100;
        this->power=100;
        this->base_inventory.push_back(this->base_sword);
        this->base_inventory.push_back(this->base_shield);
        this->attacks.push_back(this->base_attack);
    }
    Character(int health, int zloty, int satiety, int power, vector <Object> base_inventory){
        this->health = health;
        this->zloty = zloty;
        this->satiety = satiety;
        this->power = power;
        this->base_inventory = base_inventory;
    };
    virtual ~Character(){};
    void Take(Object obj){};
    void Remove(Object obj){};
    virtual void Zloty(){cout << this->zloty<< endl;};
    virtual void Trade(){};
    void Eat(Food base_food){
        cout << "+" << base_food.get_healing() << "health. + " << base_food.get_satiety() << "to satiety." << endl;
        this->health += base_food.get_healing();
        this->satiety += base_food.get_satiety();
    };
    virtual void attack(Attack one_of_attack){
        for (int i = 0; i < this->attacks.size(); i++){
            if (one_of_attack.get_name() == attacks[i].get_name()){
                this->power -= attacks[i].get_effort();
            }
        }
    };
};

class Wizard : public Character{
protected:
    int mana;
    vector <Magic> spells;
    Magic base_magic_attack;
public:
    Wizard(){this->mana=100; this->spells.push_back(this->base_magic_attack);};
    Wizard(int mana, vector <Magic> spells, Magic base_magic_attack){
        this->mana=mana;
        this->spells.push_back(this->base_magic_attack);
    };
    ~Wizard(){};
    virtual void attack(Magic one_of_attack){
        for (int i = 0; i < this->spells.size(); i++){
            if (one_of_attack.get_name() == spells[i].get_name()){
                this->mana -= spells[i].get_mana_damage();
            }
        }
    };
    int get_mana(){return this->mana;};
};

int main(){
    Character ch;
    ch.Zloty();
    Wizard w;
    Magic spell;
    vector <Magic> spells;
    spells.push_back(spell);
    w.attack(spell);
    cout << w.get_mana() << endl;
}
