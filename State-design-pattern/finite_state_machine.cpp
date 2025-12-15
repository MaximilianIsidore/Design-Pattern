#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

enum State{
    STATE_STANDING,
    STATE_JUMPING,
    STATE_DUCKING,
    STATE_DIVING
};

enum Input{
    PRESS_B,
    PRESS_DOWN,
    RELEASE_DOWN,
    PRESS_R
};

class Hero{
public:
    Hero(string name, int strength):name_(name), strength_(strength){
        state_ = STATE_STANDING;
    }

    void handleInput(Input input);
private:
    string name_;
    int strength_;
    State state_;
};

void Hero::handleInput(Input input){
    switch(state_){
        case STATE_STANDING:
            if(input == PRESS_B){
                state_ = STATE_JUMPING;
                cout<<name_<<" is jumping\n";
            }
            else if(input == PRESS_DOWN){
                state_ = STATE_DUCKING;
                cout<<name_<<" is ducking\n";
            }
            break;
        case STATE_JUMPING:
            if(input == PRESS_DOWN){
                state_ = STATE_DIVING;
                cout<<name_<<" is diving\n";
            }
            break;
        case STATE_DUCKING:
            if(input == RELEASE_DOWN){
                state_ = STATE_STANDING;
                cout<<name_<<" is stading again\n";
            }
            break;
        case STATE_DIVING:
            if(input == RELEASE_DOWN){
                state_ = STATE_JUMPING;
                cout<<name_<<" stopped diving\n";
            }
            else if(input == PRESS_R){
                state_ = STATE_STANDING;
                cout<<name_ <<" landed well\n";
            }
            break;
        default:
            cout<<"Not a valid move\n";
            break;
    }
};

int main(){
    srand(time(0));
    Hero hero("Ninja", 50);

    for(int i=0; i<20; i++){
        hero.handleInput(static_cast<Input>(rand()%4));
    }
    return 0;
}