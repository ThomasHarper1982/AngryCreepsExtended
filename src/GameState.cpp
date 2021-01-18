#include "GameState.h"
//#include "GameObject.h"
#include <random>
#include <iostream>

LevelState::~LevelState(){
     std::cout << "Deconstructor: LevelState" << std::endl;
 	//gameObjects.clear();
}


LevelState::LevelState(int time_):time{time_}{
  std::cout << "LevelState constructor "<< this << std::endl;
  gameObjects = std::vector<std::shared_ptr<GameObject>>();
}

LevelState::LevelState(const LevelState &source){
   std::cout << "LevelState Copy constructor "<< this << std::endl;
  // move = source.move;
   time = source.time;
   //transfer ownership of vector smart pointers
 //  std::vector<TileBin> bin = source.m_Items;
   gameObjects.clear();
   for (auto& g : source.gameObjects){
      // TileBin  t_ = t.get();
      GameObject g_ = *g.get(); //apply copy constructor of TitleBin
      gameObjects.push_back(std::make_shared<GameObject>(g_));
   }
} // 2 : copy constructor
LevelState& LevelState::operator=(const LevelState &source){
   std::cout << "LevelState Copy assignment "<< this << std::endl;
    if (this == &source)
      return *this;
   //move = source.move;
   time = source.time;
   gameObjects.clear();
   for (auto& g : source.gameObjects){
      // TileBin  t_ = t.get();
      GameObject g_ = *g.get(); //apply copy constructor of TitleBin
      gameObjects.push_back(std::make_shared<GameObject>(g_));
   }
   return *this;
} // 3 : copy assignment operator

LevelState::LevelState(LevelState &&source){
   std::cout << "LevelState Move Constructor "<< this << std::endl;
   gameObjects.clear();
   for (auto& g : source.gameObjects){
      gameObjects.push_back(std::move(g));
   }
  // moveNum = std::move(source.moveNum);
   time = std::move(source.time);
} // 4 : move constructor
LevelState& LevelState::operator=(LevelState &&source){
   std::cout << "LevelState Move Assignment Operator "<< this << std::endl;
   if (this == &source)
      return *this;
   gameObjects.clear();
   for (auto& g : source.gameObjects){
      gameObjects.push_back(std::move(g));
   }
  // moveNum = std::move(source.moveNum);
  time = std::move(source.time);    
  return *this;
} // 5 : move assignment operator 





/*
void GameState::flushAgents(bool deadOnly){


  if (!deadOnly){ //remove dead and alive
    gameObjects.clear();
    return;
  }
 // std::cout << "flushAgents start "  << gameObjects.size() <<  std::endl;
  for (auto& g : gameObjects){
  //  std::cout <<(*g.get()).getX() << " " <<(*g.get()).getY()  << " "  <<(*g.get()).toRemove() << std::endl;
      //  std::cout << (*g.get()) << " " << (*g.get())->toRemove() << std::endl;
  }
    gameObjects.erase(
        std::remove_if( // Selectively remove elements in the second vector...
            gameObjects.begin(),
            gameObjects.end(),
            [&] (std::unique_ptr<GameObject> const& p)
            {   // This predicate checks whether the element is contained
                // in the second vector of pointers to be removed...
                return false;//deadOnly && p.get()->toRemove();
            }),
        gameObjects.end()
        );


  //std::find_if(gameObjects.begin(), gameObjects.end(), [&parentToken](std::unique_ptr<GraphNode> &node) { return node.get()->GetID() == std::stoi(parentToken->second); });
    /*std::vector<std::unique_ptr<GameObject>>::iterator object = 
        find_if(gameObjects.begin(), gameObjects.end(),
                [&](std::unique_ptr<GameObject> & obj){return deadOnly; && obj.get()->toRemove();}
               );
        
 //   gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), *object));
    std::cout << "flush agents: end" << std::endl;  

}
*/
/**

void GameState::testCreatureShape(Creep* c){

      Array2D<int>* shapeMap = c->getShapeMap();
      std::cout << "Creep ID: " << c->getId() << std::endl;
      std::cout << "W " << c->getWidth() << " H: " << c->getHeight() << std::endl;
      for (int i =0; i < c->getWidth(); i++){
        for (int j = 0; j < c->getHeight(); j++){
            if (shapeMap->operator()(i,j)==1){
              std::cout << "("<<i << ", " <<j  <<")"<<std::endl;
            }
        }
      }
}

void GameState::testCreatureShapes(){
  //loop over the CreatureObjects
  for (GameObject* o : current.gameObjects){
    if (o->getType() == GameObject::GOType::CREEP){
      Creep* c = dynamic_cast<Creep*>(o);
      testCreatureShape(c);
      //test now does it retain a field set within Agent
    }
  }


}

void GameState::testDeletionMapPopulated(){
  
}

void GameState::testDyingCreatures(){

}
*/

