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

    wallpaper.dimensoes.x = largura;
    wallpaper.dimensoes.y = altura;
    wallpaper.posicao.x = largura/2;
    wallpaper.posicao.y = altura/2;
    wallpaper.textura = loadTexture("../Imagens/wallpaper.png");
}