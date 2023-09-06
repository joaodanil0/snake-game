# snake-game

> Video1: https://www.youtube.com/watch?v=AxrQje7V65o&t=1178s <br>
> Video2: https://www.youtube.com/watch?v=MH6QlYJ2SwU&list=PL2U2TQ__OrQ_TV2-wuHqGaK8qlnxgKUvK

## Comentarios

A primeira vista, a ideia era apenas fazer o jogo da cobrinha no terminal. Consegui montar o tabuleiro e até adicionar a maçã em um lugar aleatório dentro do tabuleiro.

Quando fui criar a cobrinha em si, começei a me deparar com o problema de atualização de terminal (*frame per second*), inicialmente me basei em um video que foi utilizado o windows (biblioteca conio.h) e ai começaram os problemas. Com um pouco de pesquisa, percebi que o equivalente ao conio.h do windows existia o ncurses.h. Eu já sabia que essa biblioteca era muito utilizada para isso, pricipalmente para usar o menuconfig do kernel, mas nunca tinha precisado utili-la diretamente.