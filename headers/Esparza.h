#ifndef ESPARZA_H
#define ESPARZA_H

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

template <class T>
class NodoE
{
public:
   int m_row;
   int m_col;
   NodoE<T> *m_pNext_row;
   NodoE<T> *m_pNext_col;
   T m_Data;
public:
   NodoE(T d, int row, int col)
   {
        m_Data = d;
        m_row = row;
        m_col = col;
        m_pNext_row = m_pNext_col = 0;
   }
};

template <class T, int row_size = 5, int col_size = 5>
class Matrix
{
private:
   NodoE<T> *m_Row[row_size];
   NodoE<T> *m_Col[col_size];
public:
   Matrix()
   {
        for (int i = 0; i < row_size; i++)
            m_Row[i] = 0;

        for (int i = 0; i < col_size; i++)
            m_Col[i] = 0;
   };

   // time is O👎
   void Insert(T d, int row, int col)
   {
        NodoE<T> **p, **q;
        bool r = find_row(row, col, p); //O👎
        bool c = find_col(row, col, q); //O👎
        if(!r && !c)
        {
            NodoE<T> * pNew = new NodoE<T>(d,row, col);
            pNew->m_pNext_row =  *p ;
            (*p) = pNew;
            pNew->m_pNext_col =  *q ;
            (*q) = pNew;
        }
        (*p)->m_Data = d;

   }

   bool find_row(int row, int col, NodoE<T> **&p) // find the row
   {
        p = &m_Col[col]; // O(1)
        while (*p) //O👎
        {
            if ((*p)->m_row == row ) return true;
            if ((*p)->m_row < row )  return false;
            p= &((*p)->m_pNext_row);

        }
        return false;
   }

   bool find_col(int row, int col, NodoE<T> **&p) // find te col
   {
        p = &m_Row[row]; //O(1)
        while (*p)   //O👎
        {

            if ((*p)->m_col == col ) return true;
            if ((*p)->m_col < col )  return false;
            p= &((*p)->m_pNext_col);

        }
        return false;
   }
/*
   void Print(ostream & os )
   {
        for(int i=0;i<row_size;i++)
        {
            for(int j=0;j<col_size;j++)
            {
                NodoE<T> ** p;
                if(find_row(i,j,p))
                    os<<" "<<(*p)->m_Data<<" ";
                else
                    os<<" / ";
            }
        os<<endl;
        }
   }
   */
   void Print(ostream & os)
   {
       os<<"digraph Sparce_Matrix {"<<endl;
        os<<"node [shape=box]"<<endl;
        os<<"Mt[label = \"Matriz\", width = 1.0  style = filled, fillcolor = firebrick1, group = 1 ];"<<endl;
        os<<"e0[ shape = point, width = 0 ];"<<endl;
        os<<"e1[ shape = point, width = 0 ];"<<endl;

        for(int i = 0; i < row_size ; i++)
            os<<"F"<<i<<" [label = \""<<i<<"\" width = 1.0 style = filled, fillcolor = bisque1, group = 1];"<<endl;

        for(int i = 0; i < row_size - 1 ; i++)
            os<<"F"<<i<<" -> "<<"F"<<i+1<<";"<<endl;

        for(int i = 0; i < col_size ; i++)
            os<<"C"<<i<<" [label = \""<<i<<"\" width = 1.0 style = filled, fillcolor = lightskyblue, group = "<<i+2<<"];"<<endl;

        for(int i = 0; i < col_size - 1 ; i++)
            os<<"C"<<i<<" -> "<<"C"<<i+1<<";"<<endl;

        os<<"Mt -> F0;"<<endl;
        os<<"Mt -> C0;"<<endl;

        os<<"{ rank = same; Mt; ";
        for(int i = 0; i < col_size; i++)
            os<<"C"<<i<<"; ";
        os<<"}"<<endl;


        for(int i=0;i<row_size;i++)
        {
            for(int j=0;j<col_size;j++)
            {
                NodoE<T> ** p;
                if(find_row(i,j,p))
                {
                    os<<"F"<<(*p)->m_row<<"_C"<<(*p)->m_col<<" [label=\""<<(*p)->m_Data<<"\" width = 1.0, group = "<<j+2<<" ];"<<endl;
                }
            }
        }

        for(int i=0;i<col_size;i++)
        {
            if(m_Col[i])
            {
                NodoE <T> *p = m_Col[i];
                while(p->m_pNext_row)
                {
                    os<<"F"<<p->m_pNext_row->m_row<<"_C"<<p->m_pNext_row->m_col<<" -> "<<"F"<<p->m_row<<"_C"<<p->m_col<<";"<<endl;
                    p = p->m_pNext_row;
                }
                os<<"C"<<i<<" -> "<<"F"<<p->m_row<<"_C"<<p->m_col<<";"<<endl;
            }
        }

        for(int i=0;i<row_size;i++)
        {
            if(m_Row[i])
            {
                NodoE <T> *p = m_Row[i];
                while(p->m_pNext_col)
                {
                    os<<"F"<<p->m_pNext_col->m_row<<"_C"<<p->m_pNext_col->m_col<<" -> "<<"F"<<p->m_row<<"_C"<<p->m_col<<";"<<endl;
                    p = p->m_pNext_col;
                }
                os<<"F"<<i<<" -> "<<"F"<<p->m_row<<"_C"<<p->m_col<<";"<<endl;
            }
        }

        for(int i=0;i<row_size;i++)
        {
            if(m_Row[i])
            {
                os<<"{rank = same; ";
                os<<"F"<<i<<"; ";
                NodoE <T> *p = m_Row[i];
                while(p)
                {
                    os<<"F"<<i<<"_C"<<p->m_col<<"; ";
                    p = p->m_pNext_col;
                }
                os<<"}";
            }
        }

       os<<"}";
   }