GameState::GameState(const GameState &source){
    std::cout << "GameState Copy Constructor " <<  std::endl;
}

GameState& GameState::operator=(const GameState &source){
    std::cout << "Copy assignment "<< this << std::endl;
    if (this == &source)
      return *this;
   /* mapX = source.mapX;
		mapY = source.mapY;
		move = source.move;
		gameOver = source.gameOver;
		restartGame = source.restartGame;
    for (std::unique_ptr<LevelState> l : source.levelStates){
      LevelState source_l = l.get();
      LevelState l_ = LevelState(source_l); //apply copy constructor of TitleBin
      levelStates.push_back(std::move(std::make_unique<LevelState>(l_)));
    }
    detectionMap =  std::move(source.detectionMap);
    current = std::move(source.current);
		player = std::move(source.player);**/
  return *this;
}

GameState::GameState(GameState &&source){
    std::cout << "GameState Move Constructor"<< std::endl;
} // 4 : move constructor
GameState& GameState::operator=(GameState &&source){
    std::cout << "ChatBot Move Assignment Operator" << std::endl;
    if (this == &source)
      return *this;

    return *this;
}

GameState::~GameState(){
}

GameState::GameState(int mapX_, int mapY_):mapX(mapX_), mapY(mapY_){

  //detectionMap =  DetectionMap(mapX_, mapY_);
//Array2D<std::vector<Agent *, std::allocator<Agent *>> *> test = new Array2D<std::vector<Agent *, std::allocator<Agent *>> *>(mapX, mapY);
 // detectionMap =  Array2D<std::vector<Agent*>>(mapX_, mapY_);
 // detectionMap =  Array2D<std::unique_ptr<std::vector<Agent*>>>(mapX_, mapY_);
  // detectionMap = new Array2D<std::vector<Agent*>*>(mapX_, mapY_);
// typedef boost::multi_array<int, 2> array_type;
  //array_type detectionMap(boost::extents[mapX][mapY]);
  //detectionMap<Agent*>(mapX_,mapY_);
};


void GameState::flushAgents(bool deadOnly){

  if (!deadOnly){ //remove dead and alive
    gameObjects.clear();
    return;
  }
 // std::cout << "flushAgents start "  << gameObjects.size() <<  std::endl;
  for (auto& g : gameObjects){
  //  std::cout <<(*g.get()).getX() << " " <<(*g.get()).getY()  << " "  <<(*g.get()).toRemove() << std::endl;
      //  std::cout << (*g.get()) << " " << (*g.get())->toRemove() << std::endl;
  }
    gameObjects.erase(
        std::remove_if( // Selectively remove elements in the second vector...
            gameObjects.begin(),
            gameObjects.end(),
            [&] (std::shared_ptr<GameObject> const& p)
            {   // This predicate checks whether the element is contained
                // in the second vector of pointers to be removed...
                return deadOnly && p.get()->toRemove();
            }),
        gameObjects.end()
        );

  //  std::cout << "flush agents: end" << std::endl;  


}

