#ifndef RED_BLACK_H
#define RED_BLACK_H

#include <iostream>
#include<fstream>
#include <queue>
#include<stack>

using namespace std;


template<class T>
class RBNodo
{
    typedef RBNodo<T>*   pNodo;
    public:
    T      m_Dato;
    pNodo  m_pSon[3];
    bool m_colorRB; // r=0 y b=1

    public:
    RBNodo(T d)
    {
      m_Dato = d;
      m_colorRB=0;
      m_pSon[0]=m_pSon[1]=m_pSon[2]=0;
    }

    void Matate()
    {
        if(m_pSon[0]) m_pSon[0]->Matate();
        if(m_pSon[1]) m_pSon[1]->Matate();

        delete this;
    }
};

template <class T>
class RBTree{
    typedef RBNodo <T> *    pNodo;
    public:
      pNodo m_pRoot;
      pNodo m_Current;

      void insert(T d)
   {
         if(!m_pRoot){m_pRoot = new RBNodo<T>(d); m_pRoot->m_pSon[2] = 0;insercion_caso1(m_pRoot);  return;}
         pNodo p = m_pRoot;
         pNodo q = p;
         while (p)
         {
            q=p;
            if(p->m_Dato==d) return;
            p= p->m_pSon[p->m_Dato <d];
         }

        pNodo &r= q->m_pSon[q->m_Dato < d];
        r = new RBNodo <T>(d);
        r->m_pSon[2] = q;
        insercion_caso1(r);
   }

   void insercion_caso1(pNodo n)
    {
        if(n->m_pSon[2]==NULL) n->m_colorRB = 1;
        else insercion_caso2(n);
    }


    void insercion_caso2(pNodo n)
    {

        if(n->m_pSon[2]->m_colorRB == 1) return;
        else insercion_caso3(n);
    }


    void insercion_caso3(pNodo n)
    {

        pNodo a= n->m_pSon[2]->m_pSon[2];
        //pNodo t = Uncle(n->m_Dato);
        pNodo t = a->m_pSon[a->m_Dato > n->m_Dato ];
        if((t!=NULL && t->m_colorRB == 0))
        {
            n->m_pSon[2]->m_colorRB = 1;
            t->m_colorRB = 1;
            //pNodo a=father(n->m_pSon[2]->m_Dato);
            a->m_colorRB = 0;
            insercion_caso1(a);
        }else
        {
            insercion_caso4(n);
        }
    }


    void insercion_caso4(pNodo n)
    {

        pNodo a = n->m_pSon[2]->m_pSon[2];
        if( n== n->m_pSon[2]->m_pSon[1] && n->m_pSon[2]== a->m_pSon[0])
        {
            rotar_izda(n->m_pSon[2]); // rotat_Izqd

            n= n->m_pSon[0];

        }
        else if ( n== n->m_pSon[2]->m_pSon[0] && n->m_pSon[2]== a->m_pSon[1])
        {
            rotar_dcha( n->m_pSon[2]);    // rotat_Izqd
            n= n->m_pSon[1];
        }
        insercion_caso5(n);
    }

    void insercion_caso5(pNodo n)
    {
        pNodo a = n->m_pSon[2]->m_pSon[2];
        n->m_pSon[2]->m_colorRB = 1;
        a->m_colorRB = 0;

        if (n== n->m_pSon[2]->m_pSon[0] && n->m_pSon[2] == a->m_pSon[0] )
            rotar_dcha (a); //derecha
        else
            rotar_izda (a);
    }


