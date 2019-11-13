// Callback de Teclado (Apertando)
void teclaPressionada(unsigned char key, int x, int y)
{
    switch(key)
    {

        // Teclas para andar com a camera
        case 'S':
        case 's':

            keyboard[83] = 1;    
            break;

        case 'W':
        case 'w':

            keyboard[87] = 1;         
            break;

        case 'A':
        case 'a':

            keyboard[65] = 1;                
            break;

        case 'D':
        case 'd':

            keyboard[68] = 1;  
            break;

	case 'N':
        case 'n':

            if(fogOn==1)
				fogOn=0;
			else
				fogOn=1;
            break;

		case 'l':
    	case 'L':
        	if(isLightingOn == 0)
            {
				isLightingOn = 1;
			}
			else
            {
				isLightingOn = 0;
			}
        break;

        // As três cameras
        // Camera perspectiva
        case '1':

            if(tela == 1){
				indicadorCamera.textura = loadTexture("../Imagens/interface_camera1.png");
                modoCamera = 1;
				cameraBrinquedos++;
				if(cameraBrinquedos == 6)
					cameraBrinquedos=1;
			}
            break;

        // Camera primeira pessoa
        case '2':

            if(tela == 1){
				indicadorCamera.textura = loadTexture("../Imagens/interface_camera2.png");
                modoCamera = 2;
			}
            break;

        // Camera terceira pessoa
        case '3':

            if(tela == 1){
		indicadorCamera.textura = loadTexture("../Imagens/interface_camera3.png");
		pi = 70.266495;
                modoCamera = 3;
			}
            break;

        //ESC
        case 27 : 

            // Menu
            if(tela == 0)
            {
                exit(0);
            }
            else if(tela == 3 || tela == 1 || tela == 2)
            {
                tela = 0;
				glutSetCursor(GLUT_CURSOR_INHERIT);
		        	glutReshapeWindow(largura,altura);
            }

            else
                exit(0);

            break;
    }   
}

// Callback de Teclado (Soltando)
void teclaSegurada(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'S':
        case 's':

            keyboard[83] = 0;
            break;


        case 'W':
        case 'w':

            keyboard[87] = 0;
            break;

        case 'A':
        case 'a':

            keyboard[65] = 0;
            break;

        case 'D':
        case 'd':

            keyboard[68] = 0;
            break;
    }
}

void movimentacao()
{
    // Tecla w/W        
    if(keyboard[87] == 1) 
    {
        cursor.x -= 0.5;
    }

    // Tecla s/S
    if(keyboard[83] == 1)  
    {
        cursor.x += 0.5;
    }

    // Tecla a/A
    if(keyboard[65] == 1)  
    {
        cursor.z += 0.5;
    }

    // Tecla d/D
    if(keyboard[68] == 1)  
    {
        cursor.z -= 0.5;
    }

}
