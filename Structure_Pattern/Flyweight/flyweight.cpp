#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>

using namespace std;

/**
 * @brief Used to reduce Heap Fragmentation
 * By means of reducing the heap allocation
 * 
 * Use sharing to support large numbers of fine-grained objects efficiently
 * 
 * Uses Factory Pattern to store objects in cache
 */

enum PlayerType{
    COUNTER_TERRORIST = 0,
    TERRORIST
};

enum Weapon {
    AK47 = 0,
    MAVERICK,
    GUT_KNIFE,
    DESERT_EAGLE
};

class Player {
    protected:
        string task;
    public:
        virtual void assignWeapon(Weapon weapon) = 0;
        virtual void mission() = 0;

        virtual ~Player(){};
};

class Terrorist : public Player {
    private:
        string weapon;

    public:
        Terrorist(){
            this->task = "Plant BOMB";
        }

        void assignWeapon(Weapon weapon) override{
            switch (weapon)
            {
            case Weapon::AK47:
                this->weapon = "AK-47";
                break;
            case Weapon::DESERT_EAGLE:
                this->weapon = "Desert Eagle";
                break;
            case Weapon::GUT_KNIFE:
                this->weapon = "Gut Knife";
                break;
            case Weapon::MAVERICK:
                this->weapon = "Maverick";
                break;
            default:
                this->weapon = "RANDOM KNIFE";
                break;
            }
        }

        void mission() override{
            cout << "Terrorist with weapon " << this->weapon << "|" <<
        " Mission is " << this->task << "\n";
        }
};

class CounterTerrorist : public Player {
    private:
        string weapon;

    public:
        CounterTerrorist(){
            this->task = "DIFFUSE BOMB";
        }

        void assignWeapon(Weapon weapon) override{
            switch (weapon)
            {
            case Weapon::AK47:
                this->weapon = "AK-47";
                break;
            case Weapon::DESERT_EAGLE:
                this->weapon = "Desert Eagle";
                break;
            case Weapon::GUT_KNIFE:
                this->weapon = "Gut Knife";
                break;
            case Weapon::MAVERICK:
                this->weapon = "Maverick";
                break;
            default:
                this->weapon = "RANDOM KNIFE";
                break;
            }
        }

        void mission() override{
            cout << "Counter Terrorist with weapon " << this->weapon << "|" <<
        " Mission is " << this->task << "\n";
        }
};

class PlayerFactory {
    private:
        unordered_map<PlayerType, Player*, hash<int>> players;

    public:

        Player *getPlayer(PlayerType type){
            Player *player;

            unordered_map<PlayerType, Player*, hash<int>>::iterator iter;

            iter = this->players.find(type);

            if (iter != this->players.end()){
                player = iter->second;
            } 
            else {
                switch (type)
                {
                case PlayerType::TERRORIST:
                    cout << "Terrorist Created" << "\n";
                    player = new Terrorist();
                    break;
                case PlayerType::COUNTER_TERRORIST:
                    cout << "Counter Terrorist Created" << "\n";
                    player = new CounterTerrorist();
                    break;
                default:
                    cout << "Unreachabe Code" << "\n";
                    break;
                }
                this->players.insert({type, player});
            }
            return player;
        }

        ~PlayerFactory() {
            for (auto iter : this->players){
                delete iter.second;
            }
        }
};


int main(int argc, char const *argv[])
{
    PlayerFactory *playerFactory = new PlayerFactory();

    Player *p;

    for (int i = 0; i < 10; i++){
        p = playerFactory->getPlayer(PlayerType(rand() % 2));

        p->assignWeapon(Weapon(rand() % 4));
        
        p->mission();
    }

    delete playerFactory;
    delete p;

    return 0;
}

