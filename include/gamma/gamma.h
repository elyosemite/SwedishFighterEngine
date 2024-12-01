#ifndef GAMMA_H
#define GAMMA_H

namespace Gamma
{
    struct GammaComponent
    {
        double weight;
        bool active;

        GammaComponent(double w, bool a) : weight(w), active(a) {}
    };

    class GammaUseCase
    {
    public:
        double calculate(const GammaComponent &gammaComponent, bool active);
    };
}

#endif