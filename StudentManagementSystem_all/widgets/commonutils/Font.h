#pragma once
#include"TypeDefine.h"
#include<string>
#include"Color.h"
class Font
{
public:
    Font();
    Font(const std::string& family, int Weight = 0, bool italic = false);

    void setHeight(int height);
    void setWidth(int width);
    void setBold(bool enable);
    void setItalic(bool enable);
    void setWeight(int weight);
    void setQuality(int Quality);
    void setFamily(const std::string& family);
    void setColor(const Color& color);

    const Color& color();

    int Height();
    int Width();
    bool Bold();
    bool Italic();
    int Weight();
    int Quality();
    std::string Family();

private:
    int32      lfHeight = 0;            //字符的平均高度
    int32      lfWidth = 0;             //字符的平均宽度(0 表示自适应)
    int32      lfEscapement = 0;        //字符串的书写角度(单位 0.1 度)；
    int32      lfOrientation = 0;       //每个字符的书写角度(单位 0.1 度)；
    int32      lfWeight = 0;            //字符的笔画粗细(0 表示默认粗细)；
    Byte      lfItalic = 0;             //是否斜体；
    Byte      lfUnderline = 0;          //是否下划线；
    Byte      lfStrikeOut = 0;          //是否删除线
    Byte      lfCharSet = 0;            //指定字符集；
    Byte      lfOutPrecision = 0;       //指定文字的输出精度；
    Byte      lfClipPrecision = 0;      //指定文字的剪辑精度；
    Byte      lfQuality = 0;            //指定文字的输出质量；
    Byte      lfPitchAndFamily = 0;     //指定以常规方式描述字体的字体系列。
    char      lfFaceName[32] = { 0 };   //字体名称
    Color     lfcolor;
};