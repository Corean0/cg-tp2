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
	//sla oq mais bicho me mata
} Roda_GG;

// p/ carregar .obj
typedef struct coords {
    float v[4];
} ponto, vetor, cor;

struct material {
    char nome[100];
    cor ambiente;
    cor difusa;
    cor especular;
    cor emissiva;
    float expoenteEspecularidade;
    float opacidade;
};

struct no {
    void *conteudo;
    struct no *proximo;
};

typedef struct lista {
    struct no *primeiro, *ultimo;
    int tamanho;
}listaEncadeada;

struct vertice {
    ponto *coordenada;
    ponto *coordenadaTextura;
    vetor *normal;
};

struct face {
    // no: (struct vertice)
    listaEncadeada vertices;
};

struct malha {
    // no: (struct face)
    listaEncadeada faces;
    // no: (struct ponto)
    listaEncadeada coordenadas;
    // no: (struct ponto)
    listaEncadeada coordenadasTextura;
    // no: (struct vetor)
    listaEncadeada normais;
};

struct modelo {
    struct malha malha;
    listaEncadeada materiais;
    listaEncadeada grupos;

    int listaVisualizacao;
};

struct grupo {
    char* nome;
    struct material* material;
    listaEncadeada faces;
};
