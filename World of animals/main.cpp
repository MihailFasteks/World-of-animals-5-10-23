//
//  main.cpp
//  World of animals
//
//  Created by Michalis on 16.12.2023.
//

#include <iostream>
#include <string.h>
using namespace std;

class Continent{
    
};
class Africa: public Continent{
    
};
class NorthAmerica: public Continent{
    
};



class Herbivore{ //Абстрактный класс травоядных
protected:
    float weight;
    bool isAlive=true;
public:
    Herbivore(int weight):weight(weight){};
    
    float getWeight() const {
           return weight;
    }
    bool isAliveStatus() const {
           return isAlive;
    }
    void setIsAlive(bool v){
        isAlive=v;
    }
    virtual void eatGrass()=0;
};

class Wildebeest:public Herbivore{
public:
    Wildebeest(float weight):Herbivore(weight){};
    void eatGrass() override{
        weight+=10;
        cout<<"Wildebeest is eating..."<<endl;
    }
};
class Bison: public Herbivore{
public:
    Bison(float weight):Herbivore(weight){};
    void eatGrass() override{
        weight+=10;
        cout<<"Bison is eating..."<<endl;
    }
};



class Carnivore{ //Абстрактный класс хищников
protected:
    int power;
public:
    Carnivore(int power):power(power){};
    virtual void Eat(Herbivore *animal)=0;
};


class Lion: public Carnivore{
public:
    Lion(float power):Carnivore(power){};
    void Eat(Herbivore *animal) override{
        if(power>=animal->getWeight()){
            power+=10;
        }
        else{
            power-=10;
        }
        animal->setIsAlive(false);
        cout<<"Lion is eating..."<<endl;
    }
};


class Wolf: public Carnivore{
public:
    Wolf(float power):Carnivore(power){};
    void Eat(Herbivore *animal) override{
        if(power>=animal->getWeight()){
            power+=10;
        }
        else{
            power-=10;
        }
        animal->setIsAlive(false);
        cout<<"Wolf is eating..."<<endl;
    }
};
class AnimalWorld {
public:
    void mealsHerbivores(Herbivore *herbivore) {
        herbivore->eatGrass();
        cout<<"Herbovores are eating"<<endl;
    }

    void nutritionCarnivores(Carnivore *carnivore, Herbivore *herbivore) {
        carnivore->Eat(herbivore);
        cout<<"Carnivores are eating"<<endl;
    }
};

int main() {
    
    Wildebeest wildebeest(50);
        Bison bison(60);
        Lion lion(80);
        Wolf wolf(70);

        AnimalWorld animalWorld;

        // Кормление травоядных
        animalWorld.mealsHerbivores(&wildebeest);
        animalWorld.mealsHerbivores(&bison);

        // Питание хищников
        animalWorld.nutritionCarnivores(&lion, &wildebeest);
        animalWorld.nutritionCarnivores(&wolf, &bison);
    return 0;
}
