//Name: Ryan Vasquez
//Date: February 18th 2014
//Class: CS153 Section
//Purpose: To provide functionality for the ArrayList class
#include "arraylist.h"
template <typename T>
ArrayList<T>& ArrayList<T>::operator =(const ArrayList<T>& rhs)
{
  if(m_data == rhs.m_data && m_size == rhs.m_size &&
       m_max == rhs.m_max) //Alias test
  {
    return *this;
  }
  else
  {
    m_size = rhs.m_size;
    m_max = rhs.m_max;
    delete [] m_data;
    m_data = new T[m_max];
    for(int i = 0; i < m_max; i++)
    {
      m_data[i] = rhs.m_data[i];
    }
  }
	return *this;
}

template <typename T>
ArrayList<T>::~ArrayList<T>()
{
  delete [] m_data;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
  m_size = 0;
  m_max =0;
  m_data = NULL;
  *this = cpy;
}
template <typename T>
int ArrayList<T>::size() const
{
  return m_size;
}

template <typename T>
const T& ArrayList<T>::first() const
{
  if(m_max >= 1)
  {
    return m_data[0];
  }
  else
  {
    cout<<"!-- ERROR : PANIC in ARRAYLIST.first()!!  (List is empty)"<<endl;
    //return m_errobj;
  }

}

template <typename T>
T& ArrayList<T>::operator[](int i)
{
  if(i > m_max)
  {
    cout<<"!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)"<<endl;
    //return m_errobj;
  }
  else
  {
    return m_data[i];
  }
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const
{
  return *this[i];
}

template <typename T>
int  ArrayList<T>::find(const T& x)
{
  for(int i = 0; i < m_size; i++)
  {
    if(m_data[i] == x)
    {
       //This will cause the loop to exit
      return i;
    }
  }
  return -1;
}


template <typename T>
void ArrayList<T>::clear()
{
  m_size = 0;
  m_max = 0;
  delete [] m_data;
  m_data = NULL;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
  if(m_size < m_max)
  {
    m_data[m_size] = x;
    m_size++;
  }
  else
  {
    if(m_max == 0)
    {
      m_max = m_max+1;
      delete [] m_data;
      m_data = new T[m_max];
    }
    else
    {
      T* tmp = new T[m_max*2];
      for(int i = 0; i < m_max; i++)
      {
        tmp[i] = m_data[i];
      }
      delete [] m_data;
      m_data = tmp;
      m_max = m_max*2;
    }
    m_data[m_size] = x;
    m_size++;
  }
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{
  T tmp;
  if(i >= m_max)
  {
    cout<<"!-- ERROR :PANIC in ARRAYLIST!!.insert()(index out of bounds)"<<endl;
  }
  else
  {
    if(i >= m_size)
    {
      i = m_size;
      insert_back(x);
    }
    else
    {
      if(m_max == 0)
      {
        cout<<"!-- ERROR :PANIC in ARRAYLISTR!!.insert() (List has max size 0)";
        cout<<endl;
      }
      else
      {
        tmp = x;
        T tmp2;
        m_data[m_size-1] = 10;
        for(int j = 0; j+i < m_size+1 ;j++)
        {
          tmp2 = m_data[j+i];
          m_data[j+i] = tmp;
          tmp = tmp2;
          if(m_size >= m_max)
          {
            T* temp = new T[m_max*2];
            for(int k = 0; k < m_max; k++)
            {
              temp[k] = m_data[k];
            }
            delete [] m_data;
            m_data = temp;
            m_max = m_max*2;
          }
        }
      }
    }
    m_size++;
  }
}

template <typename T>
void ArrayList<T>::remove(int i)
{
  if(i >= m_max)
  {
    cout<<"!-- ERROR : PANIC in ARRAYLIST!!.remove()  (index out of bounds)";
    cout<<endl;
  }
  else
  {
    if(m_size > 0)
    {
      for(int j = 0; j+i < m_size; j++)
      {
        m_data[i+j] = m_data[i+j+1];
      }
      m_size --;
      if(m_size < (m_max/4))
      {
        T* tmp = new T[m_max/2];
        for(int k = 0; k < m_size; k++)
        {
          tmp[k] = m_data[k];
        }
        delete [] m_data;
        m_data = tmp;
        m_max = m_max/2;
      }
    }
    else
    {
      cout<<"!-- ERROR : PANIC in ARRAYLIST!!.remove() (List is empty)"<<endl;
    }
  }
}

template <typename T>
void ArrayList<T>::swap(int i, int k)

{
  if(i > m_size || i > m_max || k > m_size || k > m_max)
  {
    cout<<"!-- ERROR : PANIC in ARRAYLIST!!.swap()  (index out of bounds)";
    cout<<endl;
  }
  else
  {
    T tmp;
    tmp = m_data[i];
    m_data[i] = m_data[k];
    m_data[k] = tmp;
  }
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
  if(m_size+alist.m_size >= m_max)
  {
    T* tmp = new T[m_max+alist.m_max];
    for(int i = 0; i < m_size; i++)
    {
      tmp[i] = m_data[i];
    }
    delete [] m_data;
    m_data = tmp;
    m_max = m_max + alist.m_max;
  }
  for(int i = m_size; i < m_size+alist.m_size; i++)
    {
      m_data[i] = alist.m_data[i-m_size];
    }
    m_size = m_size + alist.m_size;
}

template <typename T>
void ArrayList<T>::purge()
{
  for(int i = 0; i < m_size; i++)
  {
    for(int k = 0; k < m_size; k++)
    {
      if(k != i)
      {
        if(m_data[i] == m_data[k])
        {
          remove((i>k ? i : k));
        }
      }
    }
  }
}






