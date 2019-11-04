#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "include/Nave.h"
#include <time.h>
#include <conio.h>
#define WIDTH 500
#define HEIGHT 500
#define TAM 1000


float pontoAtual[3][2] = {{0,-30}, {-10,-40}, {10,40}};
float vetorCena[20][20];
int auxiliar = 0;

Nave *navee = new Nave(0.0, -50.0);
Nave *objetivo = new Nave(-48,47);

//Nave *objetivo;
Obstaculo *deitado = new Obstaculo(-25,-35);
Obstaculo *emPe = new Obstaculo(-35,25);
Obstaculo *deitado2 = new Obstaculo(25,-35);
Obstaculo *deitado3 = new Obstaculo(0,12);
Obstaculo *frente = new Obstaculo(35,25);
Obstaculo *deitadoEspelhado = new Obstaculo(0,35);
Obstaculo *deitadoEspelhado2 = new Obstaculo(0,-15);
Obstaculo *quadrado = new Obstaculo(-35, -20);
Obstaculo *quadrado2 = new Obstaculo(35, -20);



void init(){
    glClearColor(0.0,0.0,0.0, 1.0);//cor de fundo
    glEnable(GL_DEPTH_TEST);
}


void reshape(int w, int h){//w = largura, h = altura //sempre que o desenho for modificado a glut chama esse metodo
    glViewport(0,0,(GLsizei)w, (GLsizei)h); // definir a porção da janela que vai usar
    glMatrixMode(GL_PROJECTION);//confi da camera
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);//projeção da tela
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int colisaoOsbstaculo(){

    if(((objetivo->x + 1.5) >= -45 && (objetivo->x + 1.5) <= -25) || ((objetivo->x - 1.5) >= -45 && (objetivo->x - 1.5) <= -25)){
        if(((objetivo->y + 2.5) >= -20 && (objetivo->y + 2.5) <= 0) || ((objetivo->y) >= -20 && (objetivo->y) <= 0)){
                return 1;
        }
    }

    if(((objetivo->x + 1.5) >= 25 && (objetivo->x + 1.5) <= 45) || ((objetivo->x - 1.5) >= 25 && (objetivo->x - 1.5) <= 45)){
        if((((objetivo->y + 2.5) >= -20 && (objetivo->y + 2.5) <= 0)) || ((objetivo->y) >= -20 && (objetivo->y) <= 0)){
                return 1;
        }
    }

   if(((objetivo->x + 1.5) >= -45 && (objetivo->x + 1.5) <= -5) || ((objetivo->x - 1.5) >= -45 && (objetivo->x - 1.5) <= -5)){
        if((((objetivo->y + 2.5) >= -45 && (objetivo->y + 2.5) <= -35)) || ((objetivo->y) >= -45 && (objetivo->y) <= -35)){
                return 1;
        }
    }

    if(((objetivo->x + 1.5) >= -35 && (objetivo->x + 1.5) <= -15) || ((objetivo->x - 1.5) >= -35 && (objetivo->x - 1.5) <= -15)){
        if((((objetivo->y + 2.5) >= -35 && (objetivo->y + 2.5) <= -27)) || ((objetivo->y) >= -35 && (objetivo->y) <= -27)){
               return 1;
        }
    }

    if(((objetivo->x + 1.5) >= 5 && (objetivo->x + 1.5) <= 45) || ((objetivo->x - 1.5) >= 5 && (objetivo->x - 1.5) <= 45)){
        if((((objetivo->y + 2.5) >= -45 && (objetivo->y + 2.5) <= -35)) || ((objetivo->y) >= -45 && (objetivo->y) <= -35)){
                return 1;
        }
    }

    if(((objetivo->x + 1.5) >= 15 && (objetivo->x + 1.5) <= 35) || ((objetivo->x - 1.5) >= 15 && (objetivo->x - 1.5) <= 35)){
        if((((objetivo->y + 2.5) >= -35 && (objetivo->y + 2.5) <= -27)) || ((objetivo->y) >= -35 && (objetivo->y) <= -27)){
               return 1;
        }
    }

    if(((objetivo->x + 1.5) >= -20 && (objetivo->x + 1.5) <= 20) || ((objetivo->x - 1.5) >= -20 && (objetivo->x - 1.5) <= 20)){
        if((((objetivo->y + 2.5) >= -15 && (objetivo->y + 2.5) <= -5)) || ((objetivo->y) >= -15 && (objetivo->y) <= -5)){
               return 1;
        }
    }

    if(((objetivo->x + 1.5) >= -10 && (objetivo->x + 1.5) <= 10) || ((objetivo->x - 1.5) >= -10 && (objetivo->x - 1.5) <= 10)){
        if((((objetivo->y + 2.5) >= -23 && (objetivo->y + 2.5) <= -15)) || ((objetivo->y) >= -23 && (objetivo->y) <= -15)){
                return 1;
        }
    }

    if(((objetivo->x + 1.5) >= -45 && (objetivo->x + 1.5) <= -35) || ((objetivo->x - 1.5) >= -45 && (objetivo->x - 1.5) <= -35)){
        if((((objetivo->y + 2.5) >= 5 && (objetivo->y + 2.5) <= 45)) || ((objetivo->y) >= 5 && (objetivo->y) <= 45)){
               return 1;
        }
    }

    if(((objetivo->x + 1.5) >= -35 && (objetivo->x + 1.5) <= -25) || ((objetivo->x - 1.5) >= -35 && (objetivo->x - 1.5) <= -25)){
        if((((objetivo->y + 2.5) >= 17 && (objetivo->y + 2.5) <= 33)) || ((objetivo->y) >= 17 && (objetivo->y) <= 33)){
                return 1;
        }
    }

        if(((objetivo->x + 1.5) >= -20 && (objetivo->x + 1.5) <= 20) || ((objetivo->x - 1.5) >= -20 && (objetivo->x - 1.5) <= 20)){
                if((((objetivo->y + 2.5) >= 2 && (objetivo->y + 2.5) <= 12)) || ((objetivo->y) >= 2 && (objetivo->y) <= 12)){
                       return 1;
                }
            }

        if(((objetivo->x + 1.5) >= -10 && (objetivo->x + 1.5) <= 10) || ((objetivo->x - 1.5) >= -10 && (objetivo->x - 1.5) <= 10)){
             if((((objetivo->y + 2.5) >= 12 && (objetivo->y + 2.5) <= 20)) || ((objetivo->y) >= 12 && (objetivo->y) <= 20)){
                      return 1;
             }
        }

        if(((objetivo->x + 1.5) >= 35 && (objetivo->x + 1.5) <= 45) || ((objetivo->x - 1.5) >= 35 && (objetivo->x - 1.5) <= 45)){
                if((((objetivo->y + 2.5) >= 5 && (objetivo->y + 2.5) <= 45)) || ((objetivo->y) >= 5 && (objetivo->y) <= 45)){
                       return 1;
                }
            }

        if(((objetivo->x + 1.5) >= 25 && (objetivo->x + 1.5) <= 35) || ((objetivo->x - 1.5) >= 25 && (objetivo->x - 1.5) <= 35)){
             if((((objetivo->y + 2.5) >= 17 && (objetivo->y + 2.5) <= 33)) || ((objetivo->y) >= 17 && (objetivo->y) <= 33)){
                      return 1;

             }
        }

    if(((objetivo->x + 1.5) >= -20 && (objetivo->x + 1.5) <= 20) || ((objetivo->x - 1.5) >= -20 && (objetivo->x - 1.5) <= 20)){
        if((((objetivo->y + 2.5) >= 35 && (objetivo->y + 2.5) <= 45)) || ((objetivo->y) >= 35 && (objetivo->y) <= 45)){
                return 1;
        }
    }

    if(((objetivo->x + 1.5) >= -10 && (objetivo->x + 1.5) <= 10) || ((objetivo->x - 1.5) >= -10 && (objetivo->x - 1.5) <= 10)){
        if((((objetivo->y + 2.5) >= 27 && (objetivo->y + 2.5) <= 35)) || ((objetivo->y) >= 27 && (objetivo->y) <= 35)){
                return 1;;

        }
    }

    return 0;

}

