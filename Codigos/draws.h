void chao();
void desenhaCentro();
void ruas();
void pipocas();

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
	//desenhaCentro();
    	desenhaOBJ(fonte,0);
	pipocas();
    	desenhaOBJ(cerca,0);
	desenhaOBJ(banco,90);
	desenhaOBJ(banco2,90);
	ruas();
	chao();
	//desenhaRodaGigante();
	//interface com problema de não saber configurar 2/3D
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
	//configurar glortho para fzr (PUTA MERDA) e dps reconfigurar persperctive pra quando rodar lá n zuar nd
	configura2D();
        drawObject(jogar);
        drawObject(controles);
}


void desenhaRodaGigante(){
    int i;
    const float angulo = (M_PI*2)/CARRINHOS;
    const float raio = rodaGG_aro.dimensoes.y/2/*-(ERRO VISUAL)*/;//tem que arrumar isso daqui ainda
    auxRotacao+=VELOCIDADE_RODA;
    if(auxRotacao==360)
    	auxRotacao=0;
    
    //desenhando a base
    glPushMatrix();
    	glTranslatef(rodaGG_aro.posicao.x,rodaGG_aro.posicao.y-rodaGG_aro.dimensoes.y/2,rodaGG_aro.posicao.z);
    	glScalef(rodaGG_base.aumento.x,rodaGG_base.aumento.y,rodaGG_base.aumento.z);
        glCallList(rodaGG_base.listaVisualizacao);
    glPopMatrix();
    
    glPushMatrix();
	    glTranslatef(rodaGG_aro.posicao.x, rodaGG_aro.posicao.y, rodaGG_aro.posicao.z);
        //glRotatef(auxRotacao,1,0,0);

		//desenhando o aro
		glPushMatrix();
			    glScalef(rodaGG_aro.aumento.x,rodaGG_aro.aumento.y,rodaGG_aro.aumento.z);
			    glCallList(rodaGG_aro.listaVisualizacao);
		glPopMatrix();

        glPushMatrix();
            glTranslatef(0, -3.5, 0);
            glPushMatrix();
                //glScalef(100,1,1);
                glScalef(rodaGG_carro.aumento.x,rodaGG_carro.aumento.y,rodaGG_carro.aumento.z);
                glCallList(rodaGG_carro.listaVisualizacao);
            glPopMatrix();
    		for(i=0; i<CARRINHOS; i++){
    			glPushMatrix();
    		    //glRotatef(-auxRotacao,1,0,0); //só para teste, faz os carrinhos não girarem
                glTranslatef(0, raio*cos(angulo*i),raio*sin(angulo*i));
                //glTranslatef(0,-rodaGG_carro.dimensoes.y/2,0);
                glScalef(rodaGG_carro.aumento.x,rodaGG_carro.aumento.y,rodaGG_carro.aumento.z);
                //glRotatef(-auxRotacao,1,0,0);
    			glCallList(rodaGG_carro.listaVisualizacao);
                //glScalef(100,1,1);
                //glCallList(pedra.listaVisualizacao);
    			glPopMatrix();
    		}
        glPopMatrix();
    glPopMatrix();
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

//direcao == 1: eixo z, senão eixo x
//tem q passar o centrox e centroy
void aux_rua(int qtdeQDD, float centrox, float centroz, int direcao){
	if(direcao==1){
		for(int random = 0; random<qtdeQDD ; random++){
			glPushMatrix();
				glTranslatef(centrox,0,centroz);
				glTranslatef(terreno_rua.dimensoes.z*random,0,0);
				desenhaOBJ(terreno_rua,0);
			glPopMatrix();
		}
	}else{
		for(int random = 0; random<qtdeQDD ; random++){
			glPushMatrix();
				glTranslatef(centrox,0,centroz);
				glTranslatef(0,0,terreno_rua.dimensoes.x*random);
				desenhaOBJ(terreno_rua,0);
			glPopMatrix();
		}
	}
}

void ruas(){
	glPushMatrix();
		glTranslatef(0,terreno.dimensoes.y/2,0);
		//ruas em torno da fonte e alongando pros extremos laterais
		aux_rua(13,terreno_rua.dimensoes.x*2,-terreno_rua.dimensoes.x*6,0);
		aux_rua(13,-terreno_rua.dimensoes.x*2,-terreno_rua.dimensoes.x*6,0);
		aux_rua(5,-terreno_rua.dimensoes.x*2,terreno_rua.dimensoes.x*2.5,1);
		aux_rua(5,-terreno_rua.dimensoes.x*2,-terreno_rua.dimensoes.x*2.5,1);

		//ruas em torno das pipocas
		aux_rua(5,-terreno_rua.dimensoes.x*4,-terreno_rua.dimensoes.x*2,0);
		aux_rua(3,-terreno_rua.dimensoes.x*4,terreno_rua.dimensoes.x*2.5,1);
		aux_rua(3,-terreno_rua.dimensoes.x*4,-terreno_rua.dimensoes.x*2.5,1);
/*
		aux_rua(5,-terreno_rua.dimensoes.x*2,-terreno_rua.dimensoes.x*2.5,1);
		aux_rua(5,-terreno_rua.dimensoes.x*2,-terreno_rua.dimensoes.x*2.5,1);*/
	glPopMatrix();
}

void pipocas(){	
    	desenhaOBJ(pipoca,90);
	desenhaOBJ(pipoca1,-90);
}

void desenhaCentro(){
	glPushMatrix();
		glTranslatef(0,0,0);
		glScalef(10,10,10);
		glCallList(pedra_3.listaVisualizacao);
	glPopMatrix();
}
