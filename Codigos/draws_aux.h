/*
LEMBRETE:
Eixo x: altera cima/baixo, sendo positivo levando mais para baixo
Eixo z: altera direita/esquerda, sendo positivo levando mais para esquerda
*/

// Direcao == 1: eixo z
// Direcao == 0: eixo x
// Parametros: centrox e centroy
void aux_rua(int qtdeQDD, float centrox, float centroz, int direcao){
	if(direcao == 1)
	{
		for(int random = 0; random<qtdeQDD ; random++)
		{
			glPushMatrix();
				glTranslatef(terreno_rua.dimensoes.z*random,0,0);
				desenhaPosicao(terreno_rua,centrox,centroz,0);				
			glPopMatrix();
		}
	}
	else
	{
		for(int random = 0; random<qtdeQDD ; random++)
		{
			glPushMatrix();
				glTranslatef(0,0,terreno_rua.dimensoes.x*random);
				desenhaPosicao(terreno_rua,centrox,centroz,0);
			glPopMatrix();
		}
	}
}

// Altura = 1 Topo
// Altura = 0 Base
void torreParada(int altura, float tempo)
{
	if(altura == 1)
	{
		alturaTorre = torreB.dimensoes.y-13.1;
	}
	else if(altura == 0)
	{
		alturaTorre = torreB.posicao.y+0.01;
	}

	torreP = tempo*30;
}
