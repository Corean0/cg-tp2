// Callback de Teclado (Apertando)
void teclaPressionada(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27 : //ESC

            // Menu
            if(tela == 0)
            {
                exit(0);
            }

            // Tela do Jogo
            if(tela == 1)
            {
                sair = 1;

                if(pause % 2 == 0)
                {
                    pause++;
                }
            }

            if(tela == 2 || tela == 3)
            {
                tela = 0;
            }

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