// Desenho do jogo
void desenhaMinhaCena()
{
    glMatrixMode(GL_MODELVIEW);
    glColor4f(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if(tela == 0)
    {
		// configura2D();
        drawObject(wallpaper_menu);
        drawObject(jogar);
        drawObject(controles);
        drawObject(creditos);
        drawObject(sair_menu);
    }

    else if(tela == 1)
    {

		float colorFog[4] = {1.0, 1.0, 1.0, 1}; 
    	glEnable(GL_FOG);
    	glFogi(GL_FOG_MODE, GL_LINEAR);    // GL_EXP, GL_EXP2 e GL_LINEAR
    	glFogf(GL_FOG_START, 100);         // Inicio e termino do fog para GL_LINEAR -3.00 ate 3.00
    	glFogf(GL_FOG_END, 200);
    	glFogf(GL_FOG_DENSITY, 0.005);     // Densidade do fog 0.00 á 3.00
    	glFogfv(GL_FOG_COLOR, colorFog);

		// configura3D();
        movimentacao();

        // Coordenadas da camera em coordenadas esfericas
        camera.x = 100*sin(pi)*cos(theta);
        camera.y = 100*cos(pi);
        camera.z = 100*sin(pi)*sin(theta);

        glLoadIdentity();

        switch(modoCamera)
        {
            // Camera simples
            default:
				
                // gluLookAt(-80, 30, 0,-120, 25, 0, 0, 1, 0); // Roda Gigante
				// gluLookAt(-30, 30, -10, -60, 28, -40, 0, 1, 0); // Carrosel
				gluLookAt(-108, 25, -50,-108, 23, -55, 0, 1, 0); // Torre que cai
                break;

            // Camera primeira pessoa
            case 2:

                gluLookAt(cursor.x + 0,cursor.y + 0, cursor.z + 0, cursor.x + camera.x,cursor.y + camera.y, cursor.z + camera.z, 0, 1, 0);
                break;

            // Camera terceira pessoa
            case 3:

                gluLookAt(cursor.x + camera.x,cursor.y + camera.y, cursor.z + camera.z, cursor.x + 0,cursor.y + 0, cursor.z + 0, 0, 1, 0);
                break;
        }

	    // Esfera indicativa de onde está a luz
		/*	
		glPushMatrix();
	        glTranslatef(20.0, 50.0, 50.0);
	        glColor3f(0, 0, 0);
	        glutWireSphere(2, 8, 8); 
	    	glPopMatrix();
		*/
			
		if (isLightingOn)
		{
	        glEnable(GL_LIGHTING);
		}
		    
		glClearColor(1,1,1,1);

		chao();
		lanchonetes();
		desenhaOBJ(fonte,0);
		pipocas();
		postes();
		torre();
		arvores();
		desenhaRodaGigante();
		carrossel();
		bancos();
		ruas();
		xicaras_malucas();
		bancosCadeira();
		// Interface com problema de não saber configurar 2/3D
		// DesenhaInterface();

		if (isLightingOn)
	    {
	    	glDisable(GL_LIGHTING);
	    }

    }

    else if(tela == 2)
    {
    	drawObject(wallpaper_controles);
    	drawObject(sair_creditos);
    }

    else if(tela == 3)
    {
        drawObject(wallpaper_creditos);
        drawObject(sair_creditos);
    }
    
    glutSwapBuffers();
}

//Desenha os objetos e imagens
void drawObject(spriteObject objeto)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, objeto.textura);

    glPushMatrix();
    glTranslatef(objeto.posicao.x, objeto.posicao.y, 0);

    glBegin(GL_TRIANGLE_FAN);
    {
        glTexCoord2f(0, 0);
        glVertex3f(-objeto.dimensoes.x/2, -objeto.dimensoes.y/2,  0);
        glTexCoord2f(1, 0);
        glVertex3f( objeto.dimensoes.x/2, -objeto.dimensoes.y/2,  0);
        glTexCoord2f(1, 1);
        glVertex3f( objeto.dimensoes.x/2,  objeto.dimensoes.y/2,  0);
        glTexCoord2f(0, 1);
        glVertex3f(-objeto.dimensoes.x/2,  objeto.dimensoes.y/2,  0);
    }

    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void desenhaInterface()
{
	// Configurar glortho para fazer e depois reconfigurar persperctive
	configura2D();
        drawObject(jogar);
        drawObject(controles);
}

