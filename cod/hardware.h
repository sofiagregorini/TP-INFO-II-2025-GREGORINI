#ifndef HARDWARE_H
#define HARDWARE_H

#include "config.h"

// Prototipos de funciones de hardware
void inicializar_hardware(void);
float leer_luminosidad(void);
void activar_luz(void);
void desactivar_luz(void);
unsigned char leer_boton(void);
void esperar_soltar_boton(void);

#endif
