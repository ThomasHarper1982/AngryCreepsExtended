#include "DetectionMap.h"
#include <iostream>


TileBin::TileBin(){
   // std::cout << "TileBin() :start" << std::endl;
    bin = new std::vector<Agent*> ();
   // std::cout << "TileBin() :finish" << std::endl;
   // count++;
    //d = count;
};//bin = new std::vector<Agent*> ();}


TileBin::~TileBin(){
   bin->clear();
   delete bin;

}
TileBin::TileBin(const TileBin &source){
   std::cout << "TileBin Copy constructor "<< this << std::endl;
   bin = source.bin; //vector copy
} // 2 : copy constructor

TileBin& TileBin::operator=(const TileBin &source){
   std::cout << "TileBin Copy assignment "<< this << std::endl;
    if (this == &source)
      return *this;
   delete bin;
   bin = source.bin;

} // 3 : copy assignment operator
TileBin::TileBin(TileBin &&source){
   std::cout << "TileBin Move Constructor" << std::endl;
   bin = source.bin;
   source.bin = nullptr;

} // 4 : move constructor

TileBin& TileBin::operator=(TileBin &&source){
    std::cout << "TileBin Move Assignment Operator" << std::endl;
    if (this == &source)
      return *this;
    delete bin;
  	source.bin = nullptr;
    return *this;
}


DetectionMap::~DetectionMap(){
   std::cout << "Deconstructor: DetectionMap" << std::endl;
   //nothing to do if we use vector of smart pointer
}

DetectionMap::DetectionMap(const DetectionMap &source){
   std::cout << "Copy constructor "<< this << std::endl;
   m_RowCount = source.m_RowCount;
   m_ColCount = source.m_ColCount;
   //transfer ownership of vector smart pointers
 //  std::vector<TileBin> bin = source.m_Items;
   m_Items.clear();
   for (auto& t : source.m_Items){
      // TileBin  t_ = t.get();
      TileBin t_ = *t.get(); //apply copy constructor of TitleBin
      m_Items.push_back(std::make_unique<TileBin>(t_));
   }
} // 2 : copy constructor

DetectionMap &DetectionMap::operator=(const DetectionMap &source){
   std::cout << "Copy assignment "<< this << std::endl;
    if (this == &source)
      return *this;
   m_RowCount = source.m_RowCount;
   m_ColCount = source.m_ColCount;
   m_Items.clear();
   for (auto& t : source.m_Items){
      TileBin t_ = *t.get(); //apply copy constructor of TitleBin
      m_Items.push_back(std::make_unique<TileBin>(t_));
   }
   return *this;
} // 3 : copy assignment operator

DetectionMap::DetectionMap(DetectionMap &&source){
   std::cout << "Move Constructor" << std::endl;
    m_Items.clear();
   for (auto& t : source.m_Items){
      m_Items.push_back(std::move(t));
   }
   m_RowCount=std::move(source.m_RowCount);
   m_ColCount=std::move(source.m_ColCount);
} // 4 : move constructor

DetectionMap &DetectionMap::operator=(DetectionMap &&source){
    std::cout << "Move Assignment Operator" << std::endl;
    if (this == &source)
      return *this;
   m_Items.clear();
   for (auto& t : source.m_Items){
      m_Items.push_back(std::move(t));
   }
   m_RowCount=std::move(source.m_RowCount);
   m_ColCount=std::move(source.m_ColCount);
   //source.m_RowCount = nullptr;
  // source.m_ColCount = nullptr;
    return *this;
} // 5 : move assignment operator
