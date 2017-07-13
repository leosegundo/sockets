#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 126

static void Delay(long int count);

int main(){
        FILE *fp, *gpio;
        fp = fopen("/sys/class/gpio/export","w");

        fprintf(fp, "60");
        fclose(fp);

        FILE *dir;

       dir = fopen("/sys/class/gpio/gpio60/direction", "w");
        fprintf(dir, "out");
        fclose(dir);

        /* Declarar variaveis */
        struct sockaddr_in local_address;
        struct sockaddr_in remote_address;
        
        int socket_recebe, socket_trata;
        int message_length = 0;

      char message;
        char *resposta = "não deu";

        int tamanho_local_address = sizeof(local_address);
        int tamanho_remote_address = sizeof(remote_address);
        
        /* Criar socket */
        socket_recebe = socket(AF_INET,SOCK_STREAM,0);

        local_address.sin_family = AF_INET;
        
        /*restringir endere�ço de maquinas remotas que conectam*/
        local_address.sin_addr.s_addr = INADDR_ANY;
        /*Vincular porta*/
        local_address.sin_port = htons(33333);
        
	if(!(bind(socket_recebe,(struct sockaddr *)&local_address,tamanho_local_address))){
                /* Receber conexao */
              listen(socket_recebe,5);
                              while(1){
                        
	socket_trata = accept(socket_recebe,(struct sockaddr *)&remote_address,&tamanho_remote_address);
                        
                recv(socket_trata, &message, 1, 0);
                        if (message == '1'){
                                //liquido 1
                                resposta = "50 ml de liquido 1";
                        write(socket_trata,resposta,strlen(resposta));
                        printf(" 50 ml\n");
                gpio = fopen("/sys/class/gpio/gpio60/value", "w");
                                fprintf(gpio,"1");
                                fclose(gpio);
                                        Delay(1000000000);
                        gpio = fopen("/sys/class/gpio/gpio60/value","w");
                                fprintf(gpio,"0");      
                                fclose(gpio);
                               }
                                else if(message == '2'){
                                        //liquido 2
                                        resposta = "100 ml de liquido 1";
                        write(socket_trata,resposta,strlen(resposta));
                                printf(" 100 ml \n");   
                        gpio = fopen("/sys/class/gpio/gpio60/value","w");
                                        fprintf(gpio,"1");
                                        fclose(gpio);
                                        Delay(2000000000);
                   gpio = fopen("/sys/class/gpio/gpio60/value","w");


                  fprintf(gpio,"0");      
                                        fclose(gpio);
                                }
                                else if(message == '3'){
                                        //liquido 3
                                        resposta = "200 ml de liquido 1";
                                write(socket_trata,resposta,strlen(resposta));
                                        printf(" 200 ml\n");
                gpio = fopen("/sys/class/gpio/gpio60/value","w");
                fprintf(gpio,"1");
         
               fclose(gpio);
                Delay(4000000000);
                gpio = fopen("/sys/class/gpio/gpio60/value","w");
                                        fprintf(gpio,"0");      
                                      fclose(gpio);
                                }else{
                                        resposta = "moi�ô papai";
                write(socket_trata,resposta,strlen(resposta));
                        }
                        close(socket_trata);
                        
                }
        }else{
                printf("Erro ao alocar porta\n");
                exit(1);
        }


        return 0;
}