void desenhaOBJ(Objeto3D objeto, float rotacao)
{
	glPushMatrix();
	    	glTranslatef(objeto.posicao.x,objeto.dimensoes.y/2+objeto.posicao.y,objeto.posicao.z);
	    	glScalef(objeto.aumento.x,objeto.aumento.y,objeto.aumento.z);
		glRotatef(rotacao,0,1,0);
	    	glCallList(objeto.listaVisualizacao);
	glPopMatrix();
}

void desenhaPosicao(Objeto3D objeto,float centrox, float centroz, float rotacao)
{
	glPushMatrix();
		glTranslatef(centrox,0,centroz);
		desenhaOBJ(objeto,rotacao);
	glPopMatrix();
}

void chao()
{
		// Terreno
		glPushMatrix();
		for(int random = -QTDECHAO, auxrandom, random1, auxrandom1 ; random <= QTDECHAO ;random++)
		{
			auxrandom = random*terreno.dimensoes.x;
			for(random1 = -QTDECHAO ;random1 <= QTDECHAO; random1++)
			{
				auxrandom1 = random1*terreno.dimensoes.x;
				glPushMatrix();
	    				glTranslatef(auxrandom,0,auxrandom1);
		            		glScalef(terreno.aumento.x,terreno.aumento.y,terreno.aumento.z);
		            		glCallList(terreno.listaVisualizacao);
				glPopMatrix();
			}
		}		
		glPopMatrix();
}

/*
LEMBRETE:
Eixo x: altera cima/baixo, sendo positivo levando mais para baixo
Eixo z: altera direita/esquerda, sendo positivo levando mais para esquerda
*/

void ruas()
{
	glPushMatrix();
		// Ajustar erro terreno/rua
		glTranslatef(0,terreno.dimensoes.y/2,0);

		// Ruas em torno da fonte e alongando pros extremos laterais
		// Baixo
		aux_rua(11,terreno_rua.dimensoes.x*2,-terreno_rua.dimensoes.x*5,0);
		// Cima Fonte -> Pipocas
		aux_rua(11,-terreno_rua.dimensoes.x*2,-terreno_rua.dimensoes.x*5,0);
		// Esquerda Brinquedo1 -> Brinquedo2
		aux_rua(5,-terreno_rua.dimensoes.x*2,terreno_rua.dimensoes.x*2.5,1);
		// Direita
		aux_rua(5,-terreno_rua.dimensoes.x*2,-terreno_rua.dimensoes.x*2.5,1);

		// Ruas em torno das pipocas
		aux_rua(3,-terreno_rua.dimensoes.x*4,-terreno_rua.dimensoes.x,0);
		aux_rua(2,-terreno_rua.dimensoes.x*3,terreno_rua.dimensoes.x*2,1);
		aux_rua(2,-terreno_rua.dimensoes.x*3,-terreno_rua.dimensoes.x*2,1);

		// Ruas centrais levando à brinquedo 3
		aux_rua(7,terreno_rua.dimensoes.x*2,0,1);
		aux_rua(9,-terreno_rua.dimensoes.x*13,0,1);

		// Rua brinquedos 1-2
		aux_rua(19,-terreno_rua.dimensoes.x*11,-terreno_rua.dimensoes.x*9,0);

		// Rua brinquedos 4-5
		aux_rua(9,-terreno_rua.dimensoes.x*7,-terreno_rua.dimensoes.x*4,0);

		// Ruas para "fechar" caixa das arvores
		aux_rua(3,-terreno_rua.dimensoes.x,-terreno_rua.dimensoes.x*6,1);
		aux_rua(3,-terreno_rua.dimensoes.x,terreno_rua.dimensoes.x*6,1);

		// Ruas levando para as lanchonetes
		aux_rua(2,0,terreno_rua.dimensoes.x*7,0);
		aux_rua(2,0,-terreno_rua.dimensoes.x*8,0);

		// Ruas curvas
		// Ruas ao lado da lanchonete, na parte oposta da direção dos brinquedos
		glPushMatrix();
			glTranslatef(terreno_rua.dimensoes.x*2,0,0);
			desenhaPosicao(terreno_rcurva,0,-terreno_rua.dimensoes.x*6,-90);
			desenhaPosicao(terreno_rcurva,0,terreno_rua.dimensoes.x*6,180);
		glPopMatrix();

		// Ruas na direção Lanchonete -> Brinquedos
		glPushMatrix();
			glTranslatef(-terreno_rua.dimensoes.x*2,0,0);
			desenhaPosicao(terreno_rcurva,0,-terreno_rua.dimensoes.x*6,0);
			desenhaPosicao(terreno_rcurva,0,terreno_rua.dimensoes.x*6,90);
		glPopMatrix();

		// Ruas próximas à pipoca
		glPushMatrix();
			glTranslatef(-terreno_rua.dimensoes.x*4,0,0);
			desenhaPosicao(terreno_rcurva,0,-terreno_rua.dimensoes.x*2,0);
			desenhaPosicao(terreno_rcurva,0,terreno_rua.dimensoes.x*2,90);
		glPopMatrix();

	glPopMatrix();
}

