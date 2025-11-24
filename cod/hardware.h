#ifndef HARDWARE_H
#define HARDWARE_H

#include "config.h"

// Prototipos de funciones de hardware
void inicializar_hardware(void);
float leer_temperatura(void);
void activar_ventilador(void);
void desactivar_ventilador(void);
unsigned char leer_boton(void);
void esperar_soltar_boton(void);

#endif
