// Desenho do jogo
void desenhaMinhaCena()
{
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

        // INICIO DO TESTE

        glClearColor(1,1,1,1);
		
		if (isLightingOn) {
        glEnable(GL_LIGHTING);
    	}

		glPushMatrix();
	    	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);		
		glScalef(50,50,50);
		glmDraw(teste, GLM_SMOOTH | GLM_TEXTURE | GLM_COLOR);
   		glPopMatrix();

		glPushMatrix();
		glTranslatef( 1, -50, 1);		
		glScalef(10,0,10);
		glColor4f(0, 1, 0, 1);
		glmDraw(terreno, GLM_SMOOTH | GLM_TEXTURE | GLM_COLOR);
   		glPopMatrix();

        /*glPushMatrix();
		glColor4f(0, 1, 0, 1);       //começa a desenhar com a cor verde
		glTranslatef(0, -100, 0);   //desenha no ponto Y=-100 para parecer uma mesa para a jarra
		glutSolidCube(100);        //desenha um cubo no ponto (0, -100, 0)
		glColor4f(0, 0, 0, 1);    //começa a desenhar com a cor preta
		glutWireCube(105);       //desenha bordas de um cubo levemente maior
        glPopMatrix();*/

		if (isLightingOn) {
        glDisable(GL_LIGHTING);
    	}
        // FIM DO TESTE

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
}

*/
