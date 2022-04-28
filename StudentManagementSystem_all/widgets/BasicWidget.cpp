#include "BasicWidget.h"

BasicWidget::BasicWidget(int x, int y, int w, int h)
    :m_x(x),m_y(y),m_w(w),m_h(h),m_bkColor(),m_font("黑体")
{
    m_font.setHeight(20);
    m_font.setQuality(PROOF_QUALITY);
    settextstyle((LOGFONT*)&m_font);
    settextcolor(m_font.color().toRgb());
   
}

int BasicWidget::width() const
{
    return m_w;
}

int BasicWidget::height() const
{
    return m_h;
}

void BasicWidget::setFixedSize(int w, int h)
{
    this->m_w = w;
    this->m_h = h;
}

int BasicWidget::x() const
{
    return m_x;
}

int BasicWidget::y() const
{
    return m_y;
}

void BasicWidget::move(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}


void BasicWidget::setBackgroundColor(const Color& color)
{
    m_bkColor = color;
}

Color BasicWidget::BackgroundColor()
{
    return m_bkColor;
}

void BasicWidget::setFont(const Font& font)
{
    m_font = font;   
}

const Font& BasicWidget::font()
{
    return m_font;
}

void BasicWidget::show()
{
    settextstyle((LOGFONT*)&m_font);
    settextcolor(m_font.color());
}
