#pragma once
#include <iostream>
#include "referenceCount.h"

#ifdef  MYDLL_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

template <typename T>
class smart_ptr
{
private:
   T* m_Object{ nullptr };
   ReferenceCount* m_ReferenceCount{ nullptr };
public:
   smart_ptr() {};

   smart_ptr(T* object);

   virtual ~smart_ptr();

   smart_ptr(const smart_ptr<T>& object);

   smart_ptr<T>& operator = (const smart_ptr<T>& object);

   T& operator * ();

   T* operator -> ();
};