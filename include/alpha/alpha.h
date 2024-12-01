#ifndef ALPHA_H
#define ALPHA_H

namespace Alpha
{
    struct AlphaComponent
    {
        double weight;
        bool active;

        AlphaComponent(double w, bool a) : weight(w), active(a) {}
    };

    class AlphaUseCase
    {
    public:
        double calculate(const AlphaComponent &alphaComponent, bool active);
    };
}

#endif
