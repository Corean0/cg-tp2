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
		
	if (isLightingOn) {
        	glEnable(GL_LIGHTING);
    	}else
		glDisable(GL_LIGHTING);
	
		// INICIO DO TESTE

		glClearColor(1,1,1,1);

			glPushMatrix();
			    	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);		
				glScalef(50,50,50); // semelhante à fzr glmScale(50); na setup
				glmDraw(teste, GLM_SMOOTH | GLM_TEXTURE | GLM_COLOR);				
	   		glPopMatrix();

			//começa a lagar se desenha um chão grande, tem q ver com coutinho formas de resolver
			glPushMatrix();
				glTranslatef( 0, -50, 0);
				int random, auxrandom, random1, auxrandom1;
				for(random=-1;random<=1;random++){
					auxrandom = random*50;
					for(random1=-1;random1<=1;random1++){
						auxrandom1 = random1*50;
						glPushMatrix();
						glTranslatef(auxrandom,0,auxrandom1);
						glmDraw(terreno, GLM_SMOOTH |GLM_TEXTURE | GLM_COLOR);
						glPopMatrix();
					}
				}
			glPopMatrix();

		// FIM DO TESTE
	
	anguloRotacao+=1;
	/*glPushMatrix();
		glRotate(anguloRotacao,0,0,1);
		desenhaRodaGigante();
	glPopMatrix();
	desenhaInterface();*/
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

/*
void desenhaRodaGigante(){
    int i;
    float angulo = 360/CARRINHOS;
    glPushMatrix();
	    glTranslatef(rodaGigante.posicao.x, rodaGigante.posicao.y, rodaGigante.posicao.z);
	    //desenha o aro e base da roda gigante
	    for(i=0, i<qtdeCarrinhos, i++){
		int aux = i+1;
		glPushMatrix();
		glTranslatef(rodaGigante.raio*cos(angulo)*aux, rodaGigante.raio*sin(angulo)*aux, rodaGigante.posicao.z);
		//desenha carrinho
		glPopMatrix();
	    }
    glPopMatrix();
}*/
