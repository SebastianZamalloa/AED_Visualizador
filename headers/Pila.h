#ifndef PILA_H
#define PILA_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class PNodo
{
  public:
     T          m_Dato;
     PNodo<T>  * m_pAnt;
  public:
     PNodo(T d)
     {
       m_Dato = d;
       m_pAnt = 0;
     }

};

template<class T>
class Pila
{
    private:
     PNodo<T> * m_pTope;
     int size;
    public:
       Pila()
       {
         m_pTope =0;
         size = 0;
       }
       bool IsEmpty()
       {
           return m_pTope==0;
       }
       void Pop()
       {
          if(!m_pTope) return;

          PNodo<T> * tmp = m_pTope;
          m_pTope = m_pTope->m_pAnt;
          delete tmp;
          size--;

       }
       void Push(T d)
       {
        PNodo<T> * pNuevo = new PNodo(d);
        if(!m_pTope)
            m_pTope =  pNuevo;
        else
        {
         pNuevo->m_pAnt = m_pTope;
         m_pTope = pNuevo;
        }
        size++;
       }
       int Size(){return size;}

       T *  Top()
       {
          if(!IsEmpty())
             return &(m_pTope->m_Dato);
          return 0;
       }

       void Print(ostream &os){
           PNodo <T> * pAux = m_pTope;
           if(!pAux){
               os<<"digraph structs2 "<<endl;
               os<<"{"<<endl;
               os<<"rankdir = LR;"<<endl;
               os<<"node [shape=record];"<<endl;
                   os<<"splines=false;"<<endl;
                   os<<"hashTable [label=\"f<0>0\"];\n}";
               return;
           }

           os<<"digraph structs2 "<<endl;
           os<<"{"<<endl;
           os<<"rankdir = LR;"<<endl;
           os<<"node [shape=record];"<<endl;
               os<<"splines=false;"<<endl;
           os<<"hashTable [label=\"";
           int cont = 0;
           while(pAux){
               os<<"<f"<<cont<<">"<<pAux->m_Dato<<"|";
               pAux = pAux->m_pAnt;
               cont++;
           }
           os<<"<f"<<cont<<">NULL\"];"<<endl;

           os<<"{rank = same; node_1_0}"<<endl;
           os<<"node_1_0 [label=\"<f0>Top\"];"<<endl;
           os<<"hashTable:f0 -> node_1_0:f0;";
           os<<"}"<<endl;
       }

};

#endif // PILA_H
