#include<iostream>
#include<cmath>
using namespace std;

// look up polymorphisum

class Animal {
    public:
        virtual void Speak() = 0;
};

class Dog : public Animal {
    public:
        void Speak();
};

class Cat : public Animal {
    public:
        void Speak();
};

void Dog::Speak() {
    cout << "Bark" << endl;
}

void Cat::Speak() {
    cout << "Meow" << endl;
}

void makeAnimalTalk(Animal * animal) {
    animal -> Speak();
}

int main() {
    Animal * animal1 = new Dog();
    Animal * animal2 = new Cat();

    /*animal1 -> Speak();
    animal2 -> Speak();*/

    makeAnimalTalk(animal1);
    makeAnimalTalk(animal2);

    delete animal1;
    delete animal2;

    return 0;
}
