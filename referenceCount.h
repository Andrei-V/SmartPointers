#pragma once
class ReferenceCount
{
private:
   int m_RefCount{ 0 };
public:
   void Increment()
   {
      ++m_RefCount;
   }
   void Decrement()
   {
      --m_RefCount;
   }
   int GetCount() const
   {
      return m_RefCount;
   }
};