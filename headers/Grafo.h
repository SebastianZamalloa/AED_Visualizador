#ifndef GRAFO_H
#define GRAFO_H

#include <stack>
#include <queue>
#include <list>
#include <bits/stdc++.h>
using namespace std;


#define INF 99999


using namespace std;


template<class V, class A>
class Edge;




template<class V,class A>
class Vertex
{
    public:
     V                   m_Dato;
     int                 m_Costo;
     bool                m_Visit;
     list<Edge<V,A> >    m_list_Edge;

    Vertex(V vertice)
    {
        m_Dato = vertice;
        m_Costo = INF;
        m_Visit = false;

    }

    bool operator==(const Vertex<V,A> & Ve)
    {
        return m_Dato == Ve.m_Dato;
    }

};



template<class V,class A>
class Edge
{
    public:
        A                   m_Dato;
        Vertex<V,A>  *      m_pVertex;

        Edge(A a, Vertex<V,A>  *q=0)
        {
            m_Dato = a;
            m_pVertex=q;
        }


    bool operator==(const Edge<V,A> & Ar)
    {
        return m_Dato == Ar.m_Dato;
    }

};



template<class V,class A>
class Graph
{
   typedef typename   list< Vertex <V,A>>::iterator Iterator_Vertex;
   typedef typename   list<  Edge  <V,A>>::iterator Iterator_Edge;
   private:
      list< Vertex <V,A> >   m_Graph;
   public:
   Graph(){};

   void Insert(V Vertice)
   {
          m_Graph.push_back(Vertex<V,A>(Vertice));
   };
   void Insert_Edge(V v1, V v2, A a)
   {
         Iterator_Vertex p = find_Vertex(v1);
         Iterator_Vertex q = find_Vertex(v2);
         if(p!= m_Graph.end() && q!= m_Graph.end())
         {
            // ¿Qué ocurre si la arista y existe?
            Vertex<V,A>* pDestino = &(*q);
            p->m_list_Edge.push_back(Edge<V,A>(a, pDestino));
         }

   };

   void Reset_Graph()
   {
     Iterator_Vertex it = m_Graph.begin();
       for(; it != m_Graph.end();it++)
       {
          it->m_Visit = false;
          it->m_Costo = INF;
       }
   }

   list<V> DFS()
   {
       Reset_Graph();
       stack< Iterator_Vertex > pila;
       pila.push(m_Graph.begin());
       list <V> orden;
       while (!pila.empty())
       {
           Iterator_Vertex it = pila.top();
           pila.pop();
           if(!it->m_Visit)
                      {
               orden.push_back(it->m_Dato);
               it->m_Visit=true;
                      }
           Iterator_Edge it_e = it->m_list_Edge.begin();
           for(; it_e != it->m_list_Edge.end();++it_e)
           {
               if(it_e->m_pVertex->m_Visit==false)
               {
                Iterator_Vertex it_d = find_Vertex(it_e->m_pVertex->m_Dato);
                if(it_d != m_Graph.end())
                  pila.push(it_d);
               }
           }
       }
       return orden;

   }

    list<V> BFS()
   {
       Reset_Graph();
       queue< Iterator_Vertex > pila;
       pila.push(m_Graph.begin());
       list <V> orden;
       while (!pila.empty())
       {
           Iterator_Vertex it = pila.front();
           pila.pop();

           if(!it->m_Visit)
           {
               orden.push_back(it->m_Dato);
               it->m_Visit=true;
               //cout<<it->m_Dato<<endl;
           }
           Iterator_Edge it_e = it->m_list_Edge.begin();
           for(; it_e != it->m_list_Edge.end();++it_e)
           {
               Iterator_Vertex it_d = find_Vertex(it_e->m_pVertex->m_Dato);
                if(it_d != m_Graph.end() && it_d->m_Visit==false)
                    pila.push(it_d);

           }
       }
       return orden;

   }

   Iterator_Vertex  find_Vertex(V v)
   {
    return    std::find(m_Graph.begin(), m_Graph.end(), Vertex<V,A>(v));
   }


