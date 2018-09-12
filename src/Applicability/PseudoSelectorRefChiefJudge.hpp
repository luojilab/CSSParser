//
//  PseudoSelectorRefChiefJudge.hpp
//  DDCSSParser
//
//  Created by 1m0nster on 2018/9/12.
//  Copyright © 2018 1m0nster. All rights reserved.
//

#ifndef PseudoSelectorRefChiefJudge_hpp
#define PseudoSelectorRefChiefJudge_hpp

#include <stdio.h>
#include "gumbo.h"

namespace future {
    class PseudoSelector;
    class PseudoSelectorRefChiefJudge {
    public:
        static bool nodeAdaptToPseudo(GumboNode *, PseudoSelector*);
    };
}

#endif /* PseudoSelectorRefChiefJudge_hpp */