void cercas()
{
	aux_cerca(3,0,0,1);
}

void pipocas()
{
	// Pipoca da direita
    	desenhaOBJ(pipoca,90);
	// Pipoca da esquerda
	desenhaOBJ(pipoca1,-90);
	// Pipoca do meio
	desenhaPosicao(pipoca,0,-pipoca.posicao.z,0);
}

void bancos()
{
	// Bancos horizontais em frente à pipoca
	// Banco da direita
	desenhaPosicao(banco,pipoca.posicao.x-terreno_rua.dimensoes.x*2,pipoca.posicao.z-2,90);
	// Banco da esquerda
	desenhaPosicao(banco,pipoca.posicao.x-terreno_rua.dimensoes.x*2,pipoca.posicao.z+terreno_rua.dimensoes.x*2+3,90);

	// Bancos verticais em frente à pipoca
	desenhaPosicao(banco,pipoca.posicao.x,pipoca.posicao.z-terreno_rua.dimensoes.x*2,0);
	desenhaPosicao(banco,pipoca.posicao.x,pipoca1.posicao.z+terreno_rua.dimensoes.x*2,180);
}

void postes()
{
	//Postes em torno da fonte
	desenhaPosicao(poste,fonte.dimensoes.x/2-1,fonte.dimensoes.z/2+4,0);
	desenhaPosicao(poste,fonte.dimensoes.x/2-1,-(fonte.dimensoes.z/2+4),0);
	desenhaPosicao(poste,-(fonte.dimensoes.x/2-1),fonte.dimensoes.z/2+4,0);
	desenhaPosicao(poste,-(fonte.dimensoes.x/2-1),-(fonte.dimensoes.z/2+4),0);

	// Postes ao lado das cadeiras e mesas
	desenhaPosicao(poste,fonte.dimensoes.x*1,terreno_rua.dimensoes.x*6.5,0);
	desenhaPosicao(poste,fonte.dimensoes.x*1,-terreno_rua.dimensoes.x*6.5,0);

}

void arvores()
{
	// Arvores próximas à fonte
	// Conjunto do lado esquerdo
	desenhaPosicao(arvore1,arvore1.dimensoes.x/2,fonte.dimensoes.z*1.8,0);
	desenhaPosicao(arvore1,-arvore1.dimensoes.x/2,fonte.dimensoes.z*1.4,0);
	desenhaPosicao(pedra_3,arvore1.dimensoes.x/2,fonte.dimensoes.z*1.8-arvore1.dimensoes.z/2-pedra_3.dimensoes.z/2,45);
	// Conjunto do lado direito
	desenhaPosicao(arvore1,arvore1.dimensoes.x/2,-fonte.dimensoes.z*1.8,0);
	desenhaPosicao(arvore1,-arvore1.dimensoes.x/2,-fonte.dimensoes.z*1.4,0);
	desenhaPosicao(pedra_3,-arvore1.dimensoes.x/2,-fonte.dimensoes.z*1.4-arvore1.dimensoes.z/2-pedra_3.dimensoes.z/2,30);
}

void lanchonetes()
{
	desenhaOBJ(lanchonete,180);
	desenhaOBJ(lanchonete1,0);
}

void bancosCadeira()
{
	desenhaPosicao(banco_Cadeira,terreno_rua.dimensoes.z*1.5,terreno_rua.dimensoes.x*7.5,90);
	desenhaPosicao(banco_Cadeira,-terreno_rua.dimensoes.z*1.5,terreno_rua.dimensoes.x*7.5,90);
	desenhaPosicao(banco_Cadeira,terreno_rua.dimensoes.z*1.5,-terreno_rua.dimensoes.x*7.5,90);
	desenhaPosicao(banco_Cadeira,-terreno_rua.dimensoes.z*1.5,-terreno_rua.dimensoes.x*7.5,90);
}

void loading()
{	
        drawObject(loadingO);
	glutSwapBuffers();
}
