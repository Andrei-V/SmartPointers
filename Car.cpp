#include "car.h"
#include <iostream>

Car::Car()
{
   m_Model = "Generic Model";
   std::cout << "Generic Model car created" << std::endl;
}

Car::Car(const std::string& model)
{
   m_Model = model;
   std::cout << m_Model << " Model car created" << std::endl;
}

void Car::SetCarModel(const std::string& model)
{
   std::cout << "Model changed from " << m_Model << " to " << model << std::endl;
   m_Model = model;
}

Car::~Car()
{
   std::cout << "Destoying car of model: " << m_Model << std::endl;
}