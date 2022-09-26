#include <stdio.h>

#include <math.h>

float le_valida_nota();
int le_qtd_notas();

int main() {
	
	float notas[40], media, soma_ap, soma_rep;
	int i=0;

    printf("Vetores\n");

    int qtd_notas = le_qtd_notas();
    
	for(i = 0; i<qtd_notas; i++){
		printf("Informa a %da. Nota: ", i+1);
		notas[i] = le_valida_nota();
	}
	
	float rep[40], ap[40];
	
	int a=0, r=0;
	for(i=0; i<qtd_notas; i++){
		if(notas[i] < 7){
			rep[r] = notas[i];
			r++;
		}else{
			ap[a] = notas[i];
			a++;
		}
	}

    int qtd_rep = r;
    int qtd_ap = a;

    soma_ap = 0;
	for(i = 0;i < qtd_ap;i++){
		soma_ap = soma_ap + ap[i];
	}

    soma_rep = 0;
	for(i = 0;i < qtd_rep;i++){
		soma_rep = soma_rep + rep[i];
	}

    float media_ap = soma_ap/qtd_ap;
    printf("\nMedia aprovados: %.2f\n", media_ap);


    float nota_menor = rep[0];
    for(i = 1;i < qtd_rep;i++){
        if(rep[i] < nota_menor){
            nota_menor = rep[i];
        }
	}

    printf("Menor nota: %.2f\n", nota_menor);

	float nota_maior = ap[0];
    for(i = 1;i < qtd_ap;i++){
        if(ap[i] > nota_maior){
            nota_maior = ap[i];
        }
	}

    printf("Maior nota: %.2f\n", nota_maior);


	float soma_med_rep = 0;
	int qtd_rep_imp;
	for(i=0 ; i < qtd_notas; i++){
		if(fmod(rep[i], 2) != 0){
		soma_med_rep = soma_med_rep + rep[i];
		qtd_rep_imp++;
		}
	}

	float media_rep_imp;
	media_rep_imp = soma_med_rep/qtd_rep_imp;
    printf("Media dos reprovados impares: %.2f\n", media_rep_imp);
	
	return 0;
}

int le_qtd_notas(){
    int qtd_notas = 0;
    
    printf("Quantas notas deseja inserir (Max. 40)? ");
    scanf("%d", &qtd_notas);
   
   while( qtd_notas < 1 || qtd_notas > 40){
    printf("Insira uma valor de 1 a 40: ");
    scanf("%d", &qtd_notas);
   }

    return qtd_notas;
}

float le_valida_nota(){
	float nota;

    scanf("%f", &nota);
		
	while(nota < 0 || nota > 10){
        printf("Valor invalido, insira novamente: ");
        scanf("%f", &nota);
    }
              	
	return nota;
}