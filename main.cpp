#include "car.h"
#include "smart_ptr.cpp"

int main()
{
   smart_ptr<Car> daciaPointer(new Car("Dacia 1300"));
   daciaPointer->SetCarModel("Renault 5");
   (*daciaPointer).SetCarModel("Dacia Logan");

   smart_ptr<Car> bmwPointer(new Car("BMW"));
   daciaPointer = bmwPointer;
   return 0;
}