void GameState::init(){
  //  srand(move);
   // restartGame = false;
   // current = std::make_unique<LevelState>();
    std::cout << "Game ainit start" << std::endl;
    gameObjects = std::vector<std::shared_ptr<GameObject>>();
    detectionMap = std::make_unique<DetectionMap>(mapX, mapY);
    int num_creeps = 10;
    int num_tele = 4;
    int num_timet = 3;
    Agent::count = 0;
    
 //randomly initialise and determine the position of X creeps
  for (int i = 0; i < num_creeps; i++){
      std::cout << "init creep:" << i << std::endl;
      int x = std::rand()%mapX;
      int y = std::rand()%mapY;
      int width = std::rand()%2+4;
      int height = std::rand()%2+4;
      int speed = std::rand()%1+1;
    // Creep creep(x,y,width, height, speed);
      //make this unique pointer??
    //  std::cout << x << " " << y << " " << width << " " << height << " " << speed << std::endl;
      Creep creep = Creep(x,y,width, height, speed);
    //  std::cout << creep << std::endl;
      //testCreatureShape(creep);
    
      //std::vector<Agent> test;
      //test.push_back(dynamic_cast<GameObject>(creep));
     // LevelState* c = current.get();
      std::shared_ptr<Creep> creep_ = std::make_shared<Creep>(creep);
      submitDetectionMap(creep_.get());
      gameObjects.push_back(std::move(creep_));  
  }
  //kill off overlapping creeps, -> later iteration keep the first remove the rest
  checkCollisions(true);
  
  //(*detectionMap.get()).clearMap();
  
   placeHuman();

  //getStats();
   //
  //create human player
  //TODO place human/player randomly in safe spot (in future version)
  flushAgents(true);
  //std::cout << detectionMap.get() << std::endl;
  //exit(0);
   //seed the pseudo random number generator at every checkpoint
   // detectionMap.get()->printInfo();
  std::cout << "Game init end" << std::endl;
}

void GameState::submitDetectionMap(Agent* agent){
 // std::cout << "detection map " << agent->getId()  << " " << agent << std::endl;
  float x = agent->getX();
  float y = agent->getY();
  int width = agent->getWidth();
  int height = agent->getHeight();
  //std::cout << "x : " << x << " ,y: " << y << " ,width : " << width << " ,height " << height << std::endl;
//  std::cout << "mapX : " << mapX << " mapY " << mapY <<  std::endl;
  Array2D<int> *shapeMap = agent->getShapeMap();
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
     
     if (agent->getShapeMap()->operator()(i,j)==1){
       if (x+i < mapX && y+j<mapY){
     //    std::cout << "       i: " << i << " j:" << j<<"       x+i: " << x+i << " y+j:" << y+j<<std::endl;
         DetectionMap* detectionMap_ = detectionMap.get();
       //  std::cout << " here 1 " << std::endl;
         TileBin* tileBin = detectionMap_->operator()(x+i,y+j);
         std::vector<Agent*>* t = tileBin->getTileBin();
       //  std::cout << "t->size()" << t->size() <<std::endl;
         t->emplace_back(agent);
       }
      }
    }
  }
  
  //std::cout << "detection map: end" << agent->getId()  << " " << agent << std::endl;
}

void GameState::checkCollisions(bool spare_first){

  DetectionMap* detectionMap_ = detectionMap.get();
 //  std::cout << "here2" << std::endl;
  for (int i = 0; i < mapX; i++){
      for (int j = 0; j < mapY; j++){
        // std::cout << "Bin: i: " << i << " j:" << j<< std::endl;
     //   std::cout << "detectionMap_: " << detectionMap<< std::endl;

       // std::cout << "here 1";
        TileBin* tileBin = detectionMap_->operator()(i,j);
        //        std::cout << "here 2";
        std::vector<Agent*>* agents = tileBin->getTileBin();
                    //    std::cout << "here 3";
        if (agents->size()>=2){
            // std::cout << "Bin: i: " << i << " j:" << j<< " size: " << agents->size()<< std::endl;
             int c = 1;
             for (std::vector<Agent*>::iterator it = agents->begin() ; it != agents->end(); ++it){
                 if (!(*it)->getDying()){
                    if (!spare_first || c!=1){
                      (*it)->setDeath();
                   //   std::cout << "Died: " << (*it) << "type "<<(*it)->getType() << std::endl;
                    }else{
                   //   std::cout << "Survived: " << (*it)->getId() << std::endl;
                    }
                 }

                c++;
             }
        }
    }
  }
 // std::cout << "check collsions :end "<< std::endl;
//  for (GameObject gameObject : current.){
 // }
}

