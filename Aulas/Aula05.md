# Aula 05 - Análise de Estruturas: `structs` e Classes (Java)

## 2.2. Classes em Java

### O que são Classes?

- Classes em Java são um conceito fundamental da programação orientada a objetos, permitindo a definição de tipos de dados que incluem tanto atributos (dados) quanto métodos (funcionalidades).

### Estrutura Básica de uma Classe

Aqui está um exemplo de uma classe em Java que representa um aluno:

```java
public class Aluno {
    // Atributos (ou campos)
    private String nome;
    private int idade;
    private float nota;

    // Construtor
    public Aluno(String nome, int idade, float nota) {
        this.nome = nome;
        this.idade = idade;
        this.nota = nota;
    }

    // Métodos
    public void exibirInformacoes() {
        System.out.println("Nome: " + nome + ", Idade: " + idade + ", Nota: " + nota);
    }
}
```

### Exemplo de Uso da Classe

Aqui está um exemplo de como criar e usar a classe `Aluno` em um programa Java:

```java
public class Main {
    public static void main(String[] args) {
        // Criação de um objeto da classe Aluno
        Aluno aluno1 = new Aluno("Maria", 20, 8.5f);
        
        // Chamando o método para exibir informações
        aluno1.exibirInformacoes();
    }
}
```

### Principais Conceitos

- **Encapsulamento**: Os atributos da classe são privados (`private`), o que significa que não podem ser acessados diretamente de fora da classe. Métodos públicos (como `exibirInformacoes`) são usados para acessar e manipular esses atributos.
  
- **Construtores**: Uma classe pode ter um ou mais construtores, que são usados para inicializar os objetos. O construtor da classe `Aluno` recebe parâmetros para definir os atributos ao criar um novo objeto.

- **Métodos**: Métodos são funções definidas dentro da classe que podem operar nos dados da classe. O método `exibirInformacoes` imprime os detalhes do aluno.

### Comparação com `structs`

| Característica         | `struct` em C          | Classe em Java        |
|------------------------|------------------------|-----------------------|
| Encapsulamento         | Não suportado          | Suportado             |
| Acesso a Membros       | Público por padrão     | Privado por padrão    |
| Métodos                | Não suportados         | Suportados            |
| Herança                | Não suportada          | Suportada             |
| Construtores           | Não suportados         | Suportados            |

## Conclusão

Nesta seção, discutimos como as classes em Java funcionam e como elas se comparam às `structs` em C. Aprendemos sobre encapsulamento, construtores e métodos. Na próxima aula, exploraremos conceitos avançados de programação orientada a objetos, como herança e polimorfismo em Java.

Se você tiver alguma dúvida ou precisar de mais exemplos, sinta-se à vontade para perguntar!
