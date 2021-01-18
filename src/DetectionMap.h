#ifndef DETECTIONMAP_H
#define DETECTIONMAP_H

#include <vector>
#include <algorithm>
#include <cassert>
#include "Agent.h"
#include <iostream>
#include <memory>

/**
 * class Array2D - Implementation of an 2D Array
 **/

class TileBin{

	public:
		TileBin();//bin = new std::vector<Agent*> ();}
		~TileBin();
		TileBin(const TileBin &source); // 2 : copy constructor
 		TileBin &operator=(const TileBin &source); // 3 : copy assignment operator
    	TileBin(TileBin &&source); // 4 : move constructor
    	TileBin &operator=(TileBin &&source); // 5 : move assignment operator
		
		std::vector<Agent*>* getTileBin(){return bin;	}
		static const int count = 0;
		int id;
	private:
		std::vector<Agent*> *bin;
};

class DetectionMap
{
public:
	DetectionMap(){};

	DetectionMap(int rows, int cols): m_RowCount(rows), m_ColCount(cols)
	{
		//std::cout << "Detection Map: start" <<std::endl;
		//assert(rows > 0 && cols > 0);
		//m_Items.resize(rows * cols);
		//std::cout<<m_Items.size() << std::endl;
		//std::fill(m_Items.begin(), m_Items.end(),  TileBin());
		for (int i = 0; i < rows*cols; i++){
			m_Items.push_back(std::make_unique<TileBin>());
        }
		std::cout<<m_Items.size() << std::endl;
	}

	~DetectionMap();
	DetectionMap(const DetectionMap &source); // 2 : copy constructor
 	DetectionMap &operator=(const DetectionMap &source); // 3 : copy assignment operator
    DetectionMap(DetectionMap &&source); // 4 : move constructor
    DetectionMap &operator=(DetectionMap &&source); // 5 : move assignment operator

	void clearMap(){
		for (auto& g : m_Items) {
			TileBin* t = (g.get());
			std::vector<Agent*>* vec = t->getTileBin();
			vec->clear();
		}

	//	m_Items.clear();
	}
/**	DetectionMap(size_t rows, size_t cols, const T& val) : m_RowCount(rows), m_ColCount(cols)
	{
		assert(rows > 0 && cols > 0);
		m_Items = new T[rows * cols];
		std::fill(m_Items.begin(), m_Items.end(), val);
	}**/

	size_t rows() const 
	{ 
		return m_RowCount; 
	}
	
	size_t cols() const 
	{ 
		return m_ColCount; 
	}

	void printInfo(){
			std::cout << "DetectionMap size: "<< m_Items.size() << " m_ColCount: " << m_ColCount << " m_RowCount: "  << m_RowCount << std::endl;
	}

	//std::unique_ptr<TileBin>& operator()(const size_t row, const size_t col)
	TileBin* operator()(const size_t row, const size_t col)
	{
	//	assert(row > 0 && col > 0);
		size_t index = row * m_ColCount + col;
	//	std::cout << "size: "<< m_Items.size() << " index: " << index << "m_Items "<< m_Items.size() <<std::endl;

		//return m_Items[index]; //this wont work: use A* a = vec_a.at(0).get();
		return m_Items.at(index).get();
	}
	
	//const std::unique_ptr<TileBin>& operator()(const size_t row, const size_t col) const
	/**const TileBin operator()(const size_t row, const size_t col) const
	{
		//assert(row > 0 && col > 0);
		size_t index = row * m_ColCount + col;

		//return m_Items[index]; //this wont work: use A* a = vec_a.at(0).get();
		 return m_Items.at(index).get();
	}**/

	
private:
	std::vector<std::unique_ptr<TileBin>> m_Items;
	size_t  m_RowCount, m_ColCount;
};
#endif