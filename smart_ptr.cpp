#include "smart_ptr.h"

template <typename T>
smart_ptr<T>::smart_ptr(T* object)
{
   m_Object = object;
   m_ReferenceCount = new ReferenceCount();
   m_ReferenceCount->Increment();
   std::cout << "Created smart pointer. Reference count is: " << m_ReferenceCount->GetCount() << std::endl;
}

template <typename T>
smart_ptr<T>::~smart_ptr()
{
   if (m_ReferenceCount)
   {
      m_ReferenceCount->Decrement();
      std::cout << "Destroyed smart pointer! Reference count is: " << m_ReferenceCount->GetCount() << std::endl;
      if (m_ReferenceCount->GetCount() <= 0)
      {
	 delete m_ReferenceCount;
	 delete m_Object;

	 m_ReferenceCount = nullptr;
	 m_Object = nullptr;
      }
   }
}

template <typename T>
smart_ptr<T>::smart_ptr(const smart_ptr<T>& object)
{
   m_Object = object.m_Object;
   m_ReferenceCount = object.m_ReferenceCount;
   m_ReferenceCount->Increment();
   std::cout << "Copied smart pointer! Reference count is: " << m_ReferenceCount->GetCount() << endl;
}

template <typename T>
smart_ptr<T>& smart_ptr<T>::operator = (const smart_ptr<T>& object)
{
   if (this != &object)
   {
      if (m_ReferenceCount)
      {
	 m_ReferenceCount->Decrement();
	 if (m_ReferenceCount->GetCount() == 0)
	 {
	    delete m_ReferenceCount;
	    delete m_Object;
	 }

	 m_Object = object.m_Object;
	 m_ReferenceCount = object.m_ReferenceCount;
	 m_ReferenceCount->Increment();
      }
   }
   std::cout << "Assigning smart pointer! Reference count is: " << m_ReferenceCount->GetCount() << std::endl;
   return *this;
}

template <typename T>
T& smart_ptr<T>::operator * ()
{
   return *m_Object;
}

template <typename T>
T* smart_ptr<T>::operator -> ()
{
   return m_Object;
}