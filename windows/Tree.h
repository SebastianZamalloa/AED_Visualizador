#ifndef TREE_H
#define TREE_H

#include <iostream>
#include<fstream>
#include <queue>
#include<stack>

using namespace std;

template <class T>
class Nodo{
  public:
    T m_Dato;
    Nodo <T> *m_pSon[2];
  public:
    Nodo(T dato){
        m_Dato = dato;
        m_pSon[0] = m_pSon[1] = nullptr;
    }

};

template <class T>
class Tree{
    typedef Nodo<T> *    pNodo;
    public:
      pNodo m_pRoot;
      pNodo m_Current;

      bool insert(pNodo &p, T d) {
          if(!p){
              p = new Nodo<T>(d);
              return true;
          }
          return insert(p->m_pSon[p->m_Dato < d],d);
      }

    public:
      Tree() {m_pRoot = m_Current = NULL;}
      bool insert(T d){return insert(m_pRoot,d);}
      Tree<T> & operator<<(T d)
      {
          insert(d);
          return *this;
      }

      void rec_amplitud()
      {
           queue <pNodo> cola;
           if(!m_pRoot) return;
            cola.push(m_pRoot);
            while(!cola.empty())
            {
                pNodo q = cola.front();
                cout<<q->m_Dato<<" ";
                cola.pop();
                if(q->m_pSon[1]) cola.push(q->m_pSon[1]);
                if(q->m_pSon[0]) cola.push(q->m_pSon[0]);
            }
       }


      void Add(T d){
          if(!m_pRoot) {m_pRoot = new Nodo<T>(d); return;}
          pNodo pTmp = m_pRoot;
          for(;pTmp->m_pSon[pTmp->m_Dato < d] != 0; pTmp = pTmp->m_pSon[pTmp->m_Dato < d]){}
          pTmp->m_pSon[pTmp->m_Dato < d] = new Nodo<T> (d);
      }

      pNodo father(T d)
      {
          if(!m_pRoot) return  0;
          pNodo aux = m_pRoot;
          for(;aux->m_pSon[aux->m_Dato < d] != 0;aux = aux->m_pSon[aux->m_Dato < d]){
              if(aux->m_pSon[aux->m_Dato < d]->m_Dato == d){
                  return aux;
              }
          }
          return  0;
      }
      void pre_order(pNodo p, ostream & os){
        if(p)
        {
            cout<<p->m_Dato<<"  ";

            pre_order(p->m_pSon[0],os);
            pre_order(p->m_pSon[1],os);
        }
        else return;
      }

      void print(ostream & os){
          queue <pNodo> cola;
           if(!m_pRoot) return;
            cola.push(m_pRoot);
            while(!cola.empty())
            {
                pNodo q = cola.front();
                if(father(q->m_Dato)) {
                   os<<father(q->m_Dato)->m_Dato<<" -> "<<q->m_Dato<<";"<<endl;
                }
                else os<<q->m_Dato<<endl;
                cola.pop();
                if(q->m_pSon[0]) cola.push(q->m_pSon[0]);
                if(q->m_pSon[1]) cola.push(q->m_pSon[1]);
            }
      }
      void mostrar(ostream  & os)
      {
           // print cabecera dot
          os<<"digraph BST {"<<endl;
          os<<"{"<<endl;
          os<<"node [margin=0 fontcolor=black fontsize=15 width=0.5 shape=circle style=filled fontname=Arial fillcolor=transparent];"<<endl;

          print(os);
          os<<"}"<<endl;
          os<<"}";

          cout<<endl;
      }
      void Find(ostream &os, T d){
          if(!m_pRoot) return;
          os<<"digraph BST {"<<endl;
          os<<"{"<<endl;
          os<<"node [margin=0 fontcolor=black fontsize=15 width=0.5 shape=circle style=filled fontname=Arial];"<<endl;
              queue <pNodo> cola;
              if(!m_pRoot) return;
               cola.push(m_pRoot);
               while(!cola.empty())
               {
                   pNodo q = cola.front();
                   if(q->m_Dato == d) os<<q->m_Dato<<" [margin=0 fontcolor=black fontsize=15 width=0.5 shape=circle style=filled fontname=Arial fillcolor=yellow];"<<endl;
                   else os<<q->m_Dato<<" [margin=0 fontcolor=black fontsize=15 width=0.5 shape=circle style=filled fontname=Arial fillcolor=transparent]";
                   cola.pop();
                   if(q->m_pSon[0]) cola.push(q->m_pSon[0]);
                   if(q->m_pSon[1]) cola.push(q->m_pSon[1]);
               }
             os<<"}"<<endl;

             print(os);
             os<<"}";
      }

};
#endif // TREE_H
