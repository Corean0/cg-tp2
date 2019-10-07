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

    // Objetos gerais
    wallpaper_menu.dimensoes.x = largura;
    wallpaper_menu.dimensoes.y = altura;
    wallpaper_menu.posicao.x = largura/2;
    wallpaper_menu.posicao.y = altura/2;
    wallpaper_menu.textura = loadTexture("../Imagens/wallpaper_menu.png");

    jogar.dimensoes.x = largura/6;
    jogar.dimensoes.y = altura/12;
    jogar.posicao.x = largura/5;
    jogar.posicao.y = altura/2 - altura/50;
    jogar.textura = loadTexture("../Imagens/jogar_branco.png");

    controles.dimensoes.x = largura/4 - largura/50;
    controles.dimensoes.y = altura/12;
    controles.posicao.x = largura/6;
    controles.posicao.y = altura/4;
    controles.textura = loadTexture("../Imagens/controles_branco.png");

    creditos.dimensoes.x = largura/4 - largura/50;
    creditos.dimensoes.y = altura/12;
    creditos.posicao.x = largura/2 + largura/3;
    creditos.posicao.y = altura/2 - altura/50;
    creditos.textura = loadTexture("../Imagens/creditos_branco.png");

    sair.dimensoes.x = largura/8;
    sair.dimensoes.y = altura/12;
    sair.posicao.x = largura/2 + largura/3 - largura/20;
    sair.posicao.y = altura/4;
    sair.textura = loadTexture("../Imagens/sair_branco.png");

    wallpaper_creditos.dimensoes.x = largura;
    wallpaper_creditos.dimensoes.y = altura;
    wallpaper_creditos.posicao.x = largura/2;
    wallpaper_creditos.posicao.y = altura/2;
    wallpaper_creditos.textura = loadTexture("../Imagens/wallpaper_creditos.png");
}
