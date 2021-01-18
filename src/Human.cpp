#include "Human.h"
#include <iostream>


Human::~Human(){
  std::cout << "Deconstructor: Human" << std::endl;
  shapeMap->clear();
  player = nullptr;
};

Action::~Action(){
 std::cout << "Deconstructor: Action" << std::endl;
}


Action::Action(const Action &source){
  // time=source.time;
   type = source.type;
} // 2 : copy constructor

Action& Action::operator=(const Action &source){
   if (this == &source)
      return *this;
  // time = source.time;
   type = source.type;
   return *this;
} // 3 : copy assignment operator

Action::Action(Action &&source){
 //  time=std::move(source.time);
   type = std::move(source.type);
} // 4 : move constructor

Action& Action::operator=(Action &&source){
   if (this == &source)
      return *this;
 //  time=std::move(source.time);
   type = std::move(source.type);
   return *this;
}//6 5:move assignment operator
/**
int Action::getTime(){
   return time;
}**/
/* 
rule of 5 needed for Action class
*/

Human::Human(float x_, float y_, float width_, float height_, float speed_){
   x = x_;
   y = y_;
   width = width_; 
   height = height_; 
   shapeMap = new Array2D<int> (width, height);
   //define Shape
  // std::cout << "here" <<std::endl;
 
   for (int i=0; i<width;i++){
      for (int j=0; j<height;j++){
        shapeMap->operator()(i,j) = 1;
  
      }  
   }
  // std::cout << "here1" <<std::endl;
   speed = speed_;
   type = GOType::HUMAN;
   Agent::count++;;
   id=Agent::count;
}


  //TODO implement player/clone behaviour

Human::Human(const Human &source){
   std::cout << "Human: Copy constructor "<< this << std::endl;
   speed = source.speed;
   dying = source.dying;
   id = source.id;
   height = source.height;
   width = source.width;
   x_cen = source.x_cen; //relative to top left shape map x
   y_cen = source.y_cen; //relative to top left shape map y
   shapeMap = source.shapeMap; //= operator copies vector
   remove= source.remove;
   x = source.x;
   y = source.y;
   type = source.type;
   tele = source.tele;
} // 2 : copy constructor

Human& Human::operator=(const Human &source){
   std::cout << "Human: Copy assignment constructor "<< this << std::endl;
    if (this == &source)
      return *this;
   speed = source.speed;
   dying = source.dying;
   id = source.id;
   height = source.height;
   width = source.width;
   x_cen = source.x_cen; //relative to top left shape map x
   y_cen = source.y_cen; //relative to top left shape map y
   shapeMap = source.shapeMap; //= operator copies vector
   remove= source.remove;
   x = source.x;
   y = source.y;
   type = source.type;
   tele = source.tele;
   return *this;
} // 3 : copy assignment operator

Human::Human(Human &&source){
   std::cout << "Human Assignment Constructor" << std::endl;
   speed = std::move(source.speed);
   dying = std::move(source.dying);
   id = std::move(source.id);
   height = std::move(source.height);
   width = std::move(source.width);
   x_cen = std::move(source.x_cen); //relative to top left shape map x
   y_cen = std::move(source.y_cen); //relative to top left shape map y
   shapeMap = std::move(source.shapeMap); //= operator copies vector
   remove= std::move(source.remove);
   x = std::move(source.x);
   y = std::move(source.y);
   type = std::move(source.type);
   tele = std::move(source.tele);
}
Human& Human::operator=(Human &&source){
    std::cout << "Human Move Assignment Operator" << std::endl;
    if (this == &source)
      return *this;
   speed = std::move(source.speed);
   dying = std::move(source.dying);
   id = std::move(source.id);
   height = std::move(source.height);
   width = std::move(source.width);
   x_cen = std::move(source.x_cen); //relative to top left shape map x
   y_cen = std::move(source.y_cen); //relative to top left shape map y
   shapeMap = std::move(source.shapeMap); //= operator copies vector
   remove= std::move(source.remove);
   x = std::move(source.x);
   y = std::move(source.y);
   type = std::move(source.type);
   tele = std::move(source.tele);
   return *this;
} // 5 : move assignment operator
/**
Player::Player(){
   actions = std::vector<unique_ptr<Action>>();
};**/

Player::Player(const Player &source){
   std::cout << "Player: Copy constructor "<< this << std::endl;
   human =source.human;
   current =source.current; //current action
   moveNum = source.moveNum;
   actions.clear();
   for (auto& a : source.actions){
      Action a_ = *a.get(); //apply copy constructor of TitleBin
      actions.push_back(std::make_unique<Action>(a_));
   }
} // 2 : copy constructor

Player& Player::operator=(const Player &source){
   std::cout << "Player: Copy assignment constructor "<< this << std::endl;
   if (this == &source)
      return *this;
   human = source.human;
   current =source.current; //current action
   moveNum = source.moveNum;
   actions.clear();
   for (auto& a : source.actions){
      Action a_ = *a.get(); //apply copy constructor of TitleBin
      actions.push_back(std::make_unique<Action>(a_));
   }
   return *this;
} // 3 : copy assignment operator

Player::Player(Player &&source){
   std::cout << "Player Assignment Constructor" << std::endl;
   human = std::move(source.human);
   current = std::move(source.current); //current action
   moveNum = std::move(source.moveNum);
   actions = std::move(source.actions);
   actions.clear();
   for (auto& a : source.actions){
      actions.push_back(std::move(a));
   }
} // 4 : move constructor

Player& Player::operator=(Player &&source){
   std::cout << "Player Move Assignment" << std::endl;
   if (this == &source)
      return *this;
   human = std::move(source.human);
   current = std::move(source.current); //current action
   moveNum = std::move(source.moveNum);
   actions = std::move(source.actions);
   actions.clear();
   for (auto& a : source.actions){
      actions.push_back(std::move(a));
   }
   return *this;
}//6 5:move assignment operator
void Player::setAction(Action::Type t){
    //add to action history
   // Action* a =  new Action(t, time);
  //  
   std::cout << "setting action " << t << std::endl;
   // current = new Action(t);
    std::unique_ptr<Action> a = std::make_unique<Action>(Action(t));
    current = a.get();
    actions.emplace_back(std::move(a));

    //actions.push_back(std::make_unique<Action>(t, time)); //move here each turn
    //set human behaviour

}

Player::~Player(){
   std::cout << "Deconstructor: Player" << std::endl;
  actions.clear();
  human = nullptr;
}

void Player::printInfo(){
   if (human != nullptr){
    std::cout << "human "<< human << " x " << human->getX() << " y " <<human->getX()  << " dying?" <<human->getDying() << std::endl;
   }
  
}
