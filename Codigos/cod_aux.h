
void carregaOBJ(Objeto3D *objeto, GLMmodel* model){
	glmUnitize(model);
	glmFacetNormals(model);
	glmVertexNormals(model, 90.0, 1);
	float dimensions[3];
	glmDimensions(model, dimensions);
	objeto->dimensoes.x = dimensions[0];
	objeto->dimensoes.y = dimensions[1];
	objeto->dimensoes.z = dimensions[2];
	objeto->listaVisualizacao = glmList(model, GLM_SMOOTH | GLM_TEXTURE);
}

void aumentoProporcional(Objeto3D *objeto,float aumento){
	objeto->aumento.x = aumento;
	objeto->aumento.y = aumento;
	objeto->aumento.z = aumento;
}

void aumentoDesproporcional(Objeto3D *objeto, float x, float y, float z){
	objeto->aumento.x = x;
	objeto->aumento.y = y;
	objeto->aumento.z = z;
}

void setPosicao(Objeto3D *objeto,float x, float y, float z){
	objeto->posicao.x = x;
	objeto->posicao.y = y;
	objeto->posicao.z = z;
}
