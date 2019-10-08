
void iniciaMalha(struct malha *m)
{
    iniciaLista(&m->faces);
    iniciaLista(&m->coordenadas);
    iniciaLista(&m->coordenadasTextura);
    iniciaLista(&m->normais);
}

void adicionaCoordenadaMalha(struct malha *m, ponto *coordenada)
{
    adicionaNoFinalLista(&(m->coordenadas), coordenada);
}

void adicionaCoordenadaTexturaMalha(struct malha *m, ponto *coordenadaTextura)
{
    adicionaNoFinalLista(&m->coordenadasTextura, coordenadaTextura);
}

void adicionaNormalMalha(struct malha *m, vetor *normal)
{
    adicionaNoFinalLista(&m->normais, normal);
}

struct face *novaFaceMalha(struct malha *m)
{
    struct face *novaFace = (struct face*) malloc(sizeof(struct face));
    iniciaLista(&novaFace->vertices);
    adicionaNoFinalLista(&m->faces, novaFace);
    return novaFace;
}

void adicionaVerticeFace(struct malha *m, struct face *f, int indiceCoordenada,
    int indiceCoordenadaTextura, int indiceNormal)
{
    struct vertice *vertice = (struct vertice*) malloc(sizeof(struct vertice));

    vertice->coordenada = (ponto*)recuperaEnesimoNo(&m->coordenadas, indiceCoordenada);

    vertice->coordenadaTextura = NULL;
    if (indiceCoordenadaTextura > 0)
    {
        vertice->coordenadaTextura = (ponto*) recuperaEnesimoNo(&m->coordenadasTextura,
            indiceCoordenadaTextura);
    }

    vertice->normal = NULL;
    if (indiceNormal > 0)
    {
        vertice->normal = (vetor*) recuperaEnesimoNo(&m->normais, indiceNormal);
    }

    adicionaNoFinalLista(&f->vertices, vertice);
}