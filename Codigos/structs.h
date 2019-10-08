// Struct de x e y
typedef struct vetorR3
{
    float x;
    float y;
    float z;

} vetorR3;

// Objetos não animados
typedef struct spriteObject
{
    vetorR3 posicao;
    vetorR3 dimensoes;
    GLuint textura;

} spriteObject;

// Objetos animados
typedef struct Objeto_Animado
{
	vetorR3 posicao;
	vetorR3 dimensoes;
	vetorR3 movimento;
	float frequencia_atual;
	float frequencia_animacao;
	GLuint textura;
	double proporcaoSprite;

} spriteOb_Animado_s;

typedef struct Roda_GG
{
	vetorR3 dimensoes;
	vetorR3 posicao;
	float raio;
	//sla oq mais bicho me mata
} Roda_GG;
