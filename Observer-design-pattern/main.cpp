#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

enum State { WIN, LOSE, INCREASE_HP, GAME_PLAY};
class Observer{
public:
    virtual ~Observer(){}
    virtual void onNotify(State state) = 0;
};



class Subject{
private:
    vector<Observer*> observers;
    State state;

public:
    void attach(Observer* o){ observers.push_back(o); }

    void setState(State curr_state){
        state = curr_state;
        notifyObservers();
    }

    void notifyObservers(){
        for(auto o : observers){
            o->onNotify(state);
        }
    }

};


class Audio : public Observer{
private:
    void onNotify(State state) override{
        
        switch(state){
            case WIN:
                cout<<"play win music\n";
                break;
            case LOSE:
                cout<<"play lose sound\n";
                break;
            case INCREASE_HP:
                cout<<"play hp increase sound\n";
                break;
            default:
                cout<<"play gamplay theme\n";
                break;
        }
    }
};

class Character : public Observer{
private:
    void onNotify(State state) override{
        switch(state){
            case WIN:
                cout<<"increase character level by 1\n";
                break;
            case LOSE:
                cout<<"Decrease health by 5\n";
                break;
            case INCREASE_HP:
                cout<<"Increase HP by 20\n";
                break;
            default:
                cout<<"Normal game play\n";
                break;
        }
    }
};

class Engine{
public:
    Engine(Subject* subject) : _subject(subject){}

    void run(){

        for(int i=0; i<10; i++){
            _subject->setState(static_cast<State>(rand() % 4));
        }
    }

private:
    Subject* _subject;
};

int main(){
    srand(time(0));
    Subject* subject = new Subject();

    Audio* audio = new Audio();
    Character* character = new Character();

    subject->attach(audio);
    subject->attach(character);

    Engine engine(subject);
    engine.run();
    return 0;
}

