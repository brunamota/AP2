
typedef struct {
    char nome[50];
    float nota1;
    float nota2;
} Aluno;

void adicionarAluno(Aluno *aluno) {
    printf("Nome: ");
    setbuf(stdin, NULL);
    gets(aluno->nome);
    setbuf(stdin, NULL);
    printf("Nota 1: ");
    scanf("%f", &aluno->nota1);
    setbuf(stdin, NULL);
    printf("Nota 2: ");
    scanf("%f", &aluno->nota2);
    setbuf(stdin, NULL);
}

float calcularMedia(Aluno aluno) {
    return (aluno.nota1 + aluno.nota2) / 2.0;
}

void listarAlunos(Aluno *alunos, int total) {
    for (int i = 0; i < total; i++) {
        printf("Aluno: %s\nNota 1: %.2f\nNota 2: %.2f\nMedia: %.2f\n",
               alunos[i].nome, alunos[i].nota1, alunos[i].nota2,
               calcularMedia(alunos[i]));
    }
}

