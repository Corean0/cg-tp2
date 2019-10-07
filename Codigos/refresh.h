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

    glDisable(GL_DEPTH_TEST);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Atualiza a cena
void refresh(int delay)
{
    // Redesenha
    glutPostRedisplay();

    // Registra a callback novamente
    glutTimerFunc(delay, refresh, delay);
}