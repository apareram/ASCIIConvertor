#define STB_IMAGE_IMPLEMENTATION
#include "../lib/stb_image.h"
#include "tipos.h"
#include <stdio.h>

const char* ASCII_CHARS = " .:-=+*#%@";

Imagen cargarImagen(char ruta[]) {
    Imagen img;
    img.pixeles = stbi_load(ruta, &img.ancho, &img.alto, &img.canales, 1);
    
    if (img.pixeles == NULL) {
        printf("Error: No se pudo cargar la imagen '%s'\n", ruta);
    }
    return img;
}

void convertirImagen(Imagen img, int anchoMax) {
    if (img.pixeles == NULL) return;

    int escala = 1;
    if (img.ancho > anchoMax) {
        escala = img.ancho / anchoMax;
    }

    for (int y = 0; y < img.alto; y += (escala * 2)) {
        for (int x = 0; x < img.ancho; x += escala) {
            
            int index = y * img.ancho + x;
            unsigned char brillo = img.pixeles[index];
            
            int char_index = brillo * 9 / 255;
            putchar(ASCII_CHARS[char_index]);
        }
        putchar('\n');
    }
}

void liberarImagen(Imagen img) {
    stbi_image_free(img.pixeles);
}