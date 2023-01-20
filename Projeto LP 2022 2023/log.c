/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include <stdio.h>
#include <stdlib.h>

#include "log.h"

/**
 * Funcionalidade extra, consiste em guardar os "movimentos" feitos pelo utilizador no programa.
 * @param msg Mensagem de testo que será escrita no ficheiro.
 * @param filename ficheiro onde é guardado as logs.
 */
void logMsg(char *msg) {

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    FILE *fp = fopen("log.txt", "a");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%d-%02d-%02d %02d:%02d:%02d - %s\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec, msg);

    fclose(fp);
}
