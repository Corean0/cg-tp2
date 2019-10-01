#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

// Constantes globais

// Variavéis objetos, ASCII, constante de velocidade, pause, pontuação

spriteObject 	    

spriteScore 	  

spriteOb_Animado_s 	

int 			   

double 			    



void main(int argc, char** argv)
{

    //Inicialização
    glutInit(&argc, argv);

    //Definindo versão do GLUT
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    //Configurações iniciais da janela GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(largura, altura);
    glutInitWindowPosition(100, 100);

    //Inicializando a Janela
    glutCreateWindow("Mario Pong");

    //Seta valores iniciais
    setup();
    srand(time(0));

    // Callbacks
    glutDisplayFunc(desenhaMinhaCena);
    glutReshapeFunc(redimensionada);
    glutKeyboardFunc(teclaPressionada);
    glutKeyboardUpFunc(teclaSegurada);
    glutPassiveMotionFunc(mouseMove);
    glutMouseFunc(mouseClick);
    glutTimerFunc(FPS,refresh,FPS);


    //Loop
    glutMainLoop();
}

#include "draws.h"
#include "setup.h"
#include "keyboard.h"
#include "mouse.h"
#include "movimentos.h"
#include "refresh.h"
#include "pontuacao.h"
#include "resets.h"
#include "sides.h"
#include "events.h"
#include "musicas.h"
