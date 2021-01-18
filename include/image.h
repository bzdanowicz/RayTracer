#pragma once
#include <memory>

#define FMT_HEADER_ONLY
#include "fmt/format.h"

template <typename T>
class Image
{
public:
    Image(size_t width, size_t height, T defaultValue = {}) : m_width(width), m_height(height)
    {
        m_data = std::make_unique<T[]>(width*height);
        std::fill(m_data.get(), m_data.get() + width*height, defaultValue);
    }

    T& at(size_t x, size_t y)
    {
        return const_cast<T&>(std::as_const(*this).at(x,y));
    }

    const T& at(size_t x, size_t y) const
    {
        if(x < m_width && y < m_height)
        {
            return m_data[x + y * m_width];
        }
        else
        {
            throw std::out_of_range(fmt::format("Element [{}, {}] does not exist in image", x, y));
        }
    }

    std::string get_ppm_format() const
    {
        std::string ppmImage;
        
        ppmImage.append(fmt::format("P3\n{} {}\n{}\n", m_width, m_height, 255));
        // Reverse iteration of unsigned - carefully
        for(size_t h = m_height - 1; h < m_height; --h)
        {
            for(size_t w = 0; w < m_width; ++w)
            {
                auto dataLine = fmt::format("{:.0f} {:.0f} {:.0f}\n", at(w, h)[0], at(w, h)[1], at(w, h)[2]);
                ppmImage.append(dataLine);
            }
        }

        return ppmImage;
    }

    size_t height() const
    {
        return m_height;
    }

    size_t width() const
    {
        return m_height;
    }

private:
    size_t m_width;
    size_t m_height;
    std::unique_ptr<T[]> m_data;
};