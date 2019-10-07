// Desenho do jogo
void desenhaMinhaCena()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    if(tela == 0)
    {
        drawObject(wallpaper_menu);
        drawObject(jogar);
        drawObject(controles);
        drawObject(creditos);

        sair.posicao.x = largura/2 + largura/3 - largura/20;
        sair.posicao.y = altura/4;
        drawObject(sair);
    }

    if(tela == 1)
    {

    }

    if(tela == 2)
    {

    }

    if(tela == 3)
    {
        drawObject(wallpaper_creditos);

        sair.posicao.x = largura/2 + largura/3;
        sair.posicao.y = altura/4;
        drawObject(sair);
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