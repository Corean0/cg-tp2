// Função de carregar texturas
GLuint loadTexture(const char* arquivo)
{
    GLuint idTextura = SOIL_load_OGL_texture(arquivo, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

    if (idTextura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

    return idTextura;
}

// Reshape
void redimensiona(int w, int h)
{
    largura = w;
    altura = h;

    switch(tela)
    {
        case 0:
        case 2:
        case 3:

            glDisable(GL_DEPTH_TEST);
            glViewport(0, 0, w, h);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(0, w, 0, h, -1, 1);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            break;

        case 1:

            glEnable(GL_DEPTH_TEST);
            glViewport (0, 0, w, h);
            glMatrixMode (GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(60.0, (float)w/(float)h, 0.2, 350.0);     //colocar fovy entre 45.0 e 60.0
            glMatrixMode(GL_MODELVIEW);
            //begin3d();
            break;
    }

}
// Atualiza a cena
void refresh(int delay)
{
    // Atualiza as posições
    attPosicao();
    
    // Redesenha
    glutPostRedisplay();

    // Registra a callback novamente
    glutTimerFunc(delay, refresh, 10);
}

void begin3d()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mKd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mKs);
    glMaterialfv(GL_FRONT, GL_EMISSION, mKe);
    //glMaterialfv(GL_FRONT, GL_SHININESS, matShine);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}
