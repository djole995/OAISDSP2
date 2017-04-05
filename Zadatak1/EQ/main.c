//////////////////////////////////////////////////////////////////////////////
// *
// * Predmetni projekat iz predmeta OAiS DSP 2
// * Godina: 2017
// *
// * Zadatak: Ekvalizacija audio signala
// * Autor:
// *                                                                          
// *                                                                          
/////////////////////////////////////////////////////////////////////////////

#include "stdio.h"
#include "ezdsp5535.h"
#include "ezdsp5535_i2c.h"
#include "aic3204.h"
#include "ezdsp5535_aic3204_dma.h"
#include "ezdsp5535_i2s.h"
#include "ezdsp5535_sar.h"
#include "print_number.h"
#include "math.h"
#include "string.h"

#include "iir.h"
#include "processing.h"

/* Frekvencija odabiranja */
#define SAMPLE_RATE 8000L

#define PI 3.14159265

/* Niz za smestanje ulaznih i izlaznih odbiraka */
#pragma DATA_ALIGN(sampleBufferL,4)
Int16 sampleBufferL[AUDIO_IO_SIZE];
#pragma DATA_ALIGN(sampleBufferR,4)
Int16 sampleBufferR[AUDIO_IO_SIZE];
Int16 tempBuff[128];
Int16 tempBuff1[128];
Int16 tempBuff2[128];
float w[4] = {0.059, 0.177, 0.785, 1.429};
Int16 kValues[4] = {4096, 8192, 16384, 32767};
Uint8 kValuesIndex = 0;
Int16 k[4] = {4096, 4096, 4096, 4096};
float band[2] = {0.118, 0.393};
Int16 testInput[AUDIO_IO_SIZE];
Int16 coeff[6];
Int16 z_x[2];
Int16 z_y[2];
Uint16 button = NoKey;
Uint16 previousButton = NoKey;
Uint8 activeSubrange = 0;

void main( void )
{
	int i;
    /* Inicijalizaija razvojne ploce */
    EZDSP5535_init( );

    /* Inicijalizacija kontrolera za ocitavanje vrednosti pritisnutog dugmeta*/
    EZDSP5535_SAR_init();

    /* Inicijalizacija LCD kontrolera */
    initPrintNumber();

	printf("\n Ekvalizacija audio signala \n");
		
    /* Inicijalizacija veze sa AIC3204 kodekom (AD/DA) */
    aic3204_hardware_init();
	
    /* Inicijalizacija AIC3204 kodeka */
	aic3204_init();

    aic3204_dma_init();
    
    /* Postavljanje vrednosti frekvencije odabiranja i pojacanja na kodeku */
    set_sampling_frequency_and_gain(SAMPLE_RATE, 0);

    testInput[0] = 10000;
    memset(testInput+1, 0x0, AUDIO_IO_SIZE-1);

    printChar(activeSubrange + '0');
    printChar(kValuesIndex + '0');

    while(1)
    {
    	aic3204_read_block(sampleBufferL, sampleBufferR);

    	button = EZDSP5535_SAR_getKey();
    	if(previousButton != button)
    	{
    		if(button == SW1)
    		{
    			activeSubrange = (activeSubrange == 3) ? 0 : activeSubrange+1;
    			clearLCD();
    			kValuesIndex = 0;
    			printChar(activeSubrange+'0');
    			printChar(kValuesIndex+'0');
    		}
    		else if(button == SW2)
    		{
    			kValuesIndex = (kValuesIndex == 3) ? 0 : kValuesIndex+1;
    			k[activeSubrange] = kValues[kValuesIndex];
    			clearLCD();
    			printChar(activeSubrange+'0');
    			printChar(kValuesIndex+'0');
    		}
    	}
    	previousButton = button;

    	//calculatePeekCoeff(0.2, 0, coeff);

    	/* Your code here */

    	/*for(i = 0; i < AUDIO_IO_SIZE; i++)
    	{
    		tempBuff[i] = shelvingPeek(testInput[i], coeff, z_x, z_y, (Int16) (2*16384-1));
    	}*/

    	equalizer(testInput, AUDIO_IO_SIZE, k, w, band, tempBuff);
    	equalizer(sampleBufferL, AUDIO_IO_SIZE, k, w, band, tempBuff1);
    	equalizer(sampleBufferR, AUDIO_IO_SIZE, k, w, band, tempBuff2);

		aic3204_write_block(tempBuff1, tempBuff1);
		//aic3204_write_block(sampleBufferL, sampleBufferL);
	}

    	
	/* Prekid veze sa AIC3204 kodekom */
    aic3204_disable();

    printf( "\n***Kraj programa***\n" );
	SW_BREAKPOINT;
}


