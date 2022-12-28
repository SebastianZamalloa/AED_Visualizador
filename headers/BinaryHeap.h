#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include "iostream"
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

template <class T>
class BinaryHeap{
    private:
        vector<T> A;
    public:
        bool compare_heap(T a, T b, bool c)
        {
            if(!c)
                return (a>b);
            return a<b;
        }
        void heapFy(int i, int n, bool type)
        {
            int Posicioin_izquierda = (2*i)+1;      //#hijo_derecho();
            int Posicioin_derecha =   (2*i)+2;      //#hijo_derecho();
            if(Posicioin_izquierda >= n) return;     // se detiene llega a la hoja

            int menor = i;
            if(compare_heap(A[menor], A[Posicioin_derecha], type))
                menor = Posicioin_derecha;
            if (compare_heap(A[menor], A[Posicioin_izquierda], type))
                menor = Posicioin_izquierda;
            if (menor == i) return;
            swap(A[i], A[menor]);
            heapFy(menor, n, type);
        }

        void make_heap(bool type)
        {
            int n = A.size() -1;
            int inicio_posicion = floor(n/2);
            for(int i=inicio_posicion ; i>=0; i--)
                heapFy(i, n, type);
        }

        void HeapSort(bool type)
        {
            make_heap(type);
            int m=A.size();
            int n=m;
            for(int i=0; i<m; i++)
            {
                if(!compare_heap(A[0] ,A[n-1],type))
                    swap(A[0],A[n-1]);
                n--;
                heapFy(0,n-1,type);
            }
        }

    public:
        void Push_Back(T a){
            //if(!(find(A.begin(), A.end(), a) != A.end()))
                A.push_back(a);
        }
        void print(ostream &os)
        {
            os<<"digraph {"<<endl;

                os<<"node [shape=plaintext, fontcolor=red, fontsize=18];"<<endl;
                os<<"node [shape=record, fontcolor=black, fontsize=14, width=4.75, fixedsize=true];"<<endl;
                os<<" values [label=\"";
                for (size_t i = 0; i < A.size(); i++) {
                    if(i < (A.size()-1))
                        os<<"<f"<<i<<">"<<A[i]<<" | ";
                    else os<<"<f"<<i<<">"<<A[i]<<"\"";
                }
                os<<" , color=blue, fillcolor=lightblue, style=filled];"<<endl;
                os<<"{ rank=same; values }"<<endl;
                os<<"}";
        }
        void printT(ostream &os)
        {
            os<<"digraph {"<<endl;
                os<<"{"<<endl;
                os<<"node [margin=0 fontsize=15 width=0.5 shape=circle style=filled]"<<endl;
                for (size_t i = 0; i < A.size(); i++) {
                     os<<"f"<<i<<" [fillcolor=gray label=\""<<A[i]<<"\"]"<<endl;
                }
                os<<"}"<<endl;


            for (size_t i = 0; i < floor(A.size()/2 ); i++) {
                if((2*i+1) < A.size())
                    os<<"f"<<i<<" -> "<<"f"<<2*i +1<<endl;
                if((2*i+2) < A.size())
                    os<<"f"<<i<<" -> "<<"f"<<2*i +2<<endl;

            }
                os<<"}";
        }
};
#endif // BINARYHEAP_H
