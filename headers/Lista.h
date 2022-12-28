#ifndef ListaS_H
#define ListaS_H

#include "iostream"
#include <fstream>

using namespace std;

template<class T>
class NodoS
{
    public:
        T m_Dato;
        NodoS * m_pSig;
    public:
        NodoS(T d)
        {
            m_Dato = d;
            m_pSig = NULL;
        }
        ~NodoS(){delete m_pSig;}
};


template<class T>
class ListaS
{
    private:
        NodoS<T> * m_pHead;
        int size;
    public:
        ListaS():m_pHead(NULL),size(0){}
        ~ListaS(){delete m_pHead;}
        void AddFront(T d)
        {
            NodoS<T>  * pNew = new NodoS<T>(d);
            if(!m_pHead)
                m_pHead = pNew;
            else
            {
                pNew->m_pSig = m_pHead;
                m_pHead = pNew;
            }
            size++;
        }
        void pushBack(T d)
        {
            NodoS<T>  * pNew = new NodoS<T>(d);
            if(m_pHead == NULL){m_pHead = pNew;}
            else
            {
                NodoS<T>*pTemp = m_pHead;
                while(pTemp->m_pSig != NULL)
                    pTemp = pTemp->m_pSig;
                pTemp->m_pSig = pNew;
            }
            size++;
        }
        void pushRecursive(T d)
        {
            if(m_pHead == NULL)
            {
                NodoS<T>*pNew = new NodoS<T>(d);
                m_pHead = pNew;
            }
            else
                pushRecursive(d,m_pHead);
        }
        void pushRecursive(T d, NodoS<T>*temp)
        {
            NodoS<T>*pTemp = temp;
            if(pTemp->m_pSig != NULL)
                pushRecursive(d,pTemp->m_pSig);
            else
            {
                NodoS<T>*pNew = new NodoS<T>(d);
                pTemp->m_pSig = pNew;
                size++;
            }
        }
        void pushPosition(T d, int pos)
        {
            if(pos >= size){cout<<"\nNo existe tal posicion\n";return;}
            if(pos == 0){AddFront(d); size++; return;}
            if(pos == size-1){pushBack(d); size++; return;}
            NodoS<T>*pTemp = m_pHead;
            while(pos != 1)
            {
                pTemp = pTemp->m_pSig;
                pos--;
            }
            NodoS<T>*pTemp2 = pTemp->m_pSig;
            NodoS<T>*pNew = new NodoS<T>(d);
            pTemp->m_pSig = pNew;
            pNew->m_pSig = pTemp2;
            size++;
        }
        NodoS<T> * findIt(T d)
        {
            NodoS<T>*pTemp = m_pHead;
            while(pTemp->m_Dato != d && pTemp->m_pSig != NULL)
            {
                pTemp = pTemp->m_pSig;
            }
            if(pTemp->m_Dato == d) return pTemp;
        }
        void findRecursive(T d)
        {
            if(m_pHead == NULL)
                cout<<"\nDato "<<d<<" NO encontrado en la ListaS enlazada\n";
            else
                findRecursive(d,m_pHead);
        }
        void findRecursive(T d, NodoS<T>*temp)
        {
            NodoS<T>*pTemp = temp;
            if(pTemp->m_Dato != d && pTemp->m_pSig != NULL)
                findRecursive(d,pTemp->m_pSig);
            else
            {
                if(pTemp->m_Dato == d){cout<<"\nDato "<<d<<" encontrado en la ListaS enlazada\n";return;}
                cout<<"\nDato "<<d<<" NO encontrado en la ListaS enlazada\n";
            }
        }
        void deleteLast()
        {
            if(size==1){delete m_pHead;m_pHead = NULL;size--;return;}
            NodoS<T>*pTemp = m_pHead;
            while(pTemp->m_pSig->m_pSig)
                pTemp = pTemp->m_pSig;
            NodoS<T>*pTemp2 = pTemp->m_pSig;
            pTemp->m_pSig = NULL;
            delete pTemp2;
            size--;
        }
        void deleteFront()
        {
            if(size==1){delete m_pHead;m_pHead = NULL;return;}
            NodoS<T>*pTemp = m_pHead->m_pSig;
            m_pHead->m_pSig = NULL;
            delete m_pHead;
            m_pHead = pTemp;
            size--;
        }
        void print()
        {
            NodoS<T>*pTmp = m_pHead;
            while(pTmp)
            {
                (pTmp->m_pSig) ? cout<<pTmp->m_Dato<<" --> " : cout<<pTmp->m_Dato;
                pTmp = pTmp->m_pSig;
            }
            cout<<endl;
        }
        void print(ostream &os){
            os<<"digraph  {"<<endl;
            os<<"node[shape=record,color=black];"<<endl;
             os<<"graph[pencolor=transparent];"<<endl;
             os<<"rankdir=LR;"<<endl;

             if(!m_pHead){
                 os<<"c0[label=\"{Size = 0 | <next>}\"];"<<endl;
                 os<<"c0"<<endl;
                 os<<"}";
                 return;
             }

             NodoS<T> *pTmp = m_pHead;
             int cont = 1;
             os<<"s[label=\"{Size "<< size <<"}\"];"<<endl;
             while(pTmp)
             {
                 string color= "transparent";
                 //if(pTmp = b) color = "skyblue";
                 os<<"p"<<cont<<"[style=filled, label=\"{"<< pTmp->m_Dato <<" | <next>}\",fillcolor="<<color<<"];"<<endl;
                 //os<<"p"<<cont<<"[label=\"{"<< pTmp->m_Dato <<" | <next>}\"];"<<endl;
                 cont++;
                 pTmp = pTmp->m_pSig;
             }

             os<<" edge[tailclip=false,arrowtail=dot,dir=both,color=black];"<<endl;
             int pos=1;
             for(NodoS<T> * p = m_pHead;p->m_pSig; p=p->m_pSig)
             {
               os<<"p"<<pos<< ":next:c -> p"<<pos+1<<";"<<endl;
               pos++;
             }
            os<<"}";
        }
        void print(ostream &os, NodoS<T> * b){
                    os<<"digraph  {"<<endl;
                    os<<"node[shape=record,color=black];"<<endl;
                     os<<"graph[pencolor=transparent];"<<endl;
                     os<<"rankdir=LR;"<<endl;

                     if(!m_pHead){
                         os<<"c0[label=\"{Size = 0 | <next>}\"];"<<endl;
                         os<<"c0"<<endl;
                         os<<"}";
                         return;
                     }

                     NodoS<T> *pTmp = m_pHead;
                     int cont = 1;
                     os<<"s[label=\"{Size "<< size <<"}\"];"<<endl;
                     while(pTmp)
                     {
                         string color= "transparent";
                         if(pTmp == b) color = "skyblue";
                         os<<"p"<<cont<<"[style=filled, label=\"{"<< pTmp->m_Dato <<" | <next>}\",fillcolor="<<color<<"];"<<endl;
                         cont++;
                         pTmp = pTmp->m_pSig;
                     }

                     os<<" edge[tailclip=false,arrowtail=dot,dir=both,color=black];"<<endl;
                     int pos=1;
                     for(NodoS<T> * p = m_pHead;p->m_pSig; p=p->m_pSig)
                     {
                       os<<"p"<<pos<< ":next:c -> p"<<pos+1<<";"<<endl;
                       pos++;
                     }
                    os<<"}";
                }
        void printReverseIt()
        {
            cout<<endl;
            if(size==1){cout<<m_pHead->m_Dato;cout<<endl;return;}
            NodoS<T>*pTmp = m_pHead;
            while(pTmp->m_pSig)
                pTmp = pTmp->m_pSig;
            NodoS<T>*pIt;
            NodoS<T>*pProgress = pTmp;
            do
            {
                pIt = m_pHead;
                while(pIt->m_pSig != pProgress)
                    pIt = pIt->m_pSig;
                cout<<pIt->m_pSig->m_Dato<<" <-- ";
                pProgress = pIt;
            } while (pProgress != m_pHead);
            cout<<m_pHead->m_Dato;
            cout<<endl;
        }
        void printReverseRecursive()
        {
            cout<<endl;
            if(!m_pHead){cout<<endl;return;}
            printReverseRecursive(m_pHead);
        }
        void printReverseRecursive(NodoS<T>*progress)
        {
            if(!progress){return;}
            printReverseRecursive(progress->m_pSig);
            (progress != m_pHead) ? cout<<progress->m_Dato<<" <-- " : cout<<progress->m_Dato<<endl;
        }
        NodoS<T> * maximumIt()
        {
            NodoS<T>*pTmp = m_pHead;
            NodoS<T>*mayor = m_pHead;
            while(pTmp)
            {
                if(mayor->m_Dato  <= pTmp->m_Dato)
                    mayor = pTmp;
                pTmp = pTmp->m_pSig;
            }
            return mayor;
        }
        NodoS<T> * minumunIt()
        {
            NodoS<T>*pTmp = m_pHead;
            NodoS<T>*mayor = m_pHead;
            while(pTmp)
            {
                if(mayor->m_Dato  > pTmp->m_Dato)
                    mayor = pTmp;
                pTmp = pTmp->m_pSig;
            }
            return mayor;
        }
        T maximumRecursive()
        {
            return maximumRecursive(m_pHead->m_Dato,m_pHead);
        }
        T maximumRecursive(T mayor,NodoS<T>*it)
        {
            if(!it)
                return mayor;
            if(it->m_Dato>=mayor)
                maximumRecursive(it->m_Dato,it->m_pSig);
            else
                maximumRecursive(mayor,it->m_pSig);
        }

};
/*
int main()
{
    cout<<endl;
    ListaS<int> A;
    A.AddFront(4);
    A.AddFront(14);
    A.AddFront(24);
    A.AddFront(44);
    A.AddFront(64);
    A.print();
    A.pushRecursive(2);
    A.print();
    A.pushPosition(108,2);
    A.print();
    A.findIt(5);
    A.findIt(24);
    A.findRecursive(7);
    A.findRecursive(14);
    A.printReverseRecursive();
    cout<<"\nEl mayor es : "<<A.maximumRecursive()<<endl;
    cout<<endl;
    return 0;
}
*/
#endif // ListaS_H
