#include <stdio.h>

int main(){
   FILE *arquivo = fopen("Arquivos.txt", "r");
    char linha[100];

   if(arquivo == NULL){
     printf("Erro ao abrir o arquivo\n");
   }else{
       while (fgets(linha, 100, arquivo) != NULL) {
           printf("%s", linha);
       }
   }
   fclose(arquivo);
}
