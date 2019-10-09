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

typedef struct Roda_GG
{
	vetorR3 dimensoes;
	vetorR3 posicao;
	float raio;

} Roda_GG;
