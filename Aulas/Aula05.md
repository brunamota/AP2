# Aula 05 - Introdução à Programação Modular em C e Importância

## O que é Programação Modular?

Programação modular é uma abordagem que divide um programa em partes menores e independentes, chamadas de módulos. Cada módulo é responsável por uma parte específica da funcionalidade do programa.

### Características da Programação Modular

- **Divisão de Tarefas**: O programa é dividido em módulos que podem ser desenvolvidos, testados e mantidos separadamente.
- **Reutilização de Código**: Módulos podem ser reutilizados em diferentes partes do programa ou em projetos diferentes.
- **Facilidade de Manutenção**: Alterações em um módulo têm pouco ou nenhum impacto sobre outros módulos.

## Benefícios da Programação Modular

### Organização do Código

A modularidade ajuda a manter o código organizado, facilitando a navegação e a compreensão da estrutura do programa.

### Reutilização

Módulos podem ser reutilizados em outros projetos, economizando tempo e esforço de desenvolvimento.

### Facilita o Trabalho em Equipe

Vários desenvolvedores podem trabalhar em diferentes módulos simultaneamente, reduzindo conflitos e melhorando a colaboração.

### Testes e Depuração

Módulos podem ser testados individualmente, o que facilita a identificação e correção de erros. Isso resulta em um processo de depuração mais eficiente.

### Escalabilidade

A modularidade permite que novos módulos sejam adicionados ao programa sem a necessidade de reescrever o código existente, tornando o software mais escalável.

## Princípios da Programação Modular

### Encapsulamento

Os detalhes de implementação de um módulo devem ser ocultados. Apenas a interface pública deve ser exposta.

### Coesão

Um módulo deve ser altamente coeso, ou seja, todos os seus componentes devem estar relacionados e contribuir para uma única funcionalidade.

### Acoplamento

Os módulos devem ser fracamente acoplados, minimizando as dependências entre eles.

## Exemplo de Programação Modular em C

### Exercício

Vamos criar um simples módulo de calculadora, que terá funções para soma, subtração, multiplicação e divisão.

- **calculadora.h** (arquivo de cabeçalho)
- **main.c** (arquivo principal)

### Código

[Calculadora](https://github.com/brunamota/AP2/tree/main/Listas/Calculadora)
