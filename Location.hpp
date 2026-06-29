#pragma once

struct pos{
     int x, y;
     bool operator==(const pos &other) const {
          return other.x == x && other.y == y;
     }
};