// Desenho do jogo
void desenhaMinhaCena()
{
    glMatrixMode(GL_MODELVIEW);
    glColor4f(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if(tela == 0)
    {
	//configuras definitivamente não funcionam
	//configura2D();
        drawObject(wallpaper_menu);
        drawObject(jogar);
        drawObject(controles);
        drawObject(creditos);
        drawObject(sair_menu);
    }

    else if(tela == 1)
    {

	float colorFog[4] = {1.0, 1.0, 1.0, 1}; 
    	glEnable(GL_FOG);
    	glFogi(GL_FOG_MODE, GL_EXP2);    //GL_EXP, GL_EXP2 e GL_LINEAR
    	//glFogf(GL_FOG_START, 100);    //onde começa e termina o fog para GL_LINEAR(-3.00 ate 3.00)
    	//glFogf(GL_FOG_END, 5);
    	glFogf(GL_FOG_DENSITY, 0.005);   //densidade do fog, 0.00 á 3.00
    	glFogfv(GL_FOG_COLOR, colorFog);

	//isso aqui n ta "direito"
	//configura3D();
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

    // Esfera indicativa de onde está a luz
	/*	
	glPushMatrix();
        glTranslatef(20.0, 50.0, 50.0);
        glColor3f(0, 0, 0);
        glutWireSphere(2, 8, 8); 
    	glPopMatrix();
	*/
		
	if (isLightingOn)
	{
        glEnable(GL_LIGHTING);
	}
	    
	glClearColor(1,1,1,1);
	//tirar condicional junto de tudo relacionado a OBJ antes de entregar para professor
	if(OBJ.listaVisualizacao!=0)
		testeOBJ();
	else{
	    	desenhaOBJ(fonte,0);
		pipocas();
		//cercas();
		bancos();
		postes();
		ruas();
		arvores();
		lanchonetes();
		desenhaRodaGigante();
		carrossel();
		torre();
		//interface com problema de não saber configurar 2/3D
		//desenhaInterface();
	}
	chao();

	if (isLightingOn)
    {
    	glDisable(GL_LIGHTING);
    }

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
	//configurar glortho para fzr (PUTA MERDA) e dps reconfigurar persperctive pra quando rodar lá n zuar nd
	configura2D();
        drawObject(jogar);
        drawObject(controles);
}


//FALTA ARRUMAR A RODELA DOS CARRINHOS NOS AROS DA RODA
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

void desenhaOBJ(Objeto3D objeto, float rotacao)
{
	glPushMatrix();
	    	glTranslatef(objeto.posicao.x,objeto.dimensoes.y/2+objeto.posicao.y,objeto.posicao.z);
	    	glScalef(objeto.aumento.x,objeto.aumento.y,objeto.aumento.z);
		glRotatef(rotacao,0,1,0);
	    	glCallList(objeto.listaVisualizacao);
	glPopMatrix();
}

void desenhaPosicao(Objeto3D objeto,float centrox, float centroz, float rotacao)
{
	glPushMatrix();
		glTranslatef(centrox,0,centroz);
		desenhaOBJ(objeto,rotacao);
	glPopMatrix();
}

void chao()
{
		// Terreno
		glPushMatrix();
		for(int random = -QTDECHAO, auxrandom, random1, auxrandom1 ; random <= QTDECHAO ;random++)
		{
			auxrandom = random*terreno.dimensoes.x;
			for(random1 = -QTDECHAO ;random1 <= QTDECHAO; random1++)
			{
				auxrandom1 = random1*terreno.dimensoes.x;
				glPushMatrix();
	    				glTranslatef(auxrandom,0,auxrandom1);
		            		glScalef(terreno.aumento.x,terreno.aumento.y,terreno.aumento.z);
		            		glCallList(terreno.listaVisualizacao);
				glPopMatrix();
			}
		}		
		glPopMatrix();
}

/*
LEMBRETE:
eixo x: altera cima/baixo, sendo positivo levando mais para baixo
eixo z: altera direita/esquerda, sendo positivo levando mais para esquerda
*/

void ruas(){
	glPushMatrix();
		//para ajustar erro terreno-rua
		glTranslatef(0,terreno.dimensoes.y/2,0);

		//ruas em torno da fonte e alongando pros extremos laterais
		//"baixo"
		aux_rua(11,terreno_rua.dimensoes.x*2,-terreno_rua.dimensoes.x*5,0);
		//"cima" fonte -> pipocas
		aux_rua(11,-terreno_rua.dimensoes.x*2,-terreno_rua.dimensoes.x*5,0);
		//"esquerda" brinquedo1 -> brinquedo2
		aux_rua(5,-terreno_rua.dimensoes.x*2,terreno_rua.dimensoes.x*2.5,1);
		//"direita"
		aux_rua(5,-terreno_rua.dimensoes.x*2,-terreno_rua.dimensoes.x*2.5,1);

		//ruas em torno das pipocas
		aux_rua(3,-terreno_rua.dimensoes.x*4,-terreno_rua.dimensoes.x,0);
		aux_rua(2,-terreno_rua.dimensoes.x*3,terreno_rua.dimensoes.x*2,1);
		aux_rua(2,-terreno_rua.dimensoes.x*3,-terreno_rua.dimensoes.x*2,1);

		//ruas centrais levando à brinquedo 3
		aux_rua(7,terreno_rua.dimensoes.x*2,0,1);
		aux_rua(9,-terreno_rua.dimensoes.x*13,0,1);

		//rua brinquedos 1-2
		aux_rua(19,-terreno_rua.dimensoes.x*11,-terreno_rua.dimensoes.x*9,0);

		//rua brinquedos 4-5
		aux_rua(9,-terreno_rua.dimensoes.x*7,-terreno_rua.dimensoes.x*4,0);

		//ruas para "fechar" caixa das arvores
		aux_rua(3,-terreno_rua.dimensoes.x,-terreno_rua.dimensoes.x*6,1);
		aux_rua(3,-terreno_rua.dimensoes.x,terreno_rua.dimensoes.x*6,1);

		//ruas levando para as lanchonetes
		aux_rua(2,0,terreno_rua.dimensoes.x*7,0);
		aux_rua(2,0,-terreno_rua.dimensoes.x*8,0);

		//ruas curvas
		//ruas ao lado da lanchonete, na parte oposta da direção dos brinquedos
		glPushMatrix();
			glTranslatef(terreno_rua.dimensoes.x*2,0,0);
			desenhaPosicao(terreno_rcurva,0,-terreno_rua.dimensoes.x*6,-90);
			desenhaPosicao(terreno_rcurva,0,terreno_rua.dimensoes.x*6,180);
		glPopMatrix();

		//ruas na direção lanchonete -> brinquedos
		glPushMatrix();
			glTranslatef(-terreno_rua.dimensoes.x*2,0,0);
			desenhaPosicao(terreno_rcurva,0,-terreno_rua.dimensoes.x*6,0);
			desenhaPosicao(terreno_rcurva,0,terreno_rua.dimensoes.x*6,90);
		glPopMatrix();

		//ruas próximas à pipoca
		glPushMatrix();
			glTranslatef(-terreno_rua.dimensoes.x*4,0,0);
			desenhaPosicao(terreno_rcurva,0,-terreno_rua.dimensoes.x*2,0);
			desenhaPosicao(terreno_rcurva,0,terreno_rua.dimensoes.x*2,90);
		glPopMatrix();

	glPopMatrix();
}

void cercas(){
	aux_cerca(3,0,0,1);
}

void pipocas(){
	//pipoca da direita
    	desenhaOBJ(pipoca,90);
	//pipoca da esquerda
	desenhaOBJ(pipoca1,-90);
	//pipoca do meio
	desenhaPosicao(pipoca,0,-pipoca.posicao.z,0);
}

void bancos(){
	//bancos horizontais em frente à pipoca
	//banco da direita
	desenhaPosicao(banco,pipoca.posicao.x-terreno_rua.dimensoes.x*2,pipoca.posicao.z-2,90);
	//banco da esquerda
	desenhaPosicao(banco,pipoca.posicao.x-terreno_rua.dimensoes.x*2,pipoca.posicao.z+terreno_rua.dimensoes.x*2+3,90);

	//bancos verticais em frente à pipoca
	//
	desenhaPosicao(banco,pipoca.posicao.x,pipoca.posicao.z-terreno_rua.dimensoes.x*2,0);
	//
	desenhaPosicao(banco,pipoca.posicao.x,pipoca1.posicao.z+terreno_rua.dimensoes.x*2,180);
}

void postes(){
	//postes em torno da fonte
	desenhaPosicao(poste,fonte.dimensoes.x/2-1,fonte.dimensoes.z/2+4,0);
	desenhaPosicao(poste,fonte.dimensoes.x/2-1,-(fonte.dimensoes.z/2+4),0);
	desenhaPosicao(poste,-(fonte.dimensoes.x/2-1),fonte.dimensoes.z/2+4,0);
	desenhaPosicao(poste,-(fonte.dimensoes.x/2-1),-(fonte.dimensoes.z/2+4),0);

	//postes ao lado das cadeiras e mesas
	desenhaPosicao(poste,fonte.dimensoes.x*1,terreno_rua.dimensoes.x*6.5,0);
	desenhaPosicao(poste,fonte.dimensoes.x*1,-terreno_rua.dimensoes.x*6.5,0);

}

void arvores(){
	//arvores próximas à fonte
	//conjunto do lado esquerdo
	desenhaPosicao(arvore1,arvore1.dimensoes.x/2,fonte.dimensoes.z*1.8,0);
	desenhaPosicao(arvore1,-arvore1.dimensoes.x/2,fonte.dimensoes.z*1.4,0);
	desenhaPosicao(pedra_3,arvore1.dimensoes.x/2,fonte.dimensoes.z*1.8-arvore1.dimensoes.z/2-pedra_3.dimensoes.z/2,45);
	//conjunto do lado direito
	desenhaPosicao(arvore1,arvore1.dimensoes.x/2,-fonte.dimensoes.z*1.8,0);
	desenhaPosicao(arvore1,-arvore1.dimensoes.x/2,-fonte.dimensoes.z*1.4,0);
	desenhaPosicao(pedra_3,-arvore1.dimensoes.x/2,-fonte.dimensoes.z*1.4-arvore1.dimensoes.z/2-pedra_3.dimensoes.z/2,30);
}

void lanchonetes(){
	desenhaOBJ(lanchonete,180);
	desenhaOBJ(lanchonete1,0);
}

//FUNCIONAMENTO: desenhará "CAVALOS" cavalos em um raio exterior e os fara subir e descer (pensar em desenhar cavalos em raio interior também)
void carrossel(){
	int i;
	const float anguloRad = (M_PI*2)/CAVALOS;
	const float anguloGra = 360.0/CAVALOS;
	const float raio = carrossel_base.dimensoes.x/2-2;

	auxRotacaoCAR += VELOCIDADE_CAVALO;
	if(auxRotacaoCAR == 360)
		auxRotacaoCAR = 0;

	glPushMatrix();
		//desenhando a base estática
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

void torre(){
	glPushMatrix();
		desenhaOBJ(torreB,90);
		glTranslatef(torreB.posicao.x-3,torreB.posicao.y,torreB.posicao.z-12);
		if(alturaTorre >= torreB.dimensoes.y-13){
			torreParada(1,0.5);
			velTor = -VEL_TORRE;
		}else if(alturaTorre <= torreB.posicao.y){
			torreParada(0,1);
			velTor = VEL_TORRE/5.0;
		}if(torreP <= 0)
			alturaTorre += velTor;
		glTranslatef(0,alturaTorre,0);
		desenhaOBJ(torreC,0);
	glPopMatrix();
	torreP--;
}

void loading(){
}

void testeOBJ(){
	glPushMatrix();
		glScalef(TAMANHO,TAMANHO,TAMANHO);
		glTranslatef(0,OBJ.dimensoes.y/2,0);
		glCallList(OBJ.listaVisualizacao);
	glPopMatrix();
}
