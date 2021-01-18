#include "Creep.h"
#include <random>
#include <iostream>

Creep::Creep (float x_, float y_, float width_, float height_, float speed_){
       std::cout << "Creep:  constructor "<< this << std::endl;
 //  std::cout << "Creep cons start" << std::endl;
   //top left of shape map
   x = x_; 
   y = y_;
   //creature centre
   width = width_;
   height = height_;
   speed = speed_;
   type = GOType::CREEP;
   shapeMap = new Array2D<int>(width_, height_);
   initShape();
   //determine create centre offset position
   determineCentre();
   Agent::count++;
   id=Agent::count;
   // std::cout << "Creep cons end" << std::endl;
}

Creep::~Creep(){
    std::cout << "Deconstructor: Creep " << this << std::endl;
    shapeMap->clear();
  //  delete shapeMap;
}


Creep::Creep(const Creep &source){
   std::cout << "Creep: Copy constructor "<< this << std::endl;
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
} // 2 : copy constructor

Creep& Creep::operator=(const Creep &source){
   std::cout << "Creep: Copy assignment constructor "<< this << std::endl;
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
   return *this;
} // 3 : copy assignment operator

Creep::Creep(Creep &&source){
    std::cout << "Creep: Move Constructor " << this << std::endl;
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

}// 4 : move constructor

Creep& Creep::operator=(Creep &&source){
    std::cout << "Move Assignment Operator " << this << std::endl;
    if (this == &source)
      return *this;
   speed = source.speed;
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

    return *this;
} // 5 : move assignment operator


/**
void Creep::behaviour(int mapX, int mapY){
	 //check for boundary

     //move toward closest human
}**/

void Creep::initShape(){
    //choose a random point within the map
    //std::cout << "W: "<< getWidth() << " H:" << getHeight() << std::endl;
    int x_ = std::rand()%getWidth() ;
    int y_ = std::rand()%getHeight() ;

    recurseShape( x_,  y_,  0.80);

    // plot the shape output when done - to check it worked
}


void Creep::transformShape(){

    int lowerX;
    int nbottomX;
    shapeMap->operator()(x+i,y+j) 

    for (int i = 0; i <=  shapeMap->rows() i++){

        for (int j = 0; j <= shapeMap->cols(); j++){
            
        }
    }

}
/**
void Creep::determineSize(){
 for (int i = 0; i < width; i++){

        for (int j = 0; j < height; j++){
        }
 }
}**/

void Creep::determineCentre(){
    //get the average along each row
    x_cen = static_cast<int>(width/2.0);;
    y_cen = static_cast<int>(height/2.0);;

  /**  float x_sum = 0; 
    int x_count = 0;
    for (int i = 0; i < width; i++){
        float col_sum = 0;
        int col_count = 0;
        for (int j = 0; j < height; j++){
            if (shapeMap->operator()(i,j) > 0){
               col_sum +=j;
               col_count += shapeMap->operator()(i,j);
            }
 
        }
        if (col_count > 0){
            x_sum += col_sum/col_count;
            x_count++;
        } 
    }
    x_cen = x_sum/x_count;

    float y_sum = 0; 
    int y_count = 0;
    for (int j = 0; j < height; j++){
        float row_sum = 0;
        int row_count = 0;
        for (int i = 0; i< width; i++){

            if (shapeMap->operator()(i,j) > 0){
               row_sum +=j;
               row_count += shapeMap->operator()(i,j);
            }
        }
        if (row_count > 0){
            y_sum += row_sum/row_count;
            y_count++;
        } 
    }
    y_cen = y_sum/y_count;**/

}

void Creep::recurseShape(int x, int y, float prob){
   // std::cout << "x: "<< x<< " y:" << y << std::endl;
    //draw a point
    shapeMap->operator()(x,y) = 1;

    //decide whether to draw points up to 4 appendages
    for (int i = -1; i <= 1; i++){

        for (int j = -1; j <=1; j++){
            if (i*j==0 && i+j!=0){ //condition to give (0,-1) (1,0) etc
            //    std::cout << "       i: " << i << " j:" << j<<std::endl;
                if (x+i >= 0 && x+i < width && y+j >=0 && y+j < height){//check it is bounded with the shape map
                    
                    if (shapeMap->operator()(x+i,y+j)==0){
                        if ((std::rand()%100/100.0) < prob){
                            recurseShape(x+i, y+j, prob*0.6);
                        }
                    }
                }
            }
        }
    }
    
}


void Creep::updateShape(){
    
}

