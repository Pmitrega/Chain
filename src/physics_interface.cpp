
#include "physics_interface.hpp"
#include <iostream>
Slider::Slider(int loc_x, int loc_y, int height, int length) {
    _slider_min_x = loc_x;
    _slider_max_x = loc_x + length;
    _slider_min_y = loc_y - height/2;
    _slider_max_y = loc_y + height/2;
    _slider_height = height;
    _slider_length = length;
    _slider_value = 0.50;
}

double Slider::set_value(int x, int y) {;
    if(x > _slider_max_x or x < _slider_min_x or y > _slider_max_y or y < _slider_min_y){
        return -1.0;
    }
    else{
        _slider_value = (double)(x - _slider_min_x)/(double)_slider_length;
        return _slider_value;
    }

}