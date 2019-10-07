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
            if(tela == 3)
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