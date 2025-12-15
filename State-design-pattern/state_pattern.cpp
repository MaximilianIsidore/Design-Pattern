#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

enum Input{
    PRESS_B,
    PRESS_DOWN,
    RELEASE_DOWN,
    PRESS_R
};

class Hero;
class JumpingState;
class StandingState;
class DivingState;
class DuckingState;

class HeroState {
public:
    virtual ~HeroState() = default;
    virtual void handleInput(Hero& hero, Input input) = 0;
};

class StandingState : public HeroState {
public:
    void handleInput(Hero& hero, Input input) override;
    static StandingState* instance();
};

class JumpingState : public HeroState {
public:
    void handleInput(Hero& hero, Input input) override;
    static JumpingState* instance();
};

class DuckingState : public HeroState {
public:
    void handleInput(Hero& hero, Input input) override;
    static DuckingState* instance();
};

class DivingState : public HeroState {
public:
    void handleInput(Hero& hero, Input input) override;
    static DivingState* instance();
};



class Hero{
public:
    Hero(string name, int strength): name_(name), strength_(strength_){}

    void handleInput(Input input){
        state_->handleInput(*this, input);
    }
    void setState(HeroState* state){
        state_ = state;
    }
    void say(const string& msg){
        cout<<name_<<" "<<msg<<"\n";
    }
private:
    string name_;
    int strength_;
    HeroState* state_;
};



void StandingState::handleInput(Hero& hero, Input input){
    if (input == PRESS_B) {
        hero.say("is jumping");
        hero.setState(JumpingState::instance());
    } else if (input == PRESS_DOWN) {
        hero.say("is ducking");
        hero.setState(DuckingState::instance());
    }
}

StandingState* StandingState::instance() {
    static StandingState s;
    return &s;
}


void JumpingState::handleInput(Hero& hero, Input input){
    if (input == PRESS_DOWN) {
        hero.say("is diving");
        hero.setState(DivingState::instance());
    }
}

JumpingState* JumpingState::instance() {
    static JumpingState s;
    return &s;
}



void DivingState::handleInput(Hero& hero, Input input){
    if (input == RELEASE_DOWN) {
        hero.say("stopped diving");
        hero.setState(JumpingState::instance());
    } else if (input == PRESS_R) {
        hero.say("landed well");
        hero.setState(StandingState::instance());
    }
}

DivingState* DivingState::instance() {
    static DivingState s;
    return &s;
}


void DuckingState::handleInput(Hero& hero, Input input){
    if(input == RELEASE_DOWN){
        hero.say("is standing again");
        hero.setState(StandingState::instance());
    }
}
DuckingState* DuckingState::instance(){
    static DuckingState s;
    return &s;
}


int main(){
    srand(time(0));

    Hero hero("ninja", 50);
    hero.setState(StandingState::instance());

    for(int i=0; i<20; i++){
        hero.handleInput(static_cast<Input>(rand()%4));
    }
    return 0;
}