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

    // Realizando o efeito hover
	
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
				// Teclando Jogar
				if(mouse.posicao.x < jogar.posicao.x + jogar.dimensoes.x/2 && mouse.posicao.x > jogar.posicao.x - jogar.dimensoes.x/2 &&
				   mouse.posicao.y < jogar.posicao.y + jogar.dimensoes.y/2 && mouse.posicao.y > jogar.posicao.y - jogar.dimensoes.y/2)
				{
					tela = 1;					
				}

				// Teclando Opcoes
				if(mouse.posicao.x < opcoes.posicao.x + opcoes.dimensoes.x/2 && mouse.posicao.x > opcoes.posicao.x - opcoes.dimensoes.x/2 &&
				   mouse.posicao.y < opcoes.posicao.y + opcoes.dimensoes.y/2 && mouse.posicao.y > opcoes.posicao.y - opcoes.dimensoes.y/2)
				{
					tela = 2;
				}

				// Teclando Creditos
				if(mouse.posicao.x < creditos.posicao.x + creditos.dimensoes.x/2 && mouse.posicao.x > creditos.posicao.x - creditos.dimensoes.x/2 &&
				   mouse.posicao.y < creditos.posicao.y + creditos.dimensoes.y/2 && mouse.posicao.y > creditos.posicao.y - creditos.dimensoes.y/2)
				{
					tela = 3;
				}

				// Teclando Sair
				if(mouse.posicao.x < saida.posicao.x + saida.dimensoes.x/2 && mouse.posicao.x > saida.posicao.x - saida.dimensoes.x/2 &&
				   mouse.posicao.y < saida.posicao.y + saida.dimensoes.y/2 && mouse.posicao.y > saida.posicao.y - saida.dimensoes.y/2)
				{
					exit(0);
				}
			}			
	}
}
