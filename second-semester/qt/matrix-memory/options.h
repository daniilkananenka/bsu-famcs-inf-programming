#ifndef OPTIONS_H
#define OPTIONS_H

class Options {
public:
    int Size() const {return size;}
    int ColorCount() const {return colorCount;}

    void SetSize(int value) {size = value;}
    void SetColorCount(int value) {colorCount = value;}
private:
    int size{4};
    int colorCount{4};
};

#endif // OPTIONS_H
