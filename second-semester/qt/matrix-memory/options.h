#ifndef OPTIONS_H
#define OPTIONS_H

class Options {
public:
    int Size() const {return size;}
    int ColorCount() const {return colorCount;}
    int Level() const {return level;}

    void SetSize(int value) {size = value;}
    void SetColorCount(int value) {colorCount = value;}
    void SetLevel(int value) {level = value;}
private:
    int size{3};
    int level{1};
    int colorCount{4};
};

#endif // OPTIONS_H
