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
	
    // Texturas 2D
    wallpaper_menu.textura = loadTexture("../Imagens/wallpaper_menu.png");
    jogar.textura = loadTexture("../Imagens/jogar_branco.png");
    controles.textura = loadTexture("../Imagens/controles_branco.png");
    creditos.textura = loadTexture("../Imagens/creditos_branco.png");
    sair_menu.textura = loadTexture("../Imagens/sair_branco.png");
    sair_creditos.textura = loadTexture("../Imagens/sair_branco.png");
    wallpaper_controles.textura = loadTexture("../Imagens/wallpaper_controles.png");
    wallpaper_creditos.textura = loadTexture("../Imagens/wallpaper_creditos.png");
    wallpaper_controles.textura = loadTexture("../Imagens/wallpaper_controles.png");

    float matAmbAndDif[4] = {1.0, 1.0, 1.0, 1.0};    // Vetor cor ambiente e difusa: branca
    float matShine[] = {5};                          // Expoente especular (shininess)
    int light = 0;
}

void attPosicao()
{
    // Objetos gerais 2D
    wallpaper_menu.dimensoes.x = largura;
    wallpaper_menu.dimensoes.y = altura;
    wallpaper_menu.posicao.x = largura/2;
    wallpaper_menu.posicao.y = altura/2;

    wallpaper_controles.dimensoes.x = largura;
    wallpaper_controles.dimensoes.y = altura;
    wallpaper_controles.posicao.x = largura/2;
    wallpaper_controles.posicao.y = altura/2;

    jogar.dimensoes.x = largura/6;
    jogar.dimensoes.y = altura/12;
    jogar.posicao.x = largura/5;
    jogar.posicao.y = altura/2 - altura/50;
    jogar.posicao.z = 0;

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

void setupJogo(){
    // Carregando objetos
    // TAMANHO é a variavel global de parametrização de tamanho para as coisas
    /* Para dar ctrl C

    carregaOBJ(&, glmReadOBJ("../pontos_obj/.obj"));
    setPosicao(&,0,0,0);
    setDimensoesProp(&,TAMANHO);
    */
    carregaOBJ(&poste, glmReadOBJ("../pontos_obj/poste.obj"));
    setPosicao(&poste,0,0,0);
    setDimensoesProp(&poste,TAMANHO*1.6/2);

    carregaOBJ(&arvore1, glmReadOBJ("../pontos_obj/arvore_1.obj"));
    setPosicao(&arvore1,0,0,0);
    setDimensoesProp(&arvore1,TAMANHO);

    carregaOBJ(&arvore2, glmReadOBJ("../pontos_obj/arvore_2.obj"));
    setPosicao(&arvore2,0,0,0);
    setDimensoesProp(&arvore2,TAMANHO);

    carregaOBJ(&arvore_morta, glmReadOBJ("../pontos_obj/arvore_morta.obj"));
    setPosicao(&arvore_morta,0,0,0);
    setDimensoesProp(&arvore_morta,TAMANHO);

    carregaOBJ(&terreno, glmReadOBJ("../pontos_obj/terreno.obj"));
    setDimensoesDesprop(&terreno,TAMANHO*3,TAMANHO,TAMANHO*3);
    setPosicao(&terreno, 0,0,0);

    carregaOBJ(&fonte, glmReadOBJ("../pontos_obj/fonte.obj"));
    setDimensoesProp(&fonte, TAMANHO+TAMANHO/3);
    setPosicao(&fonte,0,0,0);

    carregaOBJ(&pipoca, glmReadOBJ("../pontos_obj/pipoca.obj"));
    setDimensoesProp(&pipoca, TAMANHO/2.3);
    setPosicao(&pipoca, -30, 0,-10);

    carregaOBJ(&pipoca1, glmReadOBJ("../pontos_obj/pipoca.obj"));
    setDimensoesProp(&pipoca1, TAMANHO/2.3);
    setPosicao(&pipoca1, -30, 0,10);
  
    carregaOBJ(&banco, glmReadOBJ("../pontos_obj/banco.obj"));
    setPosicao(&banco, 0,0,0);
    setDimensoesProp(&banco, TAMANHO/2.8);

    carregaOBJ(&terreno_rua, glmReadOBJ("../pontos_obj/terreno_rua_quadrado.obj"));
    setPosicao(&terreno_rua, 0,0,0);
    setDimensoesProp(&terreno_rua,TAMANHO/2);

    carregaOBJ(&terreno_rcurva, glmReadOBJ("../pontos_obj/terreno_rua_curva.obj"));
    setPosicao(&terreno_rcurva, 0,0,0);
    setDimensoesProp(&terreno_rcurva,TAMANHO/2);

    carregaOBJ(&cerca, glmReadOBJ("../pontos_obj/cerca.obj"));
    setPosicao(&cerca,0,0,0);
    setDimensoesProp(&cerca, TAMANHO);

    carregaOBJ(&lanchonete, glmReadOBJ("../pontos_obj/lanchonete.obj"));
    setDimensoesProp(&lanchonete,TAMANHO*2);
    setPosicao(&lanchonete,0,-2,-(-terreno_rua.dimensoes.x*8.5-lanchonete.dimensoes.z/2));

    carregaOBJ(&lanchonete1, glmReadOBJ("../pontos_obj/lanchonete.obj"));
    setDimensoesProp(&lanchonete1,TAMANHO*2);
    setPosicao(&lanchonete1,0,-2,-terreno_rua.dimensoes.x*8.5-lanchonete1.dimensoes.z/2);

    carregaOBJ(&rodaGG_base, glmReadOBJ("../pontos_obj/base_roda_gigante.obj"));
    setDimensoesProp(&rodaGG_base,TAMANHO*2-5.5/*-ERRO VISUAL*/);
    setPosicao(&rodaGG_base,-(-terreno_rua.dimensoes.x*13.5-rodaGG_base.dimensoes.x/2+2),0,0);
    carregaOBJ(&rodaGG_aro, glmReadOBJ("../pontos_obj/aro_roda_gigante.obj"));
    setPosicao(&rodaGG_aro,0,0,0);
    setDimensoesProp(&rodaGG_aro,TAMANHO*2);
    carregaOBJ(&rodaGG_carro, glmReadOBJ("../pontos_obj/carrinho_vermelho.obj"));
    setPosicao(&rodaGG_carro,0,0,0);
    setDimensoesProp(&rodaGG_carro,TAMANHO*2/5);

    carregaOBJ(&carrossel_base, glmReadOBJ("../pontos_obj/carrossel_base.obj"));
    setDimensoesProp(&carrossel_base,TAMANHO*1.5);
    setPosicao(&carrossel_base,-terreno_rua.dimensoes.x*11,0,-terreno_rua.dimensoes.x*9.5-carrossel_base.dimensoes.x/2+2);
    carregaOBJ(&carrossel_cavalo, glmReadOBJ("../pontos_obj/carrossel_cavalo.obj"));
    setPosicao(&carrossel_cavalo,0,0,0);
    setDimensoesProp(&carrossel_cavalo,TAMANHO/1.2);

    carregaOBJ(&pedra_3, glmReadOBJ("../pontos_obj/pedra_3.obj"));
    setPosicao(&pedra_3, 0,0,0);
    setDimensoesProp(&pedra_3, TAMANHO/2.2);

    carregaOBJ(&torreB, glmReadOBJ("../pontos_obj/torre.obj"));
    setDimensoesProp(&torreB,TAMANHO*3);
    setPosicao(&torreB,-terreno_rua.dimensoes.x*7,0.2,-terreno_rua.dimensoes.x*3-torreB.dimensoes.z/2);
    carregaOBJ(&torreC, glmReadOBJ("../pontos_obj/banco_da_torre.obj"));
    setPosicao(&torreC,0,0,0);
    setDimensoesProp(&torreC,torreB.aumento.x/4.2);

    carregaOBJ(&XM_base, glmReadOBJ("../pontos_obj/arena_xicaras.obj"));
    setPosicao(&XM_base,-terreno_rua.dimensoes.x*11,0,terreno_rua.dimensoes.x*10.5+XM_base.dimensoes.z/2+1);
    setDimensoesProp(&XM_base,TAMANHO*2);
    carregaOBJ(&XM_xicara, glmReadOBJ("../pontos_obj/xicara.obj"));
    setPosicao(&XM_xicara,0,0,0);
    setDimensoesProp(&XM_xicara,XM_base.aumento.x/4);

    carregaOBJ(&banco_Cadeira, glmReadOBJ("../pontos_obj/cadeira_e_mesa.obj"));
    setPosicao(&banco_Cadeira,0,0,0);
    setDimensoesProp(&banco_Cadeira,TAMANHO/2);


	for(int i=0;i<CAVALOS;i++)
    {
		if(rand() % 2 == 0)
        {
			alturaCavalo[i] = (rand() % 40)/40.0;
			velAlt[i] = -CONSTANTE;
		}
        else
        {
			alturaCavalo[i]=-(rand() % 40)/40.0;
			velAlt[i] = CONSTANTE;
		}		
	}
	
	//seta velocidades de cada uma das xicaras
	for(int i=0; i<XICARAS; i++){
		if(rand() % 2 == 0)
			rotacaoXX[i] = VEL_XX;
		else
			rotacaoXX[i] = -VEL_XX;
	}
}
