#ifndef RENDERING_ENGINE_BITMAP_TEXT_H
#define RENDERING_ENGINE_BITMAP_TEXT_H
#include <map>
#include <string>
#include <vector>
#include <GL/glew.h>
#include <glm/vec2.hpp>
#include "model.hpp"

namespace BitmapText
{
    struct CharInfo
    {
        CharInfo(float x, float y, float w, float h, float px, float py, float advance) :
            x(x),
            y(y),
            w(w),
            h(h),
            px(px),
            py(py),
            advance(advance)
        {}

        CharInfo(float x, float y, float w, float h, float px, float py) :
            CharInfo(x, y, w, h, px, py, 0.0f)
        {}

        float x;
        float y;
        float w;
        float h;
        float px;
        float py;
        float advance;
    };

    static const std::map<char, CharInfo> &simple_bitmap_text = {
        {' ', {0, 0, 0, 0, 0, 0, 8}},
        {'!', {16, 0, 6, 20, 0, 0}},
        {'\"', {32, 0, 10, 10, 0, 0}},
        {'#', {48, 4, 14, 14, 0, 4}},
        {'$', {64, 0, 14, 20, 0, 0}},
        {'%', {80, 0, 16, 20, 0, 0}},
        {'&', {96, 0, 14, 20, 0, 0}},
        {'\'', {112, 0, 6, 10, 0, 0}},
        {'(', {128, 0, 10, 22, 0, 0}},
        {')', {144, 0, 10, 22, 0, 0}},
        {'*', {160, 0, 14, 18, 0, 0}},
        {'+', {176, 6, 14, 14, 0, 6}},
        {',', {192, 14, 8, 8, 0, 14}},
        {'-', {208, 10, 14, 6, 0, 10}},
        {'.', {224, 14, 6, 6, 0, 14}},
        {'/', {240, 0, 12, 20, 0, 0}},
        {'0', {0, 24, 12, 20, 0, 0}},
        {'1', {16, 24, 10, 20, 0, 0}},
        {'2', {32, 24, 12, 20, 0, 0}},
        {'3', {48, 24, 12, 20, 0, 0}},
        {'4', {64, 24, 12, 20, 0, 0}},
        {'5', {80, 24, 12, 20, 0, 0}},
        {'6', {96, 24, 12, 20, 0, 0}},
        {'7', {112, 24, 12, 20, 0, 0}},
        {'8', {128, 24, 12, 20, 0, 0}},
        {'9', {144, 24, 12, 20, 0, 0}},
        {',', {160, 30, 6, 12, 0, 6}},
        {':', {160, 30, 8, 14, 0, 6}},
        {';', {176, 30, 8, 14, 0, 6}},
        {'<', {192, 26, 12, 18, 0, 2}},
        {'=', {208, 30, 12, 10, 0, 6}},
        {'>', {224, 26, 12, 18, 0, 2}},
        {'?', {240, 24, 14, 20, 0, 0}},
        {'@', {0, 48, 14, 20, 0, 0}},
        {'A', {16, 48, 14, 20, 0, 0}},
        {'B', {32, 48, 12, 20, 0, 0}},
        {'C', {48, 48, 12, 20, 0, 0}},
        {'D', {64, 48, 12, 20, 0, 0}},
        {'E', {80, 48, 12, 20, 0, 0}},
        {'F', {96, 48, 12, 20, 0, 0}},
        {'G', {112, 48, 12, 20, 0, 0}},
        {'H', {128, 48, 12, 20, 0, 0}},
        {'I', {144, 48, 10, 20, 0, 0}},
        {'J', {160, 48, 12, 20, 0, 0}},
        {'K', {176, 48, 12, 20, 0, 0}},
        {'L', {192, 48, 12, 20, 0, 0}},
        {'M', {208, 48, 14, 20, 0, 0}},
        {'N', {224, 48, 14, 20, 0, 0}},
        {'O', {240, 48, 12, 20, 0, 0}},
        {'P', {0, 72, 12, 20, 0, 0}},
        {'Q', {16, 72, 14, 20, 0, 0}},
        {'R', {32, 72, 12, 20, 0, 0}},
        {'S', {48, 72, 12, 20, 0, 0}},
        {'T', {64, 72, 14, 20, 0, 0}},
        {'U', {80, 72, 12, 20, 0, 0}},
        {'V', {96, 72, 14, 20, 0, 0}},
        {'W', {112, 72, 14, 20, 0, 0}},
        {'X', {128, 72, 14, 20, 0, 0}},
        {'Y', {144, 72, 14, 20, 0, 0}},
        {'Z', {160, 72, 12, 20, 0, 0}},
        {'[', {176, 72, 10, 22, 0, 0}},
        {'\\', {192, 72, 12, 20, 0, 0}},
        {']', {208, 72, 10, 22, 0, 0}},
        {'^', {224, 72, 14, 10, 0, 0}},
        {'_', {240, 88, 12, 6, 0, 16}},
        {'`', {0, 96, 10, 10, 0, 0}},
        {'a', {16, 102, 12, 14, 0, 6}},
        {'b', {32, 96, 12, 20, 0, 0}},
        {'c', {48, 102, 12, 14, 0, 6}},
        {'d', {64, 96, 12, 20, 0, 0}},
        {'e', {80, 102, 12, 14, 0, 6}},
        {'f', {96, 96, 10, 20, 0, 0}},
        {'g', {112, 102, 12, 18, 0, 6}},
        {'h', {128, 96, 12, 20, 0, 0}},
        {'i', {144, 98, 6, 18, 0, 2}},
        {'j', {160, 98, 8, 22, 0, 2}},
        {'k', {176, 96, 12, 20, 0, 0}},
        {'l', {192, 96, 6, 20, 0, 0}},
        {'m', {208, 102, 14, 14, 0, 6}},
        {'n', {224, 102, 12, 14, 0, 6}},
        {'o', {240, 102, 12, 14, 0, 6}},
        {'p', {0, 126, 12, 18, 0, 6}},
        {'q', {16, 126, 14, 18, 0, 6}},
        {'r', {32, 126, 12, 14, 0, 6}},
        {'s', {48, 126, 12, 14, 0, 6}},
        {'t', {64, 122, 12, 18, 0, 2}},
        {'u', {80, 126, 12, 14, 0, 6}},
        {'v', {96, 126, 14, 14, 0, 6}},
        {'w', {112, 126, 14, 14, 0, 6}},
        {'x', {128, 126, 14, 14, 0, 6}},
        {'y', {144, 126, 14, 18, 0, 6}},
        {'z', {160, 126, 12, 14, 0, 6}},
        {'{', {176, 120, 10, 22, 0, 0}},
        {'|', {192, 120, 6, 22, 0, 0}},
        {'}', {208, 120, 10, 22, 0, 0}},
        {'~', {224, 120, 14, 8, 0, 0}}
    };