   bool find_edge(V v, A a)
   {
        Iterator_Vertex  p = find_Vertex(v);
        Iterator_Edge    q = std::find(p->m_list_Edge.begin(), p->m_list_Edge.end(), Edge<V,A>(a));
        if(q!=p->m_list_Edge.end())
           return true;
   }
   void Print()
   {
       typedef typename   list< Vertex <V,A>>::iterator Iterator_Vertex;
       Iterator_Vertex it = m_Graph.begin();
       for(; it != m_Graph.end();it++)
       {
          Iterator_Edge    it_e = it->m_list_Edge.begin();
          for(; it_e != it->m_list_Edge.end();++it_e)
           {
              cout<<it->m_Dato<<" ---> "<<it_e->m_Dato<<"---->"<<it_e->m_pVertex->m_Dato<<endl;
           }

       }

    }

    int mini_dis(vector<int> &d)
    {
        Iterator_Vertex it = m_Graph.begin();
        int min;
        int i=0;

        for(; it != m_Graph.end();it++)
        {
            if(!it->m_Visit)
            {
                min = d[i];
                break;
            }
            i++;
        }
        i=0;
        it = m_Graph.begin();
        for(; it != m_Graph.end();it++)
        {
            if(!it->m_Visit && min > it->m_Costo)
                min = d[i];
            i++;
        }

        return min;

    }


    stack<V> disjtrak_alg(V Or,V des)
    {
        Reset_Graph();
        Iterator_Vertex O = find_Vertex(Or);
        O->m_Costo=0;
        //min_heap d;
        int n_vectors =m_Graph.size() ;
        vector<int> d(n_vectors, 0);
        vector<string> previus(n_vectors);

        //_________________________________________________________________________________________________

        for(int m=0; m<n_vectors;m++)
        {
            vector<Edge<string,int>*> lst_edges;
            for(Iterator_Edge or_ed = O->m_list_Edge.begin(); or_ed != O->m_list_Edge.end();++or_ed)
                lst_edges.push_back(&(*or_ed));

            O->m_Visit=true;

            int k =0;
            for (Iterator_Vertex it = m_Graph.begin();it!=m_Graph.end(); it++)
            {
                if(it->m_Visit)
                {
                    d[k] = it->m_Costo;
                }
                else
                {
                    bool band=false;
                    for(auto i =lst_edges.begin(); i != lst_edges.end();++i)
                    {
                        if((*i)->m_pVertex == &(*it))
                        {
                            if( d[k] != (std::min(O->m_Costo + (*i)->m_Dato, it->m_Costo)))
                                previus[k] = O->m_Dato;
                            d[k] = std::min(O->m_Costo + (*i)->m_Dato, it->m_Costo);

                            band=true;
                            it->m_Costo = std::min(O->m_Costo + (*i)->m_Dato, it->m_Costo)  ;
                            lst_edges.erase(i);
                            break;
                        }
                    }
                    if(!band)
                        d[k] = it->m_Costo;
                }
                k++;
            }
            lst_edges.clear();

            if(m==0){
                O->m_Costo= d[0]=INF;
            }

            int peso = mini_dis(d);

            Iterator_Vertex ittt = m_Graph.begin();
            vector<int>::iterator it_vd = d.begin();

            for(; ittt != m_Graph.end();ittt++)
            {
                if((*it_vd) ==peso && !ittt->m_Visit){
                    O = ittt;
                    break;
                }

                it_vd++;
            }
            k=0;

        }



        Iterator_Vertex start = m_Graph.begin();

        int l=0;
        V destiny_aux = des;
        stack<V> path;
        for(Iterator_Vertex q=m_Graph.begin(); q!=m_Graph.end();q++)
        {
            if(q->m_Dato==des)
            {
                path.push(to_string(d[l]));
                break;
            }
            l++;
        }
        l=0;
        while(start->m_Dato!=destiny_aux)
        {
            if(start==m_Graph.end())
            {
                start =m_Graph.begin();
            }

            if(start->m_Dato == destiny_aux)
            {
                path.push(start->m_Dato);
                destiny_aux = previus[l];
                start=m_Graph.begin();
                l=0;

            }else{
                start++;
                l++;
                if(start->m_Dato==destiny_aux)
                {
                    path.push(start->m_Dato);
                    destiny_aux = previus[l];
                    start=m_Graph.begin();
                    l=0;
                }

            }
        }
        path.push(Or);
        return path;

    }


    void Print(ostream & os)
    {
       typedef typename   list< Vertex <V,A>>::iterator Iterator_Vertex;
       typedef typename   list<Edge<V,A> > ::iterator Iterator_Edges;
       Iterator_Vertex it = m_Graph.begin();
       os<<"digraph Graph{"<<endl;
       os<<"fontname=\"Helvetica,Arial,sans-serif\""<<endl;
       os<<"node [fontname=\"Helvetica,Arial,sans-serif\"]"<<endl;
       os<<"edge [fontname=\"Helvetica,Arial,sans-serif\"]"<<endl;
       os<<"rankdir=LR;"<<endl;
       os<<"node[shape = circle];"<<endl;

       for(; it != m_Graph.end();it++)
       {
           os<<it->m_Dato<<";"<<endl;
       }
       it = m_Graph.begin();


       for(; it != m_Graph.end();it++)
       {
          Iterator_Edges It = it->m_list_Edge.begin();

          for (; It!= it->m_list_Edge.end();It++){
              os<<it->m_Dato<<" -> "<<It->m_pVertex->m_Dato<<" [label = \""<<It->m_Dato<<"\"];"<<endl;
          }
       }

       os<<"}";
    }

    void Print(ostream & os, stack<V> vertices)
       {
          typedef typename   list< Vertex <V,A>>::iterator Iterator_Vertex;
          typedef typename   list<Edge<V,A> > ::iterator Iterator_Edges;
          Iterator_Vertex it = m_Graph.begin();
          os<<"digraph Graph{"<<endl;
          os<<"fontname=\"Helvetica,Arial,sans-serif\""<<endl;
          os<<"node [fontname=\"Helvetica,Arial,sans-serif\",style=filled]"<<endl;
          os<<"edge [fontname=\"Helvetica,Arial,sans-serif\"]"<<endl;
          os<<"rankdir=LR;"<<endl;
          os<<"node[shape = circle];"<<endl;

          for(; it != m_Graph.end();it++)
          {

           stack<V> aux = vertices;
           bool x = 0;
           while(!aux.empty()){
            if(aux.top() == it->m_Dato){
                os<<it->m_Dato <<"[fillcolor=yellow,fontcolor=red,arrowsize=3];"<<endl;
                x = 1;
            }
            aux.pop();
           }
           if(!x) os<<it->m_Dato<<";"<<endl;

          }
          it = m_Graph.begin();


          for(; it != m_Graph.end();it++)
          {
             Iterator_Edges It = it->m_list_Edge.begin();

             for (; It!= it->m_list_Edge.end();It++){
                stack<V> v = vertices;
                bool x = 0;

                while(!v.empty()){
                    stack<V> s = v;
                    s.pop();
                    if(it->m_Dato == v.top() && It->m_pVertex->m_Dato == s.top()){
                    os<<it->m_Dato<<" -> "<<It->m_pVertex->m_Dato<<" [label = \""<<It->m_Dato<<"\" ,fillcolor=yellow,fontcolor=blue,arrowsize=2];"<<endl;
                    x = 1;
                    }
                    v.pop();
                }
                if(!x) os<<it->m_Dato<<" -> "<<It->m_pVertex->m_Dato<<" [label = \""<<It->m_Dato<<"\"];"<<endl;
             }
          }

          while(vertices.size() > 1) vertices.pop();

          os<<"k[shape=box; label = \"Distancia "<<vertices.top()<<"\"];"<<endl;

          os<<"}";
       }

    void Print(ostream & os, list<V> orden)
       {

          os<<"digraph Graph{"<<endl;
          os<<"fontname=\"Helvetica,Arial,sans-serif\""<<endl;
          os<<"node [fontname=\"Helvetica,Arial,sans-serif\",style=filled]"<<endl;
          os<<"rankdir=LR;"<<endl;
          os<<"node[shape = record];"<<endl;
          os<<"o[label=\"{ ";
          for(auto i = orden.begin() ;i != orden.end(); i++){
              if(i != --orden.end())
                os<<*i<<" | ";
              else
                  os<<*i;
          }
          os<<"}\" ]"<<endl;
          os<<"o;\n}";
       }

};

#endif // GRAFO_H
