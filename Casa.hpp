#ifndef CASA_H
#define CASA_H
#include <math.h>
#include <GL/glut.h>
#include <cstdlib>
#include <vector>
#include "Circulo.hpp"
#include "Retangulo.hpp"
#include "Ponto.hpp"

using namespace std;

class Casa
{
    private:
        float posicaoSol;
        float corCeu;
        vector<int*> *posicaoEstrelas;
        void chamine();
        void telhado();
        void baseCasa();
        void porta();
        void janela();
        void sol();
        void gramado();
        void ceu();
        void estrelas(int numeroDeEstrelas);

    public:
        void desenhar();
        void escurece();
        Casa();
};
#endif