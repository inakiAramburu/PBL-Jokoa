#include "Funtzioak.h"
#include <stdio.h>
//Ekaitz, egitura

int main(int argc, char* str[]) {

	PANTAILAK Pantaila;		//Zein pantailan dagoen jokalaria
	JOKOA Jokoa = EZJOKATZEN;

	int KargaMenua = 0;		//Argazkiak bakarrik behin kargatzeko pantaila bakoitzean
	int KargaLehen = 0;		//""
	int KargaBigarren = 0;		//""
	int KargaKredituak = 0;		//""
	int KargaKontrolak = 0;		//""

	if (LeihoaEtaRenderHasi() == 1)		//Lehioa eta renderizatua hasieratzen du
	{
		printf("Ezin izan da 1280x720- ko bideoa ezarri: %s\n", SDL_GetError());		//Erroreak
		return 1;
	}

	Pantaila = MENUA;		//Hasieran Menu pantailan dago jokalaria
	Jokoa = JOKATZEN;

	while (Jokoa)
	{
		while (Pantaila == MENUA)
		{
			KargaKredituak = 0;
			KargaKontrolak = 0;
			if (!KargaMenua)
			{
				KargatuIrudiak(Pantaila);
				KargaMenua = 1;
			}
			EbentuakKonprobatu(&Jokoa, &Pantaila);
			RenderMenu();
			Irudikatu();
			SDL_Delay(50);
			
		}
		while (Pantaila == KREDITUAK)
		{
			KargaMenua = 0;
			if (!KargaKredituak)
			{
				KargatuIrudiak(Pantaila);
				KargaKredituak = 1;
			}
			EbentuakKonprobatu(&Jokoa, &Pantaila);
			RenderPrestatu();
			Irudikatu();
			SDL_Delay(50);
		}
		while (Pantaila == KONTROLAK)
		{
			KargaMenua = 0;
			if (!KargaKredituak)
			{
				KargatuIrudiak(Pantaila);
				KargaKontrolak = 1;
			}
			EbentuakKonprobatu(&Jokoa, &Pantaila);
			RenderPrestatu();
			Irudikatu();
			SDL_Delay(50);
		}
		while (Pantaila == LEHEN)
		{
			KargaMenua = 0;
			if (!KargaLehen)
			{
				KargatuIrudiak(Pantaila);
				KargaLehen = 1;
			}
			EbentuakKonprobatu(&Jokoa, &Pantaila);
			RenderPrestatu();
			Irudikatu();
			SDL_Delay(50);
		}
	}
	return 0;
}
