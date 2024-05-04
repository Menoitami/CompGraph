typedef struct Area {
    double xlt, ylt, zlt; // Координаты левого верхнего угла ближней грани
    double xrb, yrb, zrb; // Координаты правого нижнего угла дальней грани

    // Конструктор для инициализации объекта Area из двух векторов типа std::vector<double>
    Area(const std::vector<double>& topLeft, const std::vector<double>& bottomRight)
        : xlt(topLeft[0]), ylt(topLeft[1]), zlt(topLeft[2]),
        xrb(bottomRight[0]), yrb(bottomRight[1]), zrb(bottomRight[2]) {}
} Area;