void GameState::placeHuman(){
  //choose random spot on map

    std::cout << "start place human" << std::endl;
    float x = std::rand()%mapX;
    x = std::min(std::max(x, 3.0f), mapX-3.0f);
    float y = std::rand()%mapY;
    y = std::min(std::max(y, 3.0f), mapY-3.0f);

    float width = 1;
    float height = 2;
    float speed = 1;
    //  Human* human =  new Human(x,y,width, height, speed);
     
    Human human_ =  Human(x,y,width, height, speed);

    std::cout << "here1" << std::endl;
   // submitDetectionMap(human_.get());                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
   // current.gameObjects.emplace_back(human);
   // s
    Player player_ = Player();
    std::cout << "here2" << std::endl;
    //human_.setPlayer(&player_);
     std::cout << "here3" << std::endl;
    human_.setTele(3);
   // player_.setHuman(&human_);
    std::cout << "here4" << std::endl;
   // player =std::make_unique<Player>(player.get());

    std::shared_ptr<Human> human = std::make_shared<Human>(human_);
    player =std::make_unique<Player>(player_); 
    std::cout << "here5" << std::endl;
    player.get()->setHuman(human.get());
     std::cout << "here6" << std::endl;
    human.get()->setPlayer(player.get());
    std::cout << "here7" << std::endl;
    gameObjects.push_back(human); 
    std::cout << "here8" << std::endl;


    printPlayerLinks();
  //  std::cout << "human " << human << " " << " player " <<  player<< std::endl;
   // std::cout << "end place human" << std::endl;
}

 void GameState::printPlayerLinks(){
   std::cout << "player " << player.get() << "  ";
   if (player.get()->getHuman() != nullptr){
    std::cout << "player.get()->getHuman() " << player.get()->getHuman() <<  " ";
     if (player.get()->getHuman()->getPlayer() !=nullptr)
     {
          std::cout << "player->getHuman()->getPlayer() " << player.get()->getHuman()->getPlayer() << std::endl;
     }else{
        std::cout << std::endl;
     }
   }else{
      std::cout << std::endl;
   }
 }

void GameState::endGame(){
 // std::cout << "restart " << std::endl; 
  restartGame =true;
  flushAgents(false);
 // std::cout << "flushed agents " << std::endl; 
 // init();
}


void GameState::BoundaryCheck(Agent* a, int& del_x, int& del_y){
//check whether shape boundary is within grid boundary -> no return
  int x = a->getX();
  int y = a->getY();
  int w = a->getWidth();
  int h = a->getHeight();
  int X0 = x+del_x ;
  int Y0 = y+del_y ;
  int X1 = x+w+del_x;
  int Y1 = y+h+del_y;
  //std::cout << "X0: " <<X0 << " Y0: " << Y0 << " X1 : " << X1 << " Y1 : " << Y1 << " mapX: " << mapX << " mapY: " << mapY << std::endl;
  if (X0 >= 0 && Y0 >= 0 && X1 < mapX && Y1 <mapY){

   // std::cout << "no overlap  " << std::endl;
    return;
  }else{
   // std::cout << "overlap  " << std::endl;
  
    //else check whether shape map collides with boundary, set del_x, del_y->0 return
    Array2D<int> *shapeMap = a->getShapeMap();
    for (int i = 0; i < w; i++){
        for (int j = 0; j < h; j++){
          //  std::cout << " i " << i << " j " << j << "map" << shapeMap->operator()(i,j) << std::endl;
            if (shapeMap->operator()(i,j) > 0){

              int X = x+i+del_x;
              int Y = y+j+del_y;
             //  std::cout << "?? X: " <<X << " Y: " << Y << std::endl;
              if (!(X >= 0 && X < mapX)){
               
                //if the boundary condition fails for any tile of agent->no move
                  del_x = 0;
                  
               }
              if (!( Y >= 0 && Y <mapY)){
               
                //if the boundary condition fails for any tile of agent->no move
                  del_y = 0;
                  
               }
            }
        }
    }
  } 

//yes -> block move
}


