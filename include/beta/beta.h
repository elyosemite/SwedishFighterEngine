#ifndef BETA_H
#define BETA_H

namespace Beta
{
    struct BetaComponent
    {
        double weight;
        bool active;

        BetaComponent(double w, bool a) : weight(w), active(a) {}
    };

    class BetaUseCase
    {
    public:
        double calculate(const BetaComponent &betaComponent, bool active);
    };
}

#endif