    void rotar_izda(pNodo p)
    {
        pNodo *aux = &m_pRoot;

        if (p->m_pSon[2]!=NULL && p->m_pSon[2]->m_pSon[1]==p)
            aux = &(p->m_pSon[2]->m_pSon[1]);
        else if (p->m_pSon[2]!=NULL && p->m_pSon[2]->m_pSon[0]==p)
            aux = &(p->m_pSon[2]->m_pSon[0]);

        *aux = p->m_pSon[1];
        (*aux)->m_pSon[2]= p->m_pSon[2];
        p->m_pSon[2]= *aux;
        p->m_pSon[1] = (*aux)->m_pSon[0];
        (*aux)->m_pSon[0] = p;
        if (p->m_pSon[1]!=NULL) p->m_pSon[1]->m_pSon[2]=p;

    }
    void rotar_dcha (pNodo p)
    {

        pNodo *aux = &m_pRoot;

        if (p->m_pSon[2]!=NULL && p->m_pSon[2]->m_pSon[1]==p)
            aux = &(p->m_pSon[2]->m_pSon[1]);
        else if (p->m_pSon[2]!=NULL && p->m_pSon[2]->m_pSon[0]==p)
            aux = &(p->m_pSon[2]->m_pSon[0]);

        *aux = p->m_pSon[0];
        (*aux)->m_pSon[2]= p->m_pSon[2];
        p->m_pSon[2]= *aux;


        p->m_pSon[0] = (*aux)->m_pSon[1];
        (*aux)->m_pSon[1] = p;
        if (p->m_pSon[0]!=NULL) p->m_pSon[0]->m_pSon[2]=p;


    }

    public:
      RBTree() {m_pRoot = m_Current = NULL;}
      RBTree<T> & operator<<(T d)
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
                if(q->m_pSon[0]) cola.push(q->m_pSon[0]);
                if(q->m_pSon[1]) cola.push(q->m_pSon[1]);
            }
       }


      void Add(T d){
          if(!m_pRoot) {m_pRoot = new RBNodo<T>(d); return;}
          pNodo pTmp = m_pRoot;
          for(;pTmp->m_pSon[pTmp->m_Dato < d] != 0; pTmp = pTmp->m_pSon[pTmp->m_Dato < d]){}
          pTmp->m_pSon[pTmp->m_Dato < d] = new RBNodo <T> (d);
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

          if(!m_pRoot) return;
              queue <pNodo> cola2;
              if(!m_pRoot) return;
               cola2.push(m_pRoot);
               while(!cola2.empty())
               {
                   pNodo q = cola2.front();
                   string color = "red";
                   if(q->m_colorRB) color = "black";

                   os<<q->m_Dato<<" [margin=0 fontcolor=white fontsize=15 width=0.5 shape=circle style=filled fontname=Arial fillcolor="<<color<<"]";

                   cola2.pop();
                   if(q->m_pSon[0]) cola2.push(q->m_pSon[0]);
                   if(q->m_pSon[1]) cola2.push(q->m_pSon[1]);

               }

           os<<"}"<<endl;
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

            os<<"}"<<endl;

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
                   else {
                       string color = "red";
                       if(q->m_colorRB) color = "black";
                       os<<q->m_Dato<<" [margin=0 fontcolor=white fontsize=15 width=0.5 shape=circle style=filled fontname=Arial fillcolor="<<color<<"]";
                   }
                       cola.pop();
                   if(q->m_pSon[0]) cola.push(q->m_pSon[0]);
                   if(q->m_pSon[1]) cola.push(q->m_pSon[1]);
               }
             os<<"}"<<endl;

             queue <pNodo> cola2;
              if(!m_pRoot) return;
               cola2.push(m_pRoot);
               while(!cola2.empty())
               {
                   pNodo q = cola2.front();
                   if(father(q->m_Dato)) {
                      os<<father(q->m_Dato)->m_Dato<<" -> "<<q->m_Dato<<";"<<endl;
                   }
                   else os<<q->m_Dato<<endl;

                   cola2.pop();
                   if(q->m_pSon[0]) cola2.push(q->m_pSon[0]);
                   if(q->m_pSon[1]) cola2.push(q->m_pSon[1]);
               }

               os<<"}"<<endl;

             os<<"}";
      }

};

#endif // RED_BLACK_H
