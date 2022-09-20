#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Used to reduce Heap Fragmentation
 * By means of reducing the heap allocation
 * 
 * Use sharing to support large numbers of fine-grained objects efficiently
 * 
 * Uses Factory Pattern to store objects in cache
 */

class TreeType {
    protected:
        string name;
        string color;
        string texture;

    public:
        TreeType(string name, string color, string texture) {
            this->name = name;
            this->color = color;
            this->texture = texture;
        }

        void draw(int x, int y) {
            cout << "Drawed at x = " << x << " and y = " << y << "\n";
        }
};

class Tree {
    protected:
        int x, y;
        TreeType *treeType;
    
    public:
        Tree(int x, int y, TreeType *&treeType) {
            this->x = x;
            this->y = y;
            this->treeType = treeType;
        }

        void draw(){
            this->treeType->draw(this->x, this->y);
        }
};

int main(){
    return 0;
}