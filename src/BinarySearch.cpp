#include "../include/BinarySearch.h"
#include <cstdio>

Vektor::Vektor(int dim)
{
    dimension = dim;
    daten = new int[dim];
}

Vektor::~Vektor()
{
    delete daten;
}

void Vektor::set(int i, int val)
{
    daten[i] = val;
}

int Vektor::get(int i)
{
    return daten[i];
}

int Vektor::bin_suche(int sw)
{
    int l_u = 0;
    int l_o = dimension - 1;

    while(l_u <= l_o)
    {
        //step 1: pick a pivot
        int pivot = l_u + ((l_o - l_u) / 2);

        //step 2: check if pivot is correct value and return it
        if(daten[pivot] == sw)
            return pivot;

        //step 3: check if sw is larger or smaller
        //step 4: resize upper/lower bound accordingly
        //note: pivot itself can be ignored since its already checked above, hence the +/-1
        if(sw < daten[pivot])
        {
            l_o = pivot - 1;
        }
        else
        {
            l_u = pivot + 1;
        }
    }
    //if not found, return -1 as error value
    return -1;
}

void Vektor::quick_sort(int l_u, int l_o)
{
    if(l_u < l_o)
    {
        int pivot = partition(l_u, l_o);
        quick_sort(l_u, pivot -1);
        quick_sort(pivot + 1, l_o);
    }
}

void Vektor::swap(int i1, int i2)
{
    int temp = daten[i1];
    daten[i1] = daten[i2];
    daten[i2] = temp;
}

int Vektor::partition(int l_u, int l_o)
{
    int pivot = daten[l_o];

    int x = l_u - 1;

    for(int i = l_u; i <= l_o - 1; i++)
    {
        if(daten[i] < pivot)
        {
            x++;
            swap(x, i);
        }
    }
    swap(x + 1, l_o);
    return x + 1;
}

void Vektor::print()
{
    std::cout << "Generated sorted array with randomly generated values {";
    for(int i = 0; i < size(); i++)
    {
        std::cout << "[" << i << "]" << get(i) << ", ";
    }
    std::cout << "\b \b" << "\b \b" << "}" << std::endl;
}