// FUNCIONAMENTO: desenhará "CAVALOS" cavalos em um raio exterior e os fara subir e descer (pensar em desenhar cavalos em raio interior também)
void carrossel()
{
	int i;
	const float anguloRad = (M_PI*2)/CAVALOS;
	const float anguloGra = 360.0/CAVALOS;
	const float raio = carrossel_base.dimensoes.x/2-2;

	auxRotacaoCAR += VELOCIDADE_CAVALO;
	if(auxRotacaoCAR == 360)
		auxRotacaoCAR = 0;

	glPushMatrix();
		// Desenhando a base estática
		desenhaOBJ(carrossel_base,0);

		glPushMatrix();
			glTranslatef(carrossel_base.posicao.x,carrossel_base.posicao.y+carrossel_base.dimensoes.y/2/*ERRO*/-5,carrossel_base.posicao.z);
			glRotatef(auxRotacaoCAR,0,1,0);
			for(i=0;i<CAVALOS;i++){
				glPushMatrix();
					if(alturaCavalo[i] > AMP_CAVALO  && velAlt[i] > 0)
						velAlt[i] = -CONSTANTE;
					else if(alturaCavalo[i] < -AMP_CAVALO && velAlt[i] < 0)
						velAlt[i] = CONSTANTE;
					alturaCavalo[i] = alturaCavalo[i]+velAlt[i];
					glTranslatef(0,alturaCavalo[i],0);
					glTranslatef(sin(anguloRad*i)*raio,0,cos(anguloRad*i)*raio);
					glRotatef(-auxRotacaoCAR,0,1,0);
				    	glScalef(carrossel_cavalo.aumento.x,carrossel_cavalo.aumento.y,carrossel_cavalo.aumento.z);
					glRotatef(-90,0,1,0);
				    	glCallList(carrossel_cavalo.listaVisualizacao);
				glPopMatrix();
			}
		glPopMatrix();
		
	glPopMatrix();
}

void torre()
{
	glPushMatrix();
		desenhaOBJ(torreB,90);
		glTranslatef(torreB.posicao.x-3,torreB.posicao.y,torreB.posicao.z-12);
		if(alturaTorre >= torreB.dimensoes.y-13)
		{
			torreParada(1,1.5);
			velTor = -VEL_TORRE;
		}
		else if(alturaTorre <= torreB.posicao.y)
		{
			torreParada(0,3);
			velTor = VEL_TORRE/10.0;
		}
		if(torreP <= 0)
		{
			torreP = 0;
			alturaTorre += velTor;
		}
		else{
			torreP--;
		}
		glTranslatef(0,alturaTorre,0);
		desenhaOBJ(torreC,0);
	glPopMatrix();
}

void xicaras_malucas()
{
	const float angulo = (M_PI*2)/(float)XICARAS;
	const float raio = XM_base.dimensoes.z/2-7;

	auxRotacaoX += VEL_XICARA;
	if(auxRotacaoX == 360)
		auxRotacaoX = 0;

	glPushMatrix();
		desenhaOBJ(XM_base,0);
		glTranslatef(XM_base.posicao.x,XM_base.posicao.y+0.6,XM_base.posicao.z);
		glRotatef(auxRotacaoX,0,1,0);
		for(int i=0; i<XICARAS; i++){
			glPushMatrix();
			glTranslatef(sin(angulo*i)*raio,0,cos(angulo*i)*raio);
			glRotatef(-auxRotacaoX,0,1,0);
			if(randomX<=180);
			else
			{
				if(rand()%2 == 0)
				{
					rotacaoXX[i] = VEL_XX;
				}
				else
				{
					rotacaoXX[i] = -VEL_XX;
				}
				if(i == XICARAS)
				{
					randomX = 0;
				}
			}
			rotacaoXXX[i] += rotacaoXX[i];
			glRotatef(rotacaoXXX[i],0,1,0);
			desenhaOBJ(XM_xicara,0);
			glPopMatrix();
		}
	glPopMatrix();
	randomX++;
}

// FALTA ARRUMAR A RODELA DOS CARRINHOS NOS AROS DA RODA
void desenhaRodaGigante(){
    int i;
    const float angulo = (M_PI*2)/CARRINHOS;
    const float raio = rodaGG_aro.dimensoes.y/2/*-ERRO VISUAL*/;//tem que arrumar isso daqui ainda
//printf("%f %f %f\n", rodaGG_aro.dimensoes.x,rodaGG_aro.dimensoes.y,rodaGG_aro.dimensoes.z); //valores corretos disso e do aro
    auxRotacaoRGG+=VELOCIDADE_RODA;
    if(auxRotacaoRGG==360)
    	auxRotacaoRGG=0;
    
    glPushMatrix();
	    glRotatef(180,0,1,0);
	    //desenhando a base
	    desenhaOBJ(rodaGG_base,0);
	    
	    glPushMatrix();
		    	glTranslatef(rodaGG_base.posicao.x-2, rodaGG_base.posicao.y+rodaGG_base.dimensoes.y/2+rodaGG_aro.dimensoes.y/2/*-ERRO VISUAL*/-7.4, rodaGG_base.posicao.z);
			glRotatef(auxRotacaoRGG,1,0,0);

			//desenhando o aro
			glPushMatrix();
				    glScalef(rodaGG_aro.aumento.x,rodaGG_aro.aumento.y,rodaGG_aro.aumento.z);
				    glCallList(rodaGG_aro.listaVisualizacao);
			glPopMatrix();
			
			//ajusta centro da circunferencia com centro do encaixe do carrinho(funcionando)
			//glRotatef(-auxRotacaoRGG,1,0,0);
			//glTranslatef(0,-rodaGG_carro.dimensoes.y/*ERROVISUAL*/+9,0);
			//desenhaOBJ(rodaGG_carro,0);
			//desenhaOBJ(pedra_3,0); //testa centro coincidente ou não
			//glRotatef(auxRotacaoRGG,1,0,0);
			

		    	for(i=0; i<CARRINHOS; i++){
		    		glPushMatrix();
					//não sei pq mas tem um erro q o centro não ta ajustado e esse translate arruma
					//glRotatef(-auxRotacaoRGG,1,0,0);
					glTranslatef(0, raio*sin(angulo*i+M_PI/18.0),raio*cos(angulo*i+M_PI/18.0));					
					glScalef(rodaGG_carro.aumento.x,rodaGG_carro.aumento.y,rodaGG_carro.aumento.z);
					glRotatef(-auxRotacaoRGG,1,0,0);
					glCallList(rodaGG_carro.listaVisualizacao);
					//glScalef(100,1,1);
					//glCallList(pedra_3.listaVisualizacao);
		    		glPopMatrix();
		    	}
	    glPopMatrix();    
    glPopMatrix();
}
