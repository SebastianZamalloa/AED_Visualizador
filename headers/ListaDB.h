#ifndef LISTADB_H
#define LISTADB_H

#include<iostream>
#include<fstream>


using namespace std;

template<class T>
class DBNodo
{
    public:
       T         m_Dato;
       DBNodo<T> * m_pSig;
       DBNodo<T> * m_pAnt;
    public:
       DBNodo(T d)
       {
          m_Dato=d;
          m_pSig=m_pAnt=0;
       }

       void Print(ostream & os, int  pos)
       {

           os<<"p"<<std::to_string(pos)<<"[label=\"{<ant> | <data> " << m_Dato <<"|<next>}\"]"<<endl;

           if (m_pSig)  m_pSig->Print(os,++ pos);

       }

};


template<class T>
class Lista
{
    private:
       DBNodo<T> *    m_pHead;
       DBNodo<T> *    m_pLast;

       DBNodo<T> *    m_pCurrent;

    public:
      Lista()
      {
        m_pHead=m_pLast=m_pCurrent=0;
      }

      void push_front(T d)
            {
                 // precondition
                 if(!m_pHead)
                 {
                    m_pHead = m_pLast = m_pCurrent = new DBNodo<T>(d);
                 }
                 else
                 {
                    DBNodo<T> * pNuevo=new DBNodo<T>(d);
                    pNuevo->m_pSig = m_pHead;
                    m_pHead->m_pAnt = pNuevo;
                    m_pHead =pNuevo;
                 }


            }
            void push_back(T d)
            {
                 if(!m_pHead)
                 {
                    m_pHead = m_pLast = m_pCurrent = new DBNodo<T>(d);
                 }
                 else
                 {
                    DBNodo<T> *pNuevo=new DBNodo<T>(d);
                    m_pLast->m_pSig = pNuevo;
                    pNuevo->m_pAnt = m_pLast;
                    m_pLast =pNuevo;

                 }
            }
      void push(int p, T d){}

      void pop_front()
      {
          if(!m_pHead) return;
          if(!m_pHead->m_pSig)
          {
              delete m_pHead;
              m_pHead = m_pLast =0;
              return;
          }
          m_pHead=m_pHead->m_pSig;
          delete m_pHead->m_pAnt;
          m_pHead->m_pAnt =0;

      }

      void pop_back(){}
      void pop(int p, T d){}

      bool find(T d, DBNodo<T> * & p)
      {
           for(p = m_pHead;p; p=p->m_pSig)
              if(p->m_Dato == d) return true;
           return false;
      }


      bool find_r(T d, DBNodo<T> * & p)
      {
           for(p = m_pLast;p; p=p->m_pAnt)
              if(p->m_Dato == d) return true;
           return false;
      }

      void print(ostream  & os)
      {
           // print cabecera dot
          os<<"digraph  {"<<endl;
          os<<"node[shape=record,color=black];"<<endl;
           os<<"graph[pencolor=transparent];"<<endl;
           os<<"rankdir=LR;"<<endl;
           if(!m_pHead){
               os<<"c0[label=\"{NULL | <next>}\"];"<<endl;
               os<<"c0"<<endl;
               os<<"}";
               return;
           }

          m_pHead->Print(os,1);


          os<<" edge[tailclip=false,arrowtail=dot,dir=both,color=black];"<<endl;
           int pos=1;
           int current=1;
           os<<"c0[label=\"{Current | <next>}\"];"<<endl;
           for(DBNodo<T> * p = m_pHead;p->m_pSig; p=p->m_pSig)
           {
               if(p == m_pCurrent) current = pos;
             os<<"p"<<pos<< ":next:c -> p"<<pos+1<<":ant;"<<endl;
             os<<"p"<<pos+1<< ":ant:c -> p"<<pos<<":next;"<<endl;
             pos++;
           }
           if(m_pCurrent == m_pLast) os<<"c0:next:c -> p"<<pos<<":ant"<<endl;
           else os<<"c0:next:c -> p"<<current<<":ant"<<endl;
          os<<"}";
      }

      //*****************************//
      // Iterator //
      void begin() {m_pCurrent = m_pHead;}

      void end(){m_pCurrent = m_pLast;}
      void operator++()
      {
         if(m_pCurrent->m_pSig)
           m_pCurrent=m_pCurrent->m_pSig;
      }

      void operator--()
      {
         if(m_pCurrent->m_pAnt)
             m_pCurrent=m_pCurrent->m_pAnt;
      }
      T GetData()
      {
             return m_pCurrent->m_Dato;
      }
      //******************************//
};

#endif // LISTADB_H
