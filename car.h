#pragma once
#include <string>

class Car
{
private:
   std::string m_Model;

public:
   Car();
   Car(const std::string& model);
   void SetCarModel(const  std::string& model);
   ~Car();
};