void cenarioTeste();

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

		//cenarioTeste();


		// FIM DO TESTE
	//desenhando e rotacionando roda gigante
	auxRotacao+=1;
	glPushMatrix();
		//desenhaOBJ(rodaGG_base);
		glRotatef(auxRotacao,1,0,0);
		desenhaRodaGigante();
	glPopMatrix();
	desenhaInterface();

	if (isLightingOn)
    {
    	glDisable(GL_LIGHTING);
    }

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
    float raio = rodaGG_aro.dimensoes.y/2;
    glPushMatrix();
	    glTranslatef(rodaGG_aro.posicao.x, rodaGG_aro.posicao.y, rodaGG_aro.posicao.z);
	    glPushMatrix();
		    glScalef(rodaGG_aro.dimensoes.x,rodaGG_aro.dimensoes.y,rodaGG_aro.dimensoes.z);
		    glCallList(rodaGG_aro.listaVisualizacao);
	    glPopMatrix();
	    for(i=0; i<CARRINHOS; i++){
		glPushMatrix();
			glTranslatef(raio*cos(angulo)*i, 0, raio*sin(angulo)*i);
			//printf("\n%f %f\n",raio,angulo); //retorna valores corretos
			glScalef(rodaGG_carro.dimensoes.x,rodaGG_carro.dimensoes.y,rodaGG_carro.dimensoes.z);
		    	glCallList(rodaGG_carro.listaVisualizacao);
		glPopMatrix();
	    }
    glPopMatrix();
}

void desenhaOBJ(Objeto3D objeto){
	glPushMatrix();
		glTranslatef(objeto.posicao.x,objeto.posicao.y,objeto.posicao.z);
		glScalef(objeto.dimensoes.x,objeto.dimensoes.y,objeto.dimensoes.z);
	    	glCallList(objeto.listaVisualizacao);
	glPopMatrix();
}

void cenarioTeste(){
		// Teste de Arvore
		desenhaOBJ(teste);

		// Teste de pedra
		desenhaOBJ(pedra);

		// Teste de Terreno com lista
		glPushMatrix();
		glTranslatef(0,-50,0);
		for(int random = -QTDECHAO, auxrandom, random1, auxrandom1 ; random <= QTDECHAO ;random++)
		{
			auxrandom = random*50;
			for(random1 = -QTDECHAO ;random1 <= QTDECHAO; random1++)
			{
				auxrandom1 = random1*50;
				glPushMatrix();
					glTranslatef(auxrandom,0,auxrandom1);
					desenhaOBJ(terreno);
				glPopMatrix();
			}
		}
		glPopMatrix();
}
