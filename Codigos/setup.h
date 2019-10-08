// Inicializa comandos essenciais
void setup()
{
    // Cor do fundo
    glClearColor(1.0, 1.0, 1.0, 1.0);

    // Habilita a utilização de texturas
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Limpa a tela
    glClear(GL_COLOR_BUFFER_BIT);

    // Desativando a opção de repetir uma tecla quando ela é continua apertada
    glutSetKeyRepeat(0);

    // Maquinas de estado
    tela = 0;
    xCursor = 0;
    yCursor = 0;
    zCursor = 0;
	
    wallpaper_menu.textura = loadTexture("../Imagens/wallpaper_menu.png");
    jogar.textura = loadTexture("../Imagens/jogar_branco.png");
    controles.textura = loadTexture("../Imagens/controles_branco.png");
    creditos.textura = loadTexture("../Imagens/creditos_branco.png");
    sair_menu.textura = loadTexture("../Imagens/sair_branco.png");
    sair_creditos.textura = loadTexture("../Imagens/sair_branco.png");
    wallpaper_creditos.textura = loadTexture("../Imagens/wallpaper_creditos.png");

    GLfloat lPos[4]={0.00, 0.00, 0.00, 1.00 };
    GLfloat lKa[4]={0.00, 0.5, 0.00, 1.00};
    GLfloat lKd[4]={0.5, 0.5, 0.5, 1.00};
    GLfloat lKs[4]={1.00, 1.00, 1.00, 1.00};
    GLfloat mKd[4]={0,0,0,1};
    GLfloat mKs[4]={0,0,0,1};
    GLfloat mKe[4]={0,0,0,1};

    GLfloat lKa1[4]={1.0, 1.0, 1.0, 1.00};       // cor ambiente (basta mudar as 3 para escolher a cor da luz)
    GLfloat lKd1[4]={1.0, 1.0, 1.0, 1.00};       // cor difusa
    GLfloat lKs1[4]={1.00, 1.00, 1.00, 1.00};    // cor especular

    GLfloat lPos1[4]={7.00, -31.2, -45.9, 1.00 };
    GLfloat lPos2[4]={7.00, -31.2, -70.7, 1.00 };
    GLfloat lPos3[4]={7.00, -31.2, -96.6, 1.00 };
    GLfloat lPos4[4]={-16.7, -31.2, -16.8, 1.00 };
    GLfloat lPos5[4]={-133.3, -31.2, 37.2, 1.00 };

    float matAmbAndDif[4] = {1.0, 1.0, 1.0, 1.0};    // vetor cor ambiente e difusa: branca
    //float matShine[] = {5};                          // expoente especular (shininess)
    int light = 0;
}

void attPosicao()
{
    // Objetos gerais
    wallpaper_menu.dimensoes.x = largura;
    wallpaper_menu.dimensoes.y = altura;
    wallpaper_menu.posicao.x = largura/2;
    wallpaper_menu.posicao.y = altura/2;

    jogar.dimensoes.x = largura/6;
    jogar.dimensoes.y = altura/12;
    jogar.posicao.x = largura/5;
    jogar.posicao.y = altura/2 - altura/50;

    controles.dimensoes.x = largura/4 - largura/50;
    controles.dimensoes.y = altura/12;
    controles.posicao.x = largura/6;
    controles.posicao.y = altura/4;

    creditos.dimensoes.x = largura/4 - largura/50;
    creditos.dimensoes.y = altura/12;
    creditos.posicao.x = largura/2 + largura/3;
    creditos.posicao.y = altura/2 - altura/50;

    sair_menu.dimensoes.x = largura/8;
    sair_menu.dimensoes.y = altura/12;
    sair_menu.posicao.x = largura/2 + largura/3 - largura/20;
    sair_menu.posicao.y = altura/4;

    sair_creditos.dimensoes.x = largura/8;
    sair_creditos.dimensoes.y = altura/12;
    sair_creditos.posicao.x = largura/2 + largura/3;
    sair_creditos.posicao.y = altura/4;

    wallpaper_creditos.dimensoes.x = largura;
    wallpaper_creditos.dimensoes.y = altura;
    wallpaper_creditos.posicao.x = largura/2;
    wallpaper_creditos.posicao.y = altura/2;
}
