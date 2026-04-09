//NAZEV PROJEKTU : pokusy s tlacitkem alert
//Autor: Lukas Macura
//19-03-26
//V1
//historie zmen:

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include <SI_C8051F310_Register_Enums.h>
#include <stdio.h>

//-----------------------------------------------------------------------------
// Function PROTOTYPES
//-----------------------------------------------------------------------------


//ja pridal:
void blick(void);
void delay(void);
void Init_Device(void);
void Timer2(void);
//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------

sbit button = P0^0;
sbit led = P0^1;
sbit TF2H = TMR2CN^7;
unsigned int zpozdeni = 50000;

//-----------------------------------------------------------------------------
void main (void)
{
  Init_Device();
  led = 0;

  while(1){

  }
}
//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void SiLabs_Startup (void)
{
   PCA0MD &= ~0x40;                    // WDTE = 0 (clear watchdog timer
}

//-----------------------------------------------------------------------------
void Timer2(void) interrupt 5{

  TF2H = 0;
  led = ~led;
}
void blick(void){
  int i = 0;
  for(i = 0; i<20; i++){
      if(i%2 == 1) led = 0;
      else led = 1;
      delay();
  }
}

void delay(void){
  int pocetCyklu = 0;
  while(pocetCyklu < zpozdeni) pocetCyklu++;
}
//******************************************************************************
//inicializace mcu
//******************************************************************************

// Initialization function for device,
// Call Init_Device() from your main program

//=======================================
//pridano 9.4.26 slouzi k timeru
//=======================================
void Timer_Init()
{
    TMR2CN    = 0x04;
    TMR2RLL   = 0x59;
    TMR2RLH   = 0x9C;
    TMR2L     = 0x59;
    TMR2H     = 0x9C;
}

void Port_IO_Init()
{
    // P0.0  -  Unassigned,  Open-Drain, Digital
    // P0.1  -  Unassigned,  Push-Pull,  Digital
    // P0.2  -  Unassigned,  Open-Drain, Digital
    // P0.3  -  Unassigned,  Open-Drain, Digital
    // P0.4  -  Unassigned,  Open-Drain, Digital
    // P0.5  -  Unassigned,  Open-Drain, Digital
    // P0.6  -  Unassigned,  Open-Drain, Digital
    // P0.7  -  Unassigned,  Open-Drain, Digital

    // P1.0  -  Unassigned,  Open-Drain, Digital
    // P1.1  -  Unassigned,  Open-Drain, Digital
    // P1.2  -  Unassigned,  Open-Drain, Digital
    // P1.3  -  Unassigned,  Open-Drain, Digital
    // P1.4  -  Unassigned,  Open-Drain, Digital
    // P1.5  -  Unassigned,  Open-Drain, Digital
    // P1.6  -  Unassigned,  Open-Drain, Digital
    // P1.7  -  Unassigned,  Open-Drain, Digital
    // P2.0  -  Unassigned,  Open-Drain, Digital
    // P2.1  -  Unassigned,  Open-Drain, Digital
    // P2.2  -  Unassigned,  Open-Drain, Digital
    // P2.3  -  Unassigned,  Open-Drain, Digital

    P0MDOUT   = 0x02;
    XBR1      = 0x40;
}

void Interrupts_Init()
{
    IE        = 0xA0;
}

// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
    Timer_Init();
    Port_IO_Init();
    Interrupts_Init();
}


//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------
