#include "tipos.h"
#define STB_IMAGE_IMPLEMENTATION

const char* ASCII_CHARS = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

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

    int num_caracteres = strlen(ASCII_CHARS);

    for (int y = 0; y < img.alto; y += (escala * 2)) {
        for (int x = 0; x < img.ancho; x += escala) {
            unsigned char brillo = img.pixeles[y * img.ancho + x];
            
            // Fórmula general: (brillo / 255.0) * (cantidad_caracteres - 1)
            int char_index = (brillo * (num_caracteres - 1)) / 255;
            
            putchar(ASCII_CHARS[char_index]);
        }
        putchar('\n');
    }
}

void liberarImagen(Imagen img) {
    stbi_image_free(img.pixeles);
}