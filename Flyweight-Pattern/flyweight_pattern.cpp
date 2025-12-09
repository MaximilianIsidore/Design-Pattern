#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Mesh{    
};

class Texture{
};

enum color {GREEN, RED, ORANGE};

class TreeModel {
public:
    Mesh mesh_;
    Texture bark_;
    Texture leaves_;
    
    TreeModel() {
        // expensive loading here
        cout << "TreeModel created (mesh + textures loaded once)\n";
    }
};

class TreeModelFactory {
public:
    static TreeModel* getModel() {
        static TreeModel model;   // created once
        return &model;
    }
};

class Tree{
public:
    Tree(color leafTint): leafTint_(leafTint),
                        model_(TreeModelFactory::getModel())
    {}

    color getLeafTint(){
        return leafTint_;
    }
private:
    TreeModel* model_;

    vector<int> position_;
    double height_;
    double thickness_;
    color leafTint_;
};


template <typename T>
class GPU{
public:
    GPU () {}

    void render(vector<T>& objects){
        for(auto object : objects){

            switch(object->getLeafTint()){
                case GREEN:
                    cout<<"Rendering... Tree with color Green\n";
                    break;
                case RED:
                    cout<<"Rendering... Tree with color Red\n";
                    break;
                case ORANGE:
                    cout<<"Rendering... Tree with color Orange\n";
                    break;
                default:
                    break;
            }
        }
    }
};



int main(){
    srand(time(0));
    vector<Tree*> graphics_stream;

    for(int i=0; i<100; i++){
      graphics_stream.push_back(new Tree(static_cast<color>(rand() % 3)));
    }

    GPU<Tree*> gpu;
    gpu.render(graphics_stream);

    return 0;
}
