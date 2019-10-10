
void carregaOBJ(Objeto3D objeto, GLMmodel* model){
	glmUnitize(model);
	glmFacetNormals(model);
	glmVertexNormals(model, 90.0, 1);
	float dimensions[3];
	glmDimensions(model, dimensions);
	objeto.dimensoes.x = dimensions[0];
	objeto.dimensoes.y = dimensions[1];
	objeto.dimensoes.z = dimensions[2];
	objeto.listaVisualizacao = glmList(model, GLM_SMOOTH | GLM_TEXTURE);
}
