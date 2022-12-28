#ifndef COLA_H
#define COLA_H

#include <string>
#include <iostream>
#include<fstream>


using namespace std;

template<class T>
class CNodo
{
  public:
     T          m_Dato;
     CNodo<T>  * m_pSig;
  public:
     CNodo(T d)
     {
       m_Dato = d;
       m_pSig = 0;
     }

     void Print(ostream & os, int  pos)
     {

         os<<"p"<<std::to_string(pos)<<"[label=\"{ <data> " << m_Dato <<"|<next>}\"]"<<endl;

         if (m_pSig)  m_pSig->Print(os,++ pos);

     }

};

template<class T>
class Cola
{
    private:
     CNodo<T> * m_pFirst;
     CNodo<T> * m_pLast;
     int size;

    public:
       Cola()
       {
         m_pFirst=m_pLast=0;
       }
       bool IsEmpty()
       {
            return m_pFirst==0;
       }
       void Pop()
       {
          if(!m_pFirst) return;

          CNodo<T> * tmp = m_pFirst;
          m_pFirst = m_pFirst->m_pSig;
          delete tmp;
          size--;

       }
       void Push(T d)
       {
            CNodo<T> * pNuevo = new CNodo<T>(d);
            if(!m_pFirst)
                m_pLast= m_pFirst =  pNuevo;
            else
            {
                m_pLast->m_pSig = pNuevo;
                m_pLast = pNuevo;
            }
            size++;
       }


       T*  Front()
       {
            if(!IsEmpty())
                return &(m_pFirst->m_Dato);
            return 0;
       }

       T* Back()
       {
            if(!IsEmpty())
                return &(m_pLast->m_Dato);
            return 0;
       }
       int Size()
       {
        return size;
       }

       void print(ostream  & os)
       {
           // print cabecera dot
          os<<"digraph  {"<<endl;
          os<<"node[shape=record,color=blue];"<<endl;
           os<<"graph[pencolor=transparent];"<<endl;
           os<<"rankdir=LR;"<<endl;

          m_pFirst->Print(os,1);


          os<<" edge[tailclip=false,arrowtail=dot,dir=both,color=red];"<<endl;
           int pos=1;
           for(CNodo<T> * p = m_pFirst;p->m_pSig ; p=p->m_pSig)
           {
             os<<"p"<<pos<< ":next:c -> p"<<pos+1<<":data;"<<endl;
             pos++;
           }
          os<<"}";
       }

};


#endif // COLA_H
