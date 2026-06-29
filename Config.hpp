#pragma once

class config{
public:
     static const int screen_width = 800;
     static const int screen_height = 600;
     static const int grid_size = 20;
     static const int total_column = screen_width / grid_size;
     static const int total_row = screen_height / grid_size;
};