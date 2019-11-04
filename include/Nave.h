#include <GL/glut.h>


class Nave
{
    public:
        float x = 0;
        float y = -48; // pra aparecer na parte de baixo da tela
        void desenha(float x,float y,float z);
    Nave(float a, float b){
        this->x = a;
        this->y = b;
    }
};



void Nave::desenha(float a,float b,float c){
    glBegin(GL_POLYGON);
            glColor3f(a, b, c);
            glVertex2f(this->x+1.5, this->y);
            glVertex2f(this->x+1.5, this->y+2.5);
            glVertex2f(this->x-1.5, this->y+2.5);
            glVertex2f(this->x-1.5, this->y);

    glEnd();
}


class Obstaculo
{
    public:
        int x = 0;
        int y = 0;
        int limiteMaior[4][2];
        int limiteMenor[4][2];
        int limiteQuadrado[4][2];
        void desenhaEmPe();
        void desenhaDeitado();
        void desenhaFrente();
        void desenhaDeitadoEspelhado();
        void desenhaquadrado();
        void calculaQuadradoMaior();
        void calculaQuadradoMenor();
        Obstaculo(int x, int y){
            this->x = x;
            this->y = y;
        }
};






void Obstaculo::desenhaquadrado(){

    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.2, 1.0);
        glVertex2d(this->x+10, this->y);
        glVertex2d(this->x+10, this->y+20);
        glVertex2d(this->x-10, this->y+20);
        glVertex2d(this->x-10, this->y);
    glEnd();

}


void Obstaculo::desenhaDeitadoEspelhado(){

    glBegin(GL_POLYGON);
        glColor3f(0.8, 0.5, 0.8);
        glVertex2d(this->x+20, this->y);
        glVertex2d(this->x+20, this->y+10);
        glVertex2d(this->x-20, this->y+10);
        glVertex2d(this->x-20, this->y);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.8, 0.5, 0.8);
        glVertex2d(this->x+10, this->y);
        glVertex2d(this->x+10, this->y-8);
        glVertex2d(this->x-10, this->y-8);
        glVertex2d(this->x-10, this->y);
    glEnd();
}



void Obstaculo::desenhaFrente(){
    glBegin(GL_POLYGON);
        glColor3f(0.4, 0.3, 0.2);
        glVertex2d(this->x, this->y-20);
        glVertex2d(this->x+10, this->y-20);
        glVertex2d(this->x+10, this->y+20);
        glVertex2d(this->x, this->y+20);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.4, 0.3, 0.2);
        glVertex2d(this->x, this->y-8);
        glVertex2d(this->x-10, this->y-8);
        glVertex2d(this->x-10, this->y+8);
        glVertex2d(this->x, this->y+8);
    glEnd();
}
void Obstaculo::desenhaDeitado(){

    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 1.0);
        glVertex2d(this->x-20, this->y-10);
        glVertex2d(this->x+20, this->y-10);
        glVertex2d(this->x+20, this->y);
        glVertex2d(this->x-20, this->y);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 1.0);
        glVertex2d(this->x+10, this->y);
        glVertex2d(this->x+10, this->y+8);
        glVertex2d(this->x-10, this->y+8);
        glVertex2d(this->x-10, this->y);
    glEnd();
}


void Obstaculo::desenhaEmPe(){
    glBegin(GL_POLYGON);
        glColor3f(0.4, 0.7, 1.0);
        glVertex2d(this->x-10, this->y+20);
        glVertex2d(this->x-10, this->y-20);
        glVertex2d(this->x, this->y-20);
        glVertex2d(this->x, this->y+20);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.4, 0.7, 1.0);
        glVertex2d(this->x, this->y-8);
        glVertex2d(this->x+10, this->y-8);
        glVertex2d(this->x+10, this->y+8);
        glVertex2d(this->x, this->y+8);
    glEnd();

}
