#include "Image.h"
#include"Window.h"

Image::Image():x(0),y(0),pMaskImg(nullptr)
{
	
}

Image::Image(const std::string& imgPath, int w, int h): Image()
{
	::loadimage(this, imgPath.c_str(), w, h);
	if (this->getwidth() == 0 && this->getheight() == 0)
	{
		plog("[error] %s load failed\n", imgPath.c_str());
	}
}

Image::Image(const std::string& maskImgPath, const std::string& srcImgPath, int w, int h)
	:pMaskImg(new Image(maskImgPath,w,h))
{
	::loadimage(this, srcImgPath.c_str(), w, h);
	if (this->getwidth() == 0 && this->getheight() == 0)
	{
		plog("[error] %s load failed\n", srcImgPath.c_str());
	}
}

Image::Image(const std::string& prefixPath, const std::string& maskImgPath, const std::string& srcImgPath, int w, int h)
	:Image(prefixPath+maskImgPath, prefixPath+srcImgPath,w,h)
{
}

void Image::draw()
{
	putimage_alapha(this->x, this->y, this);
}

void Image::draw(DWORD maskdwRop,DWORD srcdwRop)
{
	::putimage(this->x, this->y, pMaskImg, maskdwRop);
	::putimage(this->x, this->y, this, srcdwRop);
}

void Image::move(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Image::save(const std::string& savePath)
{
	::saveimage(savePath.c_str(), this);
}

void Image::save(const std::string& savePath, Image* img)
{
	::saveimage(savePath.c_str(), img);
}

Image* Image::getimage(int x, int y, int w, int h)
{
	Image* img = new Image;
	::getimage(img, x, y, w, h);
	return img;
}

DWORD* Image::ImageBuffer()
{
	return ::GetImageBuffer(this);
}

void Image::SetDefault()
{
}



/*@私有成员*/
//png图片透明贴图
void Image::putimage_alapha(int x, int y, IMAGE* src)
{
	// 变量初始化
	DWORD* pwin = GetImageBuffer();			//窗口缓冲区指针
	DWORD* psrc = GetImageBuffer(src);		//图片缓冲区指针
	int win_w = Window::width();				//窗口宽高
	int win_h = Window::height();
	int src_w = src->getwidth();				//图片宽高
	int src_h = src->getheight();

	// 计算贴图的实际长宽
	int real_w = (x + src_w > win_w) ? win_w - x : src_w;			// 处理超出右边界
	int real_h = (y + src_h > win_h) ? win_h - y : src_h;			// 处理超出下边界
	if (x < 0) { psrc += -x;			real_w -= -x;	x = 0; }	// 处理超出左边界
	if (y < 0) { psrc += (src_w * -y);	real_h -= -y;	y = 0; }	// 处理超出上边界


	// 修正贴图起始位置
	pwin += (win_w * y + x);

	// 实现透明贴图
	for (int iy = 0; iy < real_h; iy++)
	{
		for (int ix = 0; ix < real_w; ix++)
		{
			byte a = (byte)(psrc[ix] >> 24);//计算透明通道的值[0,256) 0为完全透明 255为完全不透明
			if (a > 100)
			{
				pwin[ix] = psrc[ix];
			}
		}
		//换到下一行
		pwin += win_w;
		psrc += src_w;
	}
}
