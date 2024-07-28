## Esse projeto é uma implementação simples de uma fractal

### Como rodar
Esse projeto é feito em C, então para compila-lo é preciso de um compilador de C, como o `gcc` ou `clang`. Também é feito uso da biblioteca `math.h`, então é preciso incluí-la no momento da compilação.
Deixo aqui alguns comandos para compilar o projeto. Use o compatível com o compilador da sua máquina.

```bash
gcc main.c fractal.c -lm -o fractal
```
Ou
```bash
clang main.c fractal.c -lm -o fractal
```

Para rodar o programa é simples, basta passar como argumento: A largura da imagem, a altura dela, e o número de iterações que o algoritmo terá. Lembrando que quanto mais iterações, mais escura a imagem tende a ser. Quanto maior a largura e altura, mais definida ela é.

```bash
./fractal 1920 1080 100
```
Logo após rodar isso, o programa vai perguntar o nome da imagem onde o fractal será salvo

O resultado do comando acima está aqui:

![result](https://github.com/user-attachments/assets/0a0ff0dd-41c8-4119-853f-636cc07eed1f)

O arquivo gerado é do tipo PPM (extensão `.ppm`). A maioria dos sistemas não deve ter dificuldade em abrir esse tipo de imagem.

Para aprender mais sobre esse formato `portable pixmap format`, [veja aqui](https://en.wikipedia.org/wiki/Netpbm)