    class Factory
    {
    public:
        Factory(
            float texture_width,
            float texture_height,
            const std::map<char, CharInfo> &character_map
        ) :
            texture_width(texture_width),
            texture_height(texture_height),
            character_map(character_map)
        {

        }
        void addRow(float x, float y, const std::string &text)
        {
            float cursor_offset = 0.0f;

            for (const char &current_char : text)
            {
                auto iterator = character_map.find(current_char);

                if (iterator == character_map.end())
                {
                    continue;
                }

                const CharInfo &char_info = iterator->second;

                const float u_min = char_info.x / texture_width;
                const float u_max = (char_info.x + char_info.w) / texture_width;

                const float v_min = char_info.y / texture_height;
                const float v_max = (char_info.y + char_info.h) / texture_height;

                const float px = char_info.px;
                const float py = char_info.py;

                const float w = char_info.w;
                const float h = char_info.h;

                if (current_char != ' ')
                {

                    Vertex2D v1 = {
                        .position = {
                            .x = x + px + cursor_offset,
                            .y = y + py
                        },
                        .uv = {
                            .u = u_min,
                            .v = v_min
                        }
                    };

                    Vertex2D v2 = {
                        .position = {
                            .x = x + px + cursor_offset + w,
                            .y = y + py
                        },
                        .uv = {
                            .u = u_max,
                            .v = v_min
                        }
                    };

                    Vertex2D v3 = {
                        .position = {
                            .x = x + px + cursor_offset,
                            .y = y + py + h
                        },
                        .uv = {
                            .u = u_min,
                            .v = v_max
                        }
                    };

                    Vertex2D v4 = {
                        .position = {
                            .x = x + px + cursor_offset + w,
                            .y = y + py + h
                        },
                        .uv = {
                            .u = u_max,
                            .v = v_max
                        }
                    };

                    vertices.push_back(v1);
                    vertices.push_back(v2);
                    vertices.push_back(v3);
                    vertices.push_back(v4);

                    const GLuint index_offset = static_cast<GLuint>(indices.size() / 6) * 4;

                    indices.push_back(index_offset + 2);
                    indices.push_back(index_offset + 1);
                    indices.push_back(index_offset + 0);

                    indices.push_back(index_offset + 2);
                    indices.push_back(index_offset + 3);
                    indices.push_back(index_offset + 1);

                }

                cursor_offset += char_info.advance ? char_info.advance : w + px;
            }
        }
        void updateModel(Model &model) const
        {
            model.data(
                vertices.data(),
                indices.data(),
                static_cast<GLuint>(vertices.size()),
                static_cast<GLuint>(indices.size())
            );
        }
    protected:
        const float texture_width;
        const float texture_height;
        const std::map<char, CharInfo> &character_map;
        std::vector<Vertex2D> vertices;
        std::vector<GLuint> indices;
    };
}

#endif
