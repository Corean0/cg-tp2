
void carregaOBJ(Objeto3D *objeto, GLMmodel* model){
	glmUnitize(model);
	glmFacetNormals(model);
	glmVertexNormals(model, 90.0, 1);
	objeto->listaVisualizacao = glmList(model, GLM_SMOOTH | GLM_TEXTURE | GLM_COLOR);
	model = NULL;
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
