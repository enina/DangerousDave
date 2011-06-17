#pragma once
/************************************************************************************
 *  Image CLASS
 ************************************************************************************/
class Image
{
  public:
	Image(void);
	Image(const char *filename){Load(filename);};
	bool Load(const char *filename);
	void Release();
	void Draw();
 
  private:
	char *imageData;
 
 
	struct tga_header
	{
		unsigned char idLength;
		unsigned char colorMapType;
		unsigned char imageTypeCode;
		unsigned char colorMapSpec[5];
		unsigned short xOrigin;
		unsigned short yOrigin;	
		unsigned short width;
		unsigned short height;
		unsigned char bpp;
		unsigned char imageDesc;
	};
	tga_header tgaheader;
};
 