void geraNave(){

    srand(time(NULL));
    float x = rand() %-48 %48;
    //printf("%f", x);
    float y = rand() %-48 %48;
    //printf("%f",y);
    objetivo->x = x;
    objetivo->y = y;
    while(colisaoOsbstaculo()){
        x = rand() %-48 %48;
        y = rand() %-48 %48;
        objetivo->x = x;
        objetivo->y = y;
    }

    objetivo->desenha(1.0,1.0,1.0);
}


void colisao(){

    if(((navee->x + 1.5) >= -45 && (navee->x + 1.5) <= -25) || ((navee->x - 1.5) >= -45 && (navee->x - 1.5) <= -25)){
        if(((navee->y + 2.5) >= -20 && (navee->y + 2.5) <= 0) || ((navee->y) >= -20 && (navee->y) <= 0)){
                navee->x = 0;
                navee->y = -50;

        }
    }

    if(((navee->x + 1.5) >= 25 && (navee->x + 1.5) <= 45) || ((navee->x - 1.5) >= 25 && (navee->x - 1.5) <= 45)){
        if((((navee->y + 2.5) >= -20 && (navee->y + 2.5) <= 0)) || ((navee->y) >= -20 && (navee->y) <= 0)){
                navee->x = 0;
                navee->y = -50;

        }
    }

   if(((navee->x + 1.5) >= -45 && (navee->x + 1.5) <= -5) || ((navee->x - 1.5) >= -45 && (navee->x - 1.5) <= -5)){
        if((((navee->y + 2.5) >= -45 && (navee->y + 2.5) <= -35)) || ((navee->y) >= -45 && (navee->y) <= -35)){
                navee->x = 0;
                navee->y = -50;

        }
    }

    if(((navee->x + 1.5) >= -35 && (navee->x + 1.5) <= -15) || ((navee->x - 1.5) >= -35 && (navee->x - 1.5) <= -15)){
        if((((navee->y + 2.5) >= -35 && (navee->y + 2.5) <= -27)) || ((navee->y) >= -35 && (navee->y) <= -27)){
                navee->x = 0;
                navee->y = -50;

        }
    }

    if(((navee->x + 1.5) >= 5 && (navee->x + 1.5) <= 45) || ((navee->x - 1.5) >= 5 && (navee->x - 1.5) <= 45)){
        if((((navee->y + 2.5) >= -45 && (navee->y + 2.5) <= -35)) || ((navee->y) >= -45 && (navee->y) <= -35)){
                navee->x = 0;
                navee->y = -50;

        }
    }

    if(((navee->x + 1.5) >= 15 && (navee->x + 1.5) <= 35) || ((navee->x - 1.5) >= 15 && (navee->x - 1.5) <= 35)){
        if((((navee->y + 2.5) >= -35 && (navee->y + 2.5) <= -27)) || ((navee->y) >= -35 && (navee->y) <= -27)){
                navee->x = 0;
                navee->y = -50;

        }
    }

    if(((navee->x + 1.5) >= -20 && (navee->x + 1.5) <= 20) || ((navee->x - 1.5) >= -20 && (navee->x - 1.5) <= 20)){
        if((((navee->y + 2.5) >= -15 && (navee->y + 2.5) <= -5)) || ((navee->y) >= -15 && (navee->y) <= -5)){
                navee->x = 0;
                navee->y = -50;

        }
    }

    if(((navee->x + 1.5) >= -10 && (navee->x + 1.5) <= 10) || ((navee->x - 1.5) >= -10 && (navee->x - 1.5) <= 10)){
        if((((navee->y + 2.5) >= -23 && (navee->y + 2.5) <= -15)) || ((navee->y) >= -23 && (navee->y) <= -15)){
                navee->x = 0;
                navee->y = -50;

        }
    }

    if(((navee->x + 1.5) >= -45 && (navee->x + 1.5) <= -35) || ((navee->x - 1.5) >= -45 && (navee->x - 1.5) <= -35)){
        if((((navee->y + 2.5) >= 5 && (navee->y + 2.5) <= 45)) || ((navee->y) >= 5 && (navee->y) <= 45)){
                navee->x = 0;
                navee->y = -50;

        }
    }

    if(((navee->x + 1.5) >= -35 && (navee->x + 1.5) <= -25) || ((navee->x - 1.5) >= -35 && (navee->x - 1.5) <= -25)){
        if((((navee->y + 2.5) >= 17 && (navee->y + 2.5) <= 33)) || ((navee->y) >= 17 && (navee->y) <= 33)){
                navee->x = 0;
                navee->y = -50;

        }
    }

        if(((navee->x + 1.5) >= -20 && (navee->x + 1.5) <= 20) || ((navee->x - 1.5) >= -20 && (navee->x - 1.5) <= 20)){
                if((((navee->y + 2.5) >= 2 && (navee->y + 2.5) <= 12)) || ((navee->y) >= 2 && (navee->y) <= 12)){
                        navee->x = 0;
                        navee->y = -50;

                }
            }

        if(((navee->x + 1.5) >= -10 && (navee->x + 1.5) <= 10) || ((navee->x - 1.5) >= -10 && (navee->x - 1.5) <= 10)){
             if((((navee->y + 2.5) >= 12 && (navee->y + 2.5) <= 20)) || ((navee->y) >= 12 && (navee->y) <= 20)){
                      navee->x = 0;
                      navee->y = -50;

             }
        }

        if(((navee->x + 1.5) >= 35 && (navee->x + 1.5) <= 45) || ((navee->x - 1.5) >= 35 && (navee->x - 1.5) <= 45)){
                if((((navee->y + 2.5) >= 5 && (navee->y + 2.5) <= 45)) || ((navee->y) >= 5 && (navee->y) <= 45)){
                        navee->x = 0;
                        navee->y = -50;

                }
            }

        if(((navee->x + 1.5) >= 25 && (navee->x + 1.5) <= 35) || ((navee->x - 1.5) >= 25 && (navee->x - 1.5) <= 35)){
             if((((navee->y + 2.5) >= 17 && (navee->y + 2.5) <= 33)) || ((navee->y) >= 17 && (navee->y) <= 33)){
                      navee->x = 0;
                      navee->y = -50;

             }
        }

    if(((navee->x + 1.5) >= -20 && (navee->x + 1.5) <= 20) || ((navee->x - 1.5) >= -20 && (navee->x - 1.5) <= 20)){
        if((((navee->y + 2.5) >= 35 && (navee->y + 2.5) <= 45)) || ((navee->y) >= 35 && (navee->y) <= 45)){
                navee->x = 0;
                navee->y = -50;

        }
    }

    if(((navee->x + 1.5) >= -10 && (navee->x + 1.5) <= 10) || ((navee->x - 1.5) >= -10 && (navee->x - 1.5) <= 10)){
        if((((navee->y + 2.5) >= 27 && (navee->y + 2.5) <= 35)) || ((navee->y) >= 27 && (navee->y) <= 35)){
                navee->x = 0;
                navee->y = -50;

        }
    }

    if(((navee->x + 1.5) >= (objetivo->x -1.5) && (navee->x + 1.5) <= (objetivo->x + 1.5)) || ((navee->x - 1.5) >= (objetivo->x - 1.5) && (navee->x - 1.5) <= (objetivo->x + 1.5))){
        if((((navee->y + 2.5) >= objetivo->y && (navee->y + 2.5) <= (objetivo->y + 2.5))) || ((navee->y) >= objetivo->y && (navee->y) <= (objetivo->y + 2.5))){
                geraNave();
        }
    }


}








