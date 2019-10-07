// Registrando a posicao atual do mouse
void mouseMove(int x, int y)
{
    mouse.posicao.x = x;

    if(y < altura/2)
    {
    	mouse.posicao.y = altura/2 - y + altura/2;
    }

    else
    {
    	mouse.posicao.y = - y + altura;
    }

    // Realizando o efeito hover no menu
    if(tela == 0)
	{
		jogar.textura = loadTexture("../Imagens/jogar_branco.png");

		if(mouse.posicao.x < jogar.posicao.x + jogar.dimensoes.x/2 && mouse.posicao.x > jogar.posicao.x - jogar.dimensoes.x/2 &&
		   mouse.posicao.y < jogar.posicao.y + jogar.dimensoes.y/2 && mouse.posicao.y > jogar.posicao.y - jogar.dimensoes.y/2)
		{
			jogar.textura = loadTexture("../Imagens/jogar_cinza.png");
		}
			
		controles.textura = loadTexture("../Imagens/controles_branco.png");

		if(mouse.posicao.x < controles.posicao.x + controles.dimensoes.x/2 && mouse.posicao.x > controles.posicao.x - controles.dimensoes.x/2 &&
		   mouse.posicao.y < controles.posicao.y + controles.dimensoes.y/2 && mouse.posicao.y > controles.posicao.y - controles.dimensoes.y/2)
		{
			controles.textura = loadTexture("../Imagens/controles_cinza.png");
		}

		creditos.textura = loadTexture("../Imagens/creditos_branco.png");

		if(mouse.posicao.x < creditos.posicao.x + creditos.dimensoes.x/2 && mouse.posicao.x > creditos.posicao.x - creditos.dimensoes.x/2 &&
		   mouse.posicao.y < creditos.posicao.y + creditos.dimensoes.y/2 && mouse.posicao.y > creditos.posicao.y - creditos.dimensoes.y/2)
		{
			creditos.textura = loadTexture("../Imagens/creditos_cinza.png");
		}

		sair.textura = loadTexture("../Imagens/sair_branco.png");
		
		if(mouse.posicao.x < sair.posicao.x + sair.dimensoes.x/2 && mouse.posicao.x > sair.posicao.x - sair.dimensoes.x/2 &&
		   mouse.posicao.y < sair.posicao.y + sair.dimensoes.y/2 && mouse.posicao.y > sair.posicao.y - sair.dimensoes.y/2)
		{
			sair.textura = loadTexture("../Imagens/sair_cinza.png");
		}
	}

	// Efeito hover nos creditos
	if(tela == 3)
	{
		sair.textura = loadTexture("../Imagens/sair_branco.png");
		
		if(mouse.posicao.x < sair.posicao.x + sair.dimensoes.x/2 && mouse.posicao.x > sair.posicao.x - sair.dimensoes.x/2 &&
		   mouse.posicao.y < sair.posicao.y + sair.dimensoes.y/2 && mouse.posicao.y > sair.posicao.y - sair.dimensoes.y/2)
		{
			sair.textura = loadTexture("../Imagens/sair_cinza.png");
		}
	}	
}

// Clique do mouse
void mouseClick(int botao, int estado, int x, int y)
{
	switch(botao)
    {
		case GLUT_LEFT_BUTTON :

			// Menu
			if(tela == 0)
			{
				// Clicando "Jogar"
				if(mouse.posicao.x < jogar.posicao.x + jogar.dimensoes.x/2 && mouse.posicao.x > jogar.posicao.x - jogar.dimensoes.x/2 &&
				   mouse.posicao.y < jogar.posicao.y + jogar.dimensoes.y/2 && mouse.posicao.y > jogar.posicao.y - jogar.dimensoes.y/2)
				{
					tela = 1;
				}

				// Clicando "Controles"
				if(mouse.posicao.x < controles.posicao.x + controles.dimensoes.x/2 && mouse.posicao.x > controles.posicao.x - controles.dimensoes.x/2 &&
				   mouse.posicao.y < controles.posicao.y + controles.dimensoes.y/2 && mouse.posicao.y > controles.posicao.y - controles.dimensoes.y/2)
			    {
			    	tela = 2;
			    }

			    // Clicando "Creditos"
				if(mouse.posicao.x < creditos.posicao.x + creditos.dimensoes.x/2 && mouse.posicao.x > creditos.posicao.x - creditos.dimensoes.x/2 &&
				   mouse.posicao.y < creditos.posicao.y + creditos.dimensoes.y/2 && mouse.posicao.y > creditos.posicao.y - creditos.dimensoes.y/2)
				{
					tela = 3;
				}

				// Clicando "Sair"
				if(mouse.posicao.x < sair.posicao.x + sair.dimensoes.x/2 && mouse.posicao.x > sair.posicao.x - sair.dimensoes.x/2 &&
				   mouse.posicao.y < sair.posicao.y + sair.dimensoes.y/2 && mouse.posicao.y > sair.posicao.y - sair.dimensoes.y/2)
				{
					exit(0);
				}
			}

			// Creditos
			if(tela == 3)
			{
				// Clicando "Sair"
				if(mouse.posicao.x < sair.posicao.x + sair.dimensoes.x/2 && mouse.posicao.x > sair.posicao.x - sair.dimensoes.x/2 &&
				   mouse.posicao.y < sair.posicao.y + sair.dimensoes.y/2 && mouse.posicao.y > sair.posicao.y - sair.dimensoes.y/2)
				{
					tela = 0;
				}
			}			
	}
}
