#include "processing.h"
#include "iir.h"
#include "math.h"

Int16 alpha[4];
Int16 beta[2];
Int16 lp_coeff[4];
Int16 peek1_coeff[6];
Int16 peek2_coeff[6];
Int16 hp_coeff[4];
Int16 z_x_lp[2] = {0};
Int16 z_x_hp[2] = {0};
Int16 z_y_lp[2] = {0};
Int16 z_y_hp[2] = {0};
Int16 z_x_peek1[3] = {0};
Int16 z_x_peek2[3] = {0};
Int16 z_y_peek1[3] = {0};
Int16 z_y_peek2[3] = {0};
Int16 tmp_lp[128];
Int16 tmp_peek1[128];
Int16 tmp_peek2[128];

void calculateShelvingCoeff(float c_alpha, Int16* output)
{
	/* Your code here */

	output[0] = (c_alpha < 0) ? c_alpha*32768 : c_alpha*32767;
	output[1] = -32768; //-1
	output[2] = 32767; //1
	output[3] = (c_alpha < 0) ? -c_alpha*32767 : -c_alpha*32768;
}

void calculatePeekCoeff(float c_alpha, float c_beta, Int16* output)
{
	/* Your code here */
	int i;
	output[0] =  (c_alpha < 0) ? (Int16) (c_alpha*32768) : (Int16) (c_alpha*32767);
	output[1] =  (c_beta < 0) ? ((Int32) ((-c_beta*(1+c_alpha))*32767)) >> 1 : ((Int32) ((-c_beta*(1+c_alpha))*32768)) >> 1;
	output[2] = 32767;

	for(i = 3; i < 6; i++)
	{
		output[i] = output[6-i-1];
	}

}

Int16 shelvingHP(Int16 input, Int16* coef, Int16* z_x, Int16* z_y, Int16 k)
{
	/* Your code here */
	Int16 allPassOutput;
	Int16 output;

	allPassOutput = first_order_IIR(input, coef, z_x, z_y);
	output = ((( (Int32)input + allPassOutput)*k) >> 1) + (( (Int32)input - allPassOutput) >> 1);

	return output;
}

Int16 shelvingLP(Int16 input, Int16* coeff, Int16* z_x, Int16* z_y, Int16 k)
{
	/* Your code here */
	Int16 allPassOutput;
	Int16 output;

	allPassOutput = first_order_IIR(input, coeff, z_x, z_y);
	output = (( (Int32)input + allPassOutput) >> 1) + ((( (Int32)input - allPassOutput)*k) >> 1);

	return output;
}

Int16 shelvingPeek(Int16 input, Int16* coeff, Int16* z_x, Int16* z_y, Int16 k)
{
	/* Your code here */
	Int16 allPassOutput;
	Int16 output;

	allPassOutput = second_order_IIR(input, coeff, z_x, z_y);
	output = (( (Int32)input + allPassOutput) >> 1) + ((( (Int32)input - allPassOutput)*k) >> 1);

	return output;
}

void calculateAlphaBeta(float *w, float *band)
{
	int i;
	float alpha1Tmp, alpha2Tmp, a;

	/* Calculating alpha for lp */
	a = cos(w[0]);
	alpha1Tmp = (2+sqrt(4-4*a*a))/(2*a);
	alpha2Tmp = (2-sqrt(4-4*a*a))/(2*a);

	alpha[0] = (alpha1Tmp >= 0 && alpha1Tmp <= 1) ? alpha1Tmp : alpha2Tmp;

	/* Calculating alpha for hp */
	a = cos(w[3]);
	alpha1Tmp = (2+sqrt(4-4*a*a))/(2*a);
	alpha2Tmp = (2-sqrt(4-4*a*a))/(2*a);

	alpha[3] = (alpha1Tmp >= -1 && alpha1Tmp <= 0) ? alpha1Tmp : alpha2Tmp;


	/* Calculating alpha for band filters */
	a = cos(band[0]);
	alpha1Tmp = (2+sqrt(4-4*a*a))/(2*a);
	alpha2Tmp = (2-sqrt(4-4*a*a))/(2*a);

	alpha[1] = (alpha1Tmp >= -1 && alpha1Tmp <= 0) ? alpha1Tmp : alpha2Tmp;


	a = cos(band[1]);
	alpha1Tmp = (2+sqrt(4-4*a*a))/(2*a);
	alpha2Tmp = (2-sqrt(4-4*a*a))/(2*a);

	alpha[2] = (alpha1Tmp >= -1 && alpha1Tmp <= 1) ? alpha1Tmp : alpha2Tmp;

	/* Calculating beta for band filters */
	for(i = 0; i < 2; i++)
	{
		beta[i] = cos(w[1+i]);
	}

}

void equalizer(Int16* input, Int16 n, Int16 *k, float *w, float *band, Int16 *output)
{
	int i;

	calculateAlphaBeta(w, band);

	calculateShelvingCoeff(alpha[0], lp_coeff);
	calculateShelvingCoeff(alpha[3], hp_coeff);

	calculatePeekCoeff(alpha[1], beta[0], peek1_coeff);
	calculatePeekCoeff(alpha[2], beta[1], peek2_coeff);

	for(i = 0; i < n; i++)
	{
		tmp_lp[i] = shelvingLP(input[i], lp_coeff, z_x_lp, z_y_lp, k[0]);
	}

	for(i = 0; i < n; i++)
	{
		tmp_peek1[i] = shelvingHP(tmp_lp[i], peek1_coeff, z_x_peek1, z_y_peek1, k[1]);
	}

	for(i = 0; i < n; i++)
	{
		tmp_peek2[i] = shelvingHP(tmp_peek1[i], peek2_coeff, z_x_peek2, z_y_peek2, k[2]);
	}

	for(i = 0; i < n; i++)
	{
		output[i] = shelvingHP(tmp_peek1[i], hp_coeff, z_x_hp, z_y_hp, k[3]);
	}

}
