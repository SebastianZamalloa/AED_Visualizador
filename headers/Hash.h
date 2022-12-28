#ifndef HASH_H
#define HASH_H

#include<iostream>
#include<list>
#include <fstream>

using namespace std;

template<class Obj,int size = 11>
class Hash
{
    private:
       list<Obj> m_Tablal[size];
    private:


    public:
    Hash(){}
    void Insert(string key, Obj obj)
    {
        char * p = (char*)key.c_str();
        int s =0;
        while (*p)
        {
           s+=*p;
           p++;
        }
        m_Tablal[s%size].push_back(obj);
    }

    void Print(ostream &os)
    {

        os<<"digraph structs2"<<endl;
        os<<"{"<<endl;
        os<<"rankdir = LR;"<<endl;
        os<<"node [shape=record];"<<endl;
            os<<"splines=false;"<<endl;
            os<<"table [label=\"";

            typedef typename list<Obj>::iterator ITERADOR;
           int cont = 0;
           for (; cont < size ; cont++){
              os<<"<f"<<cont<<">"<<cont<<"|";
           }
           os<<"<f"<<cont<<">n\"];"<<endl;


           for (int  i = 0; i < size ; i++)
           {
              ITERADOR it = m_Tablal[i].begin();
              //os<<"node_0_"<<i<<"[label=\"";
              cont = 0;
              for(;it!=m_Tablal[i].end();++it,++cont)
                  os<<"node_"<<i<<"_"<<cont<<"[label=\"{ <ant> | <data> "<< *it <<" | <next> }\"];"<<endl;
           }



           for (int i=0;i<size;i++)
           {
               if(m_Tablal[i].begin() != m_Tablal[i].end())
                 os<<"table:f"<<i<<":c -> "<<"node_"<<i<<"_0:f0:ant;"<<endl;
           }

           os<<"edge[tailclip=false,arrowtail=dot,dir=both,headclip=true,color=black];"<<endl;
           for(int i = 0; i < size; i++)
          {
               ITERADOR it = m_Tablal[i].begin();
               cont = 0;
               for(;it!=m_Tablal[i].end();++it,++cont){
                   ITERADOR aux = it;
                   if(++aux != m_Tablal[i].end())
                       os<<"node_"<<i<<"_"<<cont<<":next:c -> "<<"node_"<<i<<"_"<<cont+1<<":ant:c;"<<endl;
               }
          }
           os<<"}"<<endl;
    }

/*
    void Print(ostream &os)
    {
        os<<"digraph structs2"<<endl;
        os<<"{"<<endl;
        os<<"rankdir = LR;"<<endl;
        os<<"node [shape=record];"<<endl;
            os<<"splines=false;"<<endl;
            os<<"table [label=\"";

            typedef typename list<Obj>::iterator ITERADOR;
           int cont = 0;
           for (; cont < size ; cont++){
              os<<"<f"<<cont<<">"<<cont<<"|";
           }
           os<<"<f"<<cont<<">n\"];"<<endl;

           for (int  i = 0; i < size ; i++)
           {
              ITERADOR it = m_Tablal[i].begin();
              os<<"node_0_"<<i<<"[label=\"";
              cont = 0;
              for(;it!=m_Tablal[i].end();++it,++cont)
                  os<<"<f"<<cont<<">"<<*it<<"|";
              os<<"<f"<<cont<<">n\"];"<<endl;
           }

           for (int i=0;i<size;i++)
           {
               os<<"table:f"<<i<<" -> "<<"node_0_"<<i<<":f0;"<<endl;
           }
           os<<"}"<<endl;
    }
    */

};

#endif // HASH_H
