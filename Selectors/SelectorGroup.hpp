//
//  SelectorGroup.hpp
//  DDCSSParser
//
//  Created by 1m0nster on 2018/8/7.
//  Copyright © 2018 1m0nster. All rights reserved.
//

#ifndef SelectorGroup_hpp
#define SelectorGroup_hpp

#include <stdio.h>
#include <iostream>
#include <list>
#include "Selector.hpp"

namespace future {
    class GroupSelector: public Selector {
    public:
        GroupSelector()
        {
            m_selectorType = Selector::SelectorGroup;
        }
        ~GroupSelector();
        void addSelector(Selector *);
        std::list<Selector *>getAllSelectors()
        {
            return m_slectors;
        }
        bool isBaseSelector();
        int weight();
    private:
        std::list<Selector *> m_slectors;
    };
}

#endif /* SelectorGroup_hpp */
