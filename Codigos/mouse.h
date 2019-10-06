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
				
			}			
	}
}
