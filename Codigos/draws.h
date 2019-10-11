// Desenho do jogo
void desenhaMinhaCena()
{
    glMatrixMode(GL_MODELVIEW);
    glColor4f(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if(tela == 0)
    {
        drawObject(wallpaper_menu);
        drawObject(jogar);
        drawObject(controles);
        drawObject(creditos);
        drawObject(sair_menu);
    }

    else if(tela == 1)
    {
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

                gluLookAt(0, 0, 200, 0, 0, 0, 0, 1, 0);
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
/*	glPushMatrix();
        glTranslatef(20.0, 50.0, 50.0);
        glColor3f(0, 0, 0);
        glutWireSphere(2, 8, 8); 
    glPopMatrix();
*/
		
	if (isLightingOn)
	{
        glEnable(GL_LIGHTING);
    }
    
		// INICIO DO TESTE
	    	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		glClearColor(1,1,1,1);

		// Teste de Arvore
		desenhaOBJ(teste, testeOBJ);

		// Teste de pedra
		desenhaOBJ(pedra, pedraOBJ);

		// Teste de Terreno com lista
		glPushMatrix();
		glTranslatef(0,-50,0);
		for(int random = -1, auxrandom, random1, auxrandom1 ; random <= 1 ;random++)
		{
			auxrandom = random*50;
			for(random1 = -1 ;random1 <= 1; random1++)
			{
				auxrandom1 = random1*50;
				glPushMatrix();
					glTranslatef(auxrandom,0,auxrandom1);
					desenhaOBJ(terreno,terrenoOBJ);
				glPopMatrix();
			}
		}
		glPopMatrix();

	if (isLightingOn)
    {
    	glDisable(GL_LIGHTING);
    }

		// FIM DO TESTE
	//desenhando e rotacionando roda gigante
	/*
	auxRotacao+=1;
	glPushMatrix();
		glRotate(auxRotacao,0,0,1);
		desenhaRodaGigante();
	glPopMatrix();
	*/
	desenhaInterface();
    }

    else if(tela == 2)
    {

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

void desenhaInterface(){	
        //perguntar como fazer isso
}


void desenhaRodaGigante(){
    int i;
    float angulo = 360/CARRINHOS;
    float raio = rodaGigante.dimensoes.y/2;
    glPushMatrix();
	    glTranslatef(rodaGigante.posicao.x, rodaGigante.posicao.y, rodaGigante.posicao.z);
	    //desenha o aro e base da roda gigante
	    for(i=0; i<CARRINHOS; i++){
		glPushMatrix();
		glTranslatef(raio*cos(angulo)*i, raio*sin(angulo)*i, 0);
		//desenha carrinho
		glPopMatrix();
	    }
    glPopMatrix();
}

void desenhaOBJ(Objeto3D objeto, GLMmodel *model){
	glPushMatrix();
		glTranslatef(objeto.posicao.x,objeto.posicao.y,objeto.posicao.z);
		glScalef(objeto.aumento.x,objeto.aumento.y,objeto.aumento.z);
	    	//glCallList(teste.listaVisualizacao);
		glmDraw(model, GLM_SMOOTH | GLM_TEXTURE | GLM_COLOR);
	glPopMatrix();
}