//TODO have this method take the shared pointer of GameObject
void GameState::HumanBehave(Human* h, std::shared_ptr<GameObject> g){
 
  //TODO perform dynamic cast to Human

  Player* p =h->getPlayer();
  //std::cout << "Human behave " << h <<" " << p <<  std::endl;
  //std::cout << "Player " << player <<" " << player->getHuman() <<  std::endl;
  int del_x = 0;
  int del_y = 0;
  if (h->getPlayer()!=nullptr){
  //  std::cout << "Player behave:" << " x:  " << h->getX() << " y: " << h->getY()<< std::endl;
    Action* action = player->getCurrentAction();
  //  std::cout << "here1" << action <<  std::endl;
   // std::cout << "here2" << action->getType()<<  std::endl;
    switch(action->getType()){
        case Action::Type::U:{
        //  std::cout << "here3" << std::endl;
          del_y-=h->getSpeed();
          break;
        }case Action::Type::D:{
          del_y+=h->getSpeed();
          break;
        }
        case Action::Type::L:{          
          del_x-=h->getSpeed();
          break;}
        case Action::Type::R:{
          del_x+=h->getSpeed();
          break;
        }
        case Action::Type::TL:{
          del_x-=h->getSpeed();
          del_y-=h->getSpeed();
          break;
        }

        case Action::Type::TR:{
          del_x+=h->getSpeed();
          del_y-=h->getSpeed();
          break;
        }

        case Action::Type::BL:{
          del_x-=h->getSpeed();
          del_y+=h->getSpeed();
          break;
        }

        case Action::Type::BR:{
          del_x+=h->getSpeed();
          del_y+=h->getSpeed();
          break;
        }

        case Action::Type::TELE:{
          Teleport(h);
          break;
        }

        case Action::Type::TT:{
          //input shared pointer
          TimeTravel(h,g);
          break;
        }

        case Action::Type::NOTHING:{
          break;
        }
    }
   // std::cout << "change del x:  " << del_x << " del y: " << del_y << std::endl;
    BoundaryCheck(h, del_x, del_y);
    if (del_x!=0 || del_y!=0){
      h->move(del_x, del_y);
    }
   // std::cout << "Player behave: end" << " x:  " << h->getX() << " y: " << h->getY()<< std::endl;
  }else{
    //TODO : NPC behaviour if time travel feature included 
  }
  submitDetectionMap(h);
}

void GameState::Teleport(Human* h){
  std::cout << "teleport " << h->getTele() << std::endl;
  int tokens = h->getTele();
  if (tokens>0){
      float new_x = std::rand()%mapX;
      float new_y = std::rand()%mapY;
      h->setX(new_x);
      h->setY(new_y);
      tokens--;
      h->setTele(tokens);
      std::cout << "new_x " << new_x << " new_y "<<  new_y << std::endl;
  }

}

void GameState::TimeTravel(Human*h, std::shared_ptr<GameObject> g){
  std::cout << "time travel " << h->getTele() << std::endl;
  int tokens = h->getTimetrav();
    if (tokens>0){
      tokens--;
      h->setTimetrav(tokens);
      std::cout << "levelStates" << levelStates.size() << std::endl;
      if (levelStates.size()>0){
        int index =  rand()%levelStates.size();
      //  std::cout << "index : " << index << std::endl;
        if(levelStates.size()>=index){
          levelStates.resize(index);
        //  std::unique_ptr<LevelState> levelState = std::move(levelStates.back());
        std::unique_ptr<LevelState> levelState = std::move(levelStates.back());//std::move(levelStates.back());
         // std::cout <<  "levelState " << levelState << std::endl;
          levelStates.pop_back();
          std::vector<std::shared_ptr<GameObject>> gameObjects_ = levelState.get()->getGameObjects();
       //   std::cout << "gameObjects_" << gameObjects_.size() << std::endl;
       //   testSavedGameObjects(gameObjects_);
          gameObjects_.push_back(g); //this code represents the human travelling back in time
          gameObjects = gameObjects_;
          std::cout << "gameObjects" << gameObjects.size() << std::endl;
          testSavedGameObjects(gameObjects);
         // time = levelState.get()->getTime();
          move = levelState.get()->getTime(); 
          timeTravelFlag =true;
        }
      }
  }
   std::cout << "time travel :end " << h->getTele() << std::endl;
}

