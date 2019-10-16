
void carregaOBJ(Objeto3D *objeto, GLMmodel* model){
	glmUnitize(model);
	glmFacetNormals(model);
	glmVertexNormals(model, 90.0, 1);
	objeto->listaVisualizacao = glmList(model, GLM_SMOOTH | GLM_TEXTURE | GLM_COLOR);
	free(model);
}

void setDimensoesProp(Objeto3D *objeto,float aumento){
	objeto->dimensoes.x = aumento;
	objeto->dimensoes.y = aumento;
	objeto->dimensoes.z = aumento;
}

void setDimensoesDesprop(Objeto3D *objeto, float x, float y, float z){
	objeto->dimensoes.x = x;
	objeto->dimensoes.y = y;
	objeto->dimensoes.z = z;
}

void setPosicao(Objeto3D *objeto,float x, float y, float z){
	objeto->posicao.x = x;
	objeto->posicao.y = y;
	objeto->posicao.z = z;
}

//Não tenho nem ideia mas to testando pra ver se funciona
void configura3D(){
	glEnable(GL_DEPTH_TEST);
        glViewport (0, 0, largura, altura);
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity();
	gluPerspective(60.0, (float)largura/(float)altura, 0.2, 400.0);     //colocar fovy entre 45.0 e 60.0
	glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    	glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    	glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
   	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void configura2D(){
	glDisable(GL_DEPTH_TEST);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, largura, 0, altura, 0, 1);
        glMatrixMode(GL_MODELVIEW);
}
