// Callback de Teclado (Apertando)
void teclaPressionada(unsigned char key, int x, int y)
{
    switch(key)
    {
        // Teclas para andar com a camera
        case 'S':
        case 's':

            if(tela == 1)
                xCursor++;
            break;

        case 'W':
        case 'w':

            if(tela == 1)
                xCursor--;
            break;

        case 'A':
        case 'a':

            if(tela == 1)
                zCursor++;
            break;

        case 'D':
        case 'd':

            if(tela == 1)
                zCursor--;
            break;

        // As três cameras
        // Camera perspectiva
        case '1':

            if(tela == 1)
                modoCamera = 1;
            break;

        // Camera primeira pessoa
        case '2':

            if(tela == 1)
                modoCamera = 2;
            break;

        // Camera terceira pessoa
        case '3':

            if(tela == 1)
                modoCamera = 3;
            break;

        //ESC
        case 27 : 

            // Menu
            if(tela == 0)
            {
                exit(0);
            }
            else if(tela == 3)
            {
                tela = 0;
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
        
    }
}