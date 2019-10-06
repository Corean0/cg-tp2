// Struct de x e y
typedef struct vetorR2
{
    float x;
    float y;

} vetorR2;

// Objetos não animados
typedef struct spriteObject
{
    vetorR2 posicao;
    vetorR2 dimensoes;
    int textura;

} spriteObject;

// Objetos animados
typedef struct Objeto_Animado
{
	vetorR2 posicao;
	vetorR2 dimensoes;
	vetorR2 movimento;
	float frequencia_atual;
	float frequencia_animacao;
	int textura;
	double proporcaoSprite;

} spriteOb_Animado_s;
