#ifndef AVL_H
#define AVL_H

#include<iostream>
#include<queue>
#include<stack>
#include<fstream>

using namespace std;

template <class T>
class ANodo
{
    typedef ANodo<T>*   pANodo;
public:
T      m_Dato;
pANodo  m_pSon[3];
int m_FE;

public:
ANodo(T d)
{
  m_Dato = d;
  m_pSon[0]=m_pSon[1]=m_pSon[2]=0;
  m_FE=0;
}
void setFE(int FE)
    {
        this->m_FE = FE;
    }
void Matate()
{
    if(m_pSon[0]) m_pSon[0]->Matate();
    if(m_pSon[1]) m_pSon[1]->Matate();
    delete this;

}
};

template <class T>
class AVLTree
{
typedef ANodo<T> * pANodo;
private:
    pANodo m_pRoot;
    pANodo m_Current;
public:
    AVLTree(){ m_Current = m_pRoot = nullptr; };
    ~AVLTree(){ if(m_pRoot) m_pRoot->Matate(); }
private:
    int altura(pANodo m_p)
    {
            if (!m_pRoot)
                return 0;
            if(!m_p)
                return 0;
            return 1 + max(altura(m_p->m_pSon[0]), altura(m_p->m_pSon[1]));
     }
     void equilibrate(pANodo & p)
     {
        if(!p)
            return;
        equilibrate(p->m_pSon[0]);
        p->setFE(altura(p->m_pSon[1])-altura(p->m_pSon[0]));
        equilibrate(p->m_pSon[1]);
     }

    bool insert(pANodo & p , T d)
        {
            equilibrate(m_pRoot);
            cout<<"inico: "<<d<<endl;
            if(!p){p= new ANodo<T>(d); return true;}
            if(p->m_Dato == d) return false ;

            if(insert(p->m_pSon[p->m_Dato < d],d)){

                if(p->m_Dato<d) p->m_FE++;
                else p->m_FE--;

                switch (p->m_FE)
                {
                    case 0:return true ;
                    case 2:
                        if (p->m_pSon[1]->m_FE==-1)RC(p, true);
                        else RS(p, true); return true;break;
                    case -2:
                        if (p->m_pSon[0]->m_FE==1)RC(p, false);
                        else RS(p, false); return true;break;
                }
            }
            return true;
        }

        void print(pANodo p, ostream & os, int & i)
        {

            if(!p) return;
            os<<i<<": "<<p->m_Dato<< " ->"<<p->m_FE<< endl;
            i++;
            print(p->m_pSon[0],os,i);
            print(p->m_pSon[1],os,i);
        }
    void RS (pANodo &p, bool d)
       {

        pANodo q = p->m_pSon[d];
        p->m_pSon[d] = q->m_pSon[!d];
        q->m_pSon[!d] = p;
        p->m_FE = q->m_FE = 0;
        p=q;

       }

       void RC(pANodo &p, bool d)  // d=true = 1
       {
            pANodo q = p->m_pSon[d];
            pANodo r = q->m_pSon[!d];

            //salvar los Anodos
            p->m_pSon[d] = r->m_pSon[!d];
            q->m_pSon[!d] = r->m_pSon[d];

            r->m_pSon[d] = q;
            r->m_pSon[!d] = p;

            if (d)
            {
                switch (r->m_FE)
                {
                case 0:
                    r->m_FE = q->m_FE = p->m_FE = 0;
                    break;
                case -1:
                    r->m_FE = -1;
                    p->m_FE = 1;
                    q->m_FE = 0;
                    break;
                case 1:
                    r->m_FE = 1;
                    p->m_FE = 0;
                    q->m_FE = -1;
                    break;
                }
            }else
            {
                switch (r->m_FE)
                {
                case 0:
                    r->m_FE = q->m_FE = p->m_FE = 0;
                    break;
                case -1:
                    r->m_FE = -1;
                    p->m_FE = 0;
                    q->m_FE = 1;
                    break;
                case 1:
                    r->m_FE = 1;
                    p->m_FE = -1;
                    q->m_FE = 0;
                    break;
                }
            }
            p=r;
       }
public:
    bool find(T d){ return find(m_pRoot); }
    bool insert(T d){ return insert(m_pRoot,d); }


    AVLTree<T> & operator<<(T d)
    {
        insert(d);
        return *this;
    }
    void Find(ostream &os, T d){
        if(!m_pRoot) return;
        os<<"digraph BST {"<<endl;
        os<<"{"<<endl;
        os<<"node [margin=0 fontcolor=black fontsize=15 width=0.5 shape=circle style=filled fontname=Arial];"<<endl;
            queue <pANodo> cola;
            if(!m_pRoot) return;
             cola.push(m_pRoot);
             while(!cola.empty())
             {
                 pANodo q = cola.front();
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


    pANodo father(T d)
    {
        if (!m_pRoot) return 0;
        pANodo pTmp = m_pRoot;
        if(d == pTmp->m_Dato) return 0;
        while(pTmp)
        {
            if(d == (pTmp->m_pSon[d > pTmp->m_Dato])->m_Dato) return pTmp;
            pTmp = pTmp->m_pSon[d > pTmp->m_Dato];
        }
        return 0;
    }

    pANodo sibling(T d)
    {
        if (!m_pRoot) return 0;
        pANodo pTmp = m_pRoot;
        if(d == pTmp->m_Dato) return 0;
        pTmp = father(d);
        if(pTmp)
            return pTmp->m_pSon[d < pTmp->m_Dato];
        return 0;
    }

    pANodo Uncle(T d)
    {
        pANodo padre = father(d);
        if (padre)
        {
            pANodo tio = sibling(padre->m_Dato);
            return tio;
        }
        return 0;
    }

    pANodo grandParent(T d)
    {
        pANodo padre = father(d);
        if (padre)
        {
            pANodo abuelo = father(padre->m_Dato);
            return abuelo;
        }
        return 0;
    }

    pANodo Begin()
    {
        m_Current = m_pRoot;
        if(!m_Current) return 0;
        while(m_Current->m_pSon[0])
        {
            m_Current = m_Current->m_pSon[0];
        }
        return m_Current;
    }

    pANodo End()
    {
        m_Current = m_pRoot;
        if(!m_Current) return 0;
        while(m_Current->m_pSon[1])
        {
            m_Current = m_Current->m_pSon[1];
        }
        return m_Current;
    }

    pANodo Next()
    {
        if(!m_Current) return 0;
        if(m_Current == m_pRoot && !(m_Current->m_pSon[1])) return 0;

        if(m_Current->m_pSon[1])
        {
            m_Current = m_Current->m_pSon[1];
            while(m_Current->m_pSon[0])
                m_Current = m_Current->m_pSon[0];
            return m_Current;
        }

        pANodo pTmp_1 = father(m_Current->m_Dato);
        pANodo pTmp_2 = m_Current;
        while(pTmp_1)
        {
            if(pTmp_1->m_Dato > pTmp_2->m_Dato)
            {
                m_Current = pTmp_1;
                return m_Current;
            }
            pTmp_2 = pTmp_1;
            pTmp_1 = father(pTmp_2->m_Dato);
        }
        return 0;
    }

    T  GetData() { return m_Current->m_Dato; }

    void print(ostream & os){
        queue <pANodo> cola;
         if(!m_pRoot) return;
          cola.push(m_pRoot);
          while(!cola.empty())
          {
              pANodo q = cola.front();
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



};

#endif // AVL_H
