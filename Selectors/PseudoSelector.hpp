//
//  PseudoSelector.hpp
//  DDCSSParser
//
//  Created by 1m0nster on 2018/8/7.
//  Copyright © 2018 1m0nster. All rights reserved.
//

#ifndef PseudoSelector_hpp
#define PseudoSelector_hpp

#include <stdio.h>
#include <iostream>
#include "Selector.hpp"

// TODO not finish
namespace future {
    class PseudoSelector: public Selector {
    public:
        PseudoSelector(const std::string& data)
        {
            m_selectorType = Selector::PseudoSelector;
            m_data = data;
        }
        bool isBaseSelector();
        int weight();
    private:
        std::string m_data;
    };
}

#endif /* PseudoSelector_hpp */
