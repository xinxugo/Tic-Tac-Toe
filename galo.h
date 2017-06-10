/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   galo.h
 * Author: vasco
 *
 * Created on 18 de Junho de 2016, 14:59
 */

#ifndef GALO_H
#define GALO_H

#ifdef __cplusplus
extern "C" {
#endif


    void limpar(char v[3][3]);
    void desenhar(char v[3][3]);
    int vitoria(char v[3][3], char ch);
    void menu();
    void jogar(char v[3][3]);




#ifdef __cplusplus
}
#endif

#endif /* GALO_H */

