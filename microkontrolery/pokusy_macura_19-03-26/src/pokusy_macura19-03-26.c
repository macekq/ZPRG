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
void delay(void);
void Init_Device(void);
void Timer2(void);
void LATCH_CLOCK(void);
void SHIFT_CLOCK(void);
void Shift_Register(void);

//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------

sbit button = P0^0;
sbit led = P0^1;
sbit TF2H = TMR2CN^7;


sbit SDI = P0^2;
sbit SFT_CLK = P0^3;
sbit LCH_CLK = P0^4;

int timeControl;
unsigned int zpozdeni;
unsigned char kodovani[10] = {192, 249, 164, 176, 153, 146, 130, 248, 128, 144}; //0-9
unsigned char TMPcislo;
unsigned int cislo;
const unsigned char mask = 128;

volatile unsigned char sec;
volatile unsigned char min1;
volatile unsigned char min2;
volatile unsigned char hod1;
volatile unsigned char hod2;

//-----------------------------------------------------------------------------
void main (void)
{

timeControl = 0;
zpozdeni = 50000;

sec = 0;
min1 = 0;
min2 = 0;
hod1 = 0;
hod2 = 0;

  Init_Device();
  led = 0;

  SDI = 0;
  SFT_CLK = 0;
  LCH_CLK = 0;

  while(1){

      cislo = kodovani[2];
      Shift_Register();

      cislo = 1;
      Shift_Register();

      LATCH_CLOCK();
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
void Timer2(void)/*interrupt 5*/{

  if(timeControl >= 10){
      timeControl = 0;
      sec++;
      led = ~led;

      if(sec == 60){
          sec = 0;
          min1++;

          if(min1 == 10){
              min2++;
              min1 = 0;

              if(min2 == 6){
                  min2 = 0;
                  hod1++;

                  if(hod2 == 1 && hod1 == 2){
                      hod2 = 0;
                      hod1 = 0;

                  }else if(hod1 == 10){
                      hod2 = 1;
                      hod1 = 0;
                  }
              }
          }
      }
  }

  TF2H = 0;
  timeControl++;

}
void Shift_Register(void){
  int pocet_bitu;
  for(pocet_bitu = 0; pocet_bitu < 8; pocet_bitu++){
      TMPcislo = cislo & mask;

      SDI = TMPcislo == 0 ? 0 : 1;

      SHIFT_CLOCK();
      cislo = cislo << 1;
  }
}

void SHIFT_CLOCK(void){

  SFT_CLK = 1;
  delay();
  SFT_CLK = 0;
  delay();
}
void LATCH_CLOCK(void){

  LCH_CLK = 1;
  delay();
  LCH_CLK = 0;
  delay();
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

    //P0MDOUT   = 0x02;
    //XBR1      = 0x40;
    P0MDOUT = 0x1E;
    XBR1 = 0x40;
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