void GameState::CreepBehave(Creep* c){
  //  std::cout << "Creep Behave " << std::endl;
    //get direction from centre of creep to player
  // std::cout <<  " x "<<c->getX()<<  " y " << c->getY()<<  " w " << c->getWidth()<<  " h " << c->getHeight()<<  " " << std::endl;
    //std::cout <<  "before: x_cen "<<c->getCenX()<<  " y_cen " << c->getCenY() << std::endl;
    c->determineCentre();
  // std::cout <<  "after: x_cen "<<c->getCenX()<<  " y_cen " << c->getCenY() << std::endl;
    int X_cen_abs = c->getX() + c->getCenX();
    int Y_cen_abs = c->getY() + c->getCenY();

    //in future, generalise this for closest human (not just player) -- TIME TRAVEL feature
    int playerX = player->getHuman()->getX();
    int playerY = player->getHuman()->getY();

    int del_x = 0;
    int del_y = 0;
      //make a delx, dely
    if (X_cen_abs > playerX){
        del_x -= c->getSpeed();
    }else if(X_cen_abs < playerX){
        del_x += c->getSpeed();
    }
    if (Y_cen_abs > playerY){
        del_y -= c->getSpeed();
    }else if(Y_cen_abs < playerY){
        del_y += c->getSpeed();
    }


    //perform Boundary Check
    BoundaryCheck(c, del_x, del_y);
    if (del_x!=0 || del_y!=0){
      c->move(del_x, del_y);
    }

    submitDetectionMap(c);
  // std::cout << "Creep behave: end" << " x:  " << c->getX() << " y: " << c->getY()<< std::endl;
    //BoundaryCheck(Agent* a, int& del_x, int& del_y)
    //move in direction of player#
  // std::cout << "Creep Behave :end " << std::endl;
}


/**

void GameState::submitDetectionMap(){
  for (GameObject* o : current.gameObjects){
    if (o->getType() == GameObject::GOType::HUMAN || o->getType() == GameObject::GOType::CREEP){
      Agent* a = dynamic_cast<Agent*>(o);
      Creep* c = dynamic_cast<Creep*>(o);


    }
    
  }
}






void GameState::getStats(){
  int co = 0;
  for (GameObject* o : current.gameObjects){
    if (o->getType() == GameObject::GOType::HUMAN || o->getType() == GameObject::GOType::CREEP){
        Creep* c = dynamic_cast<Creep*>(o);
        if (!c->getDying()){
          std::cout << "ID: " <<c->getId() << " x:  " << c->getX() << " y: " << c->getY() << " width: " << c ->getWidth() << " height: " << c->getHeight() << std::endl;
          co++;
        }
    }
  }
  std::cout << "survivors : " << co << std::endl;
}

		void BoundaryCheck(Agent* a, int& del_x, int& del_y);


*/
void GameState::testSavedGameObjects(std::vector<std::shared_ptr<GameObject>> gameObjects_){
  std::cout <<  "testing saved game objects "<< std::endl;
  for (auto& go : gameObjects_){
    GameObject* go_ = go.get();
   // GameObject go__ =GameObject(*go_);

        switch(go_->getType()){
      case GameObject::GOType::CREEP:{
          Creep* c = dynamic_cast<Creep*>(go_);
          std::cout << go_ <<  " c: "<< c<<" " << c->getX() << " " << c->getY()  <<std::endl;
       // c->behaviour(mapX, mapY);0x564190ddfdc0
        break;}
      case GameObject::GOType::HUMAN:{
        Human* h = dynamic_cast<Human*>(go_);
        std::cout << go_ <<  " h: "<< h << " " << h->getX() << " " << h->getY() << " " <<h->getPlayer()<< std::endl;
        break;}
    }
  }
    std::cout <<  "testing saved game objects :end "<< std::endl;
}


