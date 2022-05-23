#include "pessoa.h"
#include <list>
#include <fstream>

#define TAM 5

class Classe_hash
{
private:
    list<pessoa> plist[TAM];

public:
    Classe_hash();
    ~Classe_hash();
    void insere(pessoa p);
    void remove(int cod);
    void consulta(int cod);
    void consultanome(string nome);
    void imprimirhash();
    int calc_hash(int cod);
};

Classe_hash::Classe_hash() {}

Classe_hash::~Classe_hash()
{
    for (int i = 0; i < TAM; i++)
    {
        plist[i].clear();
    }
}

void Classe_hash::insere(pessoa p)
{
    int num = calc_hash(p.getcodigo());
    plist[num].push_back(p);
}

void Classe_hash::remove(int cod)
{
    int num = calc_hash(cod);
    list<pessoa> *h = &plist[num];
    list<pessoa>::iterator it;

    for (it = h->begin(); it != h->end(); it++)
    {
        if (it->getcodigo() == cod)
        {
            h->erase(it);
            break;
        }
    }
}

void Classe_hash::consulta(int cod)
{
    int num = calc_hash(cod);
    list<pessoa> h = plist[num];
    list<pessoa>::iterator it;

    for (it = h.begin(); it != h.end(); it++)
    {
        if (it->getcodigo() == cod)
        {
            it->imprimir();
            break;
        }
    }
}

void Classe_hash::consultanome(string nome)
{

    list<pessoa> h;
    list<pessoa>::iterator it;

    for (int classe = 0; classe < TAM; classe++)
    {
        h = plist[classe];
        for (it = h.begin(); it != h.end(); it++)
        {
            if (it->getnome() == nome)
            {
                it->imprimir();
                break;
            }
        }
    }
}

int Classe_hash::calc_hash(int cod)
{
    return cod % 5;
}

void Classe_hash::imprimirhash()
{
    list<pessoa> h;
    list<pessoa>::iterator it;
    for (int classe = 0; classe < TAM; classe++)
    {
        h = plist[classe];
        for (it = h.begin(); it != h.end(); it++)
        {
            it->imprimir();
        }
    }
}
