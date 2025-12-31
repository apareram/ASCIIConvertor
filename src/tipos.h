#ifndef TIPOS_H
#define TIPOS_H

typedef struct {
    unsigned char *pixeles;
    int ancho;
    int alto;
    int canales;
} Imagen;

// Declaraciones de funciones (prototipos)
Imagen cargarImagen(char ruta[]);
void convertirImagen(Imagen img, int ancho);
void liberarImagen(Imagen img);

#endif