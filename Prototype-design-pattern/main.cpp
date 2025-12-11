#include <iostream>
#include<vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Monster{
public:
    virtual ~Monster(){};
    virtual Monster* clone() = 0;
};

class Ghost : public Monster{
public:
    Ghost(int health, int speed) : health_(health), speed_(speed){
        cout<<"Ghost created \n";
    }

    Monster* clone() override{
        return new Ghost(*this);
    }

private:
    int health_;
    int speed_;
};

class FireDragon : public Monster{
public:
    FireDragon(int health, int speed, int fireDamage) : health_(health), speed_(speed), fireDamage_(fireDamage){
        cout<<"Fire Dragon created\n";
    }

    Monster* clone() override{
        return new FireDragon(*this);
    }

private:
    int health_;
    int speed_;
    int fireDamage_;
};

class Spwaner{
public:
    Spwaner(Monster* prototype): prototype_(prototype)
  {}

  Monster* spawnMonster()
  {
    return prototype_->clone();
  }

private:
  Monster* prototype_;
};


int main(){
    srand(time(0));

    Ghost* weakGhost = new Ghost(10, 5);
    Ghost* strongGhost = new Ghost(50, 16);

    FireDragon* dragon = new FireDragon(30,20, 10);

    Spwaner weakGhostSpawn(weakGhost);
    Spwaner strongGhostSpawn(strongGhost);
    Spwaner dragonSpwan(dragon);

    vector<Monster*> monster_list; //for later use

    for(int i=0; i<20; i++){
        int choice = rand()%3;

        switch(choice){
            case 0:
                monster_list.push_back(weakGhostSpawn.spawnMonster());
                break;
            case 1:
                monster_list.push_back(strongGhostSpawn.spawnMonster());
                break;
            case 2:
                monster_list.push_back(dragonSpwan.spawnMonster());
                break;
            default:
                cout<<"NO monsters spwaned\n";
                break;
        }
    }

    for(auto o : monster_list){
        delete o;
    }

    delete weakGhost;
    delete strongGhost;
    delete dragon;
    
    return 0;
}