void tecla(unsigned char tecla, int x, int y){
    //printf("aqui");

    if (tecla == 'd'){
        if((navee->x+4) <= 50){
            navee->x+=1;
        }
    } else if(tecla == 'a'){
        if((navee->x-4) >= -50){
            navee->x-=1;
        }
    } else if (tecla == 'w'){
        if((navee->y + 5) <= 50){
            navee->y+=1;
        }
    } else if (tecla == 's'){
        if(navee->y - 2 >= -50){
            navee->y-=1;
        }
    }
    glutPostRedisplay();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    colisao();
    objetivo->desenha(1.0,1.0,1.0);
    navee->desenha(1.0, 0.5, 1.0);
    emPe->desenhaEmPe();
    deitado->desenhaDeitado();
    deitado2->desenhaDeitado();
    frente->desenhaFrente();
    deitadoEspelhado->desenhaDeitadoEspelhado();
    deitado3->desenhaDeitado();
    deitadoEspelhado2->desenhaDeitadoEspelhado();
    quadrado->desenhaquadrado();
    quadrado2->desenhaquadrado();
//    obst->desenha1();
    glutPostRedisplay();


    glutSwapBuffers();//para atualizar a tela e mudar o buffers
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("girar");
    init();//configura a openGL
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(tecla);
    glutMainLoop();
return 0;
}


