#include "tipos.h"

int main(int argc, char** argv) {
    char rutaImag[100];
    int ancho = 100;
    
    printf("Dame la ruta de tu imagen: ");
    scanf("%s", rutaImag);
    
    Imagen imag = cargarImagen(rutaImag);
    
    if (imag.pixeles != NULL) {
        convertirImagen(imag, ancho);
        liberarImagen(imag);
    }

    return 0;
}