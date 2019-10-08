 
#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "structs.h"
#include "cabecalho.h"

// Constantes globais
#define FPS 17.0
#define CARRINHOS 6.0

// Variaveis globais
struct modelo   *modelo;
spriteObject    wallpaper_menu, wallpaper_creditos, jogar, controles, creditos, sair_menu, sair_creditos, mouse;
vetorR3         camera, cursor;
int             keyboard[256], tela = 1, light = 0, xMouse = 0, yMouse = 0, modoCamera = 3;
float           matAmbAndDif[4], /*matShine[],*/ altura = 720, largura = 1280, pi = 90, theta = 0;
Mix_Chunk       *som1, *som2, *som3, *som4;
GLfloat         lpos[4], lKa[4], lKd[4], lKs[4], mKd[4], mKs[4], mKe[4], lKa1[4], lKd1[4], lKs1[4], lPos1[4],
                lPos2[4], lPos3[4], lPos4[4], lPos5[4]; 

void main(int argc, char** argv)
{
    // Inicializacao
    glutInit(&argc, argv);

    // Definindo versao do GLUT
    glutInitContextVersion(1,1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    // Configuracoeses iniciais da janela GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glutInitWindowSize(largura, altura);
    glutInitWindowPosition (0, 0);

    // Inicializando a Janela
    glutCreateWindow("Lego Park");

    glutEnterGameMode();

    // Callbacks
    glutDisplayFunc(desenhaMinhaCena);
    glutReshapeFunc(redimensiona);
    glutTimerFunc(FPS,refresh,FPS);
    glutKeyboardFunc(teclaPressionada);
    glutKeyboardUpFunc(teclaSegurada);
    glutPassiveMotionFunc(mouseMove);
    glutMouseFunc(mouseClick);

    // Seta valores iniciais
    setup();

    // Loop
    glutMainLoop();
}

#include "lista.h"
#include "modelo.h"
#include "toksplit.h"
#include "malha.h"
#include "refresh.h"
#include "draws.h"
#include "setup.h"
#include "keyboard.h"
#include "mouse.h"
#include "musicas.h"