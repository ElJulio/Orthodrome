#include "ort.hpp"
#include <cmath>
#include <iostream>
using namespace std;
#define ERDRADIUS 6378.137
#define PI 3.14159265

Ort::Ort(){
	geolaenge_ = 0;
	geobreite_ = 0;
}

Ort::Ort(float geolaenge, float geobreite){
	geolaenge_ = geolaenge;
	geobreite_ = geobreite;
}

Ort::Ort(Ort& o){
	geolaenge_ = o.Ort::getGeoLaenge();
	geobreite_ = o.Ort::getGeoBreite();
}

float Ort::getGeoLaenge() const{
	return geolaenge_;
}

float Ort::getGeoBreite() const{
	return geobreite_;
}

float Ort::getDist(){
	return dist_;
}

float Ort::getZentrirWinkel(){
	return zentriwinkel_;
}

float Ort::sind(float rad){
	return sin(rad*PI/180);
}

float Ort::cosd(float rad){
	return cos(rad*PI/180);
}


void Ort::aendern(float geolaenge, float geobreite){
	geolaenge_ = geolaenge;
	geobreite_ = geobreite;
}

void Ort::orthodrome(Ort& o1, Ort& o2){

	zentriwinkel_ = acos(sind(o1.getGeoBreite())*sind(o2.getGeoBreite())+ cosd(o1.getGeoBreite())*cosd(o2.getGeoBreite())*cosd(o2.getGeoLaenge() - o1.getGeoLaenge()));
	dist_ = zentriwinkel_ * ERDRADIUS;
}

void Ort::hporthodrome(Ort& o1, Ort& o2){
	float f,F,G,l,S,C,w,D,T,H1,H2,s; //Strecke
	
	f = 1/298.257223563;
	
	F = (o1.getGeoBreite()+o2.getGeoBreite())/2;
	
	G = (o1.getGeoBreite()-o2.getGeoBreite())/2;
	
	l = (o1.getGeoLaenge()-o2.getGeoLaenge())/2;
	
	S = pow(sind(G),2) * pow(cosd(l),2) + pow(cosd(F),2) * pow(sind(l),2);
	
	C = pow(cosd(G),2) * pow(cosd(l),2) + pow(sind(F),2) * pow(sind(l),2);
	
	w = atan(sqrt(S/C));
	
	D = 2 * w * ERDRADIUS;
	
	T = sqrt(S*C)/w;
	
	H1 = (3*T-1)/(2*C);
	
	H2 = (3*T+1)/(2*S);
	
	s = D*(1+f*H1*pow(sind(F),2)*pow(cosd(G),2)-f*H2*pow(cosd(F),2)*pow(sind(G),2));
	
	dist_ = s;
}
