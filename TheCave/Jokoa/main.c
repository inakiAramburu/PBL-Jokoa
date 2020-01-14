#include "Basic.h"
#include "Image.h"
#include "Event.h"
#include "Motion.h"
#include "Sound.h"
#include <stdio.h>
//devarreglo de espada//








int main(int argc, char* argv[]) {

	PANTAILAK Pantaila;		//Zein pantailan dagoen jokalaria
	BOOLEANOA Jokatzen = FALSE;
	void* pixels = NULL;
	int pitch;
	Uint8 bpp;
	Uint32 refreshrate = 0;
	Uint32 moverate = 0;

	//musica();

	if (LeihoaEtaRenderHasi() == 1)		//Lehioa eta renderizatua hasieratzen du
	{
		printf("Ezin izan da 1280x720- ko bideoa ezarri: %s\n", SDL_GetError());		//Erroreak
		return 1;
	}
	ZENTZUA begira = AURRERA;

	int Karga[10] = {0,0,0,0,0,0,0,0,0,0}; //Argazkiak bakarrik behin kargatzeko pantaila bakoitzean
	int pAnimazioa;

	int BizirikDaudenEtsaiak[ETSAI_KOPURUA];
	int BizirikKopurua;

	Pantaila = MENUA;		//Hasieran Menu pantailan dago jokalaria
	Jokatzen = TRUE;


	while (Jokatzen)
	{
		while (Pantaila == MENUA)
		{

			Karga[KONTROLAK] = 0;
			Karga[KREDITUAK] = 0;
			if (!Karga[MENUA])
			{
				KargatuIrudiak(Pantaila, BizirikDaudenEtsaiak, &BizirikKopurua);
				Karga[MENUA] = 1;
			}
			EbentuakKonprobatu(&Jokatzen, &Pantaila, &pAnimazioa, &begira);
			if (Pantaila != MENUA)
			{
				break;
			}
			RenderMenu();
			Irudikatu();
			SDL_Delay(50);
		}
		while (Pantaila == KREDITUAK)
		{
			Karga[MENUA] = 0;
			if (!Karga[KREDITUAK])
			{
				KargatuIrudiak(Pantaila, BizirikDaudenEtsaiak, &BizirikKopurua);
				RenderPrestatu(begira, BizirikDaudenEtsaiak, BizirikKopurua);
				Irudikatu();
				Karga[KREDITUAK] = 1;
			}
			EbentuakKonprobatu(&Jokatzen, &Pantaila, &pAnimazioa, &begira);
			SDL_Delay(50);
		}
		while (Pantaila == KONTROLAK)
		{
			Karga[MENUA] = 0;
			if (!Karga[KONTROLAK])
			{
				KargatuIrudiak(Pantaila, BizirikDaudenEtsaiak, &BizirikKopurua);
				RenderPrestatu(begira, BizirikDaudenEtsaiak, BizirikKopurua);
				Irudikatu();
				Karga[KONTROLAK] = 1;
			}
			EbentuakKonprobatu(&Jokatzen, &Pantaila, &pAnimazioa, &begira);
			SDL_Delay(50);
		}
		while (Pantaila == LEHEN)
		{
			Karga[MENUA] = 0;
			if (!Karga[LEHEN])
			{
				KargatuIrudiak(Pantaila, BizirikDaudenEtsaiak, &BizirikKopurua);
				KargatuMapa(LEHENENGO_MASKARA, &pixels, &pitch, &bpp);
				Karga[LEHEN] = 1;
			}
			EbentuakKonprobatu(&Jokatzen, &Pantaila, &pAnimazioa, &begira);
			Ekintzak(&pAnimazioa, &begira, pixels, pitch, bpp, &Pantaila, BizirikDaudenEtsaiak, &BizirikKopurua);
			RenderPrestatu(begira, BizirikDaudenEtsaiak, BizirikKopurua);
			Irudikatu();
			SDL_Delay(80);
		}
		while (Pantaila == BIGARREN)
		{
			Karga[Pantaila - 1] = 0;
			if (!Karga[Pantaila])
			{
				KargatuIrudiak(Pantaila, BizirikDaudenEtsaiak, &BizirikKopurua);
				KargatuMapa(BIGARREN_MASKARA, &pixels, &pitch, &bpp);
				Karga[Pantaila] = 1;
			}
			EbentuakKonprobatu(&Jokatzen, &Pantaila, &pAnimazioa, &begira);
			Ekintzak(&pAnimazioa, &begira, pixels, pitch, bpp, &Pantaila, BizirikDaudenEtsaiak, &BizirikKopurua);
			RenderPrestatu(begira, BizirikDaudenEtsaiak, BizirikKopurua);
			Irudikatu();
			SDL_Delay(80);
		}
		while (Pantaila == HIRUGARREN)
		{
			Karga[Pantaila - 1] = 0;
			if (!Karga[Pantaila])
			{
				KargatuIrudiak(Pantaila, BizirikDaudenEtsaiak, &BizirikKopurua);
				KargatuMapa(HIRUGARREN_MASKARA, &pixels, &pitch, &bpp);
				Karga[Pantaila] = 1;
			}
			EbentuakKonprobatu(&Jokatzen, &Pantaila, &pAnimazioa, &begira);
			Ekintzak(&pAnimazioa, &begira, pixels, pitch, bpp, &Pantaila, BizirikDaudenEtsaiak, &BizirikKopurua);
			RenderPrestatu(begira, BizirikDaudenEtsaiak, BizirikKopurua);
			Irudikatu();
			SDL_Delay(80);
		}
		while (Pantaila == LAUGARREN)
		{
			Karga[Pantaila - 1] = 0;
			if (!Karga[Pantaila])
			{
				KargatuIrudiak(Pantaila, BizirikDaudenEtsaiak, &BizirikKopurua);
				KargatuMapa(LAUGARREN_MASKARA, &pixels, &pitch, &bpp);
				Karga[Pantaila] = 1;
			}
			EbentuakKonprobatu(&Jokatzen, &Pantaila, &pAnimazioa, &begira);
			Ekintzak(&pAnimazioa, &begira, pixels, pitch, bpp, &Pantaila, BizirikDaudenEtsaiak, &BizirikKopurua);
			RenderPrestatu(begira, BizirikDaudenEtsaiak, BizirikKopurua);
			Irudikatu();
			SDL_Delay(80);
		}
		while (Pantaila == BOSTGARREN)
		{
			Karga[Pantaila - 1] = 0;
			if (!Karga[Pantaila])
			{
				KargatuIrudiak(Pantaila, BizirikDaudenEtsaiak, &BizirikKopurua);
				KargatuMapa(BOSTGARREN_MASKARA, &pixels, &pitch, &bpp);
				Karga[Pantaila] = 1;
			}
			EbentuakKonprobatu(&Jokatzen, &Pantaila, &pAnimazioa, &begira);
			Ekintzak(&pAnimazioa, &begira, pixels, pitch, bpp, &Pantaila, BizirikDaudenEtsaiak, &BizirikKopurua);
			RenderPrestatu(begira, BizirikDaudenEtsaiak, BizirikKopurua);
			Irudikatu();
			SDL_Delay(80);
		}
		while (Pantaila == FINAL)
		{
			Karga[Pantaila - 1] = 0;
			if (!Karga[Pantaila])
			{
				KargatuIrudiak(Pantaila, BizirikDaudenEtsaiak, &BizirikKopurua);
				KargatuMapa(BOSS_MASKARA, &pixels, &pitch, &bpp);
				Karga[Pantaila] = 1;
			}
			EbentuakKonprobatu(&Jokatzen, &Pantaila, &pAnimazioa, &begira);
			Ekintzak(&pAnimazioa, &begira, pixels, pitch, bpp, &Pantaila, BizirikDaudenEtsaiak, &BizirikKopurua);
			tiroak();
			RenderPrestatu(begira, BizirikDaudenEtsaiak, BizirikKopurua);
			Irudikatu();
			SDL_Delay(80);
		}




	
		while (Pantaila == MINIJOKOA)
		{
			if (!Karga[Pantaila])
			{
				for (int i = 0; i < 8; i++)
				{
					Karga[i] = 0;
				}
				KargatuIrudiak(Pantaila, BizirikDaudenEtsaiak, &BizirikKopurua);
				Karga[Pantaila] = 1;
			}
			EbentuakKonprobatu(&Jokatzen, &Pantaila, &pAnimazioa, &begira);

			if (SDL_TICKS_PASSED(SDL_GetTicks(), moverate))
			{
				PongExekutatu();
				moverate = SDL_GetTicks() + 20;
			}
			if (SDL_TICKS_PASSED(SDL_GetTicks(), refreshrate))
			{
				RenderPrestatu(begira, BizirikDaudenEtsaiak, BizirikKopurua);	
				Irudikatu();
				refreshrate = SDL_GetTicks() + 50;
			}
			SDL_Delay(10);
		}
	}
	return 0;
}
