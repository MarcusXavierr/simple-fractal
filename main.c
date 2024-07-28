#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "fractal.h"
#define MAX_INPUT_SIZE 256

int main(int argc, const char* argv[argc + 1]) {
    if (argc < 4) {
        printf("Uso: %s largura altura numero-iterações\n", argv[0]);
        printf("Todos os valores são números inteiros e positivos. A largura e altura são o tamanho da imagem gerada em pixels\n");
        printf("Exemplo: %s 1080 720 200\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t width, height, iterations;
    width = atoi(argv[1]);
    height = atoi(argv[2]);
    iterations = atoi(argv[3]);

    char filename[MAX_INPUT_SIZE];
    printf("Escreva o nome do arquivo: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    Mandelbrotset options = make_struct(width, height, iterations);
    FractalImageBitMap bitmap = render_fractal(options);


    save_fractal(options, bitmap, filename);

    return EXIT_SUCCESS;
}
