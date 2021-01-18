#ifndef HUMAN_H
#define HUMAN_H

//#pragma once
#include "Agent.h"
#include <memory>
//##include "Human.fwd.h"
//#include "Player.fwd.h"
class Player;

class Action{

    public:
        enum Type{U, D, L, R, TL, TR, BL, BR, TELE, TT, NOTHING};
        //use the index of action to denote the move instance
        //int moveInstance;
        ~Action();
        Action(Type type_):type{type_}{};
        Action(const Action &source); // 2 : copy constructor
 		    Action &operator=(const Action &source); // 3 : copy assignment operator
   	    Action(Action &&source); // 4 : move constructor
   	    Action &operator=(Action &&source); 
        Type getType(){return type;};
      //  int getTime();
       
    private:
       // int time;
        Type type;
        //Action getCurrentAction(); 
};


class Human: public Agent{
  public:
    ~Human();
    Human (float x_, float y_, float width_, float height_, float speed_);
    Human(const Human &source); // 2 : copy constructor
 		Human &operator=(const Human &source); // 3 : copy assignment operator
   	Human(Human &&source); // 4 : move constructor
   	Human &operator=(Human &&source); // 5 : move assignment operator
    int getTele(){return tele;};
    void setTele(int tele_){tele = tele_;};
    int getTimetrav(){return timetrav;};
    void setTimetrav(int timetrav_){timetrav = timetrav_;};
    Player* getPlayer(){return player;};
    void setPlayer(Player* player_){player=player_;};
  //	void behaviour(int mapX, int mapY) override;
  protected:


  private:
    int initMoveNum; //use this field to referebce the time () the Human is created 
    Player* player;// if this field is null, then this is an AI and applies behaviour()
    int tele{0};
    int timetrav{5};

};
class Player{

    public:
        ~Player();
        Player(){};
        Player(const Player &source); // 2 : copy constructor
 		    Player &operator=(const Player &source); // 3 : copy assignment operator
   	    Player(Player &&source); // 4 : move constructor
   	    Player &operator=(Player &&source); 
        Human* getHuman(){return human;};
        void setHuman(Human* human_){human = human_;};
        void setAction(Action::Type t);
        void printInfo();

        Action* getCurrentAction(){return current;};
    private:
     //Player();
      std::vector<std::unique_ptr<Action>> actions;
      Human* human;
      Action* current; //current action
      int moveNum{0};
   // private:
  
};
#endif