/**

#include "Item.h"

#include "GameObject.h"
#include "Agent.h"
#include "Array2D.h"

**/
#include "DetectionMap.h"
#include <vector>
#include <memory>
#include <cassert>
#include "Creep.h"
#include "Human.h"
#ifndef GAMESTATE_H
#define GAMESTATE_H


//change program such that GameState uniquely holds GameObjects, but LevelState will hold previous GameObjects.
class LevelState{
	public:
		~LevelState();
  		LevelState(int time_);
		LevelState(const LevelState &source); // 2 : copy constructor
 		LevelState &operator=(const LevelState &source); // 3 : copy assignment operator
    	LevelState(LevelState &&source); // 4 : move constructor
    	LevelState &operator=(LevelState &&source); // 5 : move assignment operator  

  	//	void flushAgents(bool deadOnly);
		int getTime(){return time;};
		int setTime(int time_){time= time_;};
		//std::vector<GameObject*> getGameObjects();
		std::vector<std::shared_ptr<GameObject>> gameObjects;
		std::vector<std::shared_ptr<GameObject>> getGameObjects(){return gameObjects;};
		void setGameObjects(std::vector<std::shared_ptr<GameObject>>  gameObjects_){gameObjects = gameObjects_;};
  	private:
		int move;
  		int time;

};



class GameState{
	public:
  		void init();
		~GameState();
    	GameState(const GameState &source); // 2 : copy constructor
 		GameState& operator=(const GameState &source); // 3 : copy assignment operator
    	GameState(GameState &&source); // 4 : move constructor
    	GameState& operator=(GameState &&source); // 5 : move assignment operator
		GameState(int mapX, int mapY);
		void Update();
		void testSavedGameObjects(std::vector<std::shared_ptr<GameObject>> gameObjects_);
		void submitDetectionMap(Agent* agent);
		//void submitDetectionMap();
		void checkCollisions(bool spare_first);
		void placeHuman();
		bool getIsPlayerDying(){return player.get()->getHuman()->getDying();}
		bool getGameOver(){return gameOver;};
		void endGame();
		Player* getPlayer(){return player.get();};
		void saveLevelState();
		//LevelState* getCurrentLevel(){return current.get();};
		void BoundaryCheck(Agent* a, int& del_x, int& del_y);
		void HumanBehave(Human* h, std::shared_ptr<GameObject> g);
		void CreepBehave(Creep* c);
		void Teleport(Human*h);
		void TimeTravel(Human*h, std::shared_ptr<GameObject> g);
		void flushAgents(bool deadOnly);
		std::vector<std::shared_ptr<GameObject>> getGameObjects(){return gameObjects;};
		bool hasEnded(){return restartGame;}
		int getMapX(){return mapX;};
		int getMapY(){return mapY;};
		int getMove(){return move;};
		void setGameOver(){gameOver =true;};
		void printPlayerLinks();
	/**	
	
		void getStats();
		
		//void setRestartGame();
		;




		
		void handleGameOver();


		void testCreatureShapes();
		void testCreatureShape(Creep* c);
		void testDeletionMapPopulated();
		void testDyingCreatures();

		
		
**/
  	private:
	  	int mapX;
		int mapY;
		bool timeTravelFlag{false};
		std::unique_ptr<DetectionMap> detectionMap;
		//std::unique_ptr<LevelState> current;
		std::unique_ptr<Player> player;
		//std::vector<std::unique_ptr<GameObject>> gameObjects;
		int move{0};
		bool gameOver{false};
		bool restartGame{false};
		std::vector<std::shared_ptr<GameObject>> gameObjects;
  		std::vector <std::unique_ptr<LevelState>> levelStates; 

		


		//
		
				
		
		
};

#endif