// Inicializa comandos essenciais
void setup()
{
    // Cor do fundo
    glClearColor(1.0, 1.0, 1.0, 0.0);

    // Habilita a utilização de texturas
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Limpa a tela
    glClear(GL_COLOR_BUFFER_BIT);

    // Desativando a opção de repetir uma tecla quando ela é continua apertada
    glutSetKeyRepeat(0);

    // Maquinas de estado
    tela = 0;
    cursor.x = 0;
    cursor.y = 0;
    cursor.z = 0;

    // carregando objetos
    // faz nessa ordem que vai setando NULL no GLMmodel pra reutilizar	
    testeOBJ = glmReadOBJ("../pontos_obj/arvore_1.obj");	
    carregaOBJ(&teste, testeOBJ);

    testeOBJ = glmReadOBJ("../pontos_obj/terreno.obj");
    carregaOBJ(&terreno, testeOBJ);

    testeOBJ = glmReadOBJ("../pontos_obj/pedra_1.obj");
    carregaOBJ(&pedra, testeOBJ);

    rodaGGOBJ = glmReadOBJ("../pontos_obj/base_roda_gigante.obj");
    carregaOBJ(&rodaGG_base, rodaGGOBJ);
    rodaGGOBJ = glmReadOBJ("../pontos_obj/aro_roda_gigante.obj");
    carregaOBJ(&rodaGG_aro, rodaGGOBJ);
    rodaGGOBJ = glmReadOBJ("../pontos_obj/carrinho_vermelho.obj");
    carregaOBJ(&rodaGG_carro, rodaGGOBJ);

   //setando valores para os objetos
   setPosicao(&teste,-20,0,0);
   setDimensoesProp(&teste, 50);

   setPosicao(&terreno, 0,0,0);
   setDimensoesProp(&terreno,50);

   setPosicao(&pedra,40,-30,0);
   setDimensoesProp(&pedra,20);

   setPosicao(&rodaGG_base,0,0,0);
   setDimensoesProp(&rodaGG_base,50);

   setPosicao(&rodaGG_aro,0,0,0);
   setDimensoesProp(&rodaGG_aro,50);

   setPosicao(&rodaGG_carro,0,0,0);
   setDimensoesProp(&rodaGG_carro,rodaGG_aro.dimensoes.x/10);
	
    wallpaper_menu.textura = loadTexture("../Imagens/wallpaper_menu.png");
    jogar.textura = loadTexture("../Imagens/jogar_branco.png");
    controles.textura = loadTexture("../Imagens/controles_branco.png");
    creditos.textura = loadTexture("../Imagens/creditos_branco.png");
    sair_menu.textura = loadTexture("../Imagens/sair_branco.png");
    sair_creditos.textura = loadTexture("../Imagens/sair_branco.png");
    wallpaper_creditos.textura = loadTexture("../Imagens/wallpaper_creditos.png");

    float matAmbAndDif[4] = {1.0, 1.0, 1.0, 1.0};    // vetor cor ambiente e difusa: branca
    float matShine[] = {5};                          // expoente especular (shininess)
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
