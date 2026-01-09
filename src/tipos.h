#include <stdio.h>
// #define STB_IMAGE_IMPLEMENTATION
#include "../lib/stb_image.h"
#include <string.h>

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