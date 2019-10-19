void chao();

// Desenho do jogo
void desenhaMinhaCena()
{
    glMatrixMode(GL_MODELVIEW);
    glColor4f(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if(tela == 0)
    {
	//configuras definitivamente não funcionam
	//configura2D();
        drawObject(wallpaper_menu);
        drawObject(jogar);
        drawObject(controles);
        drawObject(creditos);
        drawObject(sair_menu);
    }

    else if(tela == 1)
    {
	//isso aqui n ta "direito"
	//configura3D();
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
    desenhaOBJ(fonte);
    desenhaOBJ(pipoca);
    //desenhaOBJ(cerca);
	chao();
	//desenhaRodaGigante();
	//interface com problema tb
	//desenhaInterface();

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
	//configurar glortho para fzr (PUTA MERDA) e dps reconfigurar persperctive pra quando rodar lá n zuar nd
	configura2D();
        drawObject(jogar);
        drawObject(controles);
}


void desenhaRodaGigante(){
    int i;
    const float angulo = (M_PI*2)/CARRINHOS;
    const float raio = rodaGG_aro.dimensoes.y-3/*-(ERRO VISUAL)*/;//tem que arrumar isso daqui ainda
    auxRotacao+=VELOCIDADE_RODA;
    if(auxRotacao==360)
    	auxRotacao=0;
    
    //desenhando a base
    glPushMatrix();
    	glTranslatef(rodaGG_aro.posicao.x,rodaGG_aro.posicao.y-rodaGG_aro.dimensoes.y,rodaGG_aro.posicao.z);
    	glScalef(rodaGG_base.dimensoes.x,rodaGG_base.dimensoes.y,rodaGG_base.dimensoes.z);
        //glCallList(rodaGG_base.listaVisualizacao);
    glPopMatrix();
    
    glPushMatrix();
	    glTranslatef(rodaGG_aro.posicao.x, rodaGG_aro.posicao.y, rodaGG_aro.posicao.z);
        //glRotatef(auxRotacao,1,0,0);

		//desenhando o aro
		glPushMatrix();
			    glScalef(rodaGG_aro.dimensoes.x,rodaGG_aro.dimensoes.y,rodaGG_aro.dimensoes.z);
			    glCallList(rodaGG_aro.listaVisualizacao);
		glPopMatrix();

        glPushMatrix();
            glTranslatef(0, -3.5, 0);
            glPushMatrix();
                //glScalef(100,1,1);
                glScalef(rodaGG_carro.dimensoes.x,rodaGG_carro.dimensoes.y,rodaGG_carro.dimensoes.z);
                glCallList(rodaGG_carro.listaVisualizacao);
            glPopMatrix();
    		for(i=0; i<CARRINHOS; i++){
    			glPushMatrix();
    		    //glRotatef(-auxRotacao,1,0,0); //só para teste, faz os carrinhos não girarem
                glTranslatef(0, raio*cos(angulo*i),raio*sin(angulo*i));
                //glTranslatef(0,-rodaGG_carro.dimensoes.y/2,0);
                glScalef(rodaGG_carro.dimensoes.x,rodaGG_carro.dimensoes.y,rodaGG_carro.dimensoes.z);
                //glRotatef(-auxRotacao,1,0,0);
    			glCallList(rodaGG_carro.listaVisualizacao);
                //glScalef(100,1,1);
                //glCallList(pedra.listaVisualizacao);
    			glPopMatrix();
    		}
        glPopMatrix();
    glPopMatrix();
}

void desenhaOBJ(Objeto3D objeto)
{
	glPushMatrix();
    	glTranslatef(objeto.posicao.x,objeto.posicao.y,objeto.posicao.z);
    	glScalef(objeto.dimensoes.x,objeto.dimensoes.y,objeto.dimensoes.z);
    	glCallList(objeto.listaVisualizacao);
	glPopMatrix();
}

void chao()
{
		// Terreno
		glPushMatrix();
		for(int random = -QTDECHAO, auxrandom, random1, auxrandom1 ; random <= QTDECHAO ;random++)
		{
			auxrandom = random*terreno.dimensoes.x*2;
			for(random1 = -QTDECHAO ;random1 <= QTDECHAO; random1++)
			{
				auxrandom1 = random1*terreno.dimensoes.x*2;
				glPushMatrix();
    				glTranslatef(auxrandom,-TAMANHO/2,auxrandom1);
                    glScalef(terreno.dimensoes.x,terreno.dimensoes.y,terreno.dimensoes.z);
                    glCallList(terreno.listaVisualizacao);
				glPopMatrix();
			}
		}		
		glPopMatrix();
}
