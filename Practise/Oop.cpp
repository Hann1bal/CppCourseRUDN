#include <iostream>

using namespace std;

/*
public - доступен всем 
private - доступен внутри и друзьями класса или функций
protected - доступен внутри и друзьями класса или функций и в т.ч наследниками

*/
class Animal {
protected:
    string name;
    string classis;
    string sound;
    string food;
    string color;
    /*
    0-very small
    ...
    10 - very big
    */
    unsigned short size;
public:
    Animal(string name, string classis, string sound, string food, string color, unsigned short size) {
        this->classis = classis;
        this->color = color;
        this->food = food;
        this->name = name;
        this->size = size;
        this->sound = sound;
    }
    void breathe() {
        cout << "inhale" << "  " << " exhale" << endl;;
    }
    void meal() {
        cout << "ate "<<this->food << endl;;
    }
    void meal(string unusualFood) {
        cout << "ate " << unusualFood << endl;;
    }
    void meal(short time) {
        cout << "ate " << this->food <<" " << time << " times" << endl;;
    }
    void makeASound()
    {
        cout << "says: " << this->sound << endl;;
    }
    ~Animal() {
        cout << this->name << " was killed" << endl;;
    }
};

class Elephant : public Animal {
private:
    unsigned short tusksSize;
    const bool wool = false;
public: 
    Elephant(string name, string classis, string sound, string food, string color, unsigned short size, unsigned short tusksSize) :Animal(name, classis, sound, food, color, size)
    {
        this->tusksSize = tusksSize;
    }
    void breathe() {
        cout << this->name << "make it one more time" << endl;;
    }
    void waterInTrunk()
    {
        cout << "набрал воды в хобот" << endl;
    }
    ~Elephant() 
    {
        cout << "was killed" << endl;
    }
};

class Cow : public Animal {
private:
    unsigned short hornsSize;
    unsigned short milkBucketCount;
public:
    Cow(string name, string classis, string sound, string food, string color, unsigned short size, unsigned short hornsSize, unsigned short milkBucketCount) :Animal(name, classis, sound, food, color, size)
    {
        this->hornsSize = hornsSize;
        this->milkBucketCount = milkBucketCount;
    }
    void breathe() {
        cout << this->name <<"make it two more time" << endl;;
    }
    void milk()
    {
        cout << "give " << this->milkBucketCount << "at noon" << endl;
    }
    ~Cow() {
        cout << "was killed" << endl;;
    }
};

int main()
{
    Cow *cow = new Cow("Burenka", "Mamal", "mooo", "grass", "multi", 4, 6, 2);
    Elephant* eleph = new Elephant("Djambo", "Mamaml", "BLOWING", "Grass and foliage", "grey", 9, 10);
    cow->breathe();
    cow->milk();
    cow->meal();
    cow->meal("apple");
    cow->meal(6);
    eleph->makeASound();
    cow->makeASound();
    eleph->breathe();
    eleph->waterInTrunk();
    eleph->meal();
    delete eleph;
    delete cow;
}    