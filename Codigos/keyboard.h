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

        // Case Sensitive para todas as letras utilizadas
        // Alterando a "Possibilidade de Movimento" para verdadeira

        case 'W' :
        case 'w' :

            keyboard[87] = 1;
            break;

        case 'S' :
        case 's' :

            keyboard[83] = 1;
            break;

        case 'O' :
        case 'o' :

            keyboard[111] = 1;
            break;

        case 'L' :
        case 'l' :

            keyboard[108] = 1;
            break;

        // Pausando
        case 'P' :
        case 'p' :

            if(reset != 1 && sair != 1)
            {
                pause++;
                break;
            }

        // Tela de reset
        case 'R' :
        case 'r' :

            if(sair != 1 && pause != 1)
            {
                reset = 1;

                if(pause % 2 == 0)
                {
                    pause++;
                }
                break;
            }
    }   
}

// Callback de Teclado (Soltando)
void teclaSegurada(unsigned char key, int x, int y)
{
    switch(key)
    {
        // Case Sensitive para todas as letras utilizadas
        // Alterando a "Possibilidade de Movimento" para falsa

        case 'W' :
        case 'w' :

            keyboard[87] = 0;
            break;

        case 'S' :
        case 's' :

            keyboard[83] = 0;
            break;

        case 'O' :
        case 'o' :

            keyboard[111] = 0;
            break;

        case 'L' :
        case 'l' :

            keyboard[108] = 0;
            break;
    }
}