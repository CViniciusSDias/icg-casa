#include "Casa.hpp"

Casa::Casa()
{
    posicaoSol = 0.0f;
    corCeu = 1;
    posicaoEstrelas = new vector<int*>;
}

void Casa::desenhar()
{
    glLineWidth(3);
    gramado();
    ceu();
    baseCasa();
    chamine();
    telhado();
    porta();
    janela();
    sol();
};

void Casa::chamine()
{
    /* Chaminé */
    glColor3f(0.4, 0.2, 0.2);
    IForma* r = new Retangulo(-3, 5, 1, 3);
    r->desenhar();
    delete r;

    /* Contorno da Chaminé */
    glColor3f(0.3, 0.1, 0.1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-3, 5);
    glVertex2f(-2, 5);
    glVertex2f(-2, 2);
    glVertex2f(-3, 2);
    glEnd();
};

void Casa::telhado()
{
    /* Telhado */
    glColor3f(0.8, 0.4, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-5, 2);
    glVertex2f(0, 5);
    glVertex2f(5, 2);
    glEnd();

    glColor3f(0.7, 0.3, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-5, 2);
    glVertex2f(0, 5);
    glVertex2f(5, 2);
    glEnd();
};

void Casa::baseCasa()
{
    /* Casa */
    glColor3f(1, 0.8, 0.4);
    IForma* r = new Retangulo(-4, 2, 8, 4);
    r->desenhar();
    delete r;

    glColor3f(.9, 0.7, 0.3);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-4, 2);
    glVertex2f(4, 2);
    glVertex2f(4, -2);
    glVertex2f(-4, -2);
    glEnd();
};

void Casa::porta()
{
    /* Porta */
    glColor3f(1, .7, 0);
    IForma* r = new Retangulo(-1, 0, 1, 2);
    r->desenhar();
    delete r;

    glColor3f(.9, .6, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-1, 0);
    glVertex2f(0, 0);
    glVertex2f(0, -2);
    glVertex2f(-1, -2);
    glEnd();
};

void Casa::janela()
{
    /* Janela */
    glColor4f(.5, 1, 1, 0.5);
    IForma* r = new Retangulo(2, 1, 1, 1);
    r->desenhar();
    delete r;

    glColor3f(.4, .9, .9);
    glBegin(GL_LINE_LOOP);
    glVertex2f(2, 1);
    glVertex2f(3, 1);
    glVertex2f(3, 0);
    glVertex2f(2, 0);
    glEnd();
};

void Casa::sol()
{
    float rad, x, y, raio = 1;

    glColor3f(1, 1, 0);
    float xSol = -7 + posicaoSol;
    IForma* c = new Circulo(xSol, 7, raio);
    c->desenhar();
    delete c;

    glColor3f(0.9, 0.9, 0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        rad = (i * M_PI) / 180.0f;
        x = cos(rad) * raio + xSol;
        y = sin(rad) * raio + 7;
        glVertex2f(x, y);
    }
    glEnd();
};

void Casa::gramado()
{
    glColor3f(0, 1, 0);
    IForma* r = new Retangulo(-20, 0, 40, 20);
    r->desenhar();
    delete r;
};

void Casa::ceu()
{
    glColor3f(0, corCeu, corCeu);
    IForma* r = new Retangulo(-20, 20, 40, 20);
    r->desenhar();
    delete r;

    if (corCeu < 0.8) {
        estrelas(10 / corCeu);
    }
};

void Casa::estrelas(int numeroDeEstrelas)
{
    if (numeroDeEstrelas > posicaoEstrelas->size()) {
        // Cada vez o número de estrelas adicionadas é maior
        numeroDeEstrelas += posicaoEstrelas->size();
        int x = rand() % 20 + (-10);
        int y = rand() % 10;
        int* xY = new int[2];
        xY[0] = x;
        xY[1] = y;
        posicaoEstrelas->push_back(xY);
    }

    for (int i = 0; i < posicaoEstrelas->size(); i++) {
        int* posicao = posicaoEstrelas->at(i);
        glColor3f(1, 1, 1);
        Ponto* ponto = new Ponto(posicao[0], posicao[1], 2);
        ponto->desenhar();
        delete ponto;
    }
};

void Casa::escurece()
{
    bool escurecendo = posicaoSol < 13;
    // Escurece o ceu
    corCeu = escurecendo ? corCeu - 0.0004f : 1;
    // Move o sol
    posicaoSol = escurecendo ? posicaoSol + 0.01f : 0.0f;
};