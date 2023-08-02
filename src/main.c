/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:14:20 by cmateos-          #+#    #+#             */
/*   Updated: 2023/08/02 14:14:23 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"
/*Fork(); duplica el proceso acutal(lo que haya despues de su llamada) 
creando una bifurcación entre procesos.
Retorna el id de los procesos:
El proceso hijo tendrá id 0 (es el proceso creado a partir del proceso padre)
Si el id es -1 error al crear la bifurcacion/duplicar proceso.
por lo que hello aparecería 2 veces por pantalla.
*/

// La variable envp imprime por pantalla la ruta de los comandos que ponga con o sin "".
int main (int argc, char **argv, char**envp)
{
    int i= 1;
    while (i != argc)
    {
        printf("%s\n", *envp);
        i++;
    }
    exit (0);

}
/*int main(void)
{
    int fd[2];
    int result = pipe(fd);

    if (result == -1) 
    {
        perror("Error al crear la tubería");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Error al crear el proceso hijo");
        return 1;
    }
    else if (pid == 0) {
        // Proceso hijo
        close(fd[1]); // Cerramos el descriptor de escritura, ya que no lo necesitamos en el proceso hijo
        char buffer[1024];
        int num_bytes = read(fd[0], buffer, sizeof(buffer));
        printf("Proceso hijo: Recibidos %d bytes: %.*s\n", num_bytes, num_bytes, buffer);
        close(fd[0]); // Cerramos el descriptor de lectura una vez que hemos terminado de usarlo
    }
    else
    {
        // Proceso padre
        close(fd[0]); // Cerramos el descriptor de lectura, ya que no lo necesitamos en el proceso padre
        char mensaje[] = "Hola, proceso hijo!";
        write(fd[1], mensaje, sizeof(mensaje));
        close(fd[1]); // Cerramos el descriptor de escritura una vez que hemos terminado de usarlo
    }

    return 0;
}*/

