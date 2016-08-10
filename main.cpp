#include <iostream>
#include "ort.hpp"
using namespace std;

int main(){

	Ort berlin(13.408,52.518);
	Ort tokio(139.774,35.683);
	Ort lueneburg(10.4068,53.2412);
	Ort iwoinrussia(162.734436, 66.389229);
	Ort australien(133.470332,-24.317158); 
	
	berlin.hporthodrome(berlin,tokio);
	cout <<"Dist Berin - Tokio: "<< berlin.getDist() << endl;
	
	berlin.hporthodrome(berlin,lueneburg);
	cout <<"Dist Berin - Lueneburg: "<< berlin.getDist() << endl;
	
	berlin.hporthodrome(berlin,iwoinrussia);
	cout <<"Dist Berin - iwoinrussia: "<< berlin.getDist() << endl;
	
	berlin.hporthodrome(berlin,australien);
	cout <<"Dist Berin - australien: "<< berlin.getDist() << endl;
}