   void Print(ostream & os, NodoE <T> * resul)
   {
       os<<"digraph Sparce_Matrix {"<<endl;
        os<<"node [shape=box]"<<endl;
        os<<"Mt[label = \"Matriz\", width = 1.0  style = filled, fillcolor = firebrick1, group = 1 ];"<<endl;
        os<<"e0[ shape = point, width = 0 ];"<<endl;
        os<<"e1[ shape = point, width = 0 ];"<<endl;

        for(int i = 0; i < row_size ; i++)
            os<<"F"<<i<<" [label = \""<<i<<"\" width = 1.0 style = filled, fillcolor = bisque1, group = 1];"<<endl;

        for(int i = 0; i < row_size - 1 ; i++)
            os<<"F"<<i<<" -> "<<"F"<<i+1<<";"<<endl;

        for(int i = 0; i < col_size ; i++)
            os<<"C"<<i<<" [label = \""<<i<<"\" width = 1.0 style = filled, fillcolor = lightskyblue, group = "<<i+2<<"];"<<endl;

        for(int i = 0; i < col_size - 1 ; i++)
            os<<"C"<<i<<" -> "<<"C"<<i+1<<";"<<endl;

        os<<"Mt -> F0;"<<endl;
        os<<"Mt -> C0;"<<endl;

        os<<"{ rank = same; Mt; ";
        for(int i = 0; i < col_size; i++)
            os<<"C"<<i<<"; ";
        os<<"}"<<endl;


        for(int i=0;i<row_size;i++)
        {
            for(int j=0;j<col_size;j++)
            {
                NodoE<T> ** p;
                if(find_row(i,j,p))
                {
                    string fillcolor = "white";
                    if(*p == resul) fillcolor = "green";
                    os<<"F"<<(*p)->m_row<<"_C"<<(*p)->m_col<<" [label=\""<<(*p)->m_Data<<"\" width = 1.0, style = filled, fillcolor = "<<fillcolor<<", group = "<<j+2<<" ];"<<endl;
                }
            }
        }

        for(int i=0;i<col_size;i++)
        {
            if(m_Col[i])
            {
                NodoE <T> *p = m_Col[i];
                while(p->m_pNext_row)
                {
                    os<<"F"<<p->m_pNext_row->m_row<<"_C"<<p->m_pNext_row->m_col<<" -> "<<"F"<<p->m_row<<"_C"<<p->m_col<<";"<<endl;
                    p = p->m_pNext_row;
                }
                os<<"C"<<i<<" -> "<<"F"<<p->m_row<<"_C"<<p->m_col<<";"<<endl;
            }
        }

        for(int i=0;i<row_size;i++)
        {
            if(m_Row[i])
            {
                NodoE <T> *p = m_Row[i];
                while(p->m_pNext_col)
                {
                    os<<"F"<<p->m_pNext_col->m_row<<"_C"<<p->m_pNext_col->m_col<<" -> "<<"F"<<p->m_row<<"_C"<<p->m_col<<";"<<endl;
                    p = p->m_pNext_col;
                }
                os<<"F"<<i<<" -> "<<"F"<<p->m_row<<"_C"<<p->m_col<<";"<<endl;
            }
        }

        for(int i=0;i<row_size;i++)
        {
            if(m_Row[i])
            {
                os<<"{rank = same; ";
                os<<"F"<<i<<"; ";
                NodoE <T> *p = m_Row[i];
                while(p)
                {
                    os<<"F"<<i<<"_C"<<p->m_col<<"; ";
                    p = p->m_pNext_col;
                }
                os<<"}";
            }
        }

       os<<"}";
   }