void GameState::saveLevelState(){
  std::cout << "Saving Level State " <<move+1 << std::endl;
  //copy the game state
  LevelState levelState = LevelState(move+1);
  std::vector<std::shared_ptr<GameObject>> gameObjects_;
// levelState.setTime(move);
  for (auto& go : gameObjects){
    GameObject* go_ = go.get();
   // GameObject go__ =GameObject(*go_);

        switch(go_->getType()){
      case GameObject::GOType::CREEP:{
          Creep* c = dynamic_cast<Creep*>(go_);
          Creep go__ =Creep(*c);
          gameObjects_.push_back(std::make_shared<Creep>(go__));
       // c->behaviour(mapX, mapY);
        break;}
      case GameObject::GOType::HUMAN:{

          Human* h = dynamic_cast<Human*>(go_);
          Human h__ =Human(*h);
          h__.setPlayer(nullptr);
          gameObjects_.push_back(std::make_shared<Human>(h__));

        //  Human go__ =Human(*go_);
       //   gameObjects_.push_back(std::make_unique<GameObject>(go__));
       // h->behaviour(mapX, mapY);
        break;}
    }
  //  GameObject go__(go_); 
   // GameObject* go__ =  &go_;
    
  }

  //std::cout << "gameObjects_ " << gameObjects_.size() << std::endl;
  levelState.setGameObjects(gameObjects_);
  gameObjects_ = levelState.getGameObjects();
  //testSavedGameObjects(gameObjects_);
  //std::cout << "time "  << levelState.getTime() <<std::endl;
  //std::cout << "gameObjects_ " << gameObjects_.size() << std::endl;
  //levelState.push_back(std::move(gameObjects_));
  //std::cout << "levelState " << levelState << std::endl;
  levelStates.push_back(std::make_unique<LevelState>(std::move(levelState)));
  //test
  //std::unique_ptr<LevelState> levelState_ = std::move(levelStates.back());
  //std::cout << "here 1 "  <<std::endl;
  //std::shared_ptr<LevelState> levelState_ = std::move(levelStates.back());
    //std::cout << "here 2 "  <<std::endl;
  //std::unique_ptr<LevelState> levelState_ = std::move(levelStates.at(0));
  //LevelState *levelState__ = levelState_.get();
  //std::cout << "time "  << levelState__.getTime() <<std::endl;
  //gameObjects_ = levelState__->getGameObjects();
  //testSavedGameObjects(gameObjects_);
  //std::cout << "time "  << levelState.getTime() <<std::endl;

  //exit(0);

  //create LevelStatelevelStates
  //copy each gameObject
  //add LevelState to history vectory

std::cout << "Saving Level State:end" << std::endl;

}

void GameState::Update(){
  std::cout << "Update " << std::endl; 
  //player.get()->printInfo();
  flushAgents(true);  
  //clone the game state
 // if (rand() % 100 < 10){
    saveLevelState();
  //}

  std::cout << detectionMap.get() << std::endl;
  //std::cout << "Flush agents end " << gameObjects.size() << std::endl; 
  detectionMap.get()->clearMap();
 
   // std::cout << "here 2 " << std::endl; 
  //iterate over all GameObjects and execute behaviour();
 // std::vector<std::unique_ptr<GameObject>> gos =(*current.get()).getGameObjects();

  for (auto& g : gameObjects) {
  // std::cout << "memory ref: " << go <<std::endl;
   //std::cout << "here1 " << std::endl;
    GameObject* go = g.get();
    switch(go->getType()){
      case GameObject::GOType::CREEP:{
        
        Creep* c = dynamic_cast<Creep*>(go);
        CreepBehave(c);
       // c->behaviour(mapX, mapY);
        break;}
      case GameObject::GOType::HUMAN:{
        Human* h = dynamic_cast<Human*>(go);
        HumanBehave(h,g);

        if (timeTravelFlag){
          timeTravelFlag =false;

          std::cout << "Update : end" << std::endl; 


          return;
        }
       // h->behaviour(mapX, mapY);
        break;}
    }

   
  }
   //std::cout << "collsion check: start" << std::endl;
  //Check for collisions (creeps->player, creeps<->creeps)
 // std::cout << "player dying 0 " <<player->getHuman()->getDying() << std::endl;
  checkCollisions(false);
   //  std::cout << "collsion check: finish" << std::endl;
 // current.setGameObjects(std::move(gos));
  if (player->getHuman()->getDying()){
    setGameOver();
  }
  move++;
 // (*detectionMap.get()).clearMap();
    std::cout << "Update : end" << std::endl; 
}



