#pragma once

namespace neu
{
    frameTimer += g_time.deltaTime;
    if (frameTimer >= 1.0f / fps)
    {
        frameTimer = 0;
        frame++;
        if (frame > end_frame)
        {
            frame = start_frame;
        }
    }

    Vector2 cellSize = m_texture->GetSize() / Vector2{ num_columns, num_rows };

    int column = (frame - 1) % num_columns;
    int row = (frame - 1) / num_columns;

    rect.x = (int)(column * cellSize.x);
    rect.y = (int)(row * cellSize.y);
    rect.w = (int)(cellSize.x);
    rect.h = (int)(cellSize.y);
}