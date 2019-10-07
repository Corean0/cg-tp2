 
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
#include "structs.h"
#include "cabecalho.h"

// Constantes globais
#define FPS 17.0
#define CARRINHOS 6.0

// Variaveis globais
spriteObject    wallpaper_menu, wallpaper_creditos, jogar, controles, creditos, sair, mouse;
int             keyboard[256], tela = 0;
double          altura = 600, largura = 900;
Mix_Chunk       *som1, *som2, *som3, *som4;

void main(int argc, char** argv)
{
    //Inicializacao
    glutInit(&argc, argv);

    //Definindo versao do GLUT
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    //Configuracoeses iniciais da janela GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(largura, altura);
    glutInitWindowPosition (0, 0);

    //Inicializando a Janela
    glutCreateWindow("Lego Park");

    //Deixa fullscreen mas não funciona ainda
    glutEnterGameMode();

    //Seta valores iniciais
    setup();

    // Callbacks
    glutDisplayFunc(desenhaMinhaCena);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclaPressionada);
    glutKeyboardUpFunc(teclaSegurada);
    glutPassiveMotionFunc(mouseMove);
    glutMouseFunc(mouseClick);
    glutTimerFunc(FPS,refresh,FPS);

    //Loop
    glutMainLoop();
}

#include "refresh.h"
#include "draws.h"
#include "setup.h"
#include "keyboard.h"
#include "mouse.h"
#include "musicas.h"
