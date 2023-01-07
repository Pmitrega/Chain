//
// Created by pawel on 07.01.2023.
//

#ifndef CHAIN_PHYSICS_INTERFACE_HPP
#define CHAIN_PHYSICS_INTERFACE_HPP

class Slider{
public:
    Slider(int loc_x, int loc_y, int height, int length);
    double set_value(int x, int y);
    double const get_value(){return _slider_value;}
    double get_length(){return (double)_slider_value * (double)_slider_length;}
private:
    double _slider_value;
    int _slider_min_x;
    int _slider_max_x;
    int _slider_min_y;
    int _slider_max_y;
    int _slider_length;
    int _slider_height;
};
#endif //CHAIN_PHYSICS_INTERFACE_HPP
