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
#define largura 900.0
#define altura 600
#define FPS 17.0

// Variaveis globais
spriteObject wallpaper,jogar, opcoes, creditos, sair, mouse;
int        keyboard[256], tela = 0;
Mix_Chunk  *som1, *som2, *som3, *som4;

void main(int argc, char** argv)
{
    //Inicializa��o
    glutInit(&argc, argv);

    //Definindo vers�o do GLUT
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    //Configura��es iniciais da janela GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(largura, altura);
    glutInitWindowPosition(100, 100);

    //Inicializando a Janela
    glutCreateWindow("Lego Park");

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