    void Rows_Enchange(int row_1, int row_2){
        NodoE <T> ** p = &m_Row[row_1];
        m_Row[row_1] = m_Row[row_2];
        m_Row[row_2] = *p;
    }
    void Cols_Enchange(int col_1, int col_2){

        NodoE <T> * p = m_Col[col_1];
        m_Col[col_1] = m_Col[col_2];
        m_Col[col_2] = p;

    }

    NodoE <T> * Max_Row(int row)
        {
            if(m_Row[row])
            {
                NodoE <T> * max = m_Row[row];
                NodoE <T> * pTmp = m_Row[row];
                while(pTmp)
                {
                    if(pTmp->m_Data > max->m_Data) max = pTmp;
                    pTmp = pTmp->m_pNext_col;
                }
                return max;
            }
            else return 0;
        }

        NodoE <T> * Min_Row(int row)
        {
            if(m_Row[row])
            {
                NodoE <T> * min = m_Row[row];
                NodoE <T> * pTmp = m_Row[row];
                while(pTmp)
                {
                    if(pTmp->m_Data < min->m_Data) min = pTmp;
                    pTmp = pTmp->m_pNext_col;
                }
                return min;
            }
            else return 0;
        }

        NodoE <T> * Max_Col(int col)
        {
            if(m_Col[col])
            {
                NodoE <T> * max = m_Col[col];
                NodoE <T> * pTmp = m_Col[col];
                while(pTmp)
                {
                    if(pTmp->m_Data > max->m_Data) max = pTmp;
                    pTmp = pTmp->m_pNext_row;
                }
                return max;
            }
            else return 0;
        }
        NodoE <T> * Min_Col(int col)
        {
            if(m_Col[col])
            {
                NodoE <T> * pTmp = m_Col[col];
                NodoE <T> * min = m_Col[col];
                while(pTmp)
                {
                    if(pTmp->m_Data < min->m_Data) min = pTmp;
                    pTmp = pTmp->m_pNext_row;
                }
                return min;
            }
            else return 0;
        }
        NodoE <T> * Max(){
                stack <NodoE <T> *> max;
                for(int i=0;i<row_size;i++)
                {
                    for(int j=0;j<col_size;j++)
                    {
                        NodoE<T> ** p;
                        if(find_col(i,j,p)){
                            if(!max.empty()){
                                if(max.top()->m_Data < (*p)->m_Data ){
                                    max.pop();
                                    max.push((*p));
                                }
                            } else {
                                max.push((*p));
                            }
                        }
                    }
                }
                if(!max.empty()) return max.top();
                return 0;
            }

