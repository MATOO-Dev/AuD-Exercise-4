#include <iostream>

class Vektor
{
private:
    int dimension;
    int* daten;
public:
    Vektor(int dim);
    virtual ~Vektor();
    void set(int i, int val);
    int get(int i);
    int bin_suche(int sw);
    void quick_sort(int l_u, int l_o);
    void swap(int i1, int i2);
    int partition(int l_u, int l_o);
    int size() {return dimension;}
    void print();
};