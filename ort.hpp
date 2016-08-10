#ifndef ORT_HPP
#define ORT_HPP

class Ort{
	
	
	public:
		
	
		Ort();
		Ort(float geolaenge,float geobreite);
		Ort(Ort& o);
		
		float getGeoLaenge() const;
		float getGeoBreite() const;
		float getDist();
		float getZentrirWinkel();
		
		void aendern(float geolaenge,float geobreite);
		void orthodrome(Ort& o1, Ort& o2);
		void hporthodrome(Ort& o1, Ort& o2);
		
	private:
		float geolaenge_;
		float geobreite_;
		float zentriwinkel_;
		float dist_;
		
		float sind(float rad);
		float cosd(float rad);
	
};


#endif