            NodoE <T> * Min(){
                stack <NodoE <T> *> min;
                for(int i=0;i<row_size;i++)
                {
                    for(int j=0;j<col_size;j++)
                    {
                        NodoE<T> ** p;
                        if(find_col(i,j,p)){
                            if(!min.empty()){
                                if(min.top()->m_Data > (*p)->m_Data ){
                                    min.pop();
                                    min.push((*p));
                                }
                            } else {
                                min.push((*p));
                            }
                        }
                    }
                }
                if(!min.empty()) return min.top();
                return 0;
            }

    void Delete_Row(int row){
        for(int i=0;i<row_size;i++){
            Delete_Cell(row,i);
        }
    }
    void Delete_Col(int col){
        for(int i=0;i<col_size;i++){
            Delete_Cell(i,col);
        }
    }

    void Delete_Cell(int row,int col)
    {
        NodoE <T> ** q , **p;
        if(!find_row(row,col,q)) return;
        if(!find_col(row,col,p)) return;

        NodoE <T> * d = *q;

        (*q) = (*q)->m_pNext_row;
        (*p) = (*p)->m_pNext_col;

        delete d;
    }

    T Sum_Row(int row)
    {
        T suma = 0;
        NodoE <T> **p = &m_Row[row];
        for (int i=0;i<row_size;i++){
            NodoE <T> **p = &m_Row[row];
            if(find_row(row,i,p)){
                suma += (*p)->m_Data;
            }
        }
        return suma;
    }

    T Sum_Col(int col)
    {
        T suma = 0;
        NodoE <T> **p = &m_Col[col];
        for (int i=0;i<row_size;i++){
            NodoE <T> **p = &m_Col[col];
            if(find_row(i,col,p)){
                suma += (*p)->m_Data;
            }
        }
        return suma;
    }

    T Sum_Row(int row, int begin_col, int end_col)
    {
        T suma = 0;
        NodoE <T> **p = &m_Row[row];
        for(int i = begin_col; i <= end_col;i++)
        {
            if(find_col(row,i,p)) suma += (*p)->m_Data;
        }
        return suma;
    }

    T Sum_Col(int col, int begin_row, int end_row)
    {
        T suma = 0;
        NodoE <T> **p = &m_Col[col];
        for(int i = begin_row; i <= end_row ;i++)
        {
            if(find_row(i,col,p)) suma += (*p)->m_Data;
        }
        return suma;
    }

    void Transpose()
    {
        vector < pair <T,T> > pares;

        for(int i=0;i<row_size;i++)
        {
            for(int j=0;j<col_size;j++)
            {
                if(i != j){
                    NodoE <T> **p;
                    if(find_col(i,j,p)){
                        NodoE <T> **w;
                        if(find_col(j,i,w)){
                            if(i < j){
                                T temp = (*p)->m_Data;
                                (*p)->m_Data = (*w)->m_Data;
                                (*w)->m_Data = temp;
                            }
                        }
                        else{
                            if(!(find(pares.begin(), pares.end(), make_pair(i,j)) != pares.end()) ){
                                Insert((*p)->m_Data,(*p)->m_col,(*p)->m_row);
                                Delete_Cell(i,j);
                                pares.push_back(make_pair(j,i));
                            }
                        }
                    }
                }
            }
        }
    }


    void Sort_Row(int row)
    {
        NodoE <T> **p;
        for (int i=0;i<row_size;i++){
            if(find_row(row,i,p)){
                for(int j=0;j<row_size;j++){
                    NodoE <T> **q;
                    if(find_row(row,j,q)){
                        if((*p)->m_Data < (*q)->m_Data){
                            T aux = (*p)->m_Data;
                            (*p)->m_Data = (*q)->m_Data;
                            (*q)->m_Data = aux;
                        }
                    }
                }
            }
        }
    }

    void Sort_Col(int col)
    {
        NodoE <T> **p;
        for (int i=0;i<col_size;i++){
            if(find_col(i,col,p)){
                for(int j=0;j<col_size;j++){
                    NodoE <T> **q;
                    if(find_col(j,col,q)){
                        if((*p)->m_Data < (*q)->m_Data){
                            T aux = (*p)->m_Data;
                            (*p)->m_Data = (*q)->m_Data;
                            (*q)->m_Data = aux;
                        }
                    }
                }
            }
        }
    }

};

#endif // ESPARZA_H
