#include "../../include/alpha/alpha.h"
#include "../../include/alpha/alphazone.h"

namespace Alpha
{
    double AlphaUseCase::calculate(const AlphaComponent &alphaComponent, bool active)
    {
#ifdef USE_ALPHAZONE
        AlphaZone::AlphaStrikeZone strikeZone;
        return strikeZone.calculateStrikeZone();
#else
        return 1.2;
#endif
    }
}
