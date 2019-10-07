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
    GLuint textura;

} spriteObject;

// Objetos animados
typedef struct Objeto_Animado
{
	vetorR2 posicao;
	vetorR2 dimensoes;
	vetorR2 movimento;
	float frequencia_atual;
	float frequencia_animacao;
	GLuint textura;
	double proporcaoSprite;

} spriteOb_Animado_s;

typedef struct Roda_GG
{
	vetorR2 dimensoes;
	vetorR2 posicao;
	float raio;
	//sla oq mais bicho me mata
} Roda_GG;
