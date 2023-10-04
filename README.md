# 42cursus-06-Pipex
<p align="center">
	<a href="#"><img src="https://game.42sp.org.br/static/assets/achievements/pipexn.png"/></a>
</p>

Este projeto permitirá que você descubra em detalhes um mecanismo UNIX que você já conhece ao utilizá-lo em seu programa.

**Requisitos**

Esse projeto deve obedecer às seguintes regras:
• Terá um Makefile que irá compilar seus arquivos fonte. Não deve ser religado.

Para compilar, use o comando:
```bash
make
```

• O projeto precisa lidar com os erros minuciosamente. De forma alguma seu programa deve encerrar inesperadamente (falha de segmentação, erro de barramento, liberação dupla e assim por diante).

• Seu programa não deve ter vazamentos de memória.

• Deve tratar os erros como o comando shell:

```bash
< file1 cmd1 | cmd2 > file2
```

Para testar, crie um arquivo com o nome `input` na raiz do repositório. (O arquivo outfile não é necessário, se ele já existir na pasta, será sobrescrito pelo programa)

Use o seguinte formato de comando:
```bash
./pipex input "sort" "grep ea" output
```

Para entender mais sobre casos de testes desse comando, acesse a aba Actions