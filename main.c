/*
 * File:   main.c
 * Author: subram
 * Created on December 17, 2013, 12:16 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>


// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CCPMX = RB0      // CCP1 Pin Selection bit (CCP1 function on RB0)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// CONFIG2
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode disabled)

#define _XTAL_FREQ 4000000
#define LED PORTBbits.RB0

void interrupt t0_int(void)
{
if (TMR0IE && TMR0IF) {         //TM0IE=  Timer0 Interrupt Enable,
                                //TMR0IF= Timer0 Interrupt Flag
    TMR0=60;                    //TMR0 On Yukleme Degeri
    LED=~LED;                   //LED Toogle
    TMR0IF=0;                   //Timer0 Interrupt Flag Sifirlaniyor
    }
}


void main(void) {
    TRISBbits.TRISB0=0;         //RB0 Pini Cikis Olarak Ayarlaniyor
    INTCON=     0b10100000;     //Tum Kesmeler Aktif
                                //TMR0 Tasma Kesmesi Aktif
    OPTION_REG= 0b00000111;     //TMR0 Kesmesi Dahil Kaynaktan
                                //Frekans Bolme Oran? 1:256 
    while(1){
    